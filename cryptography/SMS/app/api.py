from fastapi import FastAPI
from pydantic import BaseModel
from cryptoapi import Crypto
from fastapi.openapi.utils import get_openapi
from starlette.responses import RedirectResponse

with open("flag.txt", "r") as f:
    flag = f.read().strip()

crypto = Crypto(
    [
        "Alice",
        "Bob",
        "Charlie"
    ],
    flag
)

app = FastAPI()

def custom_openapi():
    if app.openapi_schema:
        return app.openapi_schema
    openapi_schema = get_openapi(
        title="Secure Messaging Service",
        version="1.0.0",
        description=None,
        routes=app.routes
    )
    app.openapi_schema = openapi_schema
    return app.openapi_schema

app.openapi = custom_openapi


class User(BaseModel):
    user_id: int
    username: str


class Message(BaseModel):
    to_user: User
    from_user: User
    ciphertext: str


@app.get("/")
async def index():
    return RedirectResponse("/docs")

@app.get("/list/users")
async def list_users():
    users = {}
    for user in crypto.user_list:
        users[user['id']] = {
            'name': user['name']
        }
    return users

@app.get("/list/messages")
async def list_archived_messages():
    messages = {
        'message_ids': ['0']
    }
    return messages

@app.get("/keys/{user_id}")
async def list_keys(user_id: int):
    try:
        user = crypto.user_list[user_id]
        return {"Key": user['keypair'][0].exportKey("PEM")}
    except IndexError:
        return {"Error": "Key index error!"}

@app.get("/read/{message_id}")
async def read_message(message_id: int):
    if message_id != 0:
        return {"Error": "Message index error!"}
    return {
        "from_user": {
            "user_id": 0,
            "username": "Alice"
        },
        "to_user": {
            "user_id": 1,
            "username": "Bob"
        },
        "ciphertext": crypto.flag
    }

@app.post("/send")
def send_message(message: Message):
    to_user = message.to_user.username
    from_user = message.from_user.username
    ciphertext = message.ciphertext

    names = [user['name'] for user in crypto.user_list]
    if to_user not in names:
        return {"Error": "To user not in user list!"}

    if from_user not in names:
        return {"Error": "From user not in user list!"}

    if crypto.check_padding(ciphertext):
        return {"Success": "Message sent successfully!"}
    else:
        return {"Failure": "Incorrect message padding."}

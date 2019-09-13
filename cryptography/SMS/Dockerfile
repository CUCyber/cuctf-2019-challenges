FROM alpine:3.7

COPY ./app /app
WORKDIR /app

RUN apk add --no-cache                      \
        gcc g++ gnupg make libffi-dev       \
        openssl-dev uwsgi-python3 python3   \
        python3-dev                         \
    && pip3 install -r requirements.txt

CMD [ "uvicorn", "api:app", \
        "--host", "0.0.0.0", \
        "--port", "8100" ]

EXPOSE 8100

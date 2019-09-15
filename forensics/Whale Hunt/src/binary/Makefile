all: crypter comms

SRC_COMMON=encrypt.c
CFLAGS=-O0

crypter: crypter.c ${SRC_COMMON}
	${CC} ${CFLAGS} $< ${SRC_COMMON} -o $@

comms: comms.c ${SRC_COMMON}
	${CC} ${CFLAGS} $< ${SRC_COMMON} -o $@
	./crypter "CUCTF" .publichelper comms
	./crypter "ThisShouldNotBeDecrypted" .private comms
	./crypter "ThisShouldNotBeDecrypted" .privatehelper comms
	strip comms

.PHONY:
clean:
	rm crypter comms

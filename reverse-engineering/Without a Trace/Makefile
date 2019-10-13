all: crypter notrace

SRC_COMMON=encrypt.c
CFLAGS=-O0

crypter: crypter.c ${SRC_COMMON}
	${CC} ${CFLAGS} $< ${SRC_COMMON} -o $@

notrace: notrace.c ${SRC_COMMON} 
	${CC} ${CFLAGS} $< ${SRC_COMMON} -o $@
	./crypter "ccuu" .private notrace
	./crypter "ccuu" .privatehelper notrace
	./crypter "_ne3xtt" .secret notrace
	./crypter "_ne3xtt" .secrethelper notrace
	./crypter "yeea4r!" .forbidden notrace
	strip notrace

.PHONY:
clean:
	rm crypter notrace

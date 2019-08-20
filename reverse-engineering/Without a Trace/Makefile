all: crypter notrace

SRC_COMMON=encrypt.c
CFLAGS=-O0

crypter: crypter.c ${SRC_COMMON}
	${CC} ${CFLAGS} $< ${SRC_COMMON} -o $@

notrace: notrace.c ${SRC_COMMON} 
	${CC} ${CFLAGS} $< ${SRC_COMMON} -o $@
	./crypter "youre" .private notrace
	./crypter "youre" .privatehelper notrace
	./crypter "almost" .secret notrace
	./crypter "almost" .secrethelper notrace
	./crypter "there!" .forbidden notrace
	strip notrace

.PHONY:
clean:
	rm crypter notrace


APPNAME = skydoge-testhash

CC = x86_64-w64-mingw32-gcc

CFLAGS += -I. 
CFLAGS += -O2 
CFLAGS += -DCFG_DEBUG=1

#LFLAGS += -lrt -lpthread

OBJS += src/main.o
OBJS += src/trace.o
OBJS += src/skydoge.o
OBJS += src/sha3/sph_blake.o
OBJS += src/sha3/sph_bmw.o
OBJS += src/sha3/sph_groestl.o
OBJS += src/sha3/sph_jh.o
OBJS += src/sha3/sph_keccak.o
OBJS += src/sha3/sph_skein.o
OBJS += src/sha3/sph_luffa.o
OBJS += src/sha3/sph_cubehash.o
OBJS += src/sha3/sph_shavite.o
OBJS += src/sha3/sph_simd.o
OBJS += src/sha3/sph_echo.o
OBJS += src/sha3/sph_hamsi.o
OBJS += src/sha3/sph_fugue.o
OBJS += src/sha3/sph_shabal.o
OBJS += src/sha3/sph_whirlpool.o
OBJS += src/sha3/sph_sha2.o
OBJS += src/sha3/sph_haval.o
OBJS += src/sha3/sph_sha2big.o

all: src

src: app

app: $(OBJS)
	$(CC) $(CFLAGS) -o $(APPNAME) $(OBJS) $(LFLAGS)

.PHONY: src clean
clean:
	$(RM) -f $(APPNAME) $(OBJS)


#include "skydoge.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "trace.h"

#include "sha3/sph_blake.h"
#include "sha3/sph_bmw.h"
#include "sha3/sph_groestl.h"
#include "sha3/sph_jh.h"
#include "sha3/sph_keccak.h"
#include "sha3/sph_skein.h"
#include "sha3/sph_luffa.h"
#include "sha3/sph_cubehash.h"
#include "sha3/sph_shavite.h"
#include "sha3/sph_simd.h"
#include "sha3/sph_echo.h"
#include "sha3/sph_hamsi.h"
#include "sha3/sph_fugue.h"
#include "sha3/sph_shabal.h"
#include "sha3/sph_whirlpool.h"
#include "sha3/sph_sha2.h"
#include "sha3/sph_haval.h"


#define print_hash64(_name, _buf) \
    print_hashlen(_name, _buf, 64)

#define print_hash32(_name, _buf) \
    print_hashlen(_name, _buf, 32)


static void print_hashlen(const char *name, const void *buf, int buflen)
{
    static int index = 0;
    int i;
    const unsigned char *pbuf = buf;

    printf("%2d [%-11s] ", index++, name);

    for (i = 0; i < buflen; i++)
        printf("%2.2X", *pbuf++);

    printf("\n");
}


void skydoge_hash(const char* input, char* output, uint32_t len)
{
	sph_blake512_context     ctx_blake;
	sph_bmw512_context       ctx_bmw;
	sph_groestl512_context   ctx_groestl; 
	sph_skein512_context     ctx_skein;
	sph_jh512_context        ctx_jh;
	sph_keccak512_context    ctx_keccak;
	sph_luffa512_context     ctx_luffa1;
	sph_cubehash512_context  ctx_cubehash1;
	sph_shavite512_context   ctx_shavite1;
	sph_simd512_context      ctx_simd1;
	sph_echo512_context      ctx_echo1;
	sph_hamsi512_context     ctx_hamsi1;
	sph_fugue512_context     ctx_fugue1;
	sph_shabal512_context    ctx_shabal1;
	sph_whirlpool_context    ctx_whirlpool1;
	sph_sha512_context       ctx_sha512;
	sph_haval256_5_context   ctx_haval;
        sph_sha256_context       ctx_sha;

        uint32_t hash[16];
        uint32_t hashA[16];

        print_hashlen("Input", input, len);
        printf("\n");

        sph_blake512_init(&ctx_blake);
        sph_blake512 (&ctx_blake, input, len);
        sph_blake512_close (&ctx_blake, hash);
        print_hash64("blake512", hash);

        sph_skein512_init(&ctx_skein);
        sph_skein512 (&ctx_skein, hash, 64);
        sph_skein512_close (&ctx_skein, hash);
        print_hash64("skein512", hash);

        sph_bmw512_init(&ctx_bmw);
        sph_bmw512 (&ctx_bmw, hash, 64);
        sph_bmw512_close(&ctx_bmw, hash);
        print_hash64("bmw512", hash);

        sph_groestl512_init(&ctx_groestl);
        sph_groestl512 (&ctx_groestl, hash, 64);
        sph_groestl512_close(&ctx_groestl, hash);
        print_hash64("groestl512", hash);

        sph_jh512_init(&ctx_jh);
        sph_jh512 (&ctx_jh, hash, 64);
        sph_jh512_close(&ctx_jh, hash);
        print_hash64("jh512", hash);

        sph_luffa512_init (&ctx_luffa1);
        sph_luffa512 (&ctx_luffa1, hash, 64);
        sph_luffa512_close (&ctx_luffa1, hash);
        print_hash64("luffa512", hash);

        sph_keccak512_init(&ctx_keccak);
        sph_keccak512 (&ctx_keccak, hash, 64);
        sph_keccak512_close(&ctx_keccak, hash); 
        print_hash64("keccak512", hash);

        sph_simd512_init (&ctx_simd1);
        sph_simd512 (&ctx_simd1, hash, 64);
        sph_simd512_close(&ctx_simd1, hash);
        print_hash64("simd512", hash);

        sph_echo512_init (&ctx_echo1);
        sph_echo512 (&ctx_echo1, hash, 64);
        sph_echo512_close(&ctx_echo1, hash);
        print_hash64("echo512", hash);

        sph_cubehash512_init (&ctx_cubehash1);
        sph_cubehash512 (&ctx_cubehash1, hash, 64);
        sph_cubehash512_close(&ctx_cubehash1, hash);
        print_hash64("cubehash512", hash);

        sph_shavite512_init (&ctx_shavite1);
        sph_shavite512 (&ctx_shavite1, hash, 64);
        sph_shavite512_close(&ctx_shavite1, hash);
        print_hash64("shavite512", hash);

        sph_hamsi512_init (&ctx_hamsi1);
        sph_hamsi512 (&ctx_hamsi1, hash, 64);
        sph_hamsi512_close(&ctx_hamsi1, hash);
        print_hash64("hamsi512", hash);

        sph_fugue512_init (&ctx_fugue1);
        sph_fugue512 (&ctx_fugue1, hash, 64);
        sph_fugue512_close(&ctx_fugue1, hash);
        print_hash64("fugue512", hash);

        sph_shabal512_init (&ctx_shabal1);
        sph_shabal512 (&ctx_shabal1, hash, 64);
        sph_shabal512_close(&ctx_shabal1, hash);
        print_hash64("shabal512", hash);

        sph_whirlpool_init (&ctx_whirlpool1);
        sph_whirlpool (&ctx_whirlpool1, hash, 64);
        sph_whirlpool_close(&ctx_whirlpool1, hash);
        print_hash64("whirlpool", hash);

        sph_sha512_init(&ctx_sha512);
        sph_sha512(&ctx_sha512, hash, 64);
        sph_sha512_close(&ctx_sha512, hash);
        print_hash64("sha512", hash);

        sph_simd512_init (&ctx_simd1);
        sph_simd512 (&ctx_simd1, hash, 64);
        sph_simd512_close(&ctx_simd1, hash);
        print_hash64("simd512", hash);

        sph_whirlpool_init (&ctx_whirlpool1);
        sph_whirlpool (&ctx_whirlpool1, hash, 64);
        sph_whirlpool_close(&ctx_whirlpool1, hash);
        print_hash64("whirlpool", hash);

        sph_sha256_init(&ctx_sha);
        sph_sha256 (&ctx_sha, hash, 64);
        sph_sha256_close(&ctx_sha, hashA);
        print_hash64("sha256", hash);

        for (int i=8;i<16;i++)
            hashA[i]=0;

        sph_haval256_5_init(&ctx_haval);
        sph_haval256_5(&ctx_haval, hashA, 64);
        sph_haval256_5_close(&ctx_haval,hash);
        print_hash64("haval256_5", hash);

        memcpy(output, hash, 32);

        printf("\n");
        print_hash32("Output", hash);
}

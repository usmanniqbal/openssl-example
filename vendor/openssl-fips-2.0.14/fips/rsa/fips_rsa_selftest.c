/* ====================================================================
 * Copyright (c) 2003-2011 The OpenSSL Project.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer. 
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * 3. All advertising materials mentioning features or use of this
 *    software must display the following acknowledgment:
 *    "This product includes software developed by the OpenSSL Project
 *    for use in the OpenSSL Toolkit. (http://www.openssl.org/)"
 *
 * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to
 *    endorse or promote products derived from this software without
 *    prior written permission. For written permission, please contact
 *    openssl-core@openssl.org.
 *
 * 5. Products derived from this software may not be called "OpenSSL"
 *    nor may "OpenSSL" appear in their names without prior written
 *    permission of the OpenSSL Project.
 *
 * 6. Redistributions of any form whatsoever must retain the following
 *    acknowledgment:
 *    "This product includes software developed by the OpenSSL Project
 *    for use in the OpenSSL Toolkit (http://www.openssl.org/)"
 *
 * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY
 * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR
 * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#define OPENSSL_FIPSAPI

#include <string.h>
#include <openssl/err.h>
#include <openssl/fips.h>
#include <openssl/rsa.h>
#include <openssl/evp.h>
#include <openssl/bn.h>
#include <openssl/opensslconf.h>

#include "fips_locl.h"

#ifdef OPENSSL_FIPS

__fips_constseg
static const unsigned char rsa_test_2048_n[] = {
	0xDB,0x10,0x1A,0xC2,0xA3,0xF1,0xDC,0xFF,0x13,0x6B,0xED,0x44,
	0xDF,0xF0,0x02,0x6D,0x13,0xC7,0x88,0xDA,0x70,0x6B,0x54,0xF1,
	0xE8,0x27,0xDC,0xC3,0x0F,0x99,0x6A,0xFA,0xC6,0x67,0xFF,0x1D,
	0x1E,0x3C,0x1D,0xC1,0xB5,0x5F,0x6C,0xC0,0xB2,0x07,0x3A,0x6D,
	0x41,0xE4,0x25,0x99,0xAC,0xFC,0xD2,0x0F,0x02,0xD3,0xD1,0x54,
	0x06,0x1A,0x51,0x77,0xBD,0xB6,0xBF,0xEA,0xA7,0x5C,0x06,0xA9,
	0x5D,0x69,0x84,0x45,0xD7,0xF5,0x05,0xBA,0x47,0xF0,0x1B,0xD7,
	0x2B,0x24,0xEC,0xCB,0x9B,0x1B,0x10,0x8D,0x81,0xA0,0xBE,0xB1,
	0x8C,0x33,0xE4,0x36,0xB8,0x43,0xEB,0x19,0x2A,0x81,0x8D,0xDE,
	0x81,0x0A,0x99,0x48,0xB6,0xF6,0xBC,0xCD,0x49,0x34,0x3A,0x8F,
	0x26,0x94,0xE3,0x28,0x82,0x1A,0x7C,0x8F,0x59,0x9F,0x45,0xE8,
	0x5D,0x1A,0x45,0x76,0x04,0x56,0x05,0xA1,0xD0,0x1B,0x8C,0x77,
	0x6D,0xAF,0x53,0xFA,0x71,0xE2,0x67,0xE0,0x9A,0xFE,0x03,0xA9,
	0x85,0xD2,0xC9,0xAA,0xBA,0x2A,0xBC,0xF4,0xA0,0x08,0xF5,0x13,
	0x98,0x13,0x5D,0xF0,0xD9,0x33,0x34,0x2A,0x61,0xC3,0x89,0x55,
	0xF0,0xAE,0x1A,0x9C,0x22,0xEE,0x19,0x05,0x8D,0x32,0xFE,0xEC,
	0x9C,0x84,0xBA,0xB7,0xF9,0x6C,0x3A,0x4F,0x07,0xFC,0x45,0xEB,
	0x12,0xE5,0x7B,0xFD,0x55,0xE6,0x29,0x69,0xD1,0xC2,0xE8,0xB9,
	0x78,0x59,0xF6,0x79,0x10,0xC6,0x4E,0xEB,0x6A,0x5E,0xB9,0x9A,
	0xC7,0xC4,0x5B,0x63,0xDA,0xA3,0x3F,0x5E,0x92,0x7A,0x81,0x5E,
	0xD6,0xB0,0xE2,0x62,0x8F,0x74,0x26,0xC2,0x0C,0xD3,0x9A,0x17,
	0x47,0xE6,0x8E,0xAB
};
__fips_constseg
static const unsigned char rsa_test_2048_e[] = {
	0x01,0x00,0x01
};
__fips_constseg
static const unsigned char rsa_test_2048_d[] = {
	0x52,0x41,0xF4,0xDA,0x7B,0xB7,0x59,0x55,0xCA,0xD4,0x2F,0x0F,
	0x3A,0xCB,0xA4,0x0D,0x93,0x6C,0xCC,0x9D,0xC1,0xB2,0xFB,0xFD,
	0xAE,0x40,0x31,0xAC,0x69,0x52,0x21,0x92,0xB3,0x27,0xDF,0xEA,
	0xEE,0x2C,0x82,0xBB,0xF7,0x40,0x32,0xD5,0x14,0xC4,0x94,0x12,
	0xEC,0xB8,0x1F,0xCA,0x59,0xE3,0xC1,0x78,0xF3,0x85,0xD8,0x47,
	0xA5,0xD7,0x02,0x1A,0x65,0x79,0x97,0x0D,0x24,0xF4,0xF0,0x67,
	0x6E,0x75,0x2D,0xBF,0x10,0x3D,0xA8,0x7D,0xEF,0x7F,0x60,0xE4,
	0xE6,0x05,0x82,0x89,0x5D,0xDF,0xC6,0xD2,0x6C,0x07,0x91,0x33,
	0x98,0x42,0xF0,0x02,0x00,0x25,0x38,0xC5,0x85,0x69,0x8A,0x7D,
	0x2F,0x95,0x6C,0x43,0x9A,0xB8,0x81,0xE2,0xD0,0x07,0x35,0xAA,
	0x05,0x41,0xC9,0x1E,0xAF,0xE4,0x04,0x3B,0x19,0xB8,0x73,0xA2,
	0xAC,0x4B,0x1E,0x66,0x48,0xD8,0x72,0x1F,0xAC,0xF6,0xCB,0xBC,
	0x90,0x09,0xCA,0xEC,0x0C,0xDC,0xF9,0x2C,0xD7,0xEB,0xAE,0xA3,
	0xA4,0x47,0xD7,0x33,0x2F,0x8A,0xCA,0xBC,0x5E,0xF0,0x77,0xE4,
	0x97,0x98,0x97,0xC7,0x10,0x91,0x7D,0x2A,0xA6,0xFF,0x46,0x83,
	0x97,0xDE,0xE9,0xE2,0x17,0x03,0x06,0x14,0xE2,0xD7,0xB1,0x1D,
	0x77,0xAF,0x51,0x27,0x5B,0x5E,0x69,0xB8,0x81,0xE6,0x11,0xC5,
	0x43,0x23,0x81,0x04,0x62,0xFF,0xE9,0x46,0xB8,0xD8,0x44,0xDB,
	0xA5,0xCC,0x31,0x54,0x34,0xCE,0x3E,0x82,0xD6,0xBF,0x7A,0x0B,
	0x64,0x21,0x6D,0x88,0x7E,0x5B,0x45,0x12,0x1E,0x63,0x8D,0x49,
	0xA7,0x1D,0xD9,0x1E,0x06,0xCD,0xE8,0xBA,0x2C,0x8C,0x69,0x32,
	0xEA,0xBE,0x60,0x71
};
__fips_constseg
static const unsigned char rsa_test_2048_p[] = {
	0xFA,0xAC,0xE1,0x37,0x5E,0x32,0x11,0x34,0xC6,0x72,0x58,0x2D,
	0x91,0x06,0x3E,0x77,0xE7,0x11,0x21,0xCD,0x4A,0xF8,0xA4,0x3F,
	0x0F,0xEF,0x31,0xE3,0xF3,0x55,0xA0,0xB9,0xAC,0xB6,0xCB,0xBB,
	0x41,0xD0,0x32,0x81,0x9A,0x8F,0x7A,0x99,0x30,0x77,0x6C,0x68,
	0x27,0xE2,0x96,0xB5,0x72,0xC9,0xC3,0xD4,0x42,0xAA,0xAA,0xCA,
	0x95,0x8F,0xFF,0xC9,0x9B,0x52,0x34,0x30,0x1D,0xCF,0xFE,0xCF,
	0x3C,0x56,0x68,0x6E,0xEF,0xE7,0x6C,0xD7,0xFB,0x99,0xF5,0x4A,
	0xA5,0x21,0x1F,0x2B,0xEA,0x93,0xE8,0x98,0x26,0xC4,0x6E,0x42,
	0x21,0x5E,0xA0,0xA1,0x2A,0x58,0x35,0xBB,0x10,0xE7,0xBA,0x27,
	0x0A,0x3B,0xB3,0xAF,0xE2,0x75,0x36,0x04,0xAC,0x56,0xA0,0xAB,
	0x52,0xDE,0xCE,0xDD,0x2C,0x28,0x77,0x03
};
__fips_constseg
static const unsigned char rsa_test_2048_q[] = {
	0xDF,0xB7,0x52,0xB6,0xD7,0xC0,0xE2,0x96,0xE7,0xC9,0xFE,0x5D,
	0x71,0x5A,0xC4,0x40,0x96,0x2F,0xE5,0x87,0xEA,0xF3,0xA5,0x77,
	0x11,0x67,0x3C,0x8D,0x56,0x08,0xA7,0xB5,0x67,0xFA,0x37,0xA8,
	0xB8,0xCF,0x61,0xE8,0x63,0xD8,0x38,0x06,0x21,0x2B,0x92,0x09,
	0xA6,0x39,0x3A,0xEA,0xA8,0xB4,0x45,0x4B,0x36,0x10,0x4C,0xE4,
	0x00,0x66,0x71,0x65,0xF8,0x0B,0x94,0x59,0x4F,0x8C,0xFD,0xD5,
	0x34,0xA2,0xE7,0x62,0x84,0x0A,0xA7,0xBB,0xDB,0xD9,0x8A,0xCD,
	0x05,0xE1,0xCC,0x57,0x7B,0xF1,0xF1,0x1F,0x11,0x9D,0xBA,0x3E,
	0x45,0x18,0x99,0x1B,0x41,0x64,0x43,0xEE,0x97,0x5D,0x77,0x13,
	0x5B,0x74,0x69,0x73,0x87,0x95,0x05,0x07,0xBE,0x45,0x07,0x17,
	0x7E,0x4A,0x69,0x22,0xF3,0xDB,0x05,0x39
};
__fips_constseg
static const unsigned char rsa_test_2048_dmp1[] = {
	0x5E,0xD8,0xDC,0xDA,0x53,0x44,0xC4,0x67,0xE0,0x92,0x51,0x34,
	0xE4,0x83,0xA5,0x4D,0x3E,0xDB,0xA7,0x9B,0x82,0xBB,0x73,0x81,
	0xFC,0xE8,0x77,0x4B,0x15,0xBE,0x17,0x73,0x49,0x9B,0x5C,0x98,
	0xBC,0xBD,0x26,0xEF,0x0C,0xE9,0x2E,0xED,0x19,0x7E,0x86,0x41,
	0x1E,0x9E,0x48,0x81,0xDD,0x2D,0xE4,0x6F,0xC2,0xCD,0xCA,0x93,
	0x9E,0x65,0x7E,0xD5,0xEC,0x73,0xFD,0x15,0x1B,0xA2,0xA0,0x7A,
	0x0F,0x0D,0x6E,0xB4,0x53,0x07,0x90,0x92,0x64,0x3B,0x8B,0xA9,
	0x33,0xB3,0xC5,0x94,0x9B,0x4C,0x5D,0x9C,0x7C,0x46,0xA4,0xA5,
	0x56,0xF4,0xF3,0xF8,0x27,0x0A,0x7B,0x42,0x0D,0x92,0x70,0x47,
	0xE7,0x42,0x51,0xA9,0xC2,0x18,0xB1,0x58,0xB1,0x50,0x91,0xB8,
	0x61,0x41,0xB6,0xA9,0xCE,0xD4,0x7C,0xBB
};
__fips_constseg
static const unsigned char rsa_test_2048_dmq1[] = {
	0x54,0x09,0x1F,0x0F,0x03,0xD8,0xB6,0xC5,0x0C,0xE8,0xB9,0x9E,
	0x0C,0x38,0x96,0x43,0xD4,0xA6,0xC5,0x47,0xDB,0x20,0x0E,0xE5,
	0xBD,0x29,0xD4,0x7B,0x1A,0xF8,0x41,0x57,0x49,0x69,0x9A,0x82,
	0xCC,0x79,0x4A,0x43,0xEB,0x4D,0x8B,0x2D,0xF2,0x43,0xD5,0xA5,
	0xBE,0x44,0xFD,0x36,0xAC,0x8C,0x9B,0x02,0xF7,0x9A,0x03,0xE8,
	0x19,0xA6,0x61,0xAE,0x76,0x10,0x93,0x77,0x41,0x04,0xAB,0x4C,
	0xED,0x6A,0xCC,0x14,0x1B,0x99,0x8D,0x0C,0x6A,0x37,0x3B,0x86,
	0x6C,0x51,0x37,0x5B,0x1D,0x79,0xF2,0xA3,0x43,0x10,0xC6,0xA7,
	0x21,0x79,0x6D,0xF9,0xE9,0x04,0x6A,0xE8,0x32,0xFF,0xAE,0xFD,
	0x1C,0x7B,0x8C,0x29,0x13,0xA3,0x0C,0xB2,0xAD,0xEC,0x6C,0x0F,
	0x8D,0x27,0x12,0x7B,0x48,0xB2,0xDB,0x31
};
__fips_constseg
static const unsigned char rsa_test_2048_iqmp[] = {
	0x8D,0x1B,0x05,0xCA,0x24,0x1F,0x0C,0x53,0x19,0x52,0x74,0x63,
	0x21,0xFA,0x78,0x46,0x79,0xAF,0x5C,0xDE,0x30,0xA4,0x6C,0x20,
	0x38,0xE6,0x97,0x39,0xB8,0x7A,0x70,0x0D,0x8B,0x6C,0x6D,0x13,
	0x74,0xD5,0x1C,0xDE,0xA9,0xF4,0x60,0x37,0xFE,0x68,0x77,0x5E,
	0x0B,0x4E,0x5E,0x03,0x31,0x30,0xDF,0xD6,0xAE,0x85,0xD0,0x81,
	0xBB,0x61,0xC7,0xB1,0x04,0x5A,0xC4,0x6D,0x56,0x1C,0xD9,0x64,
	0xE7,0x85,0x7F,0x88,0x91,0xC9,0x60,0x28,0x05,0xE2,0xC6,0x24,
	0x8F,0xDD,0x61,0x64,0xD8,0x09,0xDE,0x7E,0xD3,0x4A,0x61,0x1A,
	0xD3,0x73,0x58,0x4B,0xD8,0xA0,0x54,0x25,0x48,0x83,0x6F,0x82,
	0x6C,0xAF,0x36,0x51,0x2A,0x5D,0x14,0x2F,0x41,0x25,0x00,0xDD,
	0xF8,0xF3,0x95,0xFE,0x31,0x25,0x50,0x12
};

static int setrsakey(RSA *k)
	{
	fips_load_key_component(k, n, rsa_test_2048);
	fips_load_key_component(k, e, rsa_test_2048);
	fips_load_key_component(k, d, rsa_test_2048);
	fips_load_key_component(k, p, rsa_test_2048);
	fips_load_key_component(k, q, rsa_test_2048);
	fips_load_key_component(k, dmp1, rsa_test_2048);
	fips_load_key_component(k, dmq1, rsa_test_2048);
	fips_load_key_component(k, iqmp, rsa_test_2048);
	return 1;
	err:
	return 0;
	}

/* Known Answer Test (KAT) data for the above RSA private key signing
 * kat_tbs.
 */

__fips_constseg
static const unsigned char kat_tbs[] = "OpenSSL FIPS 140-2 Public Key RSA KAT";

__fips_constseg
static const unsigned char kat_RSA_PSS_SHA256[] = {
	0x51,0x4F,0x0B,0x8A,0xE6,0x7F,0xF0,0x39,0x9B,0x5F,0x21,0x26,
	0x99,0x71,0xDC,0x64,0x5A,0x60,0x9B,0xFB,0xB9,0x48,0xE3,0xD4,
	0xDE,0xAE,0x2D,0x87,0x72,0x14,0x2A,0x01,0x4C,0xC7,0x5C,0x00,
	0x15,0xAE,0x23,0x09,0x5F,0xD5,0xB5,0x6F,0x94,0x59,0x76,0xEA,
	0x8C,0x28,0x90,0xC4,0xCD,0xB9,0xD7,0xB5,0x82,0x9D,0x4E,0x37,
	0xE0,0x79,0x03,0x88,0x9F,0x31,0x71,0x70,0x80,0xD6,0x99,0x49,
	0x20,0x09,0x30,0x64,0x52,0xCD,0x5C,0x10,0x72,0x29,0x4D,0x33,
	0x10,0xF6,0xEB,0xB7,0x27,0x95,0x55,0x48,0xBE,0x5A,0xBE,0xA7,
	0x74,0xCF,0x0E,0x95,0x28,0xF4,0x05,0x98,0x86,0xBA,0x36,0x5C,
	0x91,0x8F,0x5D,0xC1,0xBD,0xBE,0x74,0xD9,0x74,0x7B,0xEC,0xD1,
	0x4E,0x79,0x66,0x14,0x24,0x21,0x27,0x2D,0xCF,0x93,0xC0,0xE1,
	0x92,0x79,0xE0,0x4D,0x65,0xE2,0xA4,0xBA,0x1F,0x96,0x16,0xB1,
	0x90,0xE1,0x50,0xDE,0x2F,0xB0,0x07,0xAF,0x84,0xCC,0x81,0x1C,
	0x42,0xA9,0x1B,0xF6,0x25,0xDF,0x6F,0xEB,0x9A,0xF0,0x93,0xF3,
	0x66,0xE7,0x88,0x7B,0xF9,0xA5,0x92,0xA9,0xD5,0x35,0xAA,0x33,
	0x8F,0xEA,0x68,0xDB,0x82,0xE5,0x69,0xBB,0x95,0x31,0xC3,0x4F,
	0x0A,0x68,0x15,0x8A,0x93,0x91,0xE2,0x3B,0xDC,0xA4,0x94,0x2F,
	0x34,0xBC,0xCE,0xC9,0xA6,0xF0,0x49,0x33,0x5B,0x8F,0xDB,0x60,
	0xE8,0x37,0x8C,0x97,0xF9,0xFB,0x28,0x0A,0xF1,0xAD,0x4D,0x9D,
	0xC0,0x57,0x4D,0xD0,0x26,0x76,0x36,0x21,0x67,0x97,0x73,0xCD,
	0x26,0x3A,0xCD,0x44,0x77,0xF2,0x59,0xBB,0xDF,0x77,0x3B,0x98,
	0xC5,0x57,0xB7,0x5D
};

int FIPS_selftest_rsa()
	{
	fprintf(stdout, "FUNCTION: %s INVOKED\n", __func__);
	int ret = 0;
	RSA *key = NULL;
	EVP_PKEY pk;
	key=FIPS_rsa_new();
	setrsakey(key);
	pk.type = EVP_PKEY_RSA;
	pk.pkey.rsa = key;

	if (!fips_pkey_signature_test(FIPS_TEST_SIGNATURE,
				&pk, kat_tbs, sizeof(kat_tbs) - 1,
				kat_RSA_PSS_SHA256, sizeof(kat_RSA_PSS_SHA256),
				EVP_sha256(), RSA_PKCS1_PSS_PADDING,
				"RSA SHA256 PSS"))
		goto err;

	ret = 1;

	err:
	FIPS_rsa_free(key);
	return ret;
	}

#endif /* def OPENSSL_FIPS */


#include <stdio.h>
#include <iostream>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <exception>


EVP_MD_CTX* signature_context_create(void)
{
    EVP_MD_CTX* md_ctx = EVP_MD_CTX_new();
    EVP_SignInit(md_ctx, EVP_sha256());
    return md_ctx;
}

auto signature_keys_generate(void) -> decltype(EVP_PKEY_new())
{
    EVP_PKEY* evp_key = EVP_PKEY_new();
    EVP_PKEY_CTX* ctx;

    ctx = EVP_PKEY_CTX_new_id(EVP_PKEY_RSA, NULL);

    EVP_PKEY_keygen_init(ctx);
    EVP_PKEY_CTX_set_rsa_keygen_bits(ctx, 2048); // Key length 2048 bits

    EVP_PKEY_keygen(ctx, &evp_key);
    EVP_PKEY_CTX_free(ctx);

    return evp_key;
}

EVP_MD_CTX* signature_verification_context_create(void)
{
    EVP_MD_CTX* md_ctx = EVP_MD_CTX_new();
    EVP_VerifyInit(md_ctx, EVP_sha256());
    return md_ctx;
}
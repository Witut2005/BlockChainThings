
#pragma once

auto signature_keys_generate(void) -> decltype(EVP_PKEY_new());

#define signature_data_update(ctx, data, data_size) EVP_SignUpdate(ctx, data, data_size)
#define signature_data_confirm(ctx, signature, signature_size, private_key) EVP_SignFinal(ctx, signature, signature_size, private_key)
EVP_MD_CTX* signature_context_create(void);

#define signature_verification_data_update(ctx, data, data_size) EVP_VerifyUpdate(ctx, data, data_size)
#define signature_verification_data_confirm(ctx, signature, signature_size, public_key) EVP_VerifyFinal(ctx, signature, signature_size, public_key)
EVP_MD_CTX* signature_verification_context_create(void);
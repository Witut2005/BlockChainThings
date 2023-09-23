
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>

#include <bits/stdc++.h>

#include "./block/block.h"
#include "./blockchain/blockchain.h"

#include "./options/data/handler.h"
#include "./options/blockchain/handler.h"
#include "./options/base_handler/base_option_handler.h"

#include <openssl/x509v3.h> //x509 implementation for compatibility
#include <openssl/bn.h> // 
#include <openssl/asn1.h>
#include <openssl/x509.h> // x509 implementation
#include <openssl/x509_vfy.h> 
#include <openssl/pem.h> // for reading certificates & keys
#include <openssl/bio.h>

#include "./signature/signature.h"

int main(void)
{
    
    // Initialize OpenSSL library
    OpenSSL_add_all_algorithms();

    // Create an EVP_PKEY key pair

    auto evp_key = signature_keys_generate();

    auto signature_ctx = signature_context_create();
    signature_data_update(signature_ctx, "nicho", 5);

    unsigned char signature[EVP_MAX_MD_SIZE];
    unsigned int signature_len = 0;

    if(signature_data_confirm(signature_ctx, signature, &signature_len, evp_key) == 1)
        std::cout << "signature created" << std::endl;

    auto signature_verification_ctx = signature_verification_context_create();
    signature_verification_data_update(signature_verification_ctx, "nicho", 5);

    if(signature_verification_data_confirm(signature_verification_ctx, signature, signature_len, signature_keys_generate()))
        std::cout << "signature ok" << std::endl;
    else
        std::cerr << "serio?" << std::endl;

    while(1);

    std::vector<std::string> Data;

    std::vector<std::pair<std::string, BaseOptionHandler_t<void, std::vector<std::string>&>>> DataOptions = {
        { "data", BaseOptionHandler_t(handlers::print_data) },
        { "word", BaseOptionHandler_t(handlers::new_data_add) }
    };

    std::vector<std::pair<std::string, BaseOptionHandler_t<void, BlockChain_t&>>> BlockChainOptions = {
        { "add", BaseOptionHandler_t(handlers::new_block_add) },
        {"modify", BaseOptionHandler_t(handlers::blockchain_block_modify) },
        {"print_blocks", BaseOptionHandler_t(handlers::blockchain_blocks_print) },
        {"size", BaseOptionHandler_t(handlers::size_print) }
    }; 

    BlockChain_t BlockChain = {
        {0, "fromini", 0, 0}
    };


    handlers::print_all_available_options(DataOptions, BlockChainOptions);

    while(1)
    {
        fmt::print("\nYour option: ");
        std::string option_selected;

        std::getline(std::cin, option_selected);

        for(auto option : DataOptions)
        {
            if(option_selected == option.first)
            {
                option.second(Data);
                goto end; 
            }
        }

        for(auto option : BlockChainOptions)
        {
            if(option_selected == option.first)
            {
                option.second(BlockChain);
                goto end; 
            }
        }

        fmt::print(fg(fmt::color::red), "no such option: {}\n", option_selected);

        end:
        continue;
    }

}
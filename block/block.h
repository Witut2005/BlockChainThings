#include <bits/stdc++.h>

#pragma once
class Block{
    private:
        std::string data; 
        std::size_t previous_block_hash;
        std::size_t block_hash;
        uint32_t logic_puzzle_level;
        uint32_t nonce;
    
    public:

    Block(std::size_t previous_block_hash, std::string data, uint32_t logic_puzzle_level, uint32_t nonce);
    auto data_get(void) -> decltype(this->data) const;
    auto previous_block_hash_get(void) -> decltype(this->previous_block_hash) const;
    auto block_hash_get(void) -> decltype(this->block_hash) const;

    static bool check_logic_puzzle_level_correctness(std::size_t hash, uint32_t logic_puzzle_level);
    static bool check_nonce_correctness(std::size_t hash, uint32_t nonce);

};

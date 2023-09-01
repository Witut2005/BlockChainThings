
#include "./block.h"

Block::Block(std::size_t previous_block_hash, std::string data, uint32_t logic_puzzle_level, uint32_t nonce) : previous_block_hash(previous_block_hash), data(data), logic_puzzle_level(logic_puzzle_level), nonce(nonce)
{
    this->block_hash = std::hash<std::string>()(std::to_string(previous_block_hash) + " " + data + " " + std::to_string(logic_puzzle_level) + " " + std::to_string(nonce));
}

auto Block::data_get(void) -> decltype(this->data) const
{
    return this->data; 
}

auto Block::previous_block_hash_get(void) -> decltype(this->previous_block_hash) const
{
    return this->previous_block_hash;
}

auto Block::block_hash_get(void) -> decltype(this->block_hash) const
{
    return this->block_hash;
}

bool Block::check_logic_puzzle_level_correctness(std::size_t hash, uint32_t logic_puzzle_level)
{
    return std::bitset<sizeof(std::size_t) * 8>(hash & ((1 << logic_puzzle_level) - 1)).none();
}

bool Block::check_nonce_correctness(std::size_t hash, uint32_t nonce)
{
    return std::hash<uint32_t>()(nonce) == hash;
}

auto Block::nonce_get(void) -> decltype(this->nonce) const
{
    return this->nonce;
}

auto Block::logic_puzzle_level_get(void) -> decltype(this->nonce) const
{
    return this->logic_puzzle_level;
}
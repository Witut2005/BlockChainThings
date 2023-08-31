
#include "./block.h"

Block::Block(std::size_t previous_block_hash, std::string data, uint32_t logic_puzzle_level, uint32_t nonce) : previous_block_hash(previous_block_hash), data(data), logic_puzzle_level(logic_puzzle_level), nonce(nonce)
{
    this->block_hash = std::hash<std::string>()(std::to_string(previous_block_hash) + " " + data + " " + std::to_string(this->logic_puzzle_level) + " " + std::to_string(this->nonce));
}

auto Block::data_get(void) -> decltype(this->data)
{
    return this->data; 
}

auto Block::previous_block_hash_get(void) -> decltype(this->previous_block_hash)
{
    return this->previous_block_hash;
}

auto Block::block_hash_get(void) -> decltype(this->block_hash)
{
    return this->block_hash;
}

bool Block::check_logic_puzzle_level_correctness(std::size_t hash, uint32_t logic_puzzle_level)
{
    std::bitset<sizeof(std::size_t)>(hash & ((1 << logic_puzzle_level) - 1)).none();
}
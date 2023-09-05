
#include "./block.h"

Block::Block(std::size_t previous_block_hash, std::string data, uint32_t logic_puzzle_level, uint32_t nonce) : previous_block_hash(previous_block_hash), data(data), logic_puzzle_level(logic_puzzle_level), nonce(nonce)
{
    this->block_hash = std::hash<std::string>()(std::to_string(previous_block_hash) + " " + data + " " + std::to_string(logic_puzzle_level) + " " + std::to_string(nonce));
}

auto Block::data_get(void) const -> decltype(this->data) 
{
    return this->data; 
}

void Block::data_set(const std::string& data)
{
    this->data = data;
}

auto Block::previous_block_hash_get(void) const -> decltype(this->previous_block_hash) 
{
    return this->previous_block_hash;
}

auto Block::block_hash_get(void) const -> decltype(this->block_hash)
{
    return this->block_hash;
}

bool Block::check_logic_puzzle_level_correctness(std::size_t hash, uint32_t logic_puzzle_level)
{
    return std::bitset<sizeof(std::size_t) * 8>(hash & ((1 << logic_puzzle_level) - 1)).none();
}

auto Block::nonce_get(void) const -> decltype(this->nonce) 
{
    return this->nonce;
}

auto Block::logic_puzzle_level_get(void) const -> decltype(this->nonce) 
{
    return this->logic_puzzle_level;
}

auto Block::calculate_block_hash_from_internal_data(void) const -> decltype(this->block_hash) 
{
    return std::hash<std::string>()(std::to_string(this->previous_block_hash) + " " + this->data + " " + std::to_string(this->logic_puzzle_level) + " " + std::to_string(this->nonce));
}

bool Block::is_valid(void) const
{
    return(this->calculate_block_hash_from_internal_data() == this->block_hash) & (this->check_logic_puzzle_level_correctness(this->block_hash, this->logic_puzzle_level));
}
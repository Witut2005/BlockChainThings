
#pragma once

#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include <bits/stdc++.h>

#include "../block/block.h"
#include "../blockchain/blockchain.h"

void new_data_add_handler(std::vector<std::string>& Vec);
void print_data_handler(const std::vector<std::string>& Vec);
void new_block_add(std::vector<Block>& BlockChain);

template<class T, class B>
void print_all_available_options(std::vector<std::pair<std::string, T>> DataOptions, std::vector<std::pair<std::string, B>> BlockChainOptions)
{
    fmt::print(fmt::emphasis::bold, "\nData options\n");
    for(auto option : DataOptions)
    {
        fmt::print("{}\n", option.first);
    }

    fmt::print(fmt::emphasis::bold, "\nBlockChain options\n");
    for(auto option : BlockChainOptions)
    {
        fmt::print("{}\n", option.first);
    }
}

void blockchain_blocks_print(BlockChain_t& BlockChain);
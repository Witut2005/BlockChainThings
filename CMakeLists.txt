cmake_minimum_required(VERSION 3.11)

project(BlockChainThingsProject)

include(FetchContent)

FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG master
)

FetchContent_MakeAvailable(fmt)

add_executable(block_test main.cpp ./blockchain/blockchain.cpp ./block/block.cpp ./options/data/handler.cpp ./options/blockchain/handler.cpp)  # Adding block.cpp
target_link_libraries(block_test PRIVATE fmt::fmt)

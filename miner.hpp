#include <iostream>
#include <string>
#include <vector>
#include "blockchain.hpp"

void miner()
{
  //create a blockchain
  blockChain bChain = blockChain();

  //get the amount of blocks going to be mined and declare variables
  int blockCount;
  std::string blockCountString;
  int index = 1;
  std::string content;

  //get number of blocks to be mined
  std::cout << "Please enter the number of blocks that will be part of this chain: ";
  std::getline(std::cin, blockCountString);
  blockCount = stoi(blockCountString);

  //get data to be added to each block until amount of blocks specified before is reached
  while(index <= blockCount)
  {
    std::cout << "Enter data to go into block " << index << ": ";
    std::getline(std::cin, content);
    std::cout << "Mining block " << index << "..." << std::endl;
    bChain.addBlock(block(index, content));
    index++;
  }

  //get all the blocks from the blockChain
  std::vector<block> blocks = bChain.getVChain();
  //loop through all blocks and cout all their information
  for(block& block : blocks)
  {
    std::cout << "\n";
    std::cout << "Block " << block.getIndex() << ":";
    std::cout << "\n";
    std::cout << "Nonce: " << block.getNonce();
    std::cout << "\n";
    std::cout << "Data: " << block.getData();
    std::cout << "\n";
    std::cout << "Hash: " << block.getHash();
    std::cout << "\n";
  }
}

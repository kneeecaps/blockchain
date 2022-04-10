#include "blockchain.hpp"

//create the constructor
blockChain::blockChain()
{
  //adds the genesis block at index 0, can caus errors if the original block has custom values and nonce
  _vChain.emplace_back(block(0, "Genesis Block"));
  //defines difficulty for mining
  _nDifficulty = 6;
}

//accessor for the whole blockchain
std::vector<block> blockChain::getVChain()
{
  return _vChain;
}

//function to add a block to the blockchain
void blockChain::addBlock(block bNew)
{
  //get previous hash, mine the block and add the block to the chain
  bNew.sPrevHash = _getLastBlock().getHash();
  bNew.mineBlock(_nDifficulty);
  _vChain.push_back(bNew);
}

//Function to get the last block, what did you think??
block blockChain::_getLastBlock() const
{
  return _vChain.back();
}

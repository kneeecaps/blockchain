#include <cstdint>
#include <vector>
#include "block.hpp"

//define the class for the blockchain
class blockChain
{
public:
  //define constructor
  blockChain();

  //define functions to return the vChain and add a new block
  std::vector<block> getVChain();
  void addBlock(block bNew);
private:
  //private variable for the difficulty and the actual chain
  uint32_t _nDifficulty;
  std::vector<block> _vChain;

  //function to find the last block, what did you expect
  block _getLastBlock() const;
};

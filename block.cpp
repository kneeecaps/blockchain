#include "block.hpp"
#include "sha256.hpp"
#include <iostream>
#include <sstream>

//Constructor, takes index and data and sets the variables to that
block::block(uint32_t nIndexIn, const std::string &sDataIn) : _nIndex(nIndexIn), _sData(sDataIn)
{
  //This nonce is just so there is a default one for the original block, it probably won't be used for any other blocks
  _nNonce = -1;
}

//These functions are just to retrieve all the data
int64_t block::getIndex()
{
  return _nIndex;
}
int64_t block::getNonce()
{
  return _nNonce;
}
std::string block::getData()
{
  return _sData;
}
std::string block::getHash()
{
  return _sHash;
}

//function for mining a block
void block::mineBlock(uint32_t nDifficulty)
{
  //make an array with the size of the difficulty + 1
  char *cstr = new char[nDifficulty + 1];
  //loop through the array changing all the characters to 0s
  for (uint32_t i = 0; i < nDifficulty; ++i)
  {
    cstr[i] = '0';
  }
  //add a terminating character to the end
  cstr[nDifficulty] = '\0';

  //switch it to a string
  std::string str(cstr);

  //loop through all the numbers until you find a nonce that meets the required difficulty
  do
  {
    _nNonce++;
    _sHash = _calculateHash();
  } while(_sHash.substr(0, nDifficulty) != str);

  //when the block is mined, notify the user
  std::cout << "Block mined: " << _sHash << std::endl;
}

//make a function to calculate the hash
inline std::string block::_calculateHash() const
{
  std::stringstream ss;
  //add all the required information into a stringstream
  ss << _nIndex << _sData << _nNonce << sPrevHash;

  //calculate hash with that information
  return sha256(ss.str());
}

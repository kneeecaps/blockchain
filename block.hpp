#include <string>

//create the class "block"
//this class has all the information going into the individual blocks as well as the functions to get this information
class block
{
public:
  //create public variable for the previous hash
  std::string sPrevHash;

  //create the constructor definition
  block(uint32_t nIndexIn, const std::string &sDataIn);

  //define functions used to retrieve values
  int64_t getIndex();
  int64_t getNonce();
  std::string getData();
  std::string getHash();

  void mineBlock(uint32_t nDifficulty);
private:
  //define private variables
  uint32_t _nIndex;
  int64_t _nNonce;
  std::string _sData;
  std::string _sHash;

  //define function to find the hash
  std::string _calculateHash() const;
};

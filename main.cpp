#include <iostream>
#include "miner.hpp"

int main()
{
  //Calls miner function, from "miner.hpp"
  miner();
  //this is just to stop the terminal from automatically closing after we get the output from miner
  int stopper;
  std::cin >> stopper;
  return 0;
}

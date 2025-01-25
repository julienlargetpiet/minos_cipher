#include "layer2.h"

int main() {

  std::string input_wrd = "word";
  std::vector<unsigned int> vec = cipherer_minos(input_wrd);
  unsigned int k = vec[0];
  unsigned int n = vec[1];
  unsigned int ciphered_wrd = vec[2];
  std::string out_wrd = decipherer_minos(k, n, ciphered_wrd);
  std::cout << out_wrd << "\n";

  return 0;
};



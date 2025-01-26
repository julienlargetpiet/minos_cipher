#include "layer2.h"

int main() {

  std::string input_snt = "This a sentence! Really cool :) .hgfgfgghf";
  std::vector<unsigned int> vec;
  unsigned int k;
  unsigned int n;
  unsigned int ciphered_val;
  std::string out_snt;

  for (char val : input_snt) {
    vec = cipherer_minos1b(val);
    x1 = vec[0];
    public_info = vec[1];
    x2 = vec[2];
    out_snt.push_back(decipherer_minos1b(x1, public_info, x2));
  };

  std::cout << out_snt << "\n";

  return 0;
};



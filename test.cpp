#include "layer2.h"

int main() {

  std::string input_snt = "This a sentence! Really cool :) .";
  std::vector<unsigned int> vec;
  unsigned int k;
  unsigned int n;
  unsigned int ciphered_val;
  std::string out_snt;

  for (char val : input_snt) {
    vec = cipherer_minos(val);
    k = vec[0];
    n = vec[1];
    ciphered_val = vec[2];
    out_snt.push_back(decipherer_minos(k, n, ciphered_val));
  };

  std::cout << out_snt << "\n";

  return 0;
};



#include "layer2.h"

int main() {
  unsigned int k = 5;
  unsigned int n = 17;
  std::deque<bool> out = int_to_binarydq(126);
  for (int i = 0; i < out.size(); ++i) {
    std::cout << out[i];
  };
  std::cout << "\n";
  
  std::string teste = "bonj";
  std::vector<unsigned int> outv = cipherer_minos(teste);
  unsigned int out2 = outv[2];
  std::cout << out2 << "\n";

  k = outv[0];
  n = outv[1];

  std::cout << "n: " << n << "\n";
  std::cout << "k: " << k << "\n";

  teste = decipherer_minos(k, n, out2);
  std::cout << teste << "\n";
  return 0;
};

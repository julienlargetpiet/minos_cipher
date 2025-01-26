#include "layer2.h"

int main() {

  std::string input_snt = "This a sentence! Really cool :) .hgfgfgghf";
  std::vector<unsigned int> vec;
  unsigned int k;
  unsigned int n;
  unsigned int ciphered_val;
  unsigned int x1;
  unsigned int x2;
  unsigned int public_info;

  // Letter by letter //

  std::string out_snt;

  for (char val : input_snt) {
    vec = cipherer_minos1b(val);
    x1 = vec[0];
    public_info = vec[1];
    x2 = vec[2];
    out_snt.push_back(decipherer_minos1b(x1, public_info, x2));
  };

  std::cout << out_snt << "\n";
  
  // 3 Letters by 3 Letters //

  unsigned int step = 2;

  input_snt = "ThisIsHelloWorld";

  std::string rtn_str = "";
  std::string cur_str;
  
  const unsigned int nref = input_snt.length();
  unsigned int i = 0;
  unsigned int i2;
  while (i < nref) {
    cur_str = "";
    i2 = 0;
    while (i2 < step & i + i2 < nref) {
      cur_str.push_back(input_snt[i + i2]);
      i2 += 1;
    };
    vec = cipherer_minos(cur_str);
    x1 = vec[0];
    public_info = vec[1];
    x2 = vec[2];
    rtn_str += decipherer_minos(x1, public_info, x2);
    i += step;
  };
  std::cout << rtn_str << "\n";
  return 0;
};



#include "layer1.h"

std::vector<unsigned int> cipherer_minos1b(char &x) {
  std::vector<unsigned int> rtn_v = {0, 0, 0};
  unsigned int cur_val = int(x);
  std::deque<bool> cur_dq = int_to_binarydq(cur_val);
  const unsigned int n = cur_dq.size();
  unsigned int cur_k = 0;
  for (unsigned int i = 0; i < n; ++i) {
    if (cur_dq[i] != 0) {
      cur_k += 1;
    };
  };
  rtn_v[0] = cur_k;
  rtn_v[1] = n;
  rtn_v[2] = all_comb_iterdq(cur_dq);
  return rtn_v;
};

char decipherer_minos1b(unsigned int &k, unsigned int &n, unsigned int &x) {
  std::vector<bool> ref_v = bool_gen(k, n, x);
  std::deque<bool> cur_dq;
  unsigned int cur_val;
  for (unsigned int i = 0; i < n; ++i) {
    cur_dq.push_back(ref_v[i]);
  };
  cur_val = binarydq_to_int(cur_dq);
  return char(cur_val);
};


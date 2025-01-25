#include "layer1.h"

std::vector<unsigned int> cipherer_minos(std::string &x) {
  std::deque<bool> cur_dq = {};
  std::deque<bool> final_dq = {};
  const unsigned int n = x.size();
  std::vector<unsigned int> rtn_v = {0, 7 * n, 0};
  unsigned int cur_val;
  unsigned int i2;
  unsigned int cur_k;
  for (unsigned int i = 0; i < n; ++i) {
    cur_val = int(x[i]);
    cur_dq = int_to_binarydq(cur_val);
    cur_k = 0;
    for (i2 = 0; i2 < 7; ++i2) {
      if (cur_dq[i2] == 1) {
        cur_k += 1;
      };
    };
    rtn_v[0] += cur_k;
    final_dq.insert(final_dq.end(), cur_dq.begin(), cur_dq.end());
  };
  rtn_v[2] = all_comb_iterdq(final_dq);
  return rtn_v;
};

std::string decipherer_minos(unsigned int &k, unsigned int &n, unsigned int &x) {
  std::string rtn_str = "";
  std::vector<bool> ref_v = bool_gen(k, n, x);
  std::deque<bool> cur_dq;
  const unsigned int n2 = n / 7;
  unsigned int i2;
  unsigned int cur_val;
  for (int i = 0; i < n2; ++i) {
    cur_dq = {0, 0, 0, 0, 0, 0, 0};
    for (i2 = 0; i2 < 7; ++i2) {
      if (ref_v[i * 7 + i2] != 0) {
        cur_dq[i2] = 1;
      };
    };
    cur_val = binarydq_to_int(cur_dq);
    rtn_str.push_back(char(cur_val));
  };
  return rtn_str;
};

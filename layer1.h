#include "layer0.h"

std::vector<bool> bool_gen(unsigned int &k, unsigned int &n, double seed) {
  std::vector<unsigned int> cur_idx = {};
  std::vector<unsigned int> max_idx = {};
  std::vector<bool> cur_v = {};
  std::vector<bool> ref_v = {};
  unsigned int i = 0;
  const unsigned int ref_k = k - 1;
  int idx = ref_k;
  unsigned int idx_val;
  double cnt = 0;
  double ref_comb_val = Comb(k, n);
  seed = (int)seed % (int)ref_comb_val;
  while (i < k) {
    max_idx.push_back(n - k + i);
    cur_idx.push_back(i);
    ref_v.push_back(0);
    i += 1;
  };
  while (i < n){
    ref_v.push_back(0);
    i += 1;
  };
  while (1) {
    while (cur_idx[ref_k] != n) {
      cur_v = ref_v;
      for (i = 0; i < k; ++i) {
        cur_v[cur_idx[i]] = 1;
      };
      cnt += 1;
      if (cnt >= seed) {
        return cur_v;
      };
      cur_idx[ref_k] += 1;
    };
    idx = ref_k - 1;
    while (cur_idx[idx] == max_idx[idx] & idx > -1) {
      idx -= 1;
    };
    if (idx < 0) {
      idx = 0;
    };
    idx_val = cur_idx[idx] + 1;
    while (idx < k) {
      cur_idx[idx] = idx_val;
      idx += 1;
      idx_val += 1;
    };
  };
};

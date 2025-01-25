#include <iostream>
#include <vector>
#include <deque>

unsigned int binarydq_to_int(std::deque<bool> &x) {
  unsigned int rtn_int = 0;
  std::deque<bool> ref_dq = {};
  const unsigned int ref_n = x.size() - 1;
  ref_dq.resize(ref_n + 1, 0);
  int i;
  while (ref_dq != x) {
    i = ref_n;
    while (ref_dq[i] == 1) {
      ref_dq[i] = 0;
      i -= 1;
    };
    ref_dq[i] = 1;
    rtn_int += 1;
  };
  return rtn_int;
};

std::deque<bool> int_to_binarydq(unsigned int x) {
  std::deque<bool> rtn_dq = {};
  while (x > 0) {
    if (x % 2 == 0) {
      rtn_dq.push_front(0);
    } else {
      rtn_dq.push_front(1);
    };
    x /= 2;
  };
  return rtn_dq;
};

unsigned int all_comb_iterdq(std::deque<bool> &x) {
  unsigned int n = x.size();
  unsigned int k = 0;
  unsigned int cnt = 0;
  std::deque<unsigned int> cur_idx = {};
  std::deque<unsigned int> max_idx = {};
  std::deque<bool> cur_v = {};
  std::deque<bool> ref_v = {};
  unsigned int i;
  for (i = 0; i < n; ++i) {
    if (x[i] == 1) {
      k += 1;
    };
  };
  const unsigned int ref_k = k - 1;
  int idx = ref_k;
  unsigned int idx_val;
  i = 0;
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
  while (cur_idx[ref_k] < n) {
    while (cur_idx[ref_k] != n) {
      cur_v = ref_v;
      for (i = 0; i < k; ++i) {
        cur_v[cur_idx[i]] = 1;
      };
      cnt += 1;
      if (cur_v == x) {
        return cnt;
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
  return 0;
};

double Comb(double r, double n) {
  if ((long unsigned int)n % 2 == 0) {
    if (r > n / 2) {
      r = n - r;
    };
  } else if ((long unsigned int)n / 2 + 1 < r) {
    r = n - r;
  };
  double rslt = n / r;
  r -= 1;
  n -= 1;
  while (r > 0) {
    rslt *= (n / r);
    r -= 1;
    n -= 1;
  };
  return rslt;
};


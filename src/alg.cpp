// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t max_value = 0;
  while (num != 1) {
    if (num % 2 == 0) {
      num /= 2;
    } else {
      num = 3 * num + 1;
    }
    if (max_value < num) max_value = num;
  }
  return max_value;
}

unsigned int collatzLen(uint64_t num) {
  unsigned int len = 1;
  while (num != 1) {
    if (num % 2 == 0) {
      num /= 2;
    } else {
      num = 3 * num + 1;
    }
    ++len;
  }
  return len;
}

unsigned int seqCollatz(unsigned int* maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  *maxlen = 1;
  unsigned int current_num = 0;
  for (; lbound <= rbound; lbound++) {
    unsigned int current_len = collatzLen(lbound);
    if (*maxlen < current_len) {
      *maxlen = current_len;
      current_num = lbound;
    }
  }
  return current_num;
}

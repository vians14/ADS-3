// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
    unsigned int len = 1;  

    while (num != 1) {
        if (num & 1) {
            num = 3 * num + 1;
        }
        else {
            num /= 2;
        }
        len++;
    }

    return len;
}

unsigned int collatzLen(uint64_t num) {
    uint64_t maxx = num;

    while (num != 1) {
        if (num & 1) {
            num = 3 * num + 1;
        }
        else {
            num /= 2;
        }


        if (num > maxx) {
            maxx = num;
        }
    }
    return maxx;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
    unsigned int max_num = lbound;
    unsigned int max_len = 0;

    for (uint64_t num = lbound; num <= rbound; ++num) {
        unsigned int len = collatzLen(num);

        if (len > max_len) {
            max_len = len;
            max_num = num;
        }
    }

    if (maxlen != nullptr) *maxlen = max_len;
    
    return max_num;
}

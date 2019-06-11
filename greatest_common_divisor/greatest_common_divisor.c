#include "greatest_common_divisor.h"

int greatest_common_divisor(int a, int b) {
    int r = a % b;
    return r == 0 ? b : greatest_common_divisor(b, r);
}

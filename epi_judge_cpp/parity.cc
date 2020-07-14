#include "test_framework/generic_test.h"
// Brute Force Method O(n)
// Just iterate through the bits and flip the parity everytime you find a 1
short ParityBrute(unsigned long long x) {
    bool parity = false;
    while (x) {
        if (x & 1) {
            parity = !parity;
        }
        x >>= 1;
    }
    return parity ? 1 : 0;
}

// Lowest set bit erasing trick O(k) k being the number of bits set to 1 
// Important trick here is x = x & (x - 1) drops the lowest bit set to 1
short Parity(unsigned long long x) {
    short parity = 0;
    while (x) {
        parity ^= 1;
        x &= (x - 1); // Drops the lowest set bit of x e.g. (1001100) after substraction (1001011) after & (1001000)
    }
    return parity;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "parity.cc", "parity.tsv", &Parity,
                         DefaultComparator{}, param_names);
}

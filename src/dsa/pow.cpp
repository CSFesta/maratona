#include "../template.h"

u64 pow(u64 base, u64 expo, u64 mod) {
    u64 result = 1;
    base %= mod;
    for (;expo != 0; expo >>= 1) {
        if (expo & 1) {
            result = (result * base) % mod;
        }
        base = (base*base) % mod;
    }
    return result;
}

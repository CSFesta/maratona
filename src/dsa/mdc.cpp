#include "../template.h"

u64 mdc(u64 a, u64 b) {
    u64 aux;
    while (b != 0) {
        aux = a;
        a = b;
        b = aux % b;
    }  
    return a;
}

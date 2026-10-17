#ifndef MODINV_HPP
#define MODINV_HPP

#include <utility>

namespace dsa{

long long modinv(long long a, long long mod){
    long long b = mod, x = 1, y = 0;
    while(b){
        long long t = a/b;
        a -= t * b; std::swap(a, b);
        x -= t * y; std::swap(x, y);
    }
    x %= mod;
    if(x<0) x += mod;
    return x;
}

}

#endif // MODINV_HPP

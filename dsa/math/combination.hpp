#ifndef COMBINATION_HPP
#define COMBINATION_HPP

#include <vector>

namespace dsa{

class Combination{

    private:
        long long mod;
        std::vector<long long> fac, finv, inv;

    public:
        Combination(long long max_, long long mod_)
            : mod(mod_), fac(max_), finv(max_), inv(max_) {
            fac[0] = 1; fac[1] = 1;
            finv[0] = 1; finv[1] = 1;
            inv[1] = 1;
            for(int i=2; i<max_; i++){
                fac[i] = fac[i-1] * i % mod;
                inv[i] = mod - inv[mod%i] * (mod/i) % mod;
                finv[i] = finv[i-1] * inv[i] % mod;
            }
        }

        long long com(int n, int k) const {
            if(n<k) return 0;
            if(n<0 || k<0) return 0;
            return fac[n] * (finv[k] * finv[n-k] % mod) % mod;
        }

};

}

#endif // COMBINATION_HPP

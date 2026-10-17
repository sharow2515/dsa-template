#ifndef ROLLING_HASH_HPP
#define ROLLING_HASH_HPP

#include <chrono>
#include <random>
#include <string>
#include <vector>

namespace dsa{

class RollingHash{

    private:
        long long n;
        std::vector<long long> hs, pw;
        static constexpr long long mod = (1ll<<61)-1;

        static long long add(long long a, long long b){
            a+=b;
            return a>=mod ? a - mod : a;
        }
        static long long mul(long long a, long long b){
            auto c = (__uint128_t)a*b;
            return add(c>>61, c&mod);
        }
        static long long gen_base(){
            std::mt19937_64 mt(
                std::chrono::steady_clock::now().time_since_epoch().count());
            std::uniform_int_distribution<long long> rand(1, mod-1);
            return rand(mt);
        }
        inline static const long long base = gen_base();
        

    public:
        RollingHash(const std::string& s) : n(s.size()), hs(n+1, 0), pw(n+1, 1) {
            for(int i=0; i<n; i++){
                pw[i+1] = mul(pw[i], base);
                hs[i+1] = add(mul(hs[i], base), s[i]);
            }
        }

        long long get(int l, int r) const {
            return add(hs[r], mod - mul(hs[l], pw[r-l]));
        }

};

}

#endif // ROLLING_HASH_HPP

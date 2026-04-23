#ifndef PRIME_ENUMERATION_HPP
#define PRIME_ENUMERATION_HPP

#include <vector>

namespace dsa{

std::vector<int> enumerate_primes(int MAX_N){
    if(MAX_N<2) return {};
    MAX_N++;
    std::vector<bool> is_prime(MAX_N, true);
    std::vector<int> primes;
    is_prime[0] = false; is_prime[1] = false;
    for(long long i=2; i<MAX_N; i++){
        if(!is_prime[i]) continue;
        primes.push_back(i);
        for(long long j=i*i; j<MAX_N; j+=i) is_prime[j] = false;
    }
    return primes;
}

}

#endif // PRIME_ENUMERATION_HPP

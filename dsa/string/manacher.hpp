#ifndef MANACHER_HPP
#define MANACHER_HPP

#include <string>
#include <vector>

namespace dsa{

inline std::vector<long long> manacher(const std::string& s){

    int i = 0, j = 0, n = s.size();
    std::vector<long long> r(n, 0);
    while(i<n){
        while(i-j>=0 && i+j<n && s[i-j]==s[i+j]) j++;
        r[i] = j;
        int k = 1;
        while(i-k>=0 && k+r[i-k]<j) r[i+k] = r[i-k], k++;
        i += k; j -= k;
    }
    return r;

}

}

#endif // MANACHER_HPP

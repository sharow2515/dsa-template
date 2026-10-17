#ifndef Z_ALGORITHM_HPP
#define Z_ALGORITHM_HPP

#include <algorithm>
#include <string>
#include <vector>

namespace dsa{

std::vector<int> z_algorithm(const std::string& s){

    int c = 0, n = s.size();
    std::vector<int> z(n, 0);
    if(n==0) return z;
    for(int i=1; i<n; i++){
        int l = i - c;
        if(i+z[l]<c+z[c]) z[i] = z[l];
        else{
            int j = std::max(0, c+z[c]-i);
            while(i+j<n && s[j]==s[i+j]) j++;
            z[i] = j; c = i;
        }
    }
    z[0] = n;
    return z;

}

}

#endif // Z_ALGORITHM_HPP

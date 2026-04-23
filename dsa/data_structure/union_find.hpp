#ifndef UNION_FIND_HPP
#define UNION_FIND_HPP

#include <vector>

namespace dsa{

struct UnionFind {

    std::vector<int> parents; // parents[i] := 頂点iのroot
    std::vector<int> sizes; // sizes[i] := 頂点iが属するグループの要素数

    UnionFind(int n){
        parents = std::vector<int>(n);
        for(int i=0; i<n; i++) parents[i] = i;
        sizes = std::vector<int>(n, 1);
    }

    // 頂点iのrootを返す
    int find(int i){
        if(parents[i]==i) return i; // 自身のroot == iのとき自分がroot
        return (parents[i] = find(parents[i])); // 経路圧縮
    }

    // aが所属するグループとbが所属するグループを統合
    void merge(int a, int b){
        a = find(a);
        b = find(b);
        if(a!=b){
            sizes[a] += sizes[b];
            parents[b] = a;
        }
    }

    // aとbが同じグループに属するか
    bool connected(int a, int b){
        return (find(a)==find(b));
    }

    // iが属するグループの要素数
    int size(int i){
        return (int)sizes[find(i)];
    }

};

}

#endif // UNION_FIND_HPP

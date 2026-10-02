#ifndef TRIE_HPP
#define TRIE_HPP

#include <vector>
#include <string>
#include <cassert>

namespace dsa{

// SIGMA := 文字の種類数, MARGIN := 最小の文字 (文字 c は添え字 c - MARGIN に対応)
template <int SIGMA = 26, int MARGIN = 'a'>
class Trie{

    private:
        
        struct Node{
            int child[SIGMA]; // child[c] := 文字cで遷移する子の頂点番号 (存在しない場合は -1)
            long long pass; // この頂点を通る文字列の個数
            long long end; // この頂点で終わる文字列の個数
            Node(){
                for(int c=0; c<SIGMA; c++) child[c] = -1;
                pass = 0;
                end = 0;
            }
        };

        std::vector<Node> nodes;

    public:
        Trie(){
            nodes.push_back(Node());
        }

        // 文字列sをk個追加し終点の頂点番号を返す
        template <typename S>
        int insert(const S& s, long long k=1){
            int v = 0;
            nodes[v].pass += k;
            for(auto ch: s){
                int c = ch - MARGIN;
                if(nodes[v].child[c] == -1){
                    nodes[v].child[c] = nodes.size();
                    nodes.push_back(Node());
                }
                v = nodes[v].child[c];
                nodes[v].pass += k;
            }
            nodes[v].end += k;
            return v;
        }

        // 文字列sをk個削除する k個以上なければ何もせずfalseを返す
        template <typename S>
        bool erase(const S& s, long long k = 1){
            if(count(s) < k) return false;
            int v = 0;
            nodes[v].pass -= k;
            for(auto ch: s){
                v = nodes[v].child[ch - MARGIN];
                nodes[v].pass -= k;
            }
            nodes[v].end -= k;
            return true;
        }

        // 頂点vから文字chで遷移した先の頂点番号(なければ -1)
        int next(int v, int ch){
            if(v==-1) return -1;
            return nodes[v].child[ch - MARGIN];
        }

        // 頂点 v を通る文字列の個数
        long long pass_count(int v){
            return nodes[v].pass;
        }

        // 頂点 v で終わる文字列の個数
        long long end_count(int v){
            return nodes[v].end;
        }

        // 文字列sに対応する頂点番号 (なければ-1)
        template <typename S>
        int find(const S& s){
            int v = 0;
            for(auto ch: s){
                v = next(v, ch);
                if(v==-1) return -1;
            }
            return v;
        }

        // 文字列sの個数
        template <typename S>
        long long count(const S& s){
            int v = find(s);
            return (v == -1 ? 0 : nodes[v].end);
        }

        // sを接頭辞に持つ文字列の個数
        template <typename S>
        long long count_prefix(const S& s){
            int v = find(s);
            return (v == -1 ? 0 : nodes[v].pass);
        }

        // 辞書順でsより小さい文字列の個数
        template <typename S>
        long long count_less(const S& s){
            long long res = 0;
            int v = 0;
            for(auto ch: s){
                int c = ch - MARGIN;
                res += nodes[v].end;
                for(int d=0; d<c; d++){
                    int u = nodes[v].child[d];
                    if(u!=-1) res += nodes[u].pass;
                }
                v = nodes[v].child[c];
                if(v==-1) return res;
            }
            return res;
        }

        // 辞書順でs以下の文字列の個数
        template <typename S>
        long long count_less_equal(const S& s){
            return count_less(s) + count(s);
        }

        // 辞書順でk番目(0-indexed)の文字列
        template <typename S = std::string>
        S kth(long long k){
            assert(0<=k && k<size());
            S res;
            int v = 0;
            while(true){
                if(k < nodes[v].end) return res;
                k -= nodes[v].end;
                for(int c=0; c<SIGMA; c++){
                    int u = nodes[v].child[c];
                    if(u==-1) continue;
                    if(k < nodes[u].pass){
                        res.push_back(c + MARGIN);
                        v = u;
                        break;
                    }
                    k -= nodes[u].pass;
                }
            }
        }

        // 追加されている文字列の総数
        long long size(){
            return nodes[0].pass;
        }

};

}

#endif // TRIE_HPP
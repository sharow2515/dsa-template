#ifndef SCC_HPP
#define SCC_HPP

#include <vector>

namespace dsa{

class SCC{

    private:
        using Graph = std::vector<std::vector<int>>;
        int n;
        Graph g, rg;

        void dfs(int v, const Graph& graph, std::vector<bool>& seen, std::vector<int>& out) const {
            seen[v] = true;
            for(int nv: graph[v]) if(!seen[nv]) dfs(nv, graph, seen, out);
            out.push_back(v);
        }
    
    public:
        explicit SCC(int n_) : n(n_), g(n_), rg(n_) {}

        void add_edge(int from, int to){
            g[from].push_back(to);
            rg[to].push_back(from);
        }

        Graph scc() const {
            std::vector<int> order;
            std::vector<bool> seen(n, false);
            for(int i=0; i<n; i++) if(!seen[i]) dfs(i, g, seen, order);

            Graph res;
            seen.assign(n, false);
            for(int i=n-1; i>=0; i--){
                if(seen[order[i]]) continue;
                res.emplace_back();
                dfs(order[i], rg, seen, res.back());
            }
            return res;
        }

};

}

#endif // SCC_HPP

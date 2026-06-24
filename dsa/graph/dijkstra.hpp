#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include <vector>
#include <queue>
#include <limits>
#include <utility>

namespace dsa{

template <typename T>
class Dijkstra{

    private:
        using P = pair<T, int>;    
        struct Edge{
            T cost;
            int to;
        };
        const T INF;
        std::vector<std::vector<Edge>> g;
        int n;

    public:
        Dijkstra(int _n): n(_n), g(_n), INF(std::numeric_limits<T>::max()){}

        void add_edge(int from, int to, T cost){
            g[from].push_back({cost, to});
        }

        std::vector<T> dijkstra(int start){
            std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
            std::vector<T> dist(n, INF);
            dist[start] = 0; pq.push({0, start});
            while(!pq.empty()){
                auto [d, v] = pq.top(); pq.pop();
                if(dist[v] < d) continue;
                for(auto [cost, nv]: g[v]){
                    if(dist[nv] > dist[v] + cost){
                        dist[nv] = dist[v] + cost;
                        pq.push({dist[nv], nv});
                    }
                }
            }
            return dist;
        }
};

}

#endif // DIJKSTRA_HPP

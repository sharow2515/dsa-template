# Dijkstra

## 要約

| 内容 | コード | 計算量 |
| --- | --- | --- |
| 宣言 | `Dijkstra<T> g(V)`| $O(V)$ |
| 辺の追加 | `g.add_edge(from, to, cost)` | $O(1)$ |
| 最短経路の計算 | `g.dijkstra(s)` | $O(E \log V)$ |

ただし、$V$は頂点数、$E$は辺の数。また、`T`はコストの型。


## 使用方法

### 宣言

頂点数`V`のグラフを作成する。`T`はコストの型。

計算量 $O(V)$
```C++
dsa::Dijkstra<T> g(V);
```


### 辺の追加

頂点`from`から頂点`to`へのコストが`cost`となる辺を追加する。

計算量 $O(1)$

```C++
g.add_edge(from, to, cost);
```


### ダイクストラ

始点`s`からそれぞれの頂点への最短距離を計算する。

計算量 $O(E \log V)$

```C++
g.dijkstra(s);
```


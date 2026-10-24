# SCC

## 要約

| 内容 | コード | 計算量 |
| --- | --- | --- |
| 宣言 | `dsa::SCC g(N)`| $O(N)$ |
| 辺の追加 | `g.add_edge(from, to)` | $O(1)$ |
| 強連結成分分解 | `g.scc()` | $O(N + M)$ |

ただし、 $N$ は頂点数、 $M$ は辺の数。


## 使用方法

### 宣言

頂点数`N`のグラフを作成する。

計算量 $O(N)$

```C++
dsa::SCC g(N);
```

### 辺の追加

頂点`from`から頂点`to`への辺を追加する。

計算量 $O(1)$

```C++
g.add_edge(from, to);
```

### 強連結成分分解

互いに行き来できる頂点のグループを計算する。
配列はトポロジカルソート済み。

計算量 $O(N + M)$

```C++
g.scc();
```


## Verify

AtCoder Library Practice Contest - G
- https://atcoder.jp/contests/practice2/submissions/80293876

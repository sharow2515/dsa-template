# UnionFind

## 要約

| 内容 | コード | 計算量 |
| --- | --- | --- |
| 宣言 | `UnionFind uf(N)`| $O(N)$ |
| aの根の取得 | `uf.find(a)` | $O(\alpha(N))$ |
| aとbを統合 | `uf.merge(a, b)` | $O(\alpha(N))$ |
| aとbの統合判定 | `uf.connected(a, b)` | $O(\alpha(N))$ |
| aが属するグループの要素数 | `uf.size(a)` | $O(\alpha(N))$ |

$\alpha(N)$はアッカーマンの逆関数

## 使用方法

### 宣言

頂点数nのUnionFindを作成する

計算量 $O(N)$
```C++
dsa::UnionFind uf(n);
```


### 根の取得

頂点aの根(root)を取得する

計算量 $O(\alpha(N))$

```C++
uf.find(a);
```


### 統合

aとbを統合する

計算量 $O(\alpha(N))$

```C++
uf.merge(a, b);
```


### 統合判定

頂点aと頂点bが同じグループに属するか判定する

計算量 $O(\alpha(N))$

```C++
uf.connected(a, b);
```


### 要素数の取得

頂点aが属しているグループの要素数を取得

計算量 $O(\alpha(N))$

```C++
uf.size(a);
```

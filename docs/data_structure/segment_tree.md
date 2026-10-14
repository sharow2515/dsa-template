# SegmentTree

## 要約

| 内容 | コード | 計算量 |
| --- | --- | --- |
| 宣言(単位元で初期化) | `SegmentTree<S, op, e> seg(N)`| $O(N)$ |
| 宣言(配列から構築) | `SegmentTree<S, op, e> seg(v)`| $O(N)$ |
| 1点更新 | `seg.set(i, x)`| $O(\log N)$ |
| 1点取得 | `seg.get(i)`| $O(1)$ |
| 区間クエリ | `seg.prod(l, r)`| $O(\log N)$ |

ただし、$N$ は配列の要素数。

- `S`: 要素の型
- `op`: 二項演算 `S op(S, S)` (結合律を満たす)
- `e`: 単位元を返す関数 `S e()`

`op, e` の計算量が $O(f)$ の場合は、1点取得以外の計算量が $O(f)$ 倍となる。

## 使用方法


### 宣言(単位元で初期化)

要素数 $N$ のセグメント木を作成する。

計算量 $O(N)$

```C++
SegmentTree<S, op, e> seg(N);
```

### 宣言(配列から構築)

`std::vector<S> v` の各要素を初期値としてセグメント木を作成する。

計算量 $O(N)$

```C++
std::vector<S> v(N);
SegmentTree<S, op, e> seg(v);
```

### 1点更新

i番目の要素をxにする(0-indexed)。

計算量 $O(\log N)$

```C++
seg.set(i, x);
```

### 1点取得

i番目の要素を取得する(0-indexed)。

計算量 $O(1)$

```C++
seg.get(i);
```

### 区間クエリ

$a_l \cdot a_{l+1} \cdots a_{r-1}$ を `op` で順に結合した結果を返す。
$l = r$ の場合は `e()` を返す。

計算量 $O(\log N)$

```C++
seg.prod(l, r);
```

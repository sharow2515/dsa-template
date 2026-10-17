# RollingHash

## 要約

| 内容 | コード | 計算量 |
| --- | --- | --- |
| 宣言 | `dsa::RollingHash rh(S)` | $O(\lvert S \rvert)$ |
| $[l, r)$ のハッシュ値を取得 | `rh.get(l, r)` | $O(1)$ |


## 使用方法

### 宣言

文字列 `S` のローリングハッシュを構築する。

計算量 $O(\lvert S \rvert)$

```cpp
dsa::RollingHash rh(S);
```

### $[l, r)$ のハッシュ値を取得

計算量 $O(1)$

```cpp
rh.get(l, r);
```


## Verify

ABC430 - E
- https://atcoder.jp/contests/abc430/submissions/80095860

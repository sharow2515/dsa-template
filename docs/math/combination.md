# $\binom{n}{k}$

## 要約

| 内容 | コード | 計算量 |
| --- | --- | --- |
| 宣言 | `dsa::Combination(max_n, p)`| $O(max\_n)$ |
| $\binom{n}{k} \bmod p$ | `com.com(n, k)`| $O(1)$ |

ただし $n < max\_n$ 、 $p$ は素数。 

## 使用方法

### 宣言

計算量 $O(max\_n)$

```cpp
dsa::Combination com(max_n, p);
```

### $\binom{n}{k} \bmod p$ の計算

計算量 $O(1)$

```cpp
com.com(n, k);
```

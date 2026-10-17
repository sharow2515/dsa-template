# $a^{-1} \bmod m$

`modinv(a, m)` で $a^{-1} \bmod m$ を計算する。

($a$ と $m$ は互いに素である必要がある。)

計算量 $O(\log m)$

```cpp
dsa::modinv(a, m);
```

# Z algorithm

## 要約

| 内容 | コード | 計算量 |
| --- | --- | --- |
| 「S」と「Sのi文字目以降」の最長共通接頭辞の長さ | `dsa::z_algorithm(S)`| $O(\lvert S \rvert)$ |


## 使用方法

### 「S」と「Sのi文字目以降」の最長共通接頭辞の長さを求める

計算量 $O(\lvert S \rvert)$

```cpp
dsa::z_algorithm(S);
```


## Verify

ABC141 - E
- https://atcoder.jp/contests/abc141/submissions/80093631

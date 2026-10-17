# Manacher

## 要約

| 内容 | コード | 計算量 |
| --- | --- | --- |
| `i`文字目を中心とする最長の回文半径を記録した配列を計算 | `dsa::manacher(S)` | $O(\lvert S \rvert)$ |


## 使用方法

### `i`文字目を中心とする最長の回文半径を記録した配列を計算

計算量 $O(\lvert S \rvert)$

```cpp
dsa::manacher(S);
```

偶数長の回文を判定する場合はダミーを交互に挿入する。
(例: `abba` → `#a#b#b#a#`)


## Verify

ABC398 - F
- https://atcoder.jp/contests/abc398/submissions/80094263

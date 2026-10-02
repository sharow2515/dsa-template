# Trie

## 要約

| 内容 | コード | 計算量 |
| --- | --- | --- |
| 宣言 | `Trie<SIGMA, MARGIN> trie`| $O(\sigma)$ |
| 文字列の追加 | `trie.insert(s, k)`| $O(\lvert s \rvert)$ |
| 文字列の削除 | `trie.erase(s, k)`| $O(\lvert s \rvert)$ |
| 遷移 | `trie.next(v, ch)`| $O(1)$ |
| 頂点`v`を通る文字列の個数 | `trie.pass_count(v)`| $O(1)$ |
| 頂点`v`で終わる文字列の個数 | `trie.end_count(v)`| $O(1)$ |
| 頂点番号の取得 | `trie.find(s)`| $O(\lvert s \rvert)$ |
| 文字列`s`の個数 | `trie.count(s)`| $O(\lvert s \rvert)$ |
| `s`を接頭辞に持つ文字列の個数 | `trie.count_prefix(s)`| $O(\lvert s \rvert)$ |
| 辞書順で`s`より小さい文字列の個数 | `trie.count_less(s)`| $O(\lvert s \rvert \sigma)$ |
| 辞書順で`s`以下の文字列の個数 | `trie.count_less_equal(s)`| $O(\lvert s \rvert \sigma)$ |
| `k` 番目の文字列 | `trie.kth(k)`| $O(L \sigma)$ |
| 文字列の総数 | `trie.size()`| $O(1)$ |

ただし、 $\sigma$ は文字の種類数 `SIGMA`、 $\lvert s \rvert$ は文字列 `s` の長さ、 $L$ は求める文字列の長さ。個数はすべて重複を含めて数える。

## 使用方法


### 宣言

文字の種類数が `SIGMA`、最小の文字が `MARGIN` の Trie を作成する。
省略時は英小文字(`SIGMA = 26`, `MARGIN = 'a'`)となる。
文字 `ch` は添え字 `ch - MARGIN` に対応する。

計算量 $O(\sigma)$

```C++
dsa::Trie<SIGMA, MARGIN> trie;
```

文字列には `std::string` のほか、`std::vector<int>` なども使用できる。

```C++
dsa::Trie<> trie;     // 英小文字の文字列
dsa::Trie<2, 0> trie; // 0/1からなる std::vector<int>
```


### 文字列の追加

文字列 `s` を `k` 個追加し、 `s` の終端頂点番号を返す。 `k` を省略すると1個追加する。

計算量 $O(\lvert s \rvert)$

```C++
trie.insert(s, k);
```


### 文字列の削除

文字列 `s` を `k` 個削除し、 `true` を返す。 `s` が `k` 個以上存在しない場合は何もせず`false`を返す。 `k` を省略すると1個削除する。

計算量 $O(\lvert s \rvert)$

```C++
trie.erase(s, k);
```


### 遷移

頂点 `v` から文字 `ch` で遷移した先の頂点番号を返す。遷移先が存在しない場合は `-1` を返す。根の頂点番号は `0` 。

計算量 $O(1)$

```C++
trie.next(v, ch);
```


### 頂点 `v` を通る文字列の個数

頂点 `v` を通る文字列の個数を返す。

計算量 $O(1)$

```C++
trie.pass_count(v);
```


### 頂点 `v` で終わる文字列の個数

頂点 `v` で終わる文字列の個数を返す。

計算量 $O(1)$

```C++
trie.end_count(v);
```


### 頂点番号の取得

文字列 `s` に対応する頂点番号を返す。存在しない場合は `-1` を返す。

計算量 $O(\lvert s \rvert)$

```C++
trie.find(s);
```


### 文字列 `s` の個数

文字列 `s` の個数を返す。

計算量 $O(\lvert s \rvert)$

```C++
trie.count(s);
```


### `s`を接頭辞に持つ文字列の個数

`s` を接頭辞に持つ文字列の個数を返す。

計算量 $O(\lvert s \rvert)$

```C++
trie.count_prefix(s);
```


### 辞書順で`s`より小さい文字列の個数

辞書順で `s` より小さい文字列の個数を返す。

計算量 $O(\lvert s \rvert \sigma)$

```C++
trie.count_less(s);
```


### 辞書順で`s`以下の文字列の個数

辞書順で `s` 以下の文字列の個数を返す。

計算量 $O(\lvert s \rvert \sigma)$

```C++
trie.count_less_equal(s);
```


### `k` 番目の文字列

辞書順で `k` 番目(0-indexed) の文字列を返す。 $0 \leq k \lt$ `trie.size()` である必要がある。戻り値の型は `S` で、省略すると `std::string` 。

計算量 $O(L \sigma)$
ただし、 $L$ は `k` 番目の文字列の長さ。

```C++
trie.kth(k);
trie.kth<S>(k);
```


### 文字列の総数

追加されている文字列の総数を返す。

計算量 $O(1)$

```C++
trie.size();
```

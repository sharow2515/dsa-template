# LazySegmentTree

## テンプレート

区間更新時は `apply(l, r, {true, val})` とする。
ただし、 `l, r` は区間、 `val` は更新後の値。

区間和取得時は、 `prod(l, r).sum` とする(ただし `l, r` は区間)。

### 区間加算・区間最大値

```cpp
struct AddMax{
    static constexpr long long INF = 2e18;
    using S = long long;
    using F = long long;
    static S op(const S& a, const S& b){ return std::max(a, b); }
    static S e(){ return -INF; }
    static S mapping(const F& f, const S& x){ return x + f; }
    static F composition(const F& f, const F& g){ return f + g; }
    static F id(){ return 0; }
};
```

**Verify**

AOJ DSL_2_H - RMQ and RAQ
- https://onlinejudge.u-aizu.ac.jp/status/users/sharow/submissions/1/DSL_2_H/judge/11768805/C++

### 区間加算・区間最小値

```cpp
struct AddMin{
    static constexpr long long INF = 2e18;
    using S = long long;
    using F = long long;
    static S op(const S& a, const S& b){ return std::min(a, b); }
    static S e(){ return INF; }
    static S mapping(const F& f, const S& x){ return x + f; }
    static F composition(const F& f, const F& g){ return f + g; }
    static F id(){ return 0; }
};
```

**Verify**

AOJ DSL_2_H - RMQ and RAQ
- https://onlinejudge.u-aizu.ac.jp/status/users/sharow/submissions/1/DSL_2_H/judge/11762733/C++

### 区間加算・区間和

```cpp
struct AddSum{
    struct S{ long long sum; int len; };
    using F = long long;
    static S op(const S& a, const S& b){ return {a.sum + b.sum, a.len + b.len}; }
    static S e(){ return {0, 0}; }
    static S mapping(const F& f, const S& x){ return {x.sum + f * x.len, x.len}; }
    static F composition(const F& f, const F& g){ return f + g; }
    static F id(){ return 0; }
};
```

宣言時は `vector<AddSum::S> init(n, {val, 1});` のようにする(ただし、nは要素数、`val` は初期値)。


**Verify**

AOJ DSL_2_G - RSQ and RAQ
- https://onlinejudge.u-aizu.ac.jp/status/users/sharow/submissions/1/DSL_2_G/judge/11762724/C++

### 区間更新・区間最大値

```cpp
struct UpdateMax{
    static constexpr long long INF = 4e18;
    using S = long long;
    struct F{ bool update; long long value; };
    static S op(const S& a, const S& b){ return std::max(a, b); }
    static S e(){ return -INF; }
    static S mapping(const F& f, const S& x){ return f.update ? f.value : x; }
    static F composition(const F& f, const F& g){ return f.update ? f : g; }
    static F id(){ return {false, 0}; }
};
```

**Verify**

AOJ DSL_2_F - RMQ and RUQ
- https://onlinejudge.u-aizu.ac.jp/status/users/sharow/submissions/1/DSL_2_F/judge/11768794/C++

### 区間更新・区間最小値

```cpp
struct UpdateMin{
    static constexpr long long INF = 4e18;
    using S = long long;
    struct F{ bool update; long long value; };
    static S op(const S& a, const S& b){ return std::min(a, b); }
    static S e(){ return INF; }
    static S mapping(const F& f, const S& x){ return f.update ? f.value : x; }
    static F composition(const F& f, const F& g){ return f.update ? f : g; }
    static F id(){ return {false, 0}; }
};
```

**Verify**

AOJ DSL_2_F - RMQ and RUQ

- https://onlinejudge.u-aizu.ac.jp/status/users/sharow/submissions/1/DSL_2_F/judge/11762700/C++


### 区間更新・区間和

```cpp
struct UpdateSum{
    struct S{ long long sum; int len; };
    struct F{ bool update; long long value; };
    static S op(const S& a, const S& b){ return {a.sum + b.sum, a.len + b.len}; }
    static S e(){ return {0, 0}; }
    static S mapping(const F& f, const S& x){ return f.update ? S{f.value * x.len, x.len} : x; }
    static F composition(const F& f, const F& g){ return f.update ? f : g; }
    static F id(){ return {false, 0}; }
};
```

宣言時は `vector<UpdateSum::S> init(n, {val, 1});` のようにする(ただし、nは要素数、`val` は初期値)。

**Verify**

AOJ DSL_2_I - RSQ and RUQ

- https://onlinejudge.u-aizu.ac.jp/status/users/sharow/submissions/1/DSL_2_I/judge/11762762/C++

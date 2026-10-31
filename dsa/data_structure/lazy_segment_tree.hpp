#ifndef LAZY_SEGMENT_TREE_HPP
#define LAZY_SEGMENT_TREE_HPP

#include <vector>

namespace dsa{

template <class Monoid>
class LazySegmentTree{

    public:
        using S = typename Monoid::S;
        using F = typename Monoid::F;

    private:
        int n, sz, lg;
        std::vector<S> data;
        std::vector<F> lazy;

        void update(int k){ data[k] = Monoid::op(data[k<<1], data[k<<1|1]); }
        
        void all_apply(int k, const F& f){
            data[k] = Monoid::mapping(f, data[k]);
            if(k<sz) lazy[k] = Monoid::composition(f, lazy[k]);
        }

        void push(int k){
            all_apply(k<<1, lazy[k]);
            all_apply(k<<1|1, lazy[k]);
            lazy[k] = Monoid::id();
        }

        void push_path(int l, int r){
            for(int i=lg; i>=1; i--){
                if(((l>>i)<<i) != l) push(l>>i);
                if(((r>>i)<<i) != r) push((r-1)>>i);
            }
        }
    public:
        LazySegmentTree() : LazySegmentTree(0) {}

        explicit LazySegmentTree(int n_) : n(n_) {
            sz = 1, lg = 0;
            while(sz<n) sz<<=1, lg++;
            data.assign(2*sz, Monoid::e());
            lazy.assign(sz, Monoid::id());
        }

        explicit LazySegmentTree(const std::vector<S>& v) : LazySegmentTree((int)v.size()) {
            for(int i=0; i<n; i++) data[sz+i] = v[i];
            for(int i=sz-1; i>=1; i--) update(i);
        }

        void set(int i, const S& x){
            i += sz;
            for(int k=lg; k>=1; k--) push(i>>k);
            data[i] = x;
            for(int k=1; k<=lg; k++) update(i>>k);
        }

        S get(int i){
            i += sz;
            for(int k=lg; k>=1; k--) push(i>>k);
            return data[i];
        }

        S prod(int l, int r){
            if(l==r) return Monoid::e();
            l += sz, r += sz;
            push_path(l, r);
            S sml = Monoid::e(), smr = Monoid::e();
            for(; l<r; l>>=1, r>>=1){
                if(l&1) sml = Monoid::op(sml, data[l++]);
                if(r&1) smr = Monoid::op(data[--r], smr);
            }
            return Monoid::op(sml, smr);
        }

        void apply(int l, int r, const F& f){
            if(l==r) return;
            l += sz, r += sz;
            push_path(l, r);
            int l2 = l, r2 = r;
            for(; l<r; l>>=1, r>>=1){
                if(l&1) all_apply(l++, f);
                if(r&1) all_apply(--r, f);
            }
            l = l2, r = r2;
            for(int i=1; i<=lg; i++){
                if(((l>>i)<<i) != l) update(l>>i);
                if(((r>>i)<<i) != r) update((r-1)>>i);
            }
        }

};
    
}

#endif // LAZY_SEGMENT_TREE_HPP

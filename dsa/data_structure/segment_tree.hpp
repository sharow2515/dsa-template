#ifndef SEGMENT_TREE_HPP
#define SEGMENT_TREE_HPP

#include <vector>

namespace dsa{

template <class S, S (*op)(S, S), S(*e)()>
class SegmentTree{

    private:
        int n, sz;
        std::vector<S> data;

    public:
        SegmentTree() : SegmentTree(0) {}

        explicit SegmentTree(int n_) : n(n_) {
            sz = 1;
            while(sz<n) sz <<= 1;
            data.assign(2*sz, e());
        }

        explicit SegmentTree(const std::vector<S>& v) : SegmentTree((int)v.size()) {
            for(int i=0; i<n; i++) data[sz+i] = v[i];
            for(int i=sz-1; i>=1; i--) data[i] = op(data[i<<1], data[i<<1|1]);
        }

        void set(int i, S x){
            i += sz;
            data[i] = x;
            for(i>>=1; i>=1; i>>=1) data[i] = op(data[i<<1], data[i<<1|1]);
        }

        S get(int i) const { return data[i + sz]; }

        S prod(int l, int r) const {
            S sml = e(), smr = e();
            for(l+=sz, r+=sz; l<r; l>>=1, r>>=1){
                if(l&1) sml = op(sml, data[l++]);
                if(r&1) smr = op(data[--r], smr);
            }
            return op(sml, smr);
        }

};

}

#endif // SEGMENT_TREE_HPP
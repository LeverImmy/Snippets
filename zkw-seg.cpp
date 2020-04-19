struct ZKW {
    static const int MS = N;
    int m;
    LL dat[MS << 2], add[MS << 2];
    void maintain(int x) {
        dat[x] = dat[x << 1] + dat[x << 1 | 1];
    }
    void build(int x) {
        for(m = 1; m < x; m <<= 1);
        for(int i = m + 1; i <= m + x; ++i) dat[i] = a[i - m];
        for(int i = m; i >= 1; --i) maintain(i);
    }
    void modify(int l, int r, int v) {
        int tl = 0, tr = 0, tn = 1;
        for(l = l + m - 1, r = r + m + 1; l ^ r ^ 1; l >>= 1, r >>= 1, tn <<= 1) {
            dat[l] += 1LL * v * tl, dat[r] += 1LL * v * tr;
            if(~l & 1) add[l ^ 1] += v, dat[l ^ 1] += 1LL * v * tn, tl += tn;
            if(r & 1) add[r ^ 1] += v,  dat[r ^ 1] += 1LL * v * tn, tr += tn;
        }
        for(; l; l >>= 1, r >>= 1)
            dat[l] += 1LL * v * tl, dat[r] += 1LL * v * tr;
    }
    LL query(int l, int r) {
        int tl = 0, tr = 0, tn = 1;
        LL res = 0;
        for(l = l + m - 1, r = r + m + 1; l ^ r ^ 1; l >>= 1, r >>= 1, tn <<= 1) {
            if(add[l]) res += 1LL * add[l] * tl;
            if(add[r]) res += 1LL * add[r] * tr;
            if(~l & 1) res += dat[l ^ 1], tl += tn;
            if(r & 1) res += dat[r ^ 1], tr += tn;
        }
        for(; l; l >>= 1, r >>= 1)
            res += 1LL * add[l] * tl, res += 1LL * add[r] * tr;
        return res;
    }
} t;

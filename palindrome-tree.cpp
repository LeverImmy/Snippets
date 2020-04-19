struct EERTREE {
    static const int MS = 1e6 + 5;
    static const int C = 26;

    int n, cntNode, last, s[MS], len[MS], fail[MS], cnt[MS], ch[C][C];

    int make(int l) {
        for(int i = 0; i < C; ++i) ch[cntNode][i] = 0;
        len[cntNode] = l;
        return cntNode++;
    }
    int GetFail(int x) {
        while(s[n] != s[n - len[x] - 1]) x = fail[x];
        return x;
    }
    void extend(int x) {
        s[++n] = x;
        int fa = GetFail(last);
        if(!ch[fa][x]) {
            int now = make(len[fa] + 2);
            fail[now] = ch[ GetFail(fail[fa]) ][x];
            ch[fa][x] = now;
        }
        last = ch[fa][x];
        ++cnt[last];
    }
    void refresh() {
        for(int i = cntNode - 1; i >= 0; --i) cnt[ fail[i] ] += cnt[i];
    }
    void init() {
        n = cntNode = last = 0;
        make(0), make(-1);
        fail[0] = 1, fail[1] = 0;
        s[0] = -1;
    }
    EERTREE() {
        init();
    }
};

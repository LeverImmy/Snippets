struct EDGE {
    int to, _next, wt, ct;
} e[M << 1];

void Add_Edge(int u, int v, int w, int c) {
    e[cnt].to = v, e[cnt].wt = w, e[cnt].ct = c, e[cnt]._next = first[u];
    first[u] = cnt++;
}

void Connect(int u, int v, int w, int c) {
    Add_Edge(u, v, w, c), Add_Edge(v, u, 0, -c);
}

struct ZKW {
    static const int MS = N;
    int dis[MS], vis[MS];
    bool spfa(int st, int ed) {
        memset(vis, 0, sizeof(vis));
        memset(dis, 0x3f, sizeof(dis));
        std::queue <int> q;
        q.push(ed), vis[ed] = 1, dis[ed] = 0;
        while(!q.empty()) {
            int x = q.front(); q.pop(), vis[x] = 0;
            for(int i = first[x]; ~i; i = e[i]._next) {
                int y = e[i].to;
                if(e[i ^ 1].wt && dis[y] > dis[x] - e[i].ct) {
                    dis[y] = dis[x] - e[i].ct;
                    if(!vis[y]) {
                        vis[y] = 1;
                        q.push(y);
                    }
                }
            }
        }
        return dis[st] ^ inf;
    }
    int aug(int x, int in) {
        vis[x] = 1;
        if(x == t) return in;
        int used = 0;
        for(int i = first[x]; ~i; i = e[i]._next) {
            int y = e[i].to;
            if(!vis[y] && e[i].wt && dis[y] == dis[x] - e[i].ct) {
                int cur_flow = aug(y, std::min(in - used, e[i].wt));
                if(cur_flow) {
                    min_cost += cur_flow * e[i].ct;
                    e[i].wt -= cur_flow;
                    e[i ^ 1].wt += cur_flow;
                    used += cur_flow;
                }
                if(used == in) break;
            }
        }
        return used;
    }
    void solve(int st, int ed) {
        memset(vis, 0, sizeof(vis));
        memset(dis, 0, sizeof(dis));
        min_cost = 0;
        while(spfa(st, ed)) {
            vis[ed] = 1;
            while(vis[ed]) {
                memset(vis, 0, sizeof(vis));
                max_flow += aug(st, inf);
            }
        }
    }
} zkw;

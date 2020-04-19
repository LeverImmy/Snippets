int first[N], vis[N], dis[N], pos[N];

struct NODE {
	int id, val;
	NODE(int d = 0, int v = 0) {
		id = d, val = v;
	}
	bool operator<(const NODE &rhs) const {
		if (val == rhs.val) return id > rhs.id;
		return val < rhs.val;
	}
};

struct EDGE {
	int to, _next, wt;
} e[M << 1];

struct POOL {
	static const int MS = N;
	int s[MS], _top_, idx;
	int get() {
		return _top_ ? s[ _top_ --] : ++idx;
	}
	void save(int x) {
		s[ ++_top_ ] = x;
	}
	POOL() {
		_top_ = idx = 0;
	}
};

struct PAIRINGHEAP {
	static const int MS = N;
	int root, siz, fa[MS];
	NODE val[MS];
	std::vector<int> ch[MS];
	std::queue <int> q;
	std::stack <int> stk;
	POOL nodes;
	int join(int u, int v) {
		if(u == v) return u;
		if (val[v] < val[u]) std::swap(u, v);
		fa[v] = u, ch[u].push_back(v);
		return u;
	}
	void push(NODE v) {
		++siz;
		int u = nodes.get();
		val[u] = v;
		pos[ v.id ] = u;
		if (siz == 1) root = u;
		else root = join(u, root);
	}
	void dkey(int x, NODE v) {
		int u = x;
		fa[u] = 0, val[u] = v;
		if (u == root) return;
		else root = join(root, u);
	}
	void pop() {
		--siz;
		while (!q.empty()) q.pop();
		for (int i = ch[root].size() - 1; ~i; --i) {
			int x = ch[root][i];
//			assert(fa[x] == root);
			if (fa[x] != root) continue;
			q.push(x), fa[x] = 0;
		}
		fa[root] = 0, ch[root].clear();
		nodes.save(root), root = 0;
		if (!q.empty()) {
			while (q.size() > 1) {
				int lhs = q.front();
				q.pop();
				int rhs = q.front();
				q.pop();
				stk.push( join(lhs, rhs) );
			}
			if (q.empty()) {
				q.push(stk.top());
				stk.pop();
			}
			int res = q.front();
			while (!stk.empty()) {
				res = join(res, stk.top());
				stk.pop();
			}
			root = res;
		}
	}
	bool empty() {
		return !siz;
	}
	NODE top() {
		return val[root];
	}
	PAIRINGHEAP() {
		root = 0;
	}
};

void Add_Edge(int u, int v, int w) {
	e[cnt].to = v;
	e[cnt].wt = w;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}

PAIRINGHEAP h;

void Dijkstra(int st) {
	memset(pos, 0, sizeof(pos));
	memset(dis, 0x3f, sizeof(dis));
	h.push( NODE(st, 0) ), dis[st] = 0;
	while (!h.empty()) {
		int x = h.top().id;
		h.pop();
		for (int i = first[x], y = e[i].to; ~i; i = e[i]._next, y = e[i].to)
			if (dis[y] > dis[x] + e[i].wt) {
				dis[y] = dis[x] + e[i].wt;
				if (!pos[y]) h.push( NODE(y, dis[y]) );
				else h.dkey( pos[y], NODE(y, dis[y]) );
			}
	}
}

#include <bits/stdc++.h>

namespace GRAPH {
	template <typename _tp> class edges {
		public:
			int to, _next;
			_tp wt;
	};
	template <typename _tp, int V, int E> class graph {
		public:
			edges <_tp> e[E + 1];
			int cntEdge, first[V + 1];
			void add(int u, int v, _tp w) {
				e[cntEdge].to = v;
				e[cntEdge].wt = w;
				e[cntEdge]._next = first[u];
				first[u] = cntEdge++;
			}
			void init(int _n) {
				cntEdge = 0;
				for(int i = 0; i <= _n; ++i)
					first[i] = -1;
			}
	};
}
/*
* usage: graph <int, 100, 100> g;
* 
*/

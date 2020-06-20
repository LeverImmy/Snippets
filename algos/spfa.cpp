#include <bits/stdc++.h>
#include <F:\Projects\Snippets\headers\graph.h>
#include <F:\Projects\Snippets\headers\constants.h>

using namespace GRAPH;
using namespace CONSTANTS;

template <typename _tp, int V, int E> std::vector<_tp> spfa(graph <_tp, V, E> g, int s) {
	std::queue <int> q;
	std::vector <_tp> dis(V + 1, mx_int);
	
	while(!q.empty())
		q.pop();
	
	std::vector <bool> inq(V + 1, 0);
	q.push(s), inq[s] = 1, dis[s] = 0;
	
	while(!q.empty()) {
		int x = q.front();
		q.pop(), inq[x] = 0;
		for(int i = g.first[x]; ~i; i = g.e[i]._next) {
			int y = g.e[i].to;
			if(dis[y] > dis[x] + g.e[i].wt) {
				dis[y] = dis[x] + g.e[i].wt;
				if(!inq[y]) {
					q.push(y);
					inq[y] = 1;
				}
			}
		}
	}
	return dis;
}
/*
* usage: std::vector <int> dist = spfa <int, N, M>(g, s);
* 
*/

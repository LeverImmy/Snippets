#include <bits/stdc++.h>
#include <F:\Projects\Snippets\headers\graph.h>
#include <F:\Projects\Snippets\headers\constants.h>
#include <F:\Projects\Snippets\headers\pair.h>

using namespace GRAPH;
using namespace CONSTANTS;
using namespace PAIR;

template <typename _tp, int V, int E> std::vector<_tp> dijkstra(graph <_tp, V, E> g, int s) {
	std::priority_queue < pair<int, int> > q;
	std::vector <_tp> dis(V + 1, mx_int);
	
	while(!q.empty())
		q.pop();
	
	std::vector <bool> vis(V + 1, 0);
	q.push(pair<int, int>(s, 0)), dis[s] = 0;
	
	while(!q.empty()) {
		int x = q.top().key;
		q.pop();
		if(vis[x])
			continue;
		vis[x] = 1;
		for(int i = g.first[x]; ~i; i = g.e[i]._next) {
			int y = g.e[i].to;
			if(dis[y] > dis[x] + g.e[i].wt) {
				dis[y] = dis[x] + g.e[i].wt;
				if(!vis[y])
					q.push(pair<int, int>(y, -dis[y]));
			}
		}
	}
	return dis;
}
/*
* usage: std::vector <int> dist = dijkstra <int, N, M>(g, s);
* 
*/

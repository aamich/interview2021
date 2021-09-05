// mst, minimum spaning tree
// prim algorithm
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	const int n=4;
	vector<vector<int>> edges{{0,1,1},{0,3,3},{0,2,6},{2,3,2},{1,2,4},{1,3,5}};
	vector<vector<pair<int, int>>> g(n);
	for(auto& e : edges) {
		g[e[0]].emplace_back(e[1],e[2]);
		g[e[1]].emplace_back(e[0],e[2]);
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> q;
	vector<int> seen(n);
	q.emplace(0,0); // w, v
	int cost = 0;
	for(int i=0; i < n; ++i) {
		while(true) {
			int w = q.top().first;
			int v = q.top().second;
			q.pop();
			if(seen[v]++) continue;
			cost += w;
			for(auto& p : g[v]) {
				if(seen[p.first]) continue;
				q.emplace(p.second, p.first);
			}
			break;
		}
	}
	cout << cost << endl;
	return 0;
}

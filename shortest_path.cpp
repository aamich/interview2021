// shortest path
// Dijkstra algorithm
// Floyd-Warshall algorithm
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	vector<int> dijkstra(int n, int s, const vector<vector<int>>& edges) {
		using PII = pair<int, int>;
		vector<vector<PII>> g(n);
		for(auto& e: edges) {
			g[e[0]].emplace_back(e[1], e[2]);
			g[e[1]].emplace_back(e[0], e[2]);
		}

		vector<int> dist(n, INT_MAX/2);
		dist[s] = 0;
		priority_queue<PII, vector<PII>, std::greater<PII>> q;
		q.emplace(0, s); 	// weight, starting vertex
		while(!q.empty()) {
			int d = q.top().first; int u = q.top().second; q.pop();
			if(d > dist[u]) continue;
			for(auto vw : g[u])
				if(dist[vw.first] > dist[u] + vw.second)
					q.emplace(dist[vw.first]=dist[u]+vw.second, vw.first);
		}
		return dist;
	}
};

class Floyd {
public:
	vector<vector<int>> floyd(int n, const vector<vector<int>>& edges) {
		vector<vector<int>> dist(n, vector<int>(n, INT_MAX/2));
		for(auto& e : edges) {
			dist[e[0]][e[1]] = e[2];
			dist[e[1]][e[0]] = e[2];
		}
		for(int i = 0; i < n; ++i)
			dist[i][i] = 0;

		for(int k=0; k < n; ++k)
			for(int i=0; i < n; ++i)
				for(int j = 0; j < n; ++j)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		return dist;
	}
};

int main() {
	const int n=4;
	vector<vector<int>> edges{{0,1,1},{0,3,3},{0,2,6},{2,3,2},{1,2,4},{1,3,5}};
	cout << " Dijkstra:" << endl;
	Solution s;
	auto res = s.dijkstra(n, 0, edges);	// n: total #vertex, s: starting vertex
	for(auto it : res)
		cout << it << " ";
	cout << endl;
	cout << " Floyd" << endl;
	Floyd f;
	auto res2 = f.floyd(n, edges);
	for(auto it : res2)
		for(auto it2 : it)
			cout << it2 << " ";
	cout << endl;
	return 0;
}

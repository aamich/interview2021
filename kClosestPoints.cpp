#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> kClosestPt(vector<vector<int>>& points, int k) {
		vector<pair<int, int>> p;  // distance*distance, point_index
		int n = points.size();
		for(int i=0; i <n; ++i ) {
			int& x = points[i][0];
			int& y = points[i][1];
			p.emplace_back(x*x+y*y, i);
		}
		std::sort(p.begin(), p.end());
		vector<vector<int>> kv;
		for(int i = 0; i<k; ++i)
			kv.emplace_back(points[p[i].second]);
		return kv;
	}

	vector<vector<int>> kClosestPt2(vector<vector<int>>& points, int k) {
		std::sort(points.begin(), points.end(), 
			[&](const vector<int>& a, const vector<int>& b) {
				return a[0]*a[0] + a[1]*a[1] < b[0]*b[0] + b[1]*b[1];
			});
		vector<vector<int>> kv;
		for(int i = 0; i<k; ++i)
			kv.emplace_back(points[i]);
		return kv;
	}
};

class Solution2 {
public:
	vector<pair<int,int>> kClosestPt3(vector<pair<int,int>>& points, int k) {
		std::sort(points.begin(), points.end(), 
			[&](const pair<int,int>& a, const pair<int, int>& b) {
				return a.first*a.first + a.second*a.second < 
				b.first*b.first + b.second*b.second;
			});
		vector<pair<int,int>> kv;
		for(int i = 0; i<k; ++i)
			kv.emplace_back(points[i]);
		return kv;
	}
};


int main() {
	vector<vector<int>> vv{{0,1}, {1,2}, {2,1}, {2,3}, {3, 0}, {4,5}, {1,1}};
	Solution s;
	const auto& res = s.kClosestPt(vv,5);
	std::cout << res.size() << endl;
	for(const auto& it : res)
		cout << "(" << it[0] << " " << it[1] << ") ";
	cout << endl;
	const auto& res2 = s.kClosestPt2(vv,5);
	std::cout << res2.size() << endl;
	for(const auto& it : res2)
		cout << "(" << it[0] << " " << it[1] << ") ";
	cout << endl;
	vector<pair<int,int>> vv2{{0,1}, {1,2}, {2,1}, {2,3}, {3, 0}, {4,5}, {1,1}};

	Solution2 s2;
	const auto& res3 = s2.kClosestPt3(vv2,5);
	std::cout << res3.size() << endl;
	for(const auto& it : res3)
		cout << "(" << it.first << " " << it.second << ") ";
	cout << endl;
}

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
	void permutation(const vector<int>& v, 
		int d, unordered_set<int>& used, vector<int>& tmp) {
		if(d==v.size()) {
			ans.emplace_back(tmp);
			return;
		}
		for(auto i : v) {
			if(used.count(i)) continue;
			tmp.emplace_back(i);
			used.insert(i);
			permutation(v, d+1, used, tmp);
			tmp.pop_back();
			used.erase(i);
		}
	}

	void combination(const vector<int>& v, int n,
		int d, int s, vector<int>& tmp) {
		if(d==n) {
			ans.emplace_back(tmp);
			return;
		}
		for(int i=s; i<v.size(); ++i) {
			tmp.emplace_back(v[i]);
			combination(v, n, d+1, i+1, tmp);
			tmp.pop_back();
		}
	}

	vector<vector<int>> ans;
};

int main() {
	vector<int> v{1,2,3};
	Solution s;
	unordered_set<int> used;
	vector<int> tmp;
	s.permutation(v, 0, used, tmp);
	vector<vector<vector<int>>> res;
	res.emplace_back(s.ans);
	tmp.clear(); s.ans.clear(); 
	s.combination(v, 2, 0, 0, tmp);
	res.emplace_back(s.ans);
	for(auto it : res) {
		for(auto it2 : it) {
			for(auto it3 : it2)
				cout << it3 << " ";
			cout << endl;
		}
		cout << endl;
	}
	cout << endl;
}

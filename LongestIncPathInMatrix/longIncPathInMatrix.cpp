#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int longestIncPath(const vector<vector<int>>& mat) {
		if(mat.empty()) return 0;
		m_=mat.size();
		n_=mat[0].size();
		dp_ = vector<vector<int>>(m_, vector<int>(n_, -1));
		int ans = 0;
		for(int y=0; y < m_; ++y)
			for(int x=0; x < n_; ++x)
				ans = max(ans, dfs(mat, x, y));
		return ans;
	}
private:
	int dfs(const vector<vector<int>>& mat, int x, int y) {
		if(dp_[y][x] != -1) return dp_[y][x];
		static int dirs[] = {0, -1, 0, 1, 0};
		dp_[y][x] = 1;
		for(int i = 0; i < 4; ++i) {
			int tx = x + dirs[i];
			int ty = y + dirs[i+1];
			if(tx < 0 || ty < 0 || tx >= n_ || ty > m_ || mat[ty][tx] < mat[y][x])
				continue;
			dp_[y][x] = max(dp_[y][x], 1+dfs(mat, tx, ty));
		}
		return dp_[y][x];
	}
	int m_;
	int n_;
	vector<vector<int>> dp_;
};

int main() {
	vector<vector<int>> mat = {	{1,2,3},
								{6,5,4},
								{7,8,0}};
	Solution s;	
	cout << s.longestIncPath(mat) << endl;
}

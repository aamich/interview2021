#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxProfit(const vector<int>& prices) {
		int n = prices.size();
		if(n <= 1) 
			return 0;
		vector<int> gains=vector<int>(n-1, 0);
		for(int i=1; i<n ; ++i)
			gains[i-1] = prices[i] - prices[i-1];
		return max(0, maxGain(gains));
	}
private:
	int maxGain(const vector<int>& gains) {
		vector<int> maxProfit= vector<int>(gains.size(), -INT_MAX);
		maxProfit[0] = gains[0];
		for(int i=1; i < gains.size(); ++i) {
			maxProfit[i] = max(maxProfit[i-1]+gains[i], gains[i]);
		}
		return *std::max_element(maxProfit.begin(), maxProfit.end());
	}
};

int main() {
	vector<int> prices = {2, 8, 7, 5, 9, 6, 2, 4};
	Solution s;
	cout << s.maxProfit(prices) << endl;

	prices={9,8,7,6};
	cout << s.maxProfit(prices) << endl;
}

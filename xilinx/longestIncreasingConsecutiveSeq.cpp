// xilinx, 9/24/21
// longest increasing consecutive sequence
// (3 2 5 6 4)
//

#include <vector>
#include <iostream>

using namespace std;

int lis(const vector<int>& v) {
	if(v.empty())
		return 0;
	if(v.size()==1)
		return 1;
	int mc = 1;
	int cnt=1;
	int n = v.size();
	for(int i = 1; i < n; ++i) {
		if(v[i] > v[i-1]) {
			++cnt;
			mc = max(mc, cnt);
		}
		else
			cnt = 1;
	}
	return mc;
}

int main() {
	vector<int> v{3,2,5,6,4};
	cout << lis(v) << endl;
	vector<int> v2{3,2,5,6,7,8,1,2,3,4};
	cout << lis(v2) << endl;
	vector<int> v3{};
	cout << lis(v3) << endl;
	vector<int> v4{3};
	cout << lis(v4) << endl;
}

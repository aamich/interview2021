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
			if (mc < cnt)
				mc = cnt;
		}
		else
			cnt = 1;
	}
	return mc;
}

int main() {
	vector<int> v{3,2,5,6,4};
	cout << lis(v) << endl;
}

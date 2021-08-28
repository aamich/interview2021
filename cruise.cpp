#include <iostream>
#include <vector>
#include <functional>
#include <time.h>

using namespace std;

int main() {
	// 3 events happen at different frequencies, simulate the sequence 
	vector<int> f{1, 3, 6};
	int n = f.size();
	// prefix sum of frequencies
	vector<int> pf{0};
	pf.insert(pf.end(), f.begin(), f.end());
	for (auto i=1; i <= n; ++i)
		pf[i] += pf[i-1];
	// pf = (0, 1, 4, 10)

	// input: random number 0-9
	// return: index of frequencies according to the value of frequencies
	// 0 (or < 1) => 0; 1-3 (or < 4) => 1; 4-9 (or < 9) =>2
	function<int(int)> event = [&](int r) {
		for(auto i = 1; i < pf.size(); ++i)
			if(r < pf[i])
				return i-1;
		return 0;
	};
	srand(time(NULL));
	int cnt0{0}, cnt1{0}, cnt2{0};
	for(int i = 0; i < 10; ++i) {
		int e = event(rand()%pf.back());
		cout << "event " << e << " at " << i/10. << " second." << endl;
		e==0? ++cnt0 : e==1? ++cnt1 : ++cnt2;
	}
	cout << endl;
	cout << "Event 0:" << cnt0 << " Event 1:" << cnt1 << " Event 2:" << cnt2 << endl;
}

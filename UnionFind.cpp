#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

class UnionFind {
public:
	explicit UnionFind(int n): p_(n), r_(n) 
	{ iota(begin(p_), end(p_), 0); }

	int Find(int x) { return x==p_[x]? x : p_[x] = Find(p_[x]); }
	
	bool Union(int x, int y) {
		int rx = Find(x); 
		int ry = Find(y);
		if(rx == ry) return false;
		if(r_[rx] == r_[ry]) {
			p_[rx] = ry;
			++r_[ry];
		}
		else if (r_[rx] > r_[ry]) 
			p_[ry] = rx;
		else
			p_[rx] = ry;
		return true;
	}
	void dbgPrint() {
		for(auto it : p_)
			cout << it << " ";
		cout << endl;
		for(auto it : r_) 
			cout << it << " ";
		cout << endl;
	}
private:
	vector<int> p_;
	vector<int> r_;
};

int main() {
	UnionFind uf(10);
	uf.dbgPrint();
	// union ok
	cout << uf.Union(0,1) << endl;
	uf.dbgPrint();
	// union ok
	cout << uf.Union(1,3) << endl;
	uf.dbgPrint();
	// union fails
	cout << uf.Union(0,3) << endl;
	uf.dbgPrint();
	cout << uf.Union(6,7) << endl;
	uf.dbgPrint();
	cout << uf.Union(7,8) << endl;
	uf.dbgPrint();
	cout << uf.Union(8,9) << endl;
	uf.dbgPrint();	
	// union fails
	cout << uf.Union(6,9) << endl;
	uf.dbgPrint();
	cout << uf.Union(1,9) << endl;
	uf.dbgPrint();
}

#include <iostream>
#include <vector>
#include <functional>

using namespace std;

struct TreeNode {
	TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
	int val;
	TreeNode* left;
	TreeNode* right;
};

class Solution {
public:
	TreeNode* balancedBST(TreeNode* root) {
		vector<int> vals;
		function<void(TreeNode* root)> inorder = [&](TreeNode* root) {
			if(!root)
				return;
			inorder(root->left);
			vals.push_back(root->val);
			inorder(root->right);
		};
		function<TreeNode*(int, int)> buildBST = [&](int l, int r) {
			if(l > r)
				return (TreeNode*)nullptr;
			int m = (l+r)/2;
			auto root = new TreeNode(vals[m]);
			root->left = buildBST(l,m-1);
			root->right = buildBST(m+1, r);
			return root;
		};
		inorder(root);
		return buildBST(0, vals.size()-1);
	}
};

// void inorderTree(TreeNode* root) {
// 	if(!root) return;
// 	inorderTree(root->left);
// 	cout << root->val << " ";
// 	inorderTree(root->right);
// }

int main() {
	function<void(TreeNode*)> inorderTree = [&](TreeNode* root) {
		if(!root) return;
		inorderTree(root->left);
		cout << root->val << " ";
		inorderTree(root->right);
	};
		
	function<void(TreeNode*)> preorderTree = [&](TreeNode* root) {
		if(!root) return;
		cout << root->val << " ";
		preorderTree(root->left);
		preorderTree(root->right);
	};
	function<void(TreeNode*)> postorderTree = [&](TreeNode* root) {
		if(!root) return;
		postorderTree(root->left);
		postorderTree(root->right);
		cout << root->val << " ";
	};
	function<int(TreeNode*)> countNode = [&] (TreeNode* root) {
		if(!root) return 0;
		return 1 + countNode(root->left) + countNode(root->right);
	};

	function<void(TreeNode*, vector<int>&)> findPath = [&] (TreeNode* root, vector<int>& ans) {
		if(!root) return nullptr;
		ans.push_back(root->val);
		if(!root->left && !root->right) {
			for(auto i : ans)
				cout << i << " ";
			cout << endl;
		}

		findPath(root->left, ans);
		findPath(root->right,ans);
		ans.pop_back();
		return nullptr;
	};

	auto root = new TreeNode(0);
	root->right = new TreeNode(1);
	root->right->right = new TreeNode(2);
	root->right->right->right = new TreeNode(3);
	root->right->right->right->right = new TreeNode(4);
	root->right->right->right->right->right = new TreeNode(5);
	root->right->right->right->right->right->right = new TreeNode(6);
	root->right->right->right->right->right->right->right = new TreeNode(7);
	root->right->right->right->right->right->right->right->right = new TreeNode(8);
	root->right->right->right->right->right->right->right->right->right = new TreeNode(9);

	cout << "count: " << countNode(root) << endl;
	
	cout << "Start:" << endl;
	inorderTree(root);
	cout << endl;
	preorderTree(root);
	cout << endl;
	postorderTree(root);
	cout << endl;

	cout << " path : \n";
	vector<int> ans;
	findPath(root, ans);

	cout << "after balancing:" << endl;

	Solution s;
	root = s.balancedBST(root);
	inorderTree(root);
	cout << endl;
	preorderTree(root);
	cout << endl;
	postorderTree(root);
	cout << endl;
	cout << "count: " << countNode(root) << endl;

	cout << " path : \n";
	ans.clear();
	findPath(root, ans);

	delete root;
}

//Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The relative order of the elements may be changed.
/*
Example 1:

Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
Note that the five elements can be returned in any order.
It does not matter what you leave beyond the returned k (hence they are underscores).
*/
#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l=0;
        int r=nums.size()-1;
        while(l<=r) {
            if(nums[l] == val && nums[r]!= val)
                swap(nums[l], nums[r]);
            while(nums[l] != val) ++l;
            while(nums[r] == val) --r;
        }
        return r+1;
    }
};

int main() {
    vector<int> v0{3,2,2,3};
    vector<int> v{0,1,2,2,3,0,4,2};
    vector<int> v1{2,2,2,2,2};
    vector<int> v2{1,3,4,5};
    Solution s;
    for(auto it : {v0, v, v1, v2}) {
        int e = s.removeElement(it, 2);
        cout << "new size: " << e << endl;
        for(auto i : it)
            cout << i << " ";
        cout << endl;
    }
}

/* from peter
[0,1,2,2,3,0,4,2]
l: 0
r: 7
*/

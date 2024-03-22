// 解决问题：给定一个整数类型的数组 nums，请编写一个能够返回数组 “中心索引” 的方法。
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int total = accumulate(nums.begin(), nums.end(), 0); 
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (2*sum + nums[i] == total) 
                return i;
            sum += nums[i];
        }

        return -1; 
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    cout << "The results is : " <<sol.pivotIndex(nums) << endl; 
    system("pause");
    return 0;
}
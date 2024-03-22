// 解决问题：搜索插入位置
// 解决方案一：暴力解法
// 时间复杂度：O(n)
// 空间复杂度：O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= target)
            {
                return i;
            }
        }

        return nums.size();
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    cout << "The insert position is: " << solution.searchInsert(nums, target) << endl;
    system("pause");
    return 0;
}
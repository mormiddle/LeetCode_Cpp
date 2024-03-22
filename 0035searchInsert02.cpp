// 解决问题：搜索插入位置
// 解决方案二：二分查找
// 时间复杂度：O(logn)
// 空间复杂度：O(1)
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) >> 1;
            if (nums[mid] >= target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return left;
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
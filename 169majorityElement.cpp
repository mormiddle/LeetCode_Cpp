// 解决问题：找出数组中出现次数超过一半的元素
// 思路1：使用哈希表记录每个元素出现的次数，找出出现次数最多的元素
// 思路2：先对数组进行排序，然后返回中间的元素
// 思路3：
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> counts;
        int majority = 0, cnt = 0;
        for (int num : nums)
        {
            counts[num]++;
            if (counts[num] > cnt)
            {
                majority = num;
                cnt = counts[num];
            }
        }

        return majority;
    }

    int majorityElement2(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        return nums[n/2];
    }
};

int main()
{
    // Test case
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    Solution solution;
    int majority = solution.majorityElement2(nums);

    cout << "Majority element: " << majority << endl;

    system("pause");
    return 0;
}

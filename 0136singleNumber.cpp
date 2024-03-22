// 解决问题：找出数组中只出现一次的数字
// 思路1：暴力解法，遍历数组，对每一个元素，遍历数组，找出只出现一次的元素
// 时间复杂度：O(n^2) 空间复杂度：O(1)
// 思路2：使用异或运算，遍历数组，对每一个元素进行异或运算，最后的结果就是只出现一次的元素

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (nums[i] == nums[j])
                    count++;
            }

            if (count == 1)
                return nums[i];
        }

        return 0;
    }

    int singleNumber2(vector<int> &nums)
    {
        int ret = 0;
        for(int e : nums)
            ret ^= e;
        return ret;
    }
};

int main()
{
    vector<int> nums = {1, 2, 2, 3, 1};
    Solution obj;
    int result = obj.singleNumber2(nums);
    cout << "The single number is: " << result << endl;
    system("pause");
    return 0;
}

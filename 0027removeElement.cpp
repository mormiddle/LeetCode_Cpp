// 解决问题： https://leetcode-cn.com/problems/remove-element/
// 问题：移除元素
// 解决方法1： 双指针
// 解决方法2： 双指针优化
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0;
        for(int right = 0; right < nums.size(); right++)
        {
            if(nums[right] != val)
            {
                nums[left] = nums[right];
                left++;
            }
        }
        return left;
    }

    int removeElement2(vector<int>& nums, int val) {
        int left = 0, right = nums.size();
        while(left < right)
        {
            if(nums[left] == val)
            {
                nums[left] = nums[right - 1];
                right--;
            }
            else
            {
                left++;
            }

        }
        return left;
    }
};


int main() {
    vector<int> nums = {3,2,2,3};
    int val = 3;

    Solution obj;
    int result = obj.removeElement2(nums, val);

    cout << "Result: " << result << endl;
    for(int i = 0; i < result; i++)
    {
        cout << nums[i] << " ";
    }

    system("pause");
    return 0;
}


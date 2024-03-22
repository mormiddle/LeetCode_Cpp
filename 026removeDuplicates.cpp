// 解决问题：删除排序数组中的重复项
// 解法1：暴力法
// 时间复杂度：O(n)
// 空间复杂度：O(1)
// 解法2：双指针法
// 时间复杂度：O(n)
// 空间复杂度：O(1)
#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates1(std::vector<int> &nums)
{
    vector<int> newNums;
    int lastnum = nums[0];
    newNums.push_back(lastnum);
    int count = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != lastnum)
        {
            lastnum = nums[i];
            newNums.push_back(lastnum);
            count++;
        }
    }
    nums = newNums;
    return count;
}

int removeDuplicates2(std::vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
    {
        return 0;
    }

    int slowp = 1, fastp = 1;
    while ( fastp < n)
    {
        if (nums[slowp-1] != nums[fastp])
        {
            nums[slowp] = nums[fastp];
            slowp++;
        }
        fastp++;
    }
    
    return slowp;
}

int main()
{
    std::vector<int> nums = {1, 1, 2};
    int newSize = removeDuplicates2(nums);

    std::cout << "New size of array: " << newSize << std::endl;
    std::cout << "Updated array: ";
    for (int i = 0; i < newSize; i++)
    {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
    system("pause");
    return 0;
}
// 问题：给定一个整数数组，判断是否存在重复元素。如果存在重复，返回true；否则，返回false。
// 思路： 使用哈希表记录每个元素出现的次数，如果某个元素出现次数大于1，则返回true；否则返回false。

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> counts;
        for(int num : nums)
        {
            counts[num]++;
            if(counts[num] > 1)
                return true;
        }
        return false;

    }
};

int main() {
    // Test case 1
    vector<int> nums1 = {1, 2, 3, 1};
    Solution sol1;
    bool result1 = sol1.containsDuplicate(nums1);
    cout << "Test case 1: " << (result1 ? "Contains duplicate" : "No duplicate") << endl;

    // Test case 2
    vector<int> nums2 = {1, 2, 3, 4};
    Solution sol2;
    bool result2 = sol2.containsDuplicate(nums2);
    cout << "Test case 2: " << (result2 ? "Contains duplicate" : "No duplicate") << endl;

    // Test case 3
    vector<int> nums3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    Solution sol3;
    bool result3 = sol3.containsDuplicate(nums3);
    cout << "Test case 3: " << (result3 ? "Contains duplicate" : "No duplicate") << endl;

    system("pause");
    return 0;
}


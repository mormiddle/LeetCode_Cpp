// 解决问题：合并两个有序数组
// 思路：1. 合并后排序
//      2. 双指针，从后往前合并

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = 0; i < n; i++)
        {
            nums1[i + m] = nums2[i];
        }

        sort(nums1.begin(), nums1.end());
    }

    void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1, p2 = n - 1, p = m + n - 1;
        while( p2 >= 0)
        {
            if( p1 >= 0 && nums1[p1] > nums2[p2])
                nums1[p--] = nums1[p1--];
            else
                nums1[p--] = nums2[p2--];
        }
    }

};

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    Solution solution;
    solution.merge2(nums1, m, nums2, n);

    cout << "Merged array: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}


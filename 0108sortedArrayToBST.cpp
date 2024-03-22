

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
    }
};

int main() {
    // Test case 1
    vector<int> nums1 = {-10, -3, 0, 5, 9};
    Solution obj1;
    TreeNode* result1 = obj1.sortedArrayToBST(nums1);
    // Print the result or perform any other operations

    // Test case 2
    vector<int> nums2 = {1, 3, 5, 7};
    Solution obj2;
    TreeNode* result2 = obj2.sortedArrayToBST(nums2);
    // Print the result or perform any other operations

    // Test case 3
    vector<int> nums3 = {2, 4, 6, 8, 10};
    Solution obj3;
    TreeNode* result3 = obj3.sortedArrayToBST(nums3);
    // Print the result or perform any other operations

    return 0;
}

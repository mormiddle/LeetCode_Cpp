#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(nums[i] == nums[j] && abs(i - j) <= k)
                    return true;
            }
        }
        return false;
    }

        bool containsNearbyDuplicate2(vector<int>& nums, int k) {
  
    }
};

int main() {
    // Test case 1
    vector<int> nums1 = {1,2,3,1};
    int k1 = 3;
    Solution sol1;
    bool result1 = sol1.containsNearbyDuplicate(nums1, k1);
    cout << "Test case 1: " << (result1 ? "Passed" : "Failed") << endl;


    system("pause");
    return 0;
}


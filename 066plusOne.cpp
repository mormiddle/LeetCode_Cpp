// 解决问题： 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
// 解决方法： 从数组的最后一位开始，如果不是9，直接加一返回；如果是9，置为0，继续往前遍历，直到找到不是9的数，加一返回；如果遍历完了，说明是9999...这种情况，直接返回10000...0
// 时间复杂度O(n)，空间复杂度O(1)
// 解决方法2：
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {

        int n = digits.size();
        bool noNine = false;
        for (int i = n - 1; i >= 0; i--)
        {
            if (digits[i] != 9)
            {
                digits[i]++;
                for (int j = i + 1; j < n; j++)
                {
                    digits[j] = 0;
                }

                return digits;
            }
        }

        vector<int> ans(n + 1);
        ans[0] = 1;
        return ans;
    }

};

int main()
{
    vector<int> digits = {4, 3, 2, 1}; // Example input

    Solution obj;
    vector<int> result = obj.plusOne(digits);

    cout << "Result: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}

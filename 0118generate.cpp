//问题： 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行
//方法： 从第二行开始，每一行的第一个和最后一个元素都是1，其他元素是上一行的前一个元素和当前元素之和。
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp(numRows);
        for(int i =0; i < numRows; i++) {
            dp[i].resize(i+1);
            dp[i][0] = dp[i][i] = 1;
            for(int j = 1; j < i; j++) {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
        }
        return dp;
    }
};

int main() {
    Solution solution;
    int numRows = 5; // number of rows for testing
    vector<vector<int>> result = solution.generate(numRows);
    
    // Print the generated triangle
    for (const auto& row : result) {
        for (const auto& num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}
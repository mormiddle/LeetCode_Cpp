//问题： 判断输入的字符串是否是有效的括号组合
//方法：使用栈，遍历字符串，如果是左括号则入栈，如果是右括号则判断栈顶元素是否与之匹配，匹配则出栈，不匹配则返回false。最后判断栈是否为空。
#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if(1 == n%2) {
            return false;
        }
        
        unordered_map<char, char> bracket = {
            {'}', '{'},
            {']', '['},
            {')', '('}
        };

        stack<char> ch;
        for(auto one : s) {
            if(bracket.count(one)){
                if(ch.empty() || ch.top() != bracket[one]) {
                    return false;
                }
                else {
                    ch.pop();
                }
            }
            else {
                ch.push(one);
            }
        }
        return ch.empty();
        
    }
};

int main() {
    Solution solution;
    
    // Test case 1: Valid string
    string s1 = "()";
    bool isValid1 = solution.isValid(s1);
    cout << "Test case 1: " << (isValid1 ? "Valid" : "Invalid") << endl;
    
    // Test case 2: Invalid string
    string s2 = "([)]";
    bool isValid2 = solution.isValid(s2);
    cout << "Test case 2: " << (isValid2 ? "Valid" : "Invalid") << endl;
    
    // Test case 3: Valid string
    string s3 = "{[]}";
    bool isValid3 = solution.isValid(s3);
    cout << "Test case 3: " << (isValid3 ? "Valid" : "Invalid") << endl;
    
    system("pause");
    return 0;
}
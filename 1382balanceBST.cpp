//问题：给定一个二叉搜索树，返回一个平衡二叉搜索树，新生成的树的深度尽可能小。
//方法：首先通过中序遍历得到有序数组，然后通过有序数组构建平衡二叉搜索树。
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
    
    vector<int> inorderSeq;

    void getInorder(TreeNode* o) {
        if(o->left){
            getInorder(o->left);
        }
        inorderSeq.push_back(o->val);
        if(o->right){
            getInorder(o->right);
        }
    }

    TreeNode* build(int l, int r) {
        int mid = (l + r) >> 1;
        TreeNode* o = new TreeNode(inorderSeq[mid]);
        if(l <= mid -1) {
            o->left = build(l, mid - 1);
        }
        if(mid + 1 <= r) {
            o->right = build(mid + 1, r);
        }
        return o;
    }

    TreeNode* balanceBST(TreeNode* root) {
        getInorder(root);
        return build(0, inorderSeq.size() - 1);

    }
};

void printTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    printTree(root->left);
    std::cout << root->val << " ";
    printTree(root->right);
}

void deleteTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}


int main() {
    // Test your balanceBST function here
    // Create a sample tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);

    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Call the balanceBST function
    Solution solution;
    TreeNode* balancedRoot = solution.balanceBST(root);

    // Print the balanced tree
    std::cout << "Balanced Tree:" << std::endl;
    printTree(balancedRoot);

    // Clean up the memory
    deleteTree(root);
    deleteTree(balancedRoot);
    system("pause");
    return 0;
}


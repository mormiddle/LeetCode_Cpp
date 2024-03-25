#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

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
    TreeNode* sortedListToBST(ListNode* head) {
       return build(head, nullptr);
    }

    ListNode* getMid(ListNode* left, ListNode* right) {
        ListNode* fast = left;
        ListNode* slow = left;
        while (fast != right && fast->next != right) {
            fast = fast->next;
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
    }

    TreeNode* build(ListNode* left, ListNode* right) {
        if (left == right) {
            return nullptr;
        }
        ListNode* mid = getMid(left, right);
        TreeNode* root = new TreeNode(mid->val);
        root->left = build(left, mid);
        root->right = build(mid->next, right);
        return root;
    }
};

void printInorder(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    printInorder(node->left);
    cout << node->val << " ";
    printInorder(node->right);
}

int main() {
    // Create a linked list
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Convert the linked list to a binary search tree
    Solution solution;
    TreeNode* root = solution.sortedListToBST(head);

    // Print the inorder traversal of the binary search tree
    printInorder(root);

    system("pause");
    return 0;
}
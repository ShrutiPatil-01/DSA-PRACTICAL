#include <iostream>
using namespace std;

// Definition for a binary tree node
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    // Function to perform Inorder traversal of the binary tree
    void inorderTraversal(TreeNode* root) {
        if (root == nullptr) return;

        inorderTraversal(root->left);
        cout << root->val << " ";
        inorderTraversal(root->right);
    }

    // Function to perform Preorder traversal of the binary tree
    void preorderTraversal(TreeNode* root) {
        if (root == nullptr) return;

        cout << root->val << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }

    // Function to perform Postorder traversal of the binary tree
    void postorderTraversal(TreeNode* root) {
        if (root == nullptr) return;

        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->val << " ";
    }
};

int main() {
    // Create a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    BinaryTree bt;

    cout << "Inorder traversal: ";
    bt.inorderTraversal(root);
    cout << endl;

    cout << "Preorder traversal: ";
    bt.preorderTraversal(root);
    cout << endl;

    cout << "Postorder traversal: ";
    bt.postorderTraversal(root);
    cout << endl;

    return 0;
}


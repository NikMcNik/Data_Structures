#include <iostream>
#include <stack>
#include <queue>

using namespace std;

// Tree Node has data, left pointer, right pointer
struct TreeNode
{
    int datum;
    struct TreeNode *left;
    struct TreeNode *right;
};

// create a new node with given value, left and right pointers are nullptr
struct TreeNode *newTreeNode(int value)
{
    struct TreeNode *node = new struct TreeNode;
    node->datum = value;
    node->left = nullptr;
    node->right = nullptr;
    return (node);
}

// Non-recursive traverse a binary tree
// print out the values by inorder
// it uses stack to store the nodes
void noRecInorder(TreeNode *root)
{
    //     The algorithm of this non-recursive inorder traversal is listed as follows.
    // Create an TreeNode* stack
    stack<TreeNode *> treePointers;
    while (true)
    {
        while (root != nullptr)
        {
            treePointers.push(root);
            root = root->left;
        }
        if (treePointers.empty())
        {
            break;
        }
        root = treePointers.top();
        treePointers.pop();
        // print out the datum of root
        cout << root->datum << endl;
        root = root->right;
    }
}

// level order traversal
// It uses queue to store the values of the next level
void levelOrder(TreeNode *root)
{
    TreeNode *temp = nullptr;
    // The algorithm of level order traversal is listed as follows.
    //  Create a queue
    queue<TreeNode *> treeQ;
    if (root != nullptr)
    {
        treeQ.push(root);
    }
    while (!treeQ.empty())
    {

        temp = treeQ.front();
        treeQ.pop();
        //  Print out datum of temp
        cout << temp->datum << endl;
        // If left pointer of temp is not nullptr, push it to the queue
        if (temp->left != nullptr)
        {
            treeQ.push(temp->left);
        }
        // If right pointer of temp is not nullptr, push it to the queue
        if (temp->right != nullptr)
        {
            treeQ.push(temp->right);
        }
    }
}

// Driver program to test above functions
int main()
{
    /* Constructed binary tree is
        100
      /     \
      9      10
     /  \    /
     9   4  7
     */
    struct TreeNode *root = newTreeNode(100);
    root->left = newTreeNode(9);
    root->right = newTreeNode(10);
    root->left->left = newTreeNode(9);
    root->left->right = newTreeNode(4);
    root->right->left = newTreeNode(7);

    cout << "Inorder traversal result:" << endl;
    ;
    noRecInorder(root);
    cout << "Level traversal result:" << endl;

    levelOrder(root);

    return 0;
}

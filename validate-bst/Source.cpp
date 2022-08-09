#include <climits>
#include <iostream>

using namespace std;
class BST {
public:
    int value;
    BST* left;
    BST* right;

    BST(int val);
    BST& insert(int val);
};

BST::BST(int val) {
    value = val;
    left = nullptr;
    right = nullptr;
}

bool validateBstHelper(BST* tree, int minValue, int maxValue);
bool validateBst(BST* tree);

int main()
{
    BST* root = new BST(10);
    root->left = new BST(5);
    root->left->left = new BST(2);
    root->left->left->left = new BST(1);
    root->left->right = new BST(5);
    root->right = new BST(15);
    root->right->left = new BST(13);
    root->right->left->right = new BST(14);
    root->right->right = new BST(22);

    cout << boolalpha << validateBst(root) << " ";

    return 0;
}

bool validateBst(BST* tree) {
    // Write your code here.
    return validateBstHelper(tree, INT_MIN, INT_MAX);
}

bool validateBstHelper(BST* tree, int minValue, int maxValue)
{
    if (tree->value < minValue || tree->value >= maxValue)
    {
        return false;
    }
    if (tree->left != nullptr && !validateBstHelper(tree->left, minValue, tree->value))
    {
        return false;
    }
    if (tree->right != nullptr && !validateBstHelper(tree->right, tree->value, maxValue))
    {
        return false;
    }
    return true;
}

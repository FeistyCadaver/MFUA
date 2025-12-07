#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <climits>

using std::endl, std::cin, std::cout, std::vector, std::string;

struct TreeNode 
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) 
    {}
};

bool validateBST(TreeNode* node, long min_val, long max_val) 
{
    if (!node) return true;
    
    if (node->val <= min_val || node->val >= max_val) 
    {
        return false;
    }
    
    return validateBST(node->left, min_val, node->val) && validateBST(node->right, node->val, max_val);
}

bool isBST(TreeNode* root) 
{
    return validateBST(root, LONG_MIN, LONG_MAX);
}

TreeNode* buildTree(const vector<int>& data) 
{
    if (data.empty()) return nullptr;
    
    std::unordered_map<int, TreeNode*> nodes;
    TreeNode* root = new TreeNode(data[0]);
    nodes[data[0]] = root;
    
    for (int i = 1; i < data.size(); i += 2) 
    {
        int parent_val = data[i];
        int child_val = data[i + 1];
        
        TreeNode* parent = nodes[parent_val];
        TreeNode* child = new TreeNode(child_val);
        nodes[child_val] = child;
        
        if (!parent->left) 
        {
            parent->left = child;
        } 
        else 
        {
            parent->right = child;
        }
    }
    
    return root;
}

int main() 
{
    string input;
    cout << "Enter tree data: ";
    getline(cin, input);
    
    std::stringstream ss(input);
    vector<int> data;
    int num;
    
    while (ss >> num) 
    {
        data.push_back(num);
    }
    
    TreeNode* root = buildTree(data);
    bool result = isBST(root);
    
    cout << (result ? "true" : "false") << endl;
    
    return 0;
}
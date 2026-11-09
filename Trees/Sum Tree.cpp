/* Definition for Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
  
    pair<bool, int> issumtreefast(Node* root){
        
        // base case 
        if(root == NULL){
            pair<bool,int> p = make_pair(true,0);
            return p;
        }
        
        if(root -> left == NULL && root -> right == NULL){
            pair<bool,int> p = make_pair(true,root->data);
            return p;
        }
        
        pair<bool,int> leftans = issumtreefast(root->left);
        pair<bool,int> rightans = issumtreefast(root->right);
        
        bool left = leftans.first;
        bool right = rightans.first;
        
        bool cond = root -> data == leftans.second + rightans.second;
        
        pair<bool,int> ans;
        
        if(left && right && cond){
            ans.first = true;
            ans.second = 2*root->data;
        }
        else{
            ans.first = false;
        }
        return ans;
    }
    bool isSumTree(Node* node) {
        
        return issumtreefast(node).first;
        
    }
};

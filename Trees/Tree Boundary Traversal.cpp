/* Node Structure
class Node {
  public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
  
    void traverseleft(Node* root, vector<int> &ans){
        
        // base case 
        if( root == NULL || (root -> left == NULL && root -> right == NULL) ){
            return ;
        }
        
        ans.push_back(root->data);
        if(root -> left){
            traverseleft(root->left, ans);
        }
        else{
            traverseleft(root->right, ans);
        }
    }
    
    void traverseleaf(Node* root, vector<int> &ans){
        
        // base case 
        if(root == NULL){
            return;
        }
        
        if(root -> left == NULL && root -> right == NULL){
            ans.push_back(root -> data);
        }
        
        traverseleaf(root->left , ans);
        traverseleaf(root->right, ans);
    }
    
    void traverseright(Node* root, vector<int> &ans){
        
        // base case 
        if( root == NULL || (root-> left == NULL && root -> right == NULL)){
            return;
        }
        
        if(root->right){
            traverseright(root->right, ans);
        }
        else{
            traverseright(root->left, ans);
        }
        
        ans.push_back(root->data);
    }
    
    vector<int> boundaryTraversal(Node *root) {
        
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        
        ans.push_back(root->data);
        
        // traverse left part and store it 
        traverseleft(root->left , ans);
        
        // traverse leaf and store it 
        
        // leaf of left sub-tree
        traverseleaf(root->left, ans);
        // leaf of right sub-tree
        traverseleaf(root->right, ans);
        
        // traverse right part 
        traverseright(root->right , ans);
        
        return ans;
        
    }
};

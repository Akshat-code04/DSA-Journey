/* Structure of binary tree Node 
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  private:
    
    int height(Node* node){
        
        // base case
        if(node == NULL){
            return 0;
        }
        
        int left = height(node -> left);
        int right = height(node -> right);
        
        int ans = max(left,right) + 1;
        return ans;
    }
    
    
  public:
  
    pair<int,int> diameterfast(Node* root){
        // base case 
        if(root == NULL){
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        
        pair<int,int> left = diameterfast(root -> left);
        pair<int,int> right = diameterfast(root -> right);
        
        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second;
        
        
        pair<int,int> ans;
        ans.first = max(op1, max(op2,op3));
        ans.second = max(left.second , right.second) + 1;
        return ans;
        
    }
    int diameter(Node* root) {

        return diameterfast(root).first;
    }
};

//leetcode:426. Convert Binary Search Tree to Sorted Doubly Linked List
//https://articles.leetcode.com/convert-binary-search-tree-bst-to/
//update previous node everytime.
//then the previous node will become the rightmost node of the left tree
//set it as the left node of root.
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) return NULL;
        Node* head = NULL;
        Node* prev= NULL;
        inorder(root, head, prev);
        return head;
        
        
    }
    
    void inorder(Node* root, Node*& head, Node*& prev){
        if (!root) return;
        inorder(root->left, head, prev);
        root->left = prev;
        if(prev) prev->right = root;
        else head = root;
        
        Node* right = root->right;
        head->left = root;
        root->right = head;
        prev = root;
        inorder(right, head, prev);
            
    }
};
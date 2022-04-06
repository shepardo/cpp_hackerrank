// day 22
// https://www.hackerrank.com/challenges/30-binary-search-trees/problem?isFullScreen=true

#include <iostream>
#include <cstddef>

using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};
class Solution{
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            }
            else {
                Node* cur;
                if(data <= root->data){
                    cur = insert(root->left, data);
                    root->left = cur;
                }
                else{
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

		int getHeight2(Node* root){
        //Write your code here
        if (root == nullptr) return 0;
        int left_height = (root->left != nullptr)? getHeight(root->left) + 1 : 0;
        int right_height = (root->right != nullptr)? getHeight(root->right) + 1 : 0;
        if (left_height > right_height) {
            return left_height;
        } else {
            return right_height;
        }
    }

    int getHeight(Node* root){
        //Write your code here

    }

}; //End of Solution

int main() {
    Solution myTree;
    Node* root = NULL;
    int t;
    int data;

    cin >> t;

    while(t-- > 0){
        cin >> data;
        root = myTree.insert(root, data);
    }
    int height = myTree.getHeight(root);
    cout << height;

    return 0;
}

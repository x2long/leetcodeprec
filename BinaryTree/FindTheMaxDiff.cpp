#include <iostream>
using namespace std;
struct Node{
    int val;
    Node *left;
    Node *right
};

int maxNodeNum(Node *root){
     if(root==NULL){
        return -1;
     }
     int max=INT_MIN;
     int min=INT_MAX;
     findMaxMin(root,max,min);
     int result=max-min;
     return result;
}

void findMaxMin(Node *root, int &max,int &min){
    if(root==NULL) {
       return;
    }
    if(root->val<min){
       min=root->Val;
    }
    if(root->val>max){
       max=root->val;    
    }
    
    findMaxMin(root->left,max,min);
    findMaxMin(root->right,max,min);
}

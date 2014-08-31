#include <iostream>
#include "BiTreeHead.h"
using namespace std;
void CreateBiTree(Bitree &Tree);
int main(){
    cout<<"Now create the tree\n";
    BiTreeNode root;
    Bitree proot = &root;
    CreateBiTree(proot);
    return 0;
}
// create the tree
void CreateBiTree(Bitree &Tree){
    int key;
    cin>>key;
    if(0 == key){
        Tree = NULL;
    }else{
        /*
         here two way:
         BiTreeNode node;
         Tree = &node;
         */
        Tree = (Bitree)malloc(sizeof(BiTreeNode));
        Tree->key = key;
        cout<<"create lchild\n";
        CreateBiTree(Tree->lchild);
        cout<<"create rchild\n";
        CreateBiTree(Tree->rchild);
    }
}

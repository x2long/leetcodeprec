#include <iostream>
#include "BiTreeHead.h"
BiTreeNode binarytree_find(BiTreeNode root,int value){
    if(NULL == root){
        return NULL;
    }
    if(root->key == value)
        return root;
    if(value < root->key)
        return binarytree_find(root->lchild,value);
    return binarytree_find(root->rchild,value);
}

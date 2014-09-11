#ifndef BITREEHEAD_H_
#define BITREEHEAD_H_
typedef struct BiTreeNode{
    int key;
    BiTreeNode *lchild,*child;
}BiTreeNode,*Bitree;
typedef struct BiTNodePost{
    Bitree bitree;
    char tag;
}BiTNodePost,*BiTreePost;

#endif

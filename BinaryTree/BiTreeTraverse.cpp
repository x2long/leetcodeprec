#include <iostream>
#include <stack>
#include "BiTreeHead.h"
using namespace std;
void CreateBiTree(Bitree &Tree);
void BiTreeTraverseByMirror(Bitree &head);
void Visit(Bitree pnode);
void BiTreeTraverseByPreRecursiveOrder(Bitree &head);
void BiTreeTraverseByInRecursiveOrder(Bitree &head);
void BiTreeTraverseByPostRecursiveOrder(Bitree &head);
void BiTreeTraverseByPreNoRecOrder(Bitree &head);
void BiTreeTraverseByPostNoRecOrder(Bitree &head);
void BiTreeTraverseByInNoRecOrder(Bitree &head);

int main(){
    cout<<"Now create the tree\n";
    BiTreeNode root;
    Bitree proot = &root;
    CreateBiTree(proot);
    cout<<"by mirror order..\n";
    BiTreeTraverseByMirror(proot);
    
    cout<<"\nby precursive order...\n";
    BiTreeTraverseByPreRecursiveOrder(proot);
    cout<<"\nby pre none recursive order...\n";
    BiTreeTraverseByPreNoRecOrder(proot);
    
    cout<<"\nby incursive order...\n";
    BiTreeTraverseByInRecursiveOrder(proot);
    cout<<"\nby in none recursive order...\n";
    BiTreeTraverseByInNoRecOrder(proot);
    
    cout<<"\nby postcursive order...\n";
    BiTreeTraverseByPostRecursiveOrder(proot);
    cout<<"\nby post none recursive order...\n";
    BiTreeTraverseByPostNoRecOrder(proot);
    
    cout<<endl;
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
        cout<<"create lchild...\n";
        CreateBiTree(Tree->lchild);
        cout<<"create rchild...\n";
        CreateBiTree(Tree->rchild);
    }
}
// visit BiTreeNode
void Visit(Bitree pnode){
    if (0 != pnode->key) {
        printf("%d ",pnode->key);
    }
}
// traverse BiTree by mirror
void BiTreeTraverseByMirror(Bitree &head){
    Bitree woker=head,temp;
    while (woker) {
        if(woker->lchild == NULL){
            Visit(woker);
            woker = woker->rchild;
        }else{
            temp = woker->lchild;
            while (temp->rchild != NULL && temp->rchild != woker) {
                temp = temp->rchild;
            }
            if (temp->rchild == NULL) {
                temp->rchild = woker;
                woker = woker->lchild;
            }else{
                Visit(woker);
                temp->rchild = NULL;
                woker = woker->rchild;
            }
        }
    }
}
// visit by PreRecursive order
void BiTreeTraverseByPreRecursiveOrder(Bitree &head){
    if (head == NULL) {
        return;
    }
    Visit(head);
    BiTreeTraverseByPreRecursiveOrder(head->lchild);
    BiTreeTraverseByPreRecursiveOrder(head->rchild);
}
// visit by PostRecursive order
void BiTreeTraverseByPostRecursiveOrder(Bitree &head){
    if (head != NULL) {
        BiTreeTraverseByPostRecursiveOrder(head->lchild);
        BiTreeTraverseByPostRecursiveOrder(head->rchild);
        Visit(head);
    }
}
// visit by InRecursive order
void BiTreeTraverseByInRecursiveOrder(Bitree &head){
    if (head !=NULL) {
        BiTreeTraverseByInRecursiveOrder(head->lchild);
        Visit(head);
        BiTreeTraverseByInRecursiveOrder(head->rchild);
    }
}
// visit by pre none recursive order
void BiTreeTraverseByPreNoRecOrder(Bitree &head){
    stack<Bitree> stack;
    Bitree pworker = head;
    while(pworker || !stack.empty()){
        if(pworker != NULL){
            stack.push(pworker);
            Visit(pworker);
            pworker = pworker->lchild;
        }
        else{
            pworker = stack.top();
            stack.pop();
            pworker= pworker->rchild;
        }
    }
}
// visit by in none recursvie order
void BiTreeTraverseByInNoRecOrder(Bitree &head){
    stack<Bitree> stack;
    Bitree pworker = head;
    while(pworker || !stack.empty()){
        if(pworker != NULL){
            stack.push(pworker);
            pworker = pworker->lchild;
        }
        else{
            pworker = stack.top();
            Visit(pworker);
            stack.pop();
            pworker= pworker->rchild;
        }
    }
}

// visit by post none recursive order

void BiTreeTraverseByPostNoRecOrder(Bitree &head){
    stack<BiTreePost> stack;
    Bitree pworker = head;
    BiTreePost nodeWrapper;
    while(pworker != NULL || !stack.empty()){
        while(pworker != NULL){
            nodeWrapper = (BiTreePost)malloc(sizeof(BiTNodePost));
            nodeWrapper->bitree = pworker;
            nodeWrapper->tag = 'L';
            stack.push(nodeWrapper);
            pworker = pworker->lchild;
        }
        while(!stack.empty() && (stack.top())->tag == 'R'){
            nodeWrapper = stack.top();
            stack.pop();
            Visit(nodeWrapper->bitree);
        }
        if(!stack.empty()){
            nodeWrapper = stack.top();
            nodeWrapper->tag = 'R';
            pworker = nodeWrapper->bitree;
            pworker = pworker->rchild;
        }
    }
}

/*
 This is for JosefuRing, and more can be found from the Internet.
 */
#include <iostream>
using namespace std;
typedef struct josefuNode{
    int key;
    josefuNode * next;
} josefuNode,*josefuTree;
int getLastIndex(int totalNum, int interval);
int getAndSimulate(josefuTree pHead,int interval);
void printJosefuRing(josefuTree pHead);
void createJosefuRing(josefuTree pHead,int totalNum);
int main(){
    int totalNum,interval;
    cout<< " input the tatal num and the interval:\n";
    cin >> totalNum >> interval;
    cout << "Create the tree...\n";
    josefuTree pHead = (josefuTree)malloc(sizeof(josefuNode));
    createJosefuRing( pHead, totalNum);
    cout << "print the tree...\n";
    printJosefuRing( pHead);
    cout << "show by getLastIndex ..\n";
    cout << "The last is :" << getLastIndex(totalNum,interval);
    cout << "\nshow by getAndSimulate..\n";
    cout << getAndSimulate( pHead,interval)<<" is the last!\n";
    return 0;
}

void createJosefuRing(josefuTree pHead,int totalNum){
    josefuTree pCur = NULL, pPre = NULL;
    int i = 1;
    pPre = pHead;
    pPre->key = i;
    while(--totalNum){
        pCur = (josefuTree)malloc(sizeof(josefuNode));
        pCur->key = ++i;
        pPre->next = pCur;
        pPre = pCur;
    }
    pPre->next = pHead;
}
void printJosefuRing(josefuTree pHead){
    if(pHead == NULL) return;
    printf("%d ,",pHead->key);
    josefuTree pCur = pHead->next;
    while(pCur){
        if(pCur->key == 1) break;
        printf("%d ,",pCur->key);
        pCur = pCur->next;
    }
    printf("\n");
}
int getLastIndex(int totalNum,int interval){
    if(totalNum < 1) return 0;
    int lastIndex = 0;
    int count = 2;
    while(count <= totalNum ){
        lastIndex = (lastIndex + interval ) % count;
        count++;
    }
    return lastIndex + 1;
}
int getAndSimulate(josefuTree pHead,int interval){
    if(pHead == NULL ) return 0;
    int count = 1;
    josefuTree pCur = pHead , pPre = pHead;
    while(pCur != NULL){
        if(count == interval){
            pPre->next = pCur->next;
            printf("The %d is out...\n",pCur->key);
            free(pCur);
            pCur = pPre->next;
            count = 1;
        }
        count ++;
        pPre = pCur;
        pCur = pCur->next;
        if(pCur == pPre) return pCur->key;
    }
    return 0;
}

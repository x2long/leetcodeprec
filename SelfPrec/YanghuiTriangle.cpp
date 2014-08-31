#include <iostream>
using namespace std;
void create_trangle(int array[100][100], int size);
void show(int array[100][100],int size);
int main(){
    int Trangle[100][100]={0};
    int n;
    cout<< "Input the size of the trangle...\n";
    cin>> n;
    cout<<"Generate the trangle array...\n";
    create_trangle(Trangle,n);
    cout<<"Show array..\n";
    show(Trangle,n);
    return 0;
}
void create_trangle(int array[100][100], int size){
    int i,j;
    for(i=0;i<size;i++){
        array[i][0]=array[i][i]=1;
    }
    for(i=2;i<size;i++){
        for(j=1;j<i;j++)
             array[i][j] = array[i-1][j-1]+array[i-1][j];
    }
}
void show(int array[100][100],int size){
    int i,j;
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            if(array[i][j])
                  printf("%d ",array[i][j]);
        }
        cout<<endl;
    }  
}

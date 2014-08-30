#include <iostream>
using namespace std;
void simplest(int n);
int main(){
  cout << "Input the Number:\n";
  int number(0);
  cin >> number;
  cout << "do generate the helix matrix:\n";
  simplest(number);
  return 0;
}
void simplest(int n){
  int matrix[100][100] ={0};
  int i,j;
  for(i=0;i<n;i++)
    for(j = 0;j<n;j++) 
      matrix[i][j] =0;
  int rolls(0),num = 1;
  while(num <= n*n){
    for(i=rolls;i<n-rolls;i++)
       matrix[rolls][i] = num ++;
    for(i=rolls+1;i<n-rolls;i++)
       matrix[i][n-rolls-1] = num ++;
    for(i=n-rolls-2;i>=rolls;i--)
       matrix[n-rolls-1][i]= num ++;
    for(i=n-rolls-2;i>rolls;i--)
       matrix[i][rolls] = num ++;
    rolls ++;
  }
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      cout<<matrix[i][j]<<"  ";
    }
    cout<<endl;
  }
}

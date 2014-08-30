#include <iostream>
int FabiNacci(int n);
int main(){
  using namespace std;
  cout<< "Please input the Number:"<<endl;
  int number(0);
  cin>>number;
  cout << "The result is :\n";
  int result = FabiNacci(number);
  cout<< result << endl;
  return 0;
}
int FabiNacci(int n){
  if(n<=1) return 1;
  return FabiNacci(n-1) + FabiNacci(n-2);
}

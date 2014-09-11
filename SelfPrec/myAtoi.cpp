/*
  This is for atoi
  First is from linux c
  second is mine
  note: using const to protect the source value
*/
#include <iostream>
using namespace std;
long __decl_atol(const char *nptr);
int __decl_atoi(const char *nptr);
int myAtoi(const char *nptr);
int main(){
    cout << "Input the str:\n";
    char str[300];
    cin>>str;
    cout << "value is :" << myAtoi(str) <<endl;
    return 0;
}
long __decl_atol(const char *nptr){
    int c,sign;
    long total=0;
    while( isspace( (int)(unsigned char)*nptr ) ) nptr ++;
    sign = c = (int) (unsigned char) *nptr++;
    if( c == '+' || c == '-')
        c = (int)(unsigned char) *nptr++;
    while(isdigit(c)){
        total = total * 10 + (c - '0');
        c = (int) ( unsigned char) *nptr++;
    }
    if(sign == '-')
        return - total;
    return total;
}
int __decl_atoi(const char *nptr){
    return (int)__decl_atol(nptr);
}
//考虑情况
/*
 view this url:http://www.cnblogs.com/niocai/archive/2012/05/04/2483133.html
 1，前面有空
 2，非法字符
 3，单符号问题
 4，溢出
 */
int myAtoi(const char * str){
    if( str == NULL|| strlen(str)<1) return 0;
    while(*str == ' ') str++;
    int c,sign;
    long total=0;
    sign = c = *str++;
    if(c=='-' || c == '+') c = *str++;
    while(c>='0' && c<= '9'){
        total = total * 10 + c - '0';
        c = *str++;
    }
    if(sign == '-') return (int)(-total);
    return (int)total;
}


#include <iostream>
using namespace std;
void strcpy_0(char *to,char *from);
void strcpy_1(char *to,char *from);
void strcpy_2(char *to,char *from);
void strcpy_3(char *to,char *from);
int main(){
    char from[100];
    cin >> from;
    char toChr = 't';
    char *to = &toChr;
    char *print = to;
    strcpy_0(to,from);
    cout << print <<endl;
    return 0;
}
void strcpy_0(char *to ,char *from){
    while( (*to++ = *from++) != '\0');
}
void strcpy_1(char *to ,const char *from){
    while( (*to ++ = *from ++) != '\0' );
}
void strcpy_2(char *to, const char *from){
    if(from == NULL)
        return;
    while( (*to ++ = *from ++) != '\0' );
}
char * strcpy_3(char *to ,const char * from){
    if(from == NULL) return NULL;
    char * result = to;
    while( (*to ++ = *from ++) != '\0' );
    return result; 
}

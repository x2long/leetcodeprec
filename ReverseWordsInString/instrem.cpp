#include<iostream>
#include<sstream>
using namespace std;
class Solution{
	public:
		void reverseWords(string &s){
			if(!s.size()) return;
			stack<string> st;
			string temp;
			s = "";
			stringstrem str(s);
			while (str >> temp) st.push(temp);
			if(!st.size()) return;
			while(!st.empty()){
			s += st.top();
			s += " ";
			st.pop();
			}
			s = s.substr(0,s.size()-1);
		}
}

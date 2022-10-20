// recursive idea => if we can find the subset of string of length (n-1) then we can generate subset of string length n 
#include<iostream>
#include<string>
using namespace std;

void subset(string &str,string curr,int i) {
    if (i==str.length()) {
        cout<<curr<<endl;
        return ;
    }
    subset(str,curr,i+1);
    subset(str,curr+str[i],i+1);

}


int main() {
    string str;
    cin>>str;
    subset(str,"",0);
    return 0;
}

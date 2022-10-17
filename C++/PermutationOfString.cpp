#include<iostream>
#include<string>
using namespace std;

void per(string &str,int i) {
    if (i == str.length()-1 ) {
        cout<<str<<endl;
        return ;
    }
    for (int j=i;j<str.length();j++) {
        swap(str[i],str[j]);
        per(str,i+1);
        swap(str[j],str[i]);
    }
}

int main() {
    string str;
    cin>>str;
    per(str,0);
    return 0;
}

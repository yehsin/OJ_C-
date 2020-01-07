#include<iostream>
#include<string>
#include<sstream>

using namespace std;

string rle(string str){
    stringstream ssout;
    for(int i = 0;str[i];){
        char s = str[i];
        int num = 1;
        i++;
        while(str[i] == s){
            num++;
            i++;
        }

        ssout<<num<<s;
    }
    return ssout.str();
}

int main(){
    int lines;
    cin>>lines;

    while(lines--){
        string str;
        int k;
        cin>>str;
        cin>>k;

        while(k>0){
            str = rle(str);
            k--;
        }
        cout<<str<<"\n";
    }
}


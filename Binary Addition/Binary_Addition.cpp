#include<iostream>
#include<string>
#include<vector>
using namespace std;


int main(){
    int lines;
    cin>>lines;
    while(lines--){
        int length;
        cin>>length;
        int income = 0;
        string str1;
        string str2;
        cin>>str1;
        cin>>str2;
        for(int i =length-1;i>=0;i--){
            int a = str1[i] - 48;
            int b = str2[i] - 48;
            a = a+b ;
            if(income){
                a++;
                income = 0;
            }
            
            if(a >1){
                a = a-2;
                income = 1;
            }
            str1[i] = a+48;
        }
        cout<<str1<<"\n";
    }
}
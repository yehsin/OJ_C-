#include<iostream>
using namespace std;

int main(){
    int heigh,width,min;
    cin>>heigh>>width;
    for(int i = 0;i<heigh*width;i++){
        int num;
        if(i == 0) cin>>min;
        else{
            cin>>num;
            if(num<min){
                min = num;
            }
        }
    }
    cout<<min<<endl;
}
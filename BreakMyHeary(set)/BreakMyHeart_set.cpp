#include<iostream>
#include<set>
#include<string.h>
using namespace std;

int main(){
    int lines;
    cin>>lines;
    set<int> set1;
    while(lines--){
        string command;
        cin>>command;
        if(command == "insert"){ //insert
            int num;
            cin>>num;
            set1.insert(num);
        }
        else if(command == "print"){
            if(set1.empty()) continue;
            else{
                //Note:The end is not accept blanks
                cout<<*set1.begin();  
                for(auto i:set1){   
                    if(i == *set1.begin()) continue;
                    cout<<" ";
                    cout<<i;
                }
                cout<<endl;
            }
        }
        else if(command == "min"){
            if(set1.empty()) continue; //if empty do nothing
            else{
                auto i = set1.begin();
                cout<<*i<<endl;
            }
        }
        else if(command == "range_erase"){
            int l,r;
            cin>>l>>r;
            set1.erase(set1.lower_bound(l),set1.upper_bound(r));
        }

    }
}
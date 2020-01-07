#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main(){

    std::ios_base::sync_with_stdio(false);
    queue<string> m;
    string command;
    while(cin>>command){
        if(command == "Push"){
            string name;
            cin>>name;
            m.push(name);

        }
        else if(command == "Pop"){
            if(m.empty()) continue;
            else m.pop();
        }
        else if(command == "Front"){
            if(m.empty()) cout<<"empty"<<"\n";
            else cout<<m.front()<<"\n";
        }
    }
    
}
#include<iostream>
#include<set>
using namespace std;

int main(){
    set<pair<int,string>> peopleContain;
    
    int lines;
    cin>>lines;
    while(lines--){
        string command;
        string name;
        int age;
        cin>>command;
        pair<int, string> a;
        if(command == "born"){
            cin>>name;
            cin>>age;
            a = {age,name};
            peopleContain.insert(a);
        }
        else if(command == "find"){
            cin>>name;
            cin>>age;
            a = {age,name};
            if(peopleContain.find(a) != peopleContain.end()){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
        else if(command == "kill"){
            cin>>name;
            cin>>age;
            a = {age,name};
            if(peopleContain.find(a) != peopleContain.end()){
                peopleContain.erase(a);
            }
        }
        else if(command == "young"){
            if(!peopleContain.empty()){
                a = *peopleContain.begin();
                cout<<a.second<<" "<<a.first<<endl;
            }
        }
    }
}
#include<map>
#include<vector>
#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<iomanip>

using namespace std;


int main(){
    int lines;
    cin>>lines;
    int count;
    char ch;
    map<int,map<char,vector<string>>> bucket; 
    string str;
    while(lines--){
        count = 0;
        cin>>str;
        for(int i = 0;i<str.length();i++){
            if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
                count ++;
                ch = str[i];
            }
        }
        bucket[count][ch].push_back(str);
        
    }
    vector<pair<string,string>>  comp;
    vector<pair<string,string>>  uncomp;
    for(auto &smap:bucket){
        for(auto &v:smap.second){

            //從每個vector挑出兩個元素做成一對，直到不夠湊成一對或vector為空
            while(v.second.size()>=2){

                pair<string,string> a(*(v.second.end()-1),*(v.second.end()-2));
                comp.push_back(a);
                v.second.erase(v.second.end()-1);
                v.second.erase(v.second.end()-1);

            }
        }

        vector<string> tmp;
        //之後從剩下的挑出來做成一對變成uncomp
        for(auto &s:smap.second){ //注意&
            if(!s.second.empty()){
                tmp.push_back(s.second[0]);
            }
            if(tmp.size()>=2){
                pair<string,string> b(tmp[0],tmp[1]);
                tmp.clear();
                uncomp.push_back(b);
            }

        }
        
    }
    int compNUmbers = comp.size();
    int uncompNumbers = uncomp.size();
    //cout<<compNUmbers<<" "<<uncompNumbers<<endl;
    if(uncompNumbers > compNUmbers){
        cout<<compNUmbers<<endl;
    }
    else{
        int remains = (compNUmbers - uncompNumbers)/2;
        cout<<remains + uncompNumbers<<endl;
    }
    return 0;
}
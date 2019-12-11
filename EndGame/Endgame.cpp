#include<iostream>
#include<queue>
using namespace std;

class map{
    public:
        map(){
            destroy = 0;
        }
        ~map(){delete []road;}
        friend istream &operator >>(istream &in,map &m){
            cin>>m.width>>m.height;
            char **arr;
            arr = new char*[m.height];
            for(int i=0;i<m.height;i++){
                arr[i] = new char[m.width];
            }
            m.road = arr;
            for(int i=0;i<m.height;i++){
                for(int j = 0;j<m.width;j++){
                    cin>>m.road[i][j];
                    if(m.road[i][j] == 'T'){
                        m.destroy++;
                    }
                    else if(m.road[i][j] == 'I'){
                        m.q.push({i,j});
                        m.q.push({0,0});
                    }
                    else continue;
                }
            }
            return in;
        }

        int IronmanAttack(){
            while(!q.empty()){
                pair<int,int> dest = q.front();
                q.pop();
                pair<int,int> dist = q.front();
                q.pop();
                enum direction{up,down,left,right};
                for(int i=0;i<4;i++){
                    switch(i){
                        case up:
                            if(dest.first-1<0 ){
                                break;
                            }
                            else if(road[dest.first-1][dest.second] == 'C'){
                                break;
                            }
                            else if(road[dest.first-1][dest.second] == 'T'){
                                destroy--;
                                if(destroy == 0) return dist.first+1;
                            }
                            road[dest.first-1][dest.second] = 'C';

                            q.push({dest.first-1,dest.second});
                            q.push({dist.first+1,0});
                            break;
                        case down:
                            if(dest.first +1 >= height){
                                break;
                            }
                            else if(road[dest.first+1][dest.second] == 'C'){
                                break;
                            }
                            else if(road[dest.first+1][dest.second] == 'T'){
                                destroy--;
                                if(destroy == 0) return dist.first+1;
                            }
                            road[dest.first+1][dest.second] = 'C';
                            q.push({dest.first+1,dest.second});
                            q.push({dist.first+1,0});
                            break;
                        case left:
                            if( dest.second-1<0 ){
                                
                                break;
                            }
                            else if(road[dest.first][dest.second-1] == 'C'){
                                
                                break;
                            }
                            else if(road[dest.first][dest.second-1] == 'T'){
                                
                                destroy--;
                                if(destroy == 0) return dist.first+1;
                            }
                            road[dest.first][dest.second-1] = 'C';

                            q.push({dest.first,dest.second-1});
                            q.push({dist.first+1,0});
                            break;
                        case right:
                            if(dest.second +1 >= width){
                                break;
                            }
                            else if(road[dest.first][dest.second+1] == 'C'){
                                break;
                            }
                            else if(road[dest.first][dest.second+1] == 'T'){
                                destroy--;
                                if(destroy == 0) return dist.first+1;
                            }
                            road[dest.first][dest.second+1] = 'C';
                            //cout<<dest.first<<dest.second+1<<endl;
                            q.push({dest.first,dest.second+1});
                            q.push({dist.first+1,0});
                            break;
                    }

                }
                

            }
            return -1;
        }
        
    private:
        int width,height;
        int destroy;
        char **road;
        queue<pair<int ,int >> q;
};

int main(){
    map map;
    cin>>map;
    cout<<map.IronmanAttack()<<endl;
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

long long int gcd(long long int a,long long int b){
    while (b > 0) {
        long long int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long int lcm(long long int a,long long int b){
    long long int c = gcd(a,b);
    return a*b/c;
}

int main(){
    int lines;

    while(cin>>lines){
        long long int LCM = 1;
        long long int sum = 0;
        vector<long long int>N,M;
        for(int i = 0;i<lines;i++){
            long long int n,m;
            cin>>n>>m;
            N.push_back(n);
            M.push_back(m);
            LCM = lcm(LCM,M[i]);
        }
        for(int i = 0;i<lines;i++){
            N[i] = N[i] * (LCM/M[i]);
            sum+=N[i];
        }
        long long int a = gcd(LCM,sum);
        if(a == 1) cout<<sum<<'/'<<LCM<<"\n";
        else{
            cout<<sum/a<<'/'<<LCM/a<<"\n";
        }
    }
    
    return 0;
}
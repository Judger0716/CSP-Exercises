#include<bits/stdc++.h>
using namespace std;

int xl,yd,xr,yu;

bool is_in(int x,int y){
    if(x>=xl&&x<=xr&&y>=yd&&y<=yu) return true;
    else return false;
}

int main(){

    int n,k,t;
    cin>>n>>k>>t>>xl>>yd>>xr>>yu;
    int passcnt=0,staycnt=0;
    for(int i=0;i<n;i++){
        int zonecnt=0;
        int cnt=0;
        bool passflag=false;
        for(int j=0;j<t;j++){
            int x,y;
            cin>>x>>y;
            if(is_in(x,y)){
                cnt++;
                passflag=true;
            }
            else{
                if(cnt>zonecnt) zonecnt=cnt;
                cnt=0;
            }
        }
        if(cnt>zonecnt) zonecnt=cnt;
        if(passflag) passcnt++;
        if(zonecnt>=k) staycnt++;
    }
    cout<<passcnt<<endl<<staycnt;

    return 0;
}
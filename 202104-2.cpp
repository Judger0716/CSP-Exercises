#include<bits/stdc++.h>
using namespace std;

int graph[610][610]={0};
bool judge(int n,int i,int j,int r,int t){
    long long sum = 0;
    int cnt = 0;
    // boarder
    int left,right,up,down;
    if(j>=r) left=j-r;
    else left=0;
    if(j+r>n-1) right=n-1;
    else right=j+r;
    if(i>=r) up=i-r;
    else up=0;
    if(i+r>n-1) down=n-1;
    else down=i+r;
    // cal
    for(int p=up;p<=down;p++){
        for(int q=left;q<=right;q++){
            sum+=graph[p][q];
            cnt+=1;
        }
    }
    double avg=double(sum)/double(cnt);
    if(avg>t) return false;
    else return true;
}

int main(){

    int n,L,r,t;
    cin>>n>>L>>r>>t;
    // input
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>graph[i][j];
        }
    }
    // judge
    int res = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(judge(n,i,j,r,t)) res+=1;
            else continue;
        }
    }
    cout<<res;
    
    return 0;
}
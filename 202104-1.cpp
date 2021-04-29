#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,m,L;
    int graph[502][502]={0};
    cin>>n>>m>>L;
    int cal[260]={0};

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>graph[i][j];
            cal[graph[i][j]]+=1;
        }
    }
    for(int i=0;i<L;i++){
        cout<<cal[i]<<" ";
    }

    return 0;
}
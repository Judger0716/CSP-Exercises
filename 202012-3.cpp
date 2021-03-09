#include<bits/stdc++.h>
using namespace std;
#define N 1100000

struct node{
    int flag,sz;
}f[N];

int rt,size;
map<string,int>mp[N];

bool insert(){
    string s,to;
    cin>>s;
    int x=rt,n=s.size(),value;
    scanf("%d",&value);
    for(int i=0;i<n;i++){
        if(s[i]=='/'){
            if(!i) continue;
            if(mp[x][to]){
                if(f[mp[x][to]].flag==1) return false;
            }
            if(!mp[x][to]){
                mp[x][to]=++size;
                f[mp[x][to]].flag=0;
            }
            x=mp[x][to];
            to.clear();
            continue;
        }
        to=to+s[i];
    }
    if(mp[x][to]){
        if(f[mp[x][to]].flag==0) return false;
    }
    if(!mp[x][to]){
        mp[x][to]=++size;
        f[mp[x][to]].flag=1;
    }
    x=mp[x][to];f[x].sz=value;
    return true;
}
bool delate(){
    string s,to;
    cin>>s;
    int x=rt,n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]=='/'){
            if(!i) continue;
            if(!mp[x][to]) return true;
            x=mp[x][to];
            to.clear();
            continue;
        }
        to=to+s[i];
    }
    if(!mp[x][to])return true;
    mp[x].erase(to);
    return true;
}
 
void print(bool flag){
    if(flag) printf("Y\n");
    else printf("N\n");
}

int main(){
    int qnum;
    scanf("%d",&qnum);
    rt=1;size=1;
    for(int i=1;i<=qnum;i++){
        char fg[3];
        scanf("%s",fg);
        if(fg[0]=='C')print(insert());
        if(fg[0]=='R')print(delate());
    }
    return 0;
}
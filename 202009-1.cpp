#include<bits/stdc++.h>
using namespace std;

struct node{
    long long int x,y;
    double dis;
    long long int num;
};

long long int cal_dis(node c,long long int x,long long int y){
    return (c.x-x)*(c.x-x)+(c.y-y)*(c.y-y);
}

bool cmp(node a,node b){
    if(a.dis!=b.dis)
        return a.dis<b.dis;
    else return a.num<b.num;
}

int main(){

    long long int n;
    node citizen;
    cin>>n>>citizen.x>>citizen.y;
    node* p=new node[n];
    for(long long int i=0;i<n;i++){
        p[i].num=i+1;
        cin>>p[i].x>>p[i].y;
        p[i].dis=cal_dis(citizen,p[i].x,p[i].y);
    }
    sort(p,p+n,cmp);
    for(long long int i=0;i<3;i++){
        cout<<p[i].num<<endl;
    }

    return 0;
}
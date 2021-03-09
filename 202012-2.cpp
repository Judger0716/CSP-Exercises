#include<bits/stdc++.h>
using namespace std;

struct stu{
    int y;
    int result;
};

bool cmp(stu a,stu b){
    return a.y<b.y;
}

stu v[1000000];
// 排序后，前i个人里挂科的人数，后i个人里不挂科的人数
int pre[1000000]; 
int lst[1000000]; 

int main(){

    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&v[i].y,&v[i].result);
    }
    sort(v,v+n,cmp);
    // dp
    if(v[0].result==0) pre[0]=1;
    else pre[0]=0;
    if(v[n-1].result==1) lst[n-1]=1;
    else lst[n-1]=0;
    for(int i=1;i<n;i++){
        pre[i]=pre[i-1]+(v[i].result==0);
    }
    for(int i=n-2;i>=0;i--){
        lst[i]=lst[i+1]+(v[i].result==1);
    }
    int theta = v[0].y;
    int max = pre[0]+lst[1];
    for(int i=1;i<n;i++){
        if(v[i].y!=v[i-1].y){
            int temp = pre[i-1]+lst[i];
            if(temp>=max){
                theta=v[i].y;
                max=temp;
            }
        }
    }
    printf("%d",theta);

    return 0;
}
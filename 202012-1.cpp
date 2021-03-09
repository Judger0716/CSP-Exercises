#include<bits/stdc++.h>
using namespace std;

int relu(int x){
    int y=x>0?x:0;
    return y;
}

int main(){

    int n;
    scanf("%d",&n);
    int w,sc;
    int y=0;
    for(int i=0;i<n;i++){
        scanf("%d %d",&w,&sc);
        y+=w*sc;
    }
    y=relu(y);
    printf("%d",y);

    return 0;
}
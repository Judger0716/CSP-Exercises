#include<bits/stdc++.h>
using namespace std;

int N,n,tdef,tmin,tmax;
string H;

struct ip{
    int ip_num,expitime;
    string owner,state;
};
ip ip_pool[11000];

bool reject(string guest,string host,string order){
    if(host!=H&&host!="*"){
        if(order!="REQ") return false;
        else return true;
    }
    else if(order!="REQ"&&order!="DIS") return false;
    else if(host=="*"&&order!="DIS") return false;
    else if(host==H&&order=="DIS") return false;
    else return true;
}

void update(ip ip_pool[1100],int time){
    for(int i=1;i<=N;i++){
        if(ip_pool[i].state=="daifenpei"||ip_pool[i].state=="zhanyong"){
            if(ip_pool[i].expitime<=time){
                if(ip_pool[i].state=="daifenpei"){
                    ip_pool[i].state="weifenpei";
                    ip_pool[i].owner="null";
                    ip_pool[i].expitime=0;
                }
                else{
                    ip_pool[i].state="guoqi";
                    ip_pool[i].expitime=0;
                }
            }
        }
    }
}

int handle_DIS(int time,string guest,string host,string order,int ip,int expitime){
  
    for(int i=1;i<=N;i++){
        if(ip_pool[i].owner==guest) return ip_pool[i].ip_num;
    }
    for(int i=1;i<=N;i++){
        if(ip_pool[i].state=="weifenpei") return ip_pool[i].ip_num;
    }
    for(int i=1;i<=N;i++){
        if(ip_pool[i].state=="guoqi") return ip_pool[i].ip_num;
    }
    return -1;
}

void handle_REQ(int time,string guest,string host,string order,int ip,int expitime){
    for(int i=1;i<=N;i++){
        if(ip_pool[i].owner==guest){
            if(ip_pool[i].state=="daifenpei"){
                ip_pool[i].state="weifenpei";
                ip_pool[i].owner="null";
                ip_pool[i].expitime=0;
            }
        }
    }
}

int main(){

    cin>>N>>tdef>>tmax>>tmin>>H;
    // init IP POOL
    
    for(int i=1;i<=N;i++){
        ip_pool[i].ip_num=i;
        ip_pool[i].expitime=0;
        ip_pool[i].owner="null";
        ip_pool[i].state="weifenpei";
    }
    cin>>n;
    for(int i=0;i<n;i++){
        int time;
        string guest,host,order;
        int ip,expitime;
        cin>>time>>guest>>host>>order>>ip>>expitime;
        update(ip_pool,time);
        if(reject(guest,host,order)){
            if(order=="DIS"){
                int resp = handle_DIS(time,guest,host,order,ip,expitime);
                if(resp==-1) continue;
                else{
                    ip_pool[resp].owner=guest;
                    ip_pool[resp].state="daifenpei";
                    if(expitime==0){
                        ip_pool[resp].expitime=time+tdef;
                    }
                    else{
                        int timelen=expitime-time;
                        if(timelen>tmax){
                            ip_pool[resp].expitime=time+tmax;
                        }
                        else if(timelen<tmin) ip_pool[resp].expitime=time+tmin;
                        else ip_pool[resp].expitime=expitime;
                    }
                }
                cout<<H<<" "<<guest<<" "<<"OFR"<<" "<<ip_pool[resp].ip_num<<" "<<ip_pool[resp].expitime<<endl;
            }
            else if(order=="REQ"){
                if(host!=H) handle_REQ(time,guest,host,order,ip,expitime);
                else{
                    //check
                    bool isin=false;
                    for(int i=1;i<=N;i++){
                        if(ip_pool[i].ip_num==ip&&ip_pool[i].owner==guest){
                            isin=true;
                            break;
                        }
                    }
                    if(!isin){
                        cout<<H<<" "<<guest<<" "<<"NAK"<<" "<<ip<<" "<<0<<endl;
                        continue;
                    }
                    else{
                        ip_pool[ip].state="zhanyong";
                        ip_pool[ip].owner=guest;
                        if(expitime==0){
                            ip_pool[ip].expitime=time+tdef;
                        }
                        else{
                            int timelen=expitime-time;
                            if(timelen>tmax){
                                ip_pool[ip].expitime=time+tmax;
                            }
                            else if(timelen<tmin) ip_pool[ip].expitime=time+tmin;
                            else ip_pool[ip].expitime=expitime;
                        }
                        cout<<H<<" "<<guest<<" "<<"ACK"<<" "<<ip<<" "<<ip_pool[ip].expitime<<endl;
                    }
                }
            }
        }
    }
    
    return 0;
}
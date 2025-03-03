#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
struct node{
    int m,t,s;
    bool friend operator < (const node &a,const node &b){
        return a.m<b.m||
        a.m==b.m&&a.t<b.t||
        a.m==b.m&&a.t==b.t&&a.s<b.s;
    }
}r[1000005][4];
int a[1000005];
int pre[1000005][4];
bool check(node a){
    return a.t<k;
}
void print(int cur,int S){
    if(cur==0)return;
    print(cur-1,pre[cur][S]);
    if(S>=2)printf("%lld ",a[cur]);
    if(S==0)printf("0 ");
    if(S==1)printf("100000 ");
    return;
}
signed main(){
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        r[i][0]=r[i][1]=r[i][2]=r[i][3]=node{10000000005,10000000005,10000000005};
    }
    for(int i=1;i<=n;i++){
        for(int S1=0;S1<4;S1++){
            int P=a[i-1];
            if(S1==0)P=0;
            if(S1==1)P=100000;
            for(int S2=0;S2<4;S2++){
                int S=a[i];
                if(S2==0)S=0;
                if(S2==1)S=100000;
                if(S2&1){
                    if(S1&1){
                        if(S>P){
                            node tmp=node{r[i-1][S1].m+(S2<2),r[i-1][S1].t+1,1};
                            if(check(tmp)){
                                if(tmp<r[i][S2]){
                                    pre[i][S2]=S1;
                                }
                                r[i][S2]=min(r[i][S2],tmp);
                            }
                        }
                        else if(S==P){
                            node tmp=node{r[i-1][S1].m+(S2<2),r[i-1][S1].t+1,r[i-1][S1].s+1};
                            if(check(tmp)){
                                if(tmp<r[i][S2]){
                                    pre[i][S2]=S1;
                                }
                                r[i][S2]=min(r[i][S2],tmp);
                            }
                        }
                    }
                    else{
                        if(S>P){//
                            node tmp=node{r[i-1][S1].m+(S2<2),r[i-1][S1].s+1,1};
                            if(check(tmp)){
                                if(tmp<r[i][S2]){
                                    pre[i][S2]=S1;
                                }
                                r[i][S2]=min(r[i][S2],tmp);
                            }
                        }
                    }
                }
                else{
                    if(!(S1&1)){
                        if(S<P){
                            node tmp=node{r[i-1][S1].m+(S2<2),r[i-1][S1].t+1,1};
                            if(check(tmp)){
                                if(tmp<r[i][S2]){
                                    pre[i][S2]=S1;
                                }
                                r[i][S2]=min(r[i][S2],tmp); 
                            }
                        }
                        else if(S==P){
                            node tmp=node{r[i-1][S1].m+(S2<2),r[i-1][S1].t+1,r[i-1][S1].s+1};
                            if(check(tmp)){
                                if(tmp<r[i][S2]){
                                    pre[i][S2]=S1;
                                }
                                r[i][S2]=min(r[i][S2],tmp);
                            }
                        }
                    }
                    else{
                        if(S<P){
                            node tmp=node{r[i-1][S1].m+(S2<2),r[i-1][S1].s+1,1};
                            if(check(tmp)){
                                if(tmp<r[i][S2]){
                                    pre[i][S2]=S1;
                                }
                                r[i][S2]=min(r[i][S2],tmp);
                            }
                        }
                    }
                }
            }
        }
    }
    int MIN=r[n][0].m,mini=0;
    for(int i=1;i<4;i++){
        if(r[n][i].m<MIN){
            MIN=r[n][i].m;
            mini=i;
        }
    }
    printf("%lld\n",MIN);
    print(n,mini);
    return 0;
}
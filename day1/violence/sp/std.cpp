//Author:Leftist_G / Shunpower
//Cloud Island & Rain Temperature
//May the force be with you and me.
#include <bits/stdc++.h>
#define ET return 0
#define fi first
#define se second
#define mp make_pair
#define pb emplace_back
#define ll long long
#define ull unsigned long long
#define inf INT_MAX
#define uinf INT_MIN
#define pii pair<int,int>
#define pll pair<ll,ll>
#define debug puts("--------Chery AK IOI--------");
#define Yes cout<<"Yes"<<endl;
#define No cout<<"No"<<endl;
#define pt puts("")
#define fr1(i,a,b) for(int i=a;i<=b;i++)
#define fr2(i,a,b) for(int i=a;i>=b;i--)
#define fv(i,p) for(int i=0;i<p.size();i++)
#define ld long double
#define il inline
#define ptc putchar
using namespace std;
const int N=2e7+10;
namespace Shun{
    int lowbit(int x){
        return x&-x;
    }
    template <typename T>
    inline void read(T &x){
       T s=0,w=1;
       char ch=getchar();
       while(ch<'0'||ch>'9'){
            if(ch=='-'){
                w=-1;
            }
            ch=getchar();
        }
       while(ch>='0'&&ch<='9'){
            s=s*10+ch-'0';
            ch=getchar();
       }
       x=s*w;
    }
    template <typename T>
    inline void write(T x){
        if(x<0){
            putchar('-');
            x=-x;
        }
        if(x>9){
            write(x/10);
        }
        putchar(x%10+'0');
    }
}
using namespace Shun;
const int mod=998244353;
int n,v;
int a[N];
namespace Gen
{
    unsigned z1, z2, z3, z4, b;
    unsigned rand_()
    {
        b = ((z1 << 6) ^ z1) >> 13;
        z1 = ((z1 & 4294967294U) << 18) ^ b;
        b = ((z2 << 2) ^ z2) >> 27;
        z2 = ((z2 & 4294967288U) << 2) ^ b;
        b = ((z3 << 13) ^ z3) >> 21;
        z3 = ((z3 & 4294967280U) << 7) ^ b;
        b = ((z4 << 3) ^ z4) >> 12;
        z4 = ((z4 & 4294967168U) << 13) ^ b;
        return (z1 ^ z2 ^ z3 ^ z4);
    }
    void srand_(int n, int v)
    {
        scanf("%u%u%u%u", &z1, &z2, &z3, &z4);
        for(int i = 1; i <= n; i++) a[i] = rand_() % v + 1;
    }
}
int dp[N][2];
int sum[N][2];
il void add(int &x,int y){
    x+=y;
    if(x>mod) x-=mod;
}
int minseg(int l,int r){
    int minn=1e9;
    fr1(i,l,r) minn=min(minn,a[i]);
    return minn;
}
struct Stack{
    int s[N];
    int tot;
    il void push(int x){
        tot++;
        s[tot]=x;
    }
    il void pop(){tot--;}
    il bool empty(){return !tot;}
    il int top(){return s[tot];}
    il int top2(){
        if(!(tot-1)) return N-1;
        return s[tot-1];
    }
} st;
int main(){
#ifdef Shun
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    read(n),read(v);
    Gen::srand_(n,v);
    // fr1(i,1,n) cin>>a[i];
    dp[0][0]=1,sum[0][0]=sum[1][0]=1;
    dp[1][1]=a[1],sum[1][1]=a[1];
    st.push(0);
    st.push(1);
    fr1(i,2,n){
        // fr1(j,0,(i+1)/2) (dp[i][j]+=1ll*dp[i-1][j]*a[i]%mod)%=mod;
        // fr1(j,1,i){
        dp[i][0]=dp[i-1][0],dp[i][1]=dp[i-1][1];
        while(!st.empty()){
            if(a[st.top()]>a[i]){
                add(dp[i][0],mod-1ll*(sum[st.top()-1][1]+mod-sum[st.top2()-1][1])*a[st.top()]%mod);
                add(dp[i][1],mod-1ll*(sum[st.top()-1][0]+mod-sum[st.top2()-1][0])*a[st.top()]%mod);
                st.pop();
            }
            else break;
        }
        add(dp[i][0],1ll*(sum[i-1][1]+mod-sum[st.top()-1][1])*a[i]%mod);
        add(dp[i][1],1ll*(sum[i-1][0]+mod-sum[st.top()-1][0])*a[i]%mod);
        // cout<<st.top2()<<endl;
        st.push(i);
        // fr1(k,0,i-1){
        //     (dp[i][0]+=1ll*dp[k][1]*minseg(k+1,i)%mod)%=mod;
        //     (dp[i][1]+=1ll*dp[k][0]*minseg(k+1,i)%mod)%=mod;
        // }
        sum[i][0]=sum[i-1][0];
        add(sum[i][0],dp[i][0]);
        sum[i][1]=sum[i-1][1];
        add(sum[i][1],dp[i][1]);
        // }
        // fr1(j,0,1) cout<<i<<" "<<j<<":"<<dp[i][j]<<endl;
    }
    int ans=0;
    if(n&1) ans=dp[n][1]+mod-dp[n][0];
    else ans=dp[n][0]+mod-dp[n][1];
    cout<<ans%mod<<'\n';
    ET;
}
//ALL FOR Zhang Junhao.
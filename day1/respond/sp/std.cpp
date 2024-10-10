//Author:Leftist_G / Shunpower
//Moon Land & Letter to Past
//Hey Left
//Just enjoy the loneliness
//Open a personal party always stay
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
const int N=8010;
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
const ll mod=2007072007;
int n;
ll f[N];
ll a[N];
ll ans[N];
ll g[N];
ll h1[N];
ll h2[N];
ll sum[N];
ll pow2[N];
int main(){
#ifdef Shun
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    ios::sync_with_stdio(false);
    cin>>n;
    pow2[0]=1;
    fr1(i,1,n) pow2[i]=(pow2[i-1]+pow2[i-1])%mod;
    fr1(i,1,n) cin>>a[i],sum[i]=sum[i-1]+a[i];
    // cout<<"?"<<g[3][3]<<endl;
    fr1(i,1,n) g[i]=a[i];
    fr1(t,1,n+n){
        fr1(s,1,n) g[s]=max({g[s],(s+t<=n?sum[s+t]-sum[s-1]:0),(t<s?sum[s]-sum[s-t-1]:0)});
        fr1(s,1,n){
            ll nf=a[s];
            nf=max(h1[s-1],h2[s+1]);
            if(t<=n) nf=max(nf,g[s]);
            f[s]=max(nf,f[s]);
            ans[s]^=1ll*t*f[s];
            // cout<<f[s]<<" ";
        }
        // cout<<endl;
        // fr1(s,1,n) cout<<h2[s]<<",";
        // cout<<endl;
        fr2(s,n,1) h1[s]=max(h1[s-1],g[s]);
        fr1(s,1,n) h2[s]=max(h2[s+1],g[s]);
    }
    fr1(i,1,n) ans[i]%=mod;
    ll res=0;
    fr1(i,1,n) (res+=pow2[i]*ans[i]%mod)%=mod;
    cout<<res<<'\n';
    ET;
}
//ALL FOR Zhang Junhao.
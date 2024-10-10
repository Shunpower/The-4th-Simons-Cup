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
const int N=1e6+10;
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
int tc;
int n,q,type;
string s;
ll a[N],w[N];
ll premin[N];
ll sufsum[N];
#define mid (l+r>>1)
struct sgt1{
    ll sum[N<<2];
    il void pushup(int p){sum[p]=sum[p<<1]+sum[p<<1|1];}
    il void build(int p,int l,int r){
        if(l==r) return sum[p]=a[l],void();
        build(p<<1,l,mid);
        build(p<<1|1,mid+1,r);
        pushup(p);
    }
    il void insert(int p,int l,int r,int d,ll x){
        if(l==r) return sum[p]=x,void();
        if(d<=mid) insert(p<<1,l,mid,d,x);
        else insert(p<<1|1,mid+1,r,d,x);
        pushup(p);
    }
    il int binary(int p,int l,int r,ll x){
        if(sum[p]<x) throw("bad");
        if(l==r) return l;
        if(sum[p<<1|1]>=x) return binary(p<<1|1,mid+1,r,x);
        else{
            x-=sum[p<<1|1];
            return binary(p<<1,l,mid,x);
        }
    }
} T1;
struct sgt2{
    ll sum[N<<2],ans[N<<2];
    ll des[N<<2],lzy[N<<2];
    void pushdown(int p){
        sum[p<<1]-=des[p],sum[p<<1|1]-=des[p];
        ans[p<<1]-=des[p],ans[p<<1|1]-=des[p];
        des[p<<1]+=des[p],des[p<<1|1]+=des[p];
        des[p]=0;
        ans[p<<1]=min(ans[p<<1],sum[p<<1]+lzy[p]);
        ans[p<<1|1]=min(ans[p<<1|1],sum[p<<1|1]+lzy[p]);
        lzy[p<<1]=min(lzy[p<<1],lzy[p]);
        lzy[p<<1|1]=min(lzy[p<<1|1],lzy[p]);
        lzy[p]=1e18;
    }
    void pushup(int p){
        sum[p]=min(sum[p<<1],sum[p<<1|1]);
        ans[p]=min(ans[p<<1],ans[p<<1|1]);
    }
    void build(int p,int l,int r){
        des[p]=0;
        lzy[p]=1e18;
        if(l==r) return sum[p]=sufsum[l],ans[p]=sufsum[l]+premin[l],void();
        build(p<<1,l,mid);
        build(p<<1|1,mid+1,r);
        pushup(p);
    }
    void modify(int p,int l,int r,int ml,int mr,ll x){
        if(ml<=l&&r<=mr){
            des[p]+=x,sum[p]-=x,ans[p]-=x;
            return;
        }
        pushdown(p);
        if(ml<=mid) modify(p<<1,l,mid,ml,mr,x);
        if(mid<mr) modify(p<<1|1,mid+1,r,ml,mr,x);
        pushup(p);
    }
    void maintainans(int p,int l,int r,int ml,int mr,ll x){
        if(ml<=l&&r<=mr){
            ans[p]=min(ans[p],sum[p]+x);
            lzy[p]=min(lzy[p],x);
            // cout<<l<<" "<<r<<"<-"<<ans[p]<<endl;
            return;
        }
        pushdown(p);
        if(ml<=mid) maintainans(p<<1,l,mid,ml,mr,x);
        if(mid<mr) maintainans(p<<1|1,mid+1,r,ml,mr,x);
        pushup(p);
    }
    ll query(int p,int l,int r,int ml,int mr){
        if(ml<=l&&r<=mr){
            // cout<<l<<" "<<r<<":"<<sum[p]<<" "<<ans[p]<<endl;
            return ans[p];
        }
        pushdown(p);
        ll minn=1e18;
        if(ml<=mid) minn=min(minn,query(p<<1,l,mid,ml,mr));
        if(mid<mr) minn=min(minn,query(p<<1|1,mid+1,r,ml,mr));
        return minn;
    }
} T2;
#undef mid
ll lst;
ll calc(){
    int r=T1.binary(1,1,n,T1.sum[1]/2+1);
    ll ans=1e18;
    // cout<<"!"<<r<<endl;
    // cout<<T1.sum[0]<<" "<<r<<" "<<a[r]<<endl;
    if(a[r]>=T1.sum[1]/2+1) ans=min(ans,(ll)w[r]);
    ans=min(ans,T2.query(1,1,n,1,r));
    lst=abs(ans);
    return ans;
}
void solve(){
    read(n),read(q),read(type);
    // cin>>s;//P10796
    // n++;//P10796
    fr1(i,1,n) read(a[i]),read(w[i]);
    T1.build(1,1,n);
    premin[0]=2e9;
    fr1(i,1,n) premin[i]=min(premin[i-1],w[i]);
    sufsum[n+1]=0;
    fr2(i,n,1) sufsum[i]=sufsum[i+1]+w[i];
    T2.build(1,1,n);
    write(calc());
    ptc('\n');
    while(q--){
        ll o,p,x;
        read(o),read(p),read(x);
        // o=o^(type?lst:0);//P10796
        p=p^(type?lst:0);
        // p++;//P10796
        x=(x<=0?-1ll:1ll)*(abs(x)^(type?lst:0));
        if(o==1) T1.insert(1,1,n,p,x),a[p]=x;
        else{
            T2.modify(1,1,n,1,p,w[p]-x);
            T2.maintainans(1,1,n,p,n,x);
            w[p]=x;
        }
        write(calc());
        ptc('\n');
    }
}
int main(){
#ifdef Shun
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    read(tc);
    while(tc--) solve();
    ET;
}
//ALL FOR Zhang Junhao.
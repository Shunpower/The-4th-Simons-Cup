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
const int N=1e5+10;
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
int n,m;
int a[N],b[N];
int ans[N];
int ori[N],tmp[N],op[N];
int cnt[N];
int col[N*3];
bool vis[N*3];
int head[N*12],to[N*12],nxt[N*12];
int tot;
/*
[0,2^n) 输入向1
[2^n,2^{n+1}) 输入向2
[2^{n+1},2^{n+1}+2^n) 输出向1
[2^{n+1}+2^n,2^{n+1}+2^{n+1}) 输出向2
*/
void add(int x,int y){
    tot++;
    nxt[tot]=head[x],to[tot]=y,head[x]=tot;
    tot++;
    nxt[tot]=head[y],to[tot]=x,head[y]=tot;
}
void dfs(int x,int c){
    vis[x]=1;
    col[x]=c;
    for(int i=head[x];~i;i=nxt[i]){
        int y=to[i];
        if(col[y]==col[x]) throw("failed proof");
        if(vis[y]) continue;
        dfs(y,c^1);
    }
}
void divide(int n,int l,int r,int num){
    if(r<l) return;
    if(n==0){
        ans[ori[l]]=num;
        return;
    }
    fr1(i,0,(1<<n-1)-1) add(i,i+(1<<n-1));
    fr1(i,(1<<n),(1<<n)+(1<<n-1)-1) add(i,i+(1<<n-1));
    fr1(i,(1<<n+1),(1<<n+1)+(1<<n-1)-1) add(i,i+(1<<n-1));
    fr1(i,(1<<n+1)+(1<<n),(1<<n+1)+(1<<n)+(1<<n-1)-1) add(i,i+(1<<n-1));
    fr1(i,0,(1<<n)-1) add(i,i+(1<<n));
    fr1(i,(1<<n+1),(1<<n+1)+(1<<n)-1) add(i,i+(1<<n));
    fr1(i,l,r){
        add(a[ori[i]],(1<<n+1)+(1<<n)+b[ori[i]]);
        add((1<<n)+a[ori[i]],(1<<n+1)+b[ori[i]]);
    }
    fr1(i,0,(1<<n+1)+(1<<n+1)-1){
        if(!vis[i]) dfs(i,2);
    }
    // cout<<"!"<<endl;
    fr1(i,l,r) tmp[i]=ori[i];
    fr1(i,l,r){
        if(col[a[ori[i]]]==2) op[i]=0;
        else op[i]=1;
        a[ori[i]]&=((1<<n-1)-1);
        b[ori[i]]&=((1<<n-1)-1);
    }
    int tot1=l-1;
    fr1(i,l,r){
        if(!op[i]) tot1++,ori[tot1]=tmp[i];
    }
    int tot2=tot1;
    fr1(i,l,r){
        if(op[i]) tot2++,ori[tot2]=tmp[i];
    }
    fr1(i,0,(1<<n+1)+(1<<n+1)-1) vis[i]=col[i]=0;
    fr1(i,0,(1<<n+1)+(1<<n+1)-1) head[i]=-1;
    tot=0;
    divide(n-1,l,tot1,num);
    divide(n-1,tot1+1,tot2,num+(1<<n-1));
}
void solve(){
    read(n),read(m);
    fr1(i,1,m) read(a[i]),read(b[i]);
    fr1(i,0,(1<<n)-1) cnt[i]=0;
    fr1(i,1,m) cnt[a[i]]++;
    fr1(i,0,(1<<n)-1) if(cnt[i]>=2) return puts("NO"),void();
    fr1(i,0,(1<<n)-1) cnt[i]=0;
    fr1(i,1,m) cnt[b[i]]++;
    fr1(i,0,(1<<n)-1) if(cnt[i]>=2) return puts("NO"),void();
    fr1(i,1,m) ori[i]=i;
    divide(n,1,m,0);
    puts("YES");
    fr1(i,1,m){
        write(ans[i]);
        if(i!=m) ptc(' ');
    }
    ptc('\n');
}
#define Shun cute
int main(){
#ifdef Shun
    freopen("fearless.in","r",stdin);
    freopen("fearless.out","w",stdout);
#endif
    memset(head,-1,sizeof head);
    read(tc);
    while(tc--) solve();
    cerr<<clock()<<'\n';
    ET;
}
//ALL FOR Zhang Junhao.

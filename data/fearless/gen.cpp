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

int test=11;
int k;
// int n=10,lim=10;
int n=16,lim=(1<<n);

int m;
char C[100];
int tc=30;
mt19937 rnd(time(0));
void no_sol(){
    fr1(i,1,m){
        int x=rnd()%(1<<n);
        int y=rnd()%(1<<n);
        cout<<x<<" "<<(1<<n)-1-x<<endl;
    }
}
int p[N],q[N];
// int tot;
void simple(){
    fr1(i,0,(1<<n)-1) p[i]=i,q[i]=i;
    shuffle(p,p+(1<<n),rnd);
    shuffle(q,q+(1<<n),rnd);
    fr1(i,0,m-1) cout<<p[i]<<" "<<(1<<n)-1-p[i]<<endl;
}
void solve(){
    // m=rnd()%(1<<n)+1;
    m=(tc>15?rnd()%lim+1:lim);
    k=rnd()%(1<<n);
    cout<<n<<" "<<m<<endl;
    if(rnd()%5==0) no_sol();
    else simple();
}
int main(){
#ifdef Shun
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    sprintf(C,"fearless%d.in",test);
    freopen(C,"w",stdout);
    cout<<tc<<endl;
    while(tc--) solve();
    ET;
}
//ALL FOR Zhang Junhao.
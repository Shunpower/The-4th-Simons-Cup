//Author:KIT / Shunpower
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
#define fr1(i,a,b) for(int i=a;i<=b;i++)
#define fr2(i,a,b) for(int i=a;i>=b;i--)
#define ld long double
#define il inline
#define all(a) a.begin(),a.end()
//Quickly power: ll d=qpow(b,p>>1,k);
//Segment Tree: Memory Limit Excceed
//Segment Tree: Modify()->Pushdown()
//Mod: +M, %M, define int ll
//Mod: Don't use 998244353 instead of 1e9+7 and so on
//Don't solve a problem for too long time.
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
mt19937 rnd(time(0));
char c[1010];
int n[]={0,5,5,15,15,80,80,80,80,300,300,3000,3000,8000,8000,8000,8000,300000,300000,300000,300000,1000000,1000000,20000000,20000000,20000000};
// string name="violence00.in";
int main(){
#ifdef Shun
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	fr1(i,23,23){
		sprintf(c,"violence%d.in",10);
        freopen(c,"w",stdout);
		if(i&1){
			cout<<n[i]<<" "<<(int)1e9<<endl;
			fr1(i,1,4) cout<<rnd()<<" ";
			cout<<endl;
		}
		else{
			cout<<n[i]<<" "<<n[i]<<endl;
			fr1(i,1,4) cout<<rnd()<<" ";
			cout<<endl;
		}
	}
	ET;
}
//ALL FOR Zhang Junhao.
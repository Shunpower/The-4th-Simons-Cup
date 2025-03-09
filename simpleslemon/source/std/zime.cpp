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
#define ptc putchar
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
int n,q,k,v;
ll qpow(ll b,int p){
	if(!p) return 1;
	ll d=qpow(b,p>>1);
	if(p&1) return d*d%v*b%v;
	else return d*d%v;
}
int a[N];
int f[1000][17];
int bit[N];
bitset <13001> dp;
void add(int p,int x){
	while(p<=n){
		bit[p]+=x;
		p+=lowbit(p);
	}
}
int query(int p){
	int ans=0;
	while(p){
		ans+=bit[p];
		p-=lowbit(p);
	}
	return ans;
}
#define Shun cute 
int main(){
#ifdef Shun
	freopen("zime.in","r",stdin);
	freopen("zime.out","w",stdout);
#endif
	read(n),read(q),read(k),read(v);
	fr1(i,1,n) read(a[i]);
	fr1(i,0,v-1) f[i][0]=qpow(i,k);
	fr1(j,1,16){
		fr1(i,0,v-1) f[i][j]=f[f[i][j-1]][j-1];
	}
	while(q--){
		int op,l,r;
		read(op),read(l),read(r);
		if(op==1){
			if(r-l+1>13){
				ptc('Y'),ptc('E'),ptc('S');
				ptc('\n');
				continue;
			}
			dp.reset();
			dp[0]=1;
			bool flg=0;
			fr1(i,l,r){
				int cnt=query(i);
				int val=a[i];
				fr2(j,16,0) if(cnt>=(1<<j)) val=f[val][j],cnt-=(1<<j);
				val++;
				if((dp&(dp<<val)).any()){
					ptc('Y'),ptc('E'),ptc('S');
					ptc('\n');
					flg=1;
					break;
				} 
				dp|=(dp<<val);
			}
			if(!flg){
				ptc('N'),ptc('O');
				ptc('\n');
			}
		}
		else{
			add(l,1);
			add(r+1,-1);
		}
	}
	ET;
}
//ALL FOR Zhang Junhao.

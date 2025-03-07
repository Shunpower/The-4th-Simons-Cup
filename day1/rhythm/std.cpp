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
// ll remind(int l,int r){
// 	cout<<"? "<<l<<" "<<r<<endl;
// 	ll x;
// 	cin>>x;
// 	return x;
// }
int tc;
vector <ll> ans;
bool type[2010];
struct interval{
	int l,r;
	ll sum;//-1e18 means negative
};
vector <interval> p;
void cover(int l,int r,ll x){
	// cout<<l<<" "<<r<<" "<<x<<endl;
	fr1(i,l,r) ans[i-1]=x;
}
void lefmerge(int id1,int id2,int id3,ll x){
	cover(p[id2].l,p[id2].r,0);
	cover(p[id2].r,p[id2].r,x-(p[id1].sum+p[id3].sum));
	p[id3].sum=x;
	p[id3].l=p[id1].l;
	p.erase(p.begin()+id2);
	p.erase(p.begin()+id1);
}
void rigmerge(int id1,int id2,int id3,ll x){
	// cout<<"!"<<p[id1].sum<<" "<<p[id3].sum<<" "<<x<<endl;
	cover(p[id2].l,p[id2].r,0);
	cover(p[id2].r,p[id2].r,x-(p[id1].sum+p[id3].sum));
	p[id1].sum=x;
	p[id1].r=p[id3].r;
	p.erase(p.begin()+id3);
	p.erase(p.begin()+id2);
}
vector <ll> rhythm(int n,int q,int c){
	p.clear();
	ans.clear();
	ans.resize(n);
	fr1(i,1,n){
		ll x=remind(i,i);
		type[i]=x;
		if(x) ans[i-1]=x;
	}
	int lst=1;
	ll sum=0;
	fr1(i,1,n){
		sum+=ans[i-1];
		if(type[i]!=type[i+1]||i==n){
			p.push_back({lst,i,(type[i]?sum:(ll)-1e18)});
			lst=i+1;
			sum=0;
		}
	}
	if((p.begin()->sum)==-1e18){
		cover(p.begin()->l,p.begin()->r,0);
		p.erase(p.begin());
	}
	if(p.empty()) return ans;
	if(p.back().sum==-1e18){
		cover(p.back().l,p.back().r,0);
		p.pop_back();
	}
	if(p.empty()) return ans;
	while(p.size()>1){
		// for(auto i:p) cout<<i.l<<" "<<i.r<<" "<<i.sum<<endl;
		int pos=-1;
		fr1(i,0,(int)p.size()-1){
			if(p[i].sum!=-1e18){
				if(~pos){
					if(p[i].sum<p[pos].sum) pos=i;
				}
				else pos=i;
			}
		}
		ll x=-1e18,y=-1e18;
		// cout<<"!"<<pos<<endl;
		if(pos!=0) x=remind(p[pos-2].l,p[pos].r);
		if(pos!=(int)p.size()-1) y=remind(p[pos].l,p[pos+2].r);
		if(x==-1e18){
			if(y!=p[pos+2].sum) rigmerge(pos,pos+1,pos+2,y);
			else{
				// cout<<"?"<<endl;
				cover(p[pos+1].l,p[pos+1].r,0);
				cover(p[pos+1].r,p[pos+1].r,-p[pos].sum);
				p.erase(p.begin()+pos+1);
				p.erase(p.begin()+pos);
			}
		}
		else if(y==-1e18){
			if(x!=p[pos-2].sum) lefmerge(pos-2,pos-1,pos,x);
			else{
				cover(p[pos-1].l,p[pos-1].r,0);
				cover(p[pos-1].l,p[pos-1].l,-p[pos].sum);
				p.pop_back();
				p.pop_back();
			}
		}
		else{
			if(x!=p[pos-2].sum) lefmerge(pos-2,pos-1,pos,x);
			else if(y!=p[pos+2].sum) rigmerge(pos,pos+1,pos+2,y);
			else{
				cover(p[pos-1].l,p[pos-1].r,0);
				cover(p[pos-1].l,p[pos-1].l,-p[pos].sum);
				p.erase(p.begin()+pos);
				p.erase(p.begin()+pos-1);
			}
		}
	}
	return ans;
}
// int main(){
// #ifdef Shun
// 	freopen(".in","r",stdin);
// 	freopen(".out","w",stdout);
// #endif
// 	ios::sync_with_stdio(false);
// 	cin>>tc;
// 	while(tc--){
// 		int n;
// 		cin>>n;
// 		vector <ll> ans=rhythm(n,2*n,0);
// 		cout<<"! ";
// 		for(auto i:ans) cout<<i<<" ";
// 		cout<<endl;
// 	}
// 	ET;
// }
//ALL FOR Zhang Junhao.
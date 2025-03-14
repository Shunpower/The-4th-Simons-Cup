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

int test=2;
const int n=500;
const int q=6*n;

mt19937 rnd(time(0));
char C[N];
const int V=2e9+1;
int gval(int l,int r){
	int x=0;
	do{
		x=(int)(rnd()%(r-l+1))+l;
	}while(x==0);
	return x;
}

vector <vector<int>> a;

void valley(){
	vector <int> ans;
	fr1(i,1,n) ans.pb(gval(-1e9,1e9));
	sort(ans.begin(),ans.end(),[](int &x,int &y){
		return abs(x)<abs(y);
	});
	deque <int> q;
	for(auto i:ans){
		int op=rnd()%2;
		if(op) q.push_back(i);
		else q.push_front(i);
	}
	ans.clear();
	for(auto i:q) ans.pb(i);
	a.pb(ans);
}
void the_way_to_the_top(){
	vector <int> ans;
	fr1(i,1,n) ans.pb(gval(-1e9,1e9));
	sort(ans.begin(),ans.end(),[](int &x,int &y){
		return abs(x)>abs(y);
	});
	deque <int> q;
	for(auto i:ans){
		int op=rnd()%2;
		if(op) q.push_back(i);
		else q.push_front(i);
	}
	ans.clear();
	for(auto i:q) ans.pb(i);
	a.pb(ans);
} 
void increasing(){
	vector <int> ans;
	fr1(i,1,n) ans.pb(gval(-1e9,1e9));
	sort(ans.begin(),ans.end(),[](int &x,int &y){
		return abs(x)<abs(y);
	});
	a.pb(ans);
}
void decreasing(){
	vector <int> ans;
	fr1(i,1,n) ans.pb(gval(-1e9,1e9));
	sort(ans.begin(),ans.end(),[](int &x,int &y){
		return abs(x)>abs(y);
	});
	a.pb(ans);
}
void postive(){
	vector <int> ans;
	fr1(i,1,n) ans.pb(gval(1,1e9));
	a.pb(ans);
}
void negative(){
	vector <int> ans;
	fr1(i,1,n) ans.pb(gval(-1e9,-1));
	a.pb(ans);
}
void pos_neg_pos(){
	vector <int> ans;
	fr1(i,1,n){
		if(i&1) ans.pb(gval(1,1e9));
		else ans.pb(gval(-1e9,-1));
	}
	a.pb(ans);
}
void random(){
	vector <int> ans;
	fr1(i,1,n) ans.pb(gval(-1e9,1e9));
	a.pb(ans);
}
int main(){
#ifdef Shun
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	sprintf(C,"rhythm%d.in",test);
	freopen(C,"w",stdout);
	cout<<n<<" "<<q<<" "<<test<<endl;
	while(1){
		label:
		valley();
		valley();
		valley();
		the_way_to_the_top();
		the_way_to_the_top();
		the_way_to_the_top();
		increasing();
		increasing();
		decreasing();
		decreasing();
		postive();
		postive();
		negative();
		negative();
		pos_neg_pos();
		pos_neg_pos();
		random();
		random();
		random();
		random();
		for(auto i:a){
			fr1(j,0,(int)i.size()-1){
				fr1(k,j+1,(int)i.size()-1){
					if(i[j]==i[k]) {
						a.clear();
						goto label;
					}
				}
			}
		}
		for(auto i:a){
			fr1(j,0,(int)i.size()-1) cout<<i[j]<<" \n"[j+1==i.size()];
		}
		break;
	}
	ET;
}
//ALL FOR Zhang Junhao.
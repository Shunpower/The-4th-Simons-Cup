#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=16,M=(1<<N)+10;
int n,m;
int a[M],b[M];
int c[1<<N],pos[1<<N];
int to1[1<<N],to2[1<<N],pos1[1<<N],pos2[1<<N];
bool vis[1<<N];
struct ufset{
	int fa[(2<<N)+10];
	void init(){for(int i=1;i<=2<<n;i++)fa[i]=0;}
	int root(int x){return fa[x]?fa[x]=root(fa[x]):x;}
	void mrg(int x,int y){
		x=root(x),y=root(y);
		if(x!=y)fa[x]=y;
	}
}ufs;
void link(int x,int y){
	ufs.mrg(x+1,y+(1<<n)+1),ufs.mrg(x+(1<<n)+1,y+1);
}
vector<int> cc[(2<<N)+10];
void mian(){//remember to make it first
	cin>>n>>m;
	for(int i=0;i<1<<n;i++)vis[i]=false,c[i]=-1;
	for(int i=1;i<=m;i++)cin>>a[i]>>b[i],c[a[i]]=b[i],pos[b[i]]=a[i],vis[b[i]]=true;
	int now=0;
	for(int i=0;i<1<<n;i++)if(!~c[i]){
		while(vis[now])now++;
		vis[now]=true;
		c[i]=now;pos[now]=i;
	}
//	for(int i=0;i<1<<n;i++)cout<<c[i]<<" \n"[i+1==(1<<n)];
	for(int i=0;i<1<<n;i++)to1[i]=to2[i]=pos1[i]=pos2[i]=i;
	for(int i=n-1;~i;i--){
		for(int j=0;j<1<<n;j++)vis[j]=false;
		for(int j=1;j<=2<<n;j++)cc[j].clear();
		ufs.init();
		for(int j=0;j<1<<n;j++){
			link(pos1[j],pos1[j^1<<i]);
			link(pos[pos2[j]],pos[pos2[j^1<<i]]);
//			cout<<pos1[j]<<" "<<pos1[j^1<<i]<<"!\n";
		}
		for(int j=1;j<=2<<n;j++)cc[ufs.root(j)].pb(j);
		for(int j=1;j<=2<<n;j++){
			for(int k=0;k<cc[j].size();k++){
				int x=(cc[j][k]-1)%(1<<n),y=(cc[j][k]-1)/(1<<n);
				if(vis[x])continue;
				to1[x]=to1[x]^(to1[x]&1<<i)^(y<<i);
				to2[c[x]]=to2[c[x]]^(to2[c[x]]&1<<i)^(y<<i);
			}
		}
		for(int j=0;j<1<<n;j++)pos1[to1[j]]=j,pos2[to2[j]]=j;
//		for(int j=0;j<1<<n;j++)cout<<to1[j]<<" ";puts(",");
//		for(int j=0;j<1<<n;j++)cout<<to2[j]<<" ";puts("!");
	}
	for(int i=0;i<1<<n;i++)assert(to1[i]==to2[c[i]]);
	for(int i=1;i<=m;i++)printf("%d%c",to1[a[i]]," \n"[i==m]);
}
int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    ios::sync_with_stdio(false);
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
    cerr<<clock()<<'\n';
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define mem(x,v) memset(x,v,sizeof(x))

const int N=17;
int t,n,m,x[1<<N],y[1<<N];
int cnt,vis[4<<N],col[4<<N],hd[4<<N],nxt[12<<N],to[12<<N];
int bol[1<<N];
void add(int u,int v){
	nxt[cnt]=hd[u],hd[u]=cnt,to[cnt++]=v;
	nxt[cnt]=hd[v],hd[v]=cnt,to[cnt++]=u;
}
void dfs(int id,int c){
	vis[id]=1,col[id]=c;
	for(int i=hd[id];i;i=nxt[i])if(!vis[to[i]])dfs(to[i],c^1); 
}

void solve(){
	cin>>n>>m;
	// cout<<n<<" "<<m<<endl;
	for(int i=0;i<m;i++) scanf("%d%d",&x[i],&y[i]);
	mem(bol,0);
	for(int i=0;i<m;i++) bol[x[i]]++;
	for(int i=0;i<(1<<n);i++){
		if(bol[i]>1) return cout<<"NO\n",void();
	}
	mem(bol,0);
	for(int i=0;i<m;i++) bol[y[i]]++;
	for(int i=0;i<(1<<n);i++){
		if(bol[i]>1) return cout<<"NO\n",void();
	}
	for(int i=n-1;~i;i--){
		// cout<<i<<endl;
		mem(vis,0),mem(col,0),mem(hd,0),cnt=0;
		for(int j=0;j<m;j++)add(x[j],y[j]+(3<<n)),add(x[j]+(1<<n),y[j]+(2<<n));
		for(int j=0;j<1<<n;j++)add(j,j+(1<<n)),add(j+(2<<n),j+(3<<n));
		for(int j=0;j<1<<n;j++)if((j>>i)&1)
			add(j,j-(1<<i)),add(j+(1<<n),j-(1<<i)+(1<<n)),
			add(j+(2<<n),j+(2<<n)-(1<<i)),
			add(j+(3<<n),j+(3<<n)-(1<<i));
		for(int j=0;j<4<<n;j++)if(!vis[j])dfs(j,0);
		for(int j=0;j<m;j++){
			if(col[x[j]])x[j]-=(x[j]>>i&1)<<i;
			else x[j]+=(!(x[j]>>i&1))<<i;
			if(col[y[j]+(2<<n)])y[j]-=(y[j]>>i&1)<<i;
			else y[j]+=(!(y[j]>>i&1))<<i;
		} 
	}
	cout<<"YES\n";
	for(int i=0;i<m;i++)cout<<x[i]<<(i==m-1?'\n':' ');
}
int main(){
	freopen("fearless.in","r",stdin);
	freopen("fearless.out","w",stdout);
	// ios::sync_with_stdio(false);
	cin>>t;
	while(t--)solve();
	cerr<<clock()<<'\n';
	return 0;
}
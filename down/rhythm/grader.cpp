//Author:KIT / Shunpower
//Cloud Island & Rain Temperature
//May the force be with you and me.
#include "rhythm.h"
#include <stdio.h>
#include <assert.h>
#include <vector>
#include <iostream>
namespace Shun_Li_Cheng_Zhang{
	int tc;
	int n,q,c;
	std::vector <long long> tmp;
	long long a[2001],b[2001],sum[2001];
	long long mss[2001][2001],mssb[2001];
	bool flg;
	long long remind(int l,int r){
		if(flg) return -1000000000000000000ll;
		if(l<1||r>n||q==0||l>r){
			flg=1;
			std::cout<<"Wrong Answer: Invalid call"<<std::endl;
			return -1000000000000000000ll;
		}
		q--;
		return mss[l][r];
	}
	void main(){
		assert(scanf("%d%d%d",&n,&q,&c)==3);
		int orgq=q;
		for(int _=1;_<=20;_++){
			flg=0;
			q=orgq;
			for(int i=1;i<=n;i++) assert(scanf("%lld",&a[i])==1); 
			for(int i=1;i<=n;i++){
				mss[i][i-1]=-1e18;
				long long minn=0;
				sum[i-1]=0;
				for(int j=i;j<=n;j++){
					sum[j]=sum[j-1]+a[j];
					mss[i][j]=std::max(0ll,mss[i][j-1]);
					mss[i][j]=std::max(mss[i][j],sum[j]-minn);
					minn=std::min(sum[j],minn);
				}
			}
			tmp=rhythm(n,q,c);
			if(flg) return;
			for(int i=1;i<=n;i++){
				if(b[i]<-1000000000000000ll||b[i]>1000000000000000ll){
					std::cout<<"Wrong Answer: Unlike Simons"<<std::endl;
					return;
				}
				b[i]=tmp[i-1];
			}
			for(int i=1;i<=n;i++){
				mssb[i-1]=-1e18;
				long long minn=0;
				sum[i-1]=0;
				for(int j=i;j<=n;j++){
					sum[j]=sum[j-1]+a[j];
					mssb[j]=std::max(0ll,mssb[j-1]);
					mssb[j]=std::max(mssb[j],sum[j]-minn);
					minn=std::min(sum[j],minn);
					if(mssb[j]!=mss[i][j]){
						std::cout<<"Wrong Answer: Unlike Simons"<<std::endl;
						return;
					}
				}
			}
			std::cout<<"OK: Simons did it"<<std::endl;
		}
	}
}
long long remind(int l,int r){
	return Shun_Li_Cheng_Zhang::remind(l,r);
}
int main(){
	// freopen("rhythm.in","r",stdin);
	// freopen("rhythm.out","w",stdout);
	Shun_Li_Cheng_Zhang::main();
}
//ALL FOR Zhang Junhao.

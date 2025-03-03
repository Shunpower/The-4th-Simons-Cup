#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=2007072007;
const int N=1010;
ll pre[N];
ll f1[N][N<<1],f2[N][N<<1];
int n;
ll qpow(ll b,ll p){
    if(!p) return 1;
    ll d=qpow(b,p>>1);
    if(p&1) return d*d%mod*b%mod;
    else return d*d%mod;
}
void solve(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> pre[i];
        pre[i] = pre[i-1] + pre[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n*2;j++){
            int l = max(1,i-j) , r = min(n,i+j);
            f1[i][j] = max(pre[i]-pre[l-1],pre[r]-pre[i-1]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n*2;j++){
            f2[i][j] = max(f2[i-1][j-1],f1[i][j]);
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=1;j<=n*2;j++){
            f1[i][j] = max(f1[i+1][j-1],f1[i][j]);
        }
    }
    ll ans =0;
    for(int i=1;i<=n;i++){
        ll res = 0;
        for(int j=1;j<=n*2;j++){
            res ^= 1ll * j * max(f1[i][j],f2[i][j]);
        }
        res%=mod;
        (ans += (qpow(2,i) * res)%mod)%=mod;
    }
    cout << ans << '\n';
}
int main(){
    solve();
    return 0;
}
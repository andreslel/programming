#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll MOD = 1000000007;

ll binExp(ll x, ll n, ll p){
    ll ans = 1;

    while(n){
        if(n&1) ans = (ans*x)%p;
        n >>=1;
        x*=x;
        if(x >= p) x %= p;
    }
    return ans;
}

ll modInverse(ll x, ll p){
    return binExp(x,p-2,p);
}

ll factorials[1000000];

int main(){
    factorials[0] = 1;
    for(ll i = 1; i < 1000000;++i){
        factorials[i] = factorials[i-1]*i;
        if(factorials[i] >= MOD)
            factorials[i] %= MOD;
    }
    int t;
    scanf(" %d",&t);
    while(t--){
        ll m,n;
        scanf(" %lld %lld",&m,&n);
        ll ans = 0;
        for(ll i = 0; i <= m-n;++i){
            ll imp = factorials[m-i-1];
            imp *= modInverse((factorials[n-1]*factorials[m-i-n])%MOD,MOD);
            if(imp >= MOD) imp %= MOD;
            imp *= binExp(n,i,MOD);
            if(imp >= MOD) imp %= MOD;
            imp *= binExp(n-1,m-n-i,MOD);
            if(imp >= MOD) imp %= MOD;
            ans += imp;
            if(ans >= MOD) ans -= MOD;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
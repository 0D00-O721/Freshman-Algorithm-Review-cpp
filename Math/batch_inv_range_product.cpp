#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=1054*1054+185*185;
const int N=1e6+10;
ll a[N],sum=1,Inv,ans;
ll aff[N],pre[N];
int n,q;

ll fastp(ll b,ll p){
    if(!p) return 1;
    ll k=1;
    while(p){
        if(p&1) k=(k*b)%M;
        p>>=1;
        b=(b*b)%M;
    }return k;
}

int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        sum=(sum*a[i])%M;
    }
    Inv=fastp(sum,M-2);

    pre[0]=1,aff[n+1]=1;
    for(int i=1;i<=n;i++) pre[i]=(pre[i-1]*a[i])%M;
    for(int i=n;i>=1;i--) aff[i]=(aff[i+1]*a[i])%M;
    
    while(q--){
        int l,r;
        scanf("%d%d",&l,&r);
        ll ans1=(pre[r]*((Inv*aff[l])%M))%M;
        ans^=ans1;
    }
    printf("%lld",ans);
    return 0;
}
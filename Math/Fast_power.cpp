#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1145141;
ll b,p;

ll fastpow(ll b,ll p){
    if(!p) return 1;
    ll s=1;
    while(p>1){
        if(p&1){
            s=(s*b)%M;
            p--;
        }
        b=(b*b)%M;
        p>>=1;
    }
    return (s*b)%M;
}

int main(){
    scanf("%lld%lld",&b,&p);
    ll ans=fastpow(b,p);
    printf("%lld",ans);
    return 0;
}
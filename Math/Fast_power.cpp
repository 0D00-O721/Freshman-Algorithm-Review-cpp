#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1145141;
ll b,p;

ll fastpow(ll b,ll p){
    if(!p) return 1;
    ll k=1;
    while(p){
        if(p&1) k=(k*b)%M;
        p>>=1;
        b=(b*b)%M;
    }return k;
}

int main(){
    scanf("%lld%lld",&b,&p);
    ll ans=fastpow(b,p);
    printf("%lld",ans);
    return 0;
}
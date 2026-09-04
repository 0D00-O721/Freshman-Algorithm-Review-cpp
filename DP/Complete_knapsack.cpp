#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+10;
const int T=1e7+10;
ll f[T],v[N],w[N];
int m,t;
int main(){
    scanf("%d%d",&t,&m);
    for(int i=1;i<=m;i++){
        scanf("%lld%lld",&w[i],&v[i]);
    }
    for(int i=1;i<=m;i++){
        for(int j=w[i];j<=t;j++){
            f[j]=max(f[j],f[j-w[i]]+v[i]);
        }
    }printf("%lld",f[t]);
}
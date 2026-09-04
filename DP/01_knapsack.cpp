#include<bits/stdc++.h>
using namespace std;
const int N=114;
const int T=1145;
int f[T],w[N],v[N];
int t,m;

int main(){
    scanf("%d%d",&t,&m);
    for(int i=1;i<=m;i++) scanf("%d%d",&w[i],&v[i]);
    for(int i=1;i<=m;i++){
        for(int j=t;j>=w[i];j--){
            f[j]=max(f[j],f[j-w[i]]+v[i]);
        }
    }
    printf("%d",f[t]);
    return 0;
}
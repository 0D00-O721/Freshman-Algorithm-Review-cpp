#include<bits/stdc++.h>
using namespace std;
const int N=1e8+10;
const int M=6e6+10;
bool vis[N];
int p[M],cnt=0,n,q;

void ola(int n){
    memset(vis,0,n*sizeof(bool));
    for(int i=2;i<=n;i++){
        if(!vis[i]){
            p[++cnt]=i;
        }for(int j=1;(1ll*p[j]*i)<=n;j++){
            vis[p[j]*i]=1;
            if(!(i%p[j])) break;
        }
    }
}

int main(){
    scanf("%d%d",&n,&q);
    ola(n);
    while(q--){
        int k;
        scanf("%d",&k);
        printf("%d\n",p[k]);
    }
    return 0;
}
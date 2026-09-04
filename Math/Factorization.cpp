#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
const int M=5e6+10;
int vis[N],p[M],cnt;
int n;

void ola(int n){
    for(int i=2;i<=n;i++){
        if(!vis[i]) p[++cnt]=i;
        for(int j=1;1ll*p[j]*i<=n;j++){
            vis[i*p[j]]=p[j];    //这里将欧拉筛模板中的“标记为真”改为“标记为最小质因子”
            if(!(i%p[j])) break;
        }
    }
}

int main(){
    scanf("%d",&n);
    ola(n);
    while(vis[n]){
        printf("%d*",vis[n]);
        n/=vis[n];
    }printf("%d",n);
    return 0;
}
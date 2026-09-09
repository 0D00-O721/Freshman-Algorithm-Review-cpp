#include<bits/stdc++.h>
using namespace std;
const int N=6e3+10;
int dp[N][2];
vector<int> e[N];
int r[N],ind[N];
int n,s;

void DFS(int u){
    dp[u][1]=r[u];
    if(e[u].empty()) return;
    for(auto it:e[u]){
        DFS(it);
        dp[u][1]+=dp[it][0];
        dp[u][0]+=max(dp[it][0],dp[it][1]);
    }
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&r[i]);
    for(int i=1,l,k;i<=n-1;i++){
        scanf("%d%d",&l,&k);
        e[k].push_back(l);
        ind[l]=1;
    }
    for(int i=1;i<=n;i++) if(!ind[i]) s=i;

    DFS(s);

    printf("%d",max(dp[s][0],dp[s][1]));
    return 0;
}
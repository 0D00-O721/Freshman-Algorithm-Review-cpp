#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
vector<pair<int,int>> g[114];
bool flag[114];
int dp[N];
int n,m,k;

int main(){
    scanf("%d%d",&m,&n);
    for(int i=1,w,v,ki;i<=n;i++){
        scanf("%d%d%d",&w,&v,&ki);
        g[ki].push_back({w,v});
        flag[ki]=1;
    }

    for(int i=1;i<=114;i++){
        if(!flag[i]){
            k=i-1;
            break;
        }
    }

    for(int i=1;i<=k;i++){
        for(int j=m;j>0;j--){
            for(auto it:g[i]){
                int w=it.first;
                int v=it.second;
                if(j>=w) dp[j]=max(dp[j],dp[j-w]+v);
            }
        }
    }

    printf("%d",dp[m]);
    return 0;
}
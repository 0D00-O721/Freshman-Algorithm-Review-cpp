#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
vector<pair<int,int>> g[114];
bool flag[114];
int dp[N][N];
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
    //printf("k=%d\n",k);

    for(int i=1;i<=k;i++){
        //printf("第%d组\n",i);
        for(auto s:g[i]){
            int w = s.first;
            int v = s.second;
            //printf("{%d,%d}\n",w,v);
            for(int j = 1; j <= m; j++){
                dp[i][j]=max(dp[i][j],dp[i-1][j]);
                if(j>=w) dp[i][j] = max(dp[i][j], dp[i-1][j-w]+v);
            }
        }
    }

    printf("%d",dp[k][m]);
    return 0;
}
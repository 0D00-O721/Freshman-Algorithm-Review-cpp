#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+10;
ll a[N][N];
ll sum[N][N],maxn;
int n,m,q,maxi,maxj;

void init(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            sum[i][j]=a[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    }
}

ll query(int x1,int y1,int x2,int y2){
    return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
}

int main(){
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%lld",&a[i][j]);
        }
    }
    init();
    while(q--){
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        printf("%lld\n",query(x1,y1,x2,y2));
    }
    return 0;
}
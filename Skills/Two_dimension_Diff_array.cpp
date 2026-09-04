#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1010;
ll a[N][N];
ll dif[N][N];
int n,m,q;

void construct_dif(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dif[i][j]=a[i][j]-a[i-1][j]-a[i][j-1]+a[i-1][j-1];
        }
    }
}

void presum(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            a[i][j]=dif[i][j]+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        }
    }
}

void add(int x1,int y1,int x2,int y2,int x){
    dif[x1][y1]+=x;
    dif[x2+1][y2+1]+=x;
    dif[x1][y2+1]-=x;
    dif[x2+1][y1]-=x;
}

int main(){
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%lld",&a[i][j]);
        }
    }
    construct_dif();
    while(q--){
        int x1,y1,x2,y2,x;
        scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&x);
        add(x1,y1,x2,y2,x);
    }
    presum();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%d ",a[i][j]);
        }printf("\n");
    }
    return 0;
}

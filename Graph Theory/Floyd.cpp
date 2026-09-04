#include<bits/stdc++.h>
using namespace std;
const int N=211;
int d[N][N];
int n;

void Floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
}

int main(){
    memset(d,0x3f,sizeof(d));
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            scanf("%d",&d[i][j]);
        }
    }
    for(int i=1;i<=n;i++) d[i][i]=0;
    Floyd();
    printf("%d",d[1][n]);
    return 0;
}
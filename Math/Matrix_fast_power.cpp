#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=114;
const ll M=1e9+7;
ll a[N][N],s[N][N],cp1[N][N],cp2[N][N];
int n,k;

void MM(ll ans[][N],ll a[][N],ll b[][N]){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cp1[i][j]=a[i][j];
            cp2[i][j]=b[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ll sum=0;
            for(int k=1;k<=n;k++) sum=(sum+(cp1[i][k]*cp2[k][j])%M)%M;
            ans[i][j]=sum;
        }
    }return;
}

void MatrixFP(ll a[][N],int p){
    while(p>1){
        if(p&1){
            p--;
            MM(s,s,a);
        }
        p>>=1;
        MM(a,a,a);
    }
    MM(a,s,a);
    return;
}

int main(){
    scanf("%d%d",&n,&k);

    for(int i=1;i<=n;i++) s[i][i]=1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%lld",&a[i][j]);
        }
    }

    if(!k){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                printf("%lld ",s[i][j]);
            }printf("\n");
        }return 0;
    }


    MatrixFP(a,k);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%lld ",a[i][j]);
        }printf("\n");
    }
    return 0;
}
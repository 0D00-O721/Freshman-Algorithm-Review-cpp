#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=21;
int m[N][M];
int n,q;

void presolve(){
    for(int i=1;i<=20;i++){
        for(int j=1;j+(1<<i)-1<=n;j++){
            m[j][i]=max(m[j][i-1],m[j+(1<<(i-1))][i-1]);
        }
    }
}

int findmax(int l,int r){
    int lth=log2(r-l+1);
    return max(m[l][lth],m[r-(1<<lth)+1][lth]);
}

int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%d",&m[i][0]);
    
    presolve();
    
    while(q--){
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",findmax(l,r));
    }
    return 0;
}
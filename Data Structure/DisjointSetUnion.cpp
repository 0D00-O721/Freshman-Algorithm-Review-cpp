#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int n,q;

int find(int x){
    if(a[x]==x) return x;
    return a[x]=find(a[x]);//边查询边压缩
}

void merge(int x,int y){
    a[find(y)]=find(x);
}



int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) a[i]=i;
    while(q--){
        int op,x,y;
        scanf("%d%d%d",&op,&x,&y);
        if(op==1){
            merge(x,y);
        }else{
            if(find(x)==find(y)) printf("Y\n");
            else printf("N\n");
        }
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],t[N];
int n,m;

//lowbit函数：返回最低位1的位置对应二进制数的十进制数
int lowbit(int x){
    return x & (-x);
}

void build(){
    for(int i=1;i<=n;i++){
        t[i+lowbit(i)]+=t[i];
    }
}

void modify(int idx,int x){
    for(int i=idx;i<=n;i+=lowbit(i)){
        t[i]+=x;
    }
}

int quest(int x){
    int ans=0;
    for(int i=x;i>0;i-=lowbit(i)){
        ans+=t[i];
    }return ans;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&t[i]);
    build();
    while(m--){
        int c,x,y;
        scanf("%d%d%d",&c,&x,&y);
        if(c==1){
            modify(x,y);
        }else{
            printf("%d\n",(quest(y)-quest(x-1)));
        }
    }
    return 0;
}

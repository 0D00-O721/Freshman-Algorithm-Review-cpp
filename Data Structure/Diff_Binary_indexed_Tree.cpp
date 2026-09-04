#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll t[N];
int a[N];
int n,m;

int lowbit(int x){
    return x & (-x);
}

void build(){
    for(int i=1;i<=n;i++){
        int p=i+lowbit(i);
        if(p<=n) t[p]+=t[i];
    }
}

void modify(int x,int k){
    for(int i=x;i<=n;i+=lowbit(i)){
        t[i]+=k;
    }
}

ll quest(int x){
    ll ans=0;
    for(int i=x;i>=1;i-=lowbit(i)){
        ans+=t[i];
    }return ans;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        t[i]=a[i]-a[i-1];
    }
    build();

    while(m--){
        int c;
        scanf("%d",&c);
        if(c==2){
            int x2;
            scanf("%d",&x2);
            printf("%lld\n",quest(x2));
        }else{
            int x,y,k;
            scanf("%d%d%d",&x,&y,&k);
            modify(x,k);
            modify(y+1,-k);
        }
    }
    return 0;
}
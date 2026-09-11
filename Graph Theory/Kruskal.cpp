#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+10;
const int M=2e5+10;
int fa[N];
int n,m,cnt,num;
ll ans;

int find(int x){    //压路查询
    if(fa[x]==x) return x;
    return fa[x] = find(fa[x]);
}

void merge(int u,int v){    //并查集融合
    fa[find(v)] = find(u);
}

struct line{
    int w,u,v;
}l[M];

bool cmp(line l1,line l2){
    return l1.w<l2.w;
}

void kruskal(){
    for(int i=1;i<=n;i++) fa[i] = i; //初始化并查集
    for(int i=1;i<=cnt;i++){
        if( find(l[i].u) == find(l[i].v) ) continue;
        merge(l[i].u, l[i].v);
        ans += l[i].w;
        num++;
    }
    if(num == n-1) printf("%lld",ans);
    else printf("orz");
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u1,v1,w1;
        scanf("%d%d%d",&u1,&v1,&w1);
        l[++cnt].u = u1;
        l[cnt].v = v1;
        l[cnt].w = w1;
    }

    sort(l+1,l+cnt+1,cmp);

    kruskal();

    return 0;
}
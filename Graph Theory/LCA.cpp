#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
vector<int> e[N];
int fa[N][21]; //节点i的第2^j级祖先
int dep[N];
int n,m,s;

void BFS(){    //处理每个节点的第2^0级祖先
    dep[s]=1;
    queue<int> q;
    q.push(s);
    while(q.size()){
        int t = q.front();
        q.pop();
        for(auto v:e[t]){
            if(dep[v]) continue;
            dep[v] = dep[t]+1;
            fa[v][0] = t;
            q.push(v);
        }
    }
}

void init(){
    for(int k=1;k<=20;k++){
        for(int i=1;i<=n;i++){
            fa[i][k] = fa[fa[i][k-1]][k-1];
        }
    }
}

int LCA(int u,int v){   //LCA(保证u比v浅)
    if(dep[u]>dep[v]) swap(u,v);
    //将v提到u的高度
    for(int k=20;k>=0;k--){
        if(dep[ fa[v][k] ] < dep[u]) continue;
        v = fa[v][k];
    }
    if(u==v) return u;
    //一起往上提
    for(int k=20;k>=0;k--){
        if(fa[u][k]==fa[v][k]) continue;
        u = fa[u][k];
        v = fa[v][k];
    }return fa[u][0];
}

int main(){
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1,u,v;i<=n-1;i++){
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }

    BFS();
    init();

    while(m--){
        int u,v;
        scanf("%d%d",&u,&v);
        printf("%d\n",LCA(u,v));
    }
    
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
const int inf=2147483647;
int vis[N],d[N];        //在别处使用的时候考虑一下要不要开longlong
int n,m,s;
struct node{
    int v,w;
};
priority_queue<pair<int,int>> q;
vector <node> e[N];

void dijkstra(){
    for(int i=0;i<=n;i++) d[i]=inf;
    d[s]=0;
    q.push({0,s});
    while(q.size()){
        auto t=q.top();
        q.pop();
        int u=t.second;
        if(vis[u]) continue;
        vis[u]=1;
        for(auto ed:e[u]){
            int v=ed.v,w=ed.w;
            if(d[u]+w<d[v]){
                d[v]=d[u]+w;
                q.push({-d[v],v});
            }
        }

    }
}

int main(){
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1,u,v,w;i<=m;i++){
        scanf("%d%d%d",&u,&v,&w);
        e[u].push_back({v,w});
    }
    dijkstra();
    for(int i=1;i<=n;i++){
        printf("%d ",d[i]);
    }
    return 0;
}
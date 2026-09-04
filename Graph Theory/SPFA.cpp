#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
const int inf=2147483647;
struct node{
    int v,w;
};
vector <node> e[N];
int Inq[N],d[N];
int n,m,s;

void SPFA(){
    for(int i=0;i<=n;i++) d[i]=inf;
    d[s]=0;
    queue <int> q;
    q.push(s);
    Inq[s]=1;
    while(q.size()){
        int u=q.front();
        q.pop();
        Inq[u]=0;
        for(auto ed:e[u]){
            int w=ed.w,v=ed.v;
            if(d[u]+w<d[v]){
                d[v]=d[u]+w;
                if(!Inq[v]){
                    q.push(v);
                    Inq[v]=1;
                }
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
    SPFA();
    for(int i=1;i<=n;i++) printf("%d ",d[i]);
    return 0;
}
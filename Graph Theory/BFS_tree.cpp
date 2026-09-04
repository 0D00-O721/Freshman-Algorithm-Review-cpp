#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
vector<int> e[N];
bool tag[N];
int n;

void BFS(){
    queue<int> q;
    q.push(1);
    tag[1]=1;

    while(q.size()){
        int u=q.front();
        for(auto i:e[u]){
            if(!tag[i]){
                q.push(i);
                tag[i]=1;
            }
        }
        printf("%d ",u);
        q.pop();
        
    }
    return;
}

int main(){
    scanf("%d",&n);
    memset(tag,0,sizeof(tag));
    
    for(int i=1,u,v;i<=n-1;i++){
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }

    for(int i=1;i<=n;i++){
        sort(e[i].begin(),e[i].end());
    }

    BFS();
    return 0;
}

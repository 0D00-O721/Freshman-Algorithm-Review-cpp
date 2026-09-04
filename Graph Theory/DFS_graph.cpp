#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
vector<int> e[N];
int tag[N];
int n;

//DFS遍历+标记+输出
void DFS(int u){
    tag[u]=1;
    printf("%d ",u);
    for(auto i:e[u]){
        if(!tag[i]){
            DFS(i);
        }
    }
    return;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }

    //对邻接表中每个点的出点进行排序，以达到总字典序的最小
    for(int i=1;i<=n;i++){
        sort(e[i].begin(),e[i].end());
    }

    //从根开始遍历
    DFS(1);
    return 0;
}
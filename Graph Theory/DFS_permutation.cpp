#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int tag[N],path[N];
int n;

void DFS(int pos){
    if(pos>n){
        for(int i=1;i<=n;i++){
            printf("%d ",path[i]);
        }printf("\n");
        return;
    }

    for(int i=1;i<=n;i++){
        if(tag[i]==0){
            path[pos]=i;
            tag[i]=1;
            DFS(pos+1);
            tag[i]=0;
        }
    }
}

int main(){
    memset(tag,0,sizeof(tag));
    scanf("%d",&n);
    DFS(1);
    return 0;
}
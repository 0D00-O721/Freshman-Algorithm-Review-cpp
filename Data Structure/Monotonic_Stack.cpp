#include<bits/stdc++.h>
using namespace std;
const int N=3e6+10;
int a[N],n;
stack <pair<int,int>> stk;
int main(){
    scanf("%d",&n);
    for(int i=1,u;i<=n;i++){
        scanf("%d",&u);
        if(stk.empty() || stk.top().first>=u){
            stk.push({u,i});
        }else{
            while(!stk.empty() && stk.top().first<u){
                a[stk.top().second]=i;
                stk.pop();
            }stk.push({u,i});
        }
    }
    for(int i=1;i<=n;i++) printf("%d ",a[i]);
    return 0;
}
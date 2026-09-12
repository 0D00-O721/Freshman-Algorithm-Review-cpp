#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
char m[N],p[N];
int border[N];
int lm,lp;

void KMP(){
    int cur=1;
    //求border(最长相同真前后缀)
    for(int i=2;i<=lm;i++){
        while(cur>1 && m[cur]!=m[i]) cur = border[cur-1]+1;
        if(m[i] == m[cur]) cur++;
        border[i] = cur-1;
    }
    //匹配原字符串
    cur=1;
    for(int i=1;i<=lp;i++){
        while(cur>1 && m[cur]!=p[i]) cur = border[cur-1]+1;
        if(m[cur] == p[i]) cur++;
        if(cur == lm+1){
            printf("%d\n",i-lm+1);
            cur = border[cur-1]+1;
        }
    }
}


int main(){
    scanf("%s%s",p+1,m+1);
    lm = strlen(m+1);
    lp = strlen(p+1);

    KMP();
    for(int i=1;i<=lm;i++) printf("%d ",border[i]);
    return 0;
}
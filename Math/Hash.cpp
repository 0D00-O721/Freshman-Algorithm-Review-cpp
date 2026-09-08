#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+2e5;
const int M=1e9+9;
const int LN=1515;
const ll B=1145141;
unordered_set<ll> us;
ll Bp[LN];
char c[LN];
int n,cnt;

void init(){
    Bp[0]=1;
    for(int i=1;i<=LN;i++) Bp[i]=(Bp[i-1]*B)%M;
}

void Hash(int l){
    ll hash=0;
    for(int i=1;i<=l;i++) hash=(hash+(c[i] * Bp[l-i])%M )%M;
    //printf("%d\n",hash);
    us.insert(hash);
}

int main(){
    init();
    scanf("%d",&n);
    while(n--){
        scanf("%s",c+1);
        int lth=strlen(c+1);
        Hash(lth);
    }
    printf("%d",us.size());

    return 0;
}

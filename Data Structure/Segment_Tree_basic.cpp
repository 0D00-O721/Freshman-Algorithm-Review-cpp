#include <bits/stdc++.h>
#define lc u<<1
#define rc (u<<1)+1
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;

struct Node {
    ll sum, add, mul;       //x * mul + add
}t[4*N];

ll a[N];
int n, m;

void pushup(int u) {
    t[u].sum = t[lc].sum + t[rc].sum;
}

// 把变换 (mul, add) 作用到节点 u 上，区间长度为 len
void apply(int u, ll mul, ll add, int len) {
    t[u].sum = t[u].sum * mul + add * len;
    t[u].mul *= mul;
    t[u].add  = t[u].add * mul + add;
}

void pushdown(int u, int l, int r) {
    if (t[u].mul == 1 && t[u].add == 0) return;
    int mid = (l+r)/2;
    apply(lc, t[u].mul, t[u].add, mid-l+1);
    apply(rc, t[u].mul, t[u].add, r-mid);
    t[u].mul = 1;
    t[u].add = 0;
}

void build(int u, int l, int r) {
    t[u].mul = 1;
    t[u].add = 0;
    if (l == r) {
        t[u].sum = a[l];
        return;
    }
    int mid = (l+r)/2;
    build(lc, l, mid);
    build(rc, mid+1, r);
    pushup(u);
}

// 区间乘 v
void update_mul(int u, int l, int r, int ql, int qr, ll v) {
    if(ql <= l && r <= qr) {
        apply(u,v,0,r-l+1);
        return;
    }
    pushdown(u,l,r);
    int mid = (l+r)/2;
    if (ql<=mid) update_mul(lc,l,mid,ql,qr,v);
    if (qr>mid) update_mul(rc,mid+1,r,ql,qr,v);
    pushup(u);
}

// 区间加 v
void update_add(int u, int l, int r, int ql, int qr, ll v) {
    if(ql <= l && r <= qr) {
        apply(u,1,v,r-l+1);
        return;
    }
    pushdown(u,l,r);
    int mid = (l+r)/2;
    if (ql<=mid) update_add(lc,l,mid,ql,qr,v);
    if (qr>mid) update_add(rc,mid+1,r,ql,qr,v);
    pushup(u);
}

// 区间求和
ll query_sum(int u, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) return t[u].sum;
    pushdown(u,l,r);
    int mid = (l+r)/2;
    ll res = 0;
    if (ql<=mid) res += query_sum(lc,l,mid,ql,qr);
    if (qr>mid) res += query_sum(rc,mid+1,r,ql,qr);
    return res;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    build(1,1,n);
    while(m--){
        int op,x,y;
        ll k;
        scanf("%d",&op);
        if(op==1){
            scanf("%d%d%lld",&x,&y,&k);
            update_add(1,1,n,x,y,k);
        }else{
            scanf("%d%d",&x,&y);
            printf("%lld\n",query_sum(1,1,n,x,y));
        }
    }
    return 0;
}
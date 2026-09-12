#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
deque<int> q;
int a[N];
int n,k;

void RangeMin(){
    for(int i=1;i<=n;i++){
        while(!q.empty() && a[q.back()] > a[i]) q.pop_back();
        q.push_back(i);
        while(!q.empty() && q.front() < i-k+1) q.pop_front();
        if(i>=k) printf("%d ",a[q.front()]);
    }
    printf("\n");
}

void RangeMax(){
    for(int i=1;i<=n;i++){
        while(!q.empty() && a[q.back()] < a[i]) q.pop_back();
        q.push_back(i);
        while(!q.empty() && q.front() < i-k+1) q.pop_front();
        if(i>=k) printf("%d ",a[q.front()]);
    }
    printf("\n");
}

int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);

    RangeMin();
    q.clear();
    RangeMax();

    return 0;
}
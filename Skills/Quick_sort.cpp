#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],n;

void quick_sort(int l,int r){
    if(r<=l) return;
    int mid=l+rand()%(r-l+1);
    int base=a[mid];
    swap(a[mid],a[r]);
    int il=l-1;
    for(int j=l;j<r;j++){
        if(a[j]<=base){
            il++;
            swap(a[il],a[j]);
        }
    }swap(a[r],a[il+1]);
    quick_sort(l,il);
    quick_sort(il+2,r);
}

int main(){
    srand(time(0));
    //printf("%d\n",rand());
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    quick_sort(1,n);
    for(int i=1;i<=n;i++){
        printf("%d ",a[i]);
    }

    return 0;
}
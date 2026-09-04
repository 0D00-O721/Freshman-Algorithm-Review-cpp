#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],c[N],n;

void gb_sort(int l,int r){  //功能：把给定数组的l-r区间排好序
    if(r-l<=1){
        if(a[l]>a[r]) swap(a[l],a[r]); //处理单、双元素问题
    }else{
        int mid=(l+r)/2;
        //切成两半，各自排好序
        gb_sort(l,mid);
        gb_sort(mid+1,r);
        //双指针整合两个有序数组
        int il=l,ir=mid+1,cnt=l-1;
        while(il<=mid && ir<=r){
            if(a[il]<=a[ir]) c[++cnt]=a[il++];
            else c[++cnt]=a[ir++];
        }
        //处理没跑完的那个指针
        while(il<=mid) c[++cnt]=a[il++];
        while(ir<=r) c[++cnt]=a[ir++];
        //存回原数组
        for(int i=l;i<=r;i++) a[i]=c[i];
    }
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    gb_sort(1,n);
    for(int i=1;i<=n;i++) printf("%d ",a[i]);
    return 0;
}
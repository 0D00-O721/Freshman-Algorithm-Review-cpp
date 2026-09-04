#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
int v[N],n,m;

//注意事项
//1.找第一个就先判、挪后边界
//2.找最后一个就先判、挪前边界
//3.有>=或<=的判断就让f或b与m相等而不能越过
//4.哪个边界要越过m，就对哪一方进行取整


//二分查找1：在单调不减数组中的第一个出现位置
int tfind_up_f(int x){
    int f=1,b=n,m;

    while(f<b){
        m=(f+b)/2;        //向下取整
        if(v[m]>=x) b=m;  
        else f=m+1;
    }

    if(v[f]==x) return f;
    else return -1;
}


//二分查找2：在单调不减数组中的最后一个出现位置
int tfind_up_b(int x){
    int f=1,b=n,m;

    while(f<b){
        m=(f+b+1)/2;        //向上取整
        if(v[m]<=x) f=m;  
        else b=m-1;
    }

    if(v[f]==x) return f;
    else return -1;
}

//二分查找3：在单调不增数组中的第一个出现位置
int tfind_low_f(int x){
    int f=1,b=n,m;

    while(f<b){
        m=(f+b)/2;        //向下取整
        if(v[m]<=x) b=m;  
        else f=m+1;
    }

    if(v[f]==x) return f;
    else return -1;
}

//二分查找4：在单调不增数组中的最后一个出现位置
int tfind_low_b(int x){
    int f=1,b=n,m;

    while(f<b){
        m=(f+b+1)/2;        //向上取整
        if(v[m]>=x) f=m;  
        else b=m-1;
    }

    if(v[f]==x) return f;
    else return -1;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&v[i]);
    }
    for(int i=1;i<=m;i++){
        int j,ans;
        scanf("%d",&j);
        ans=tfind_low_b(j);
        printf("%d ",ans);
    }
    return 0;
}
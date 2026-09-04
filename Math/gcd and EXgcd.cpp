#include<bits/stdc++.h>
using namespace std;

int gcd2(int a,int b){
    if(!b) return a;
    return gcd2(b,a%b);
}

int exgcd(int a,int b,int &x,int &y){
    if(!b){
        x=1,y=0;
        return a;
    }
    int d,x1,y1;
    d=exgcd(b,a%b,x1,y1);
    x=y1;
    y=x1-(a/b)*y1;
    return d;
}

int main(){
    int a,b,x,y;
    scanf("%d%d",&a,&b);
    exgcd(a,b,x,y);
    printf("x=%d,y=%d",x,y);
    return 0;
}
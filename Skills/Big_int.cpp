#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
char p1[N],p2[N],ans[N];
int lth1,lth2;

void strrev(char* arr,int lth){
    for(int i=1;i<=(lth+1)/2;i++){
        swap(arr[i],arr[lth-i+1]);
    }
}

void revprint(char* arr){
    int lth=strlen(arr+1);
    for(int i=lth;i>=1;i--){
        printf("%c",arr[i]);
    }
}

void hplus(char* p1,char* p2,int l1,int l2){
    int icc=0;
    int maxn=max(l1,l2);
    for(int i=1;i<=maxn;i++){
        int a=0,b=0;
        if(p1[i]>='0' && p1[i]<='9') a=p1[i]-'0';
        if(p2[i]>='0' && p2[i]<='9') b=p2[i]-'0';
        icc+=(a+b);
        if(icc>=10) ans[i]='0'+(icc-10);
        else ans[i]='0'+icc;
        icc/=10;
    }
    if(icc){
        ans[maxn+1]='0'+icc;
        ans[maxn+2]='\0';
    }else{
        ans[maxn+1]='\0';
    }
}


int main(){
    scanf("%s",p1+1);
    scanf("%s",p2+1);
    lth1=strlen(p1+1);
    lth2=strlen(p2+1);
    strrev(p1,lth1);
    strrev(p2,lth2);

    hplus(p1,p2,lth1,lth2);

    revprint(ans);

    return 0;
}
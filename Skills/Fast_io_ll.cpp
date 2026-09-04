#include<bits/stdc++.h>
typedef long long ll;
using namespace std;



inline ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){
		if (ch=='-') f=-1;
		ch = getchar();
	}while (ch >= '0' && ch <= '9'){
		x = (x<<1)+(x<<3)+(ch^48);
		ch = getchar();
	}return x*f;
}

inline void write(ll x){
	if (x<0) putchar('-'), x=-x;
	if(x>9)
		write(x/10);
	putchar(x%10+'0');
	return;
}

int main(){
    ll a=read();
    write(a);
    return 0;
}

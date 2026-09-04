#include<bits/stdc++.h>
using namespace std;



inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){
		if (ch=='-') f=-1;
		ch = getchar();
	}while (ch >= '0' && ch <= '9'){
		x = (x<<1)+(x<<3)+(ch^48);
		ch = getchar();
	}return x*f;
}

inline void write(int x){
	if (x<0) putchar('-'), x=-x;
	if(x>9)
		write(x/10);
	putchar(x%10+'0');
	return;
}

int main(){
    int a=read();
    write(a);
    return 0;
}

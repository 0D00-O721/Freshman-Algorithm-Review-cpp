#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
const int inf=2147483647;
int a[N],cnt,n,op;
//实现一个简单的小根堆：父节点永远小于左右子节点的完全二叉树
//完全二叉树从上往下从左往右排节点，则左右子结点分别是父节点序号的两倍和两倍加一
//因此，节点之间的连接方式可以通过运算建立，只需要一个数组就可以存储二叉堆

void add(int x,int pos){    //在pos位置添加值为x的元素
    a[pos]=x;
    int idx=pos;
    while(idx/2>0 && a[idx/2]>a[idx]){  //如果没越界而且父节点比自己大就不停往上滚
        swap(a[idx/2],a[idx]);
        idx=idx/2;
    }return;
}

// void remove(){  //删除堆顶1（自制的废案，效率不够高）
//     int pos=1,nxt;
//     while(pos*2<=cnt){
//         nxt=pos*2;                  //选取左右子节点中较小的那一个
//         if(a[nxt+1]<a[nxt]) nxt++;
//         swap(a[pos],a[nxt]);        //一路将堆顶交换下去直到二叉树这个分支的底部
//         pos=nxt;
//     }
//     if(nxt<cnt) add(a[cnt],nxt);    //如果要删除的元素最后不位于最后一个位置
//     a[cnt--]=inf;                   //则需要把最后一个元素插到这个位置，以保证二叉树是完全的
// }

void remove(){  //标准的删除函数
    if(!cnt) return;
    a[1]=a[cnt--];      //直接把堆尾塞到堆头
    int pos=1,nxt;
    while(pos*2<=cnt){  //将这个新的“不合法堆头”下沉到正确位置
        nxt=pos*2;
        if(a[nxt+1]<a[nxt]) nxt++;  //选取两个子节点中较小的那一个
        if(a[nxt]>a[pos]) break;    //如果已经达到了正确位置（小于两个子节点）就停止
        swap(a[pos],a[nxt]);        //否则下沉一次
        pos=nxt;
    }
}


int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) a[i]=inf; //初始化最大以避免越界换0元素混入堆
    while(n--){
        scanf("%d",&op);
        if(op==1){
            int x;
            scanf("%d",&x);
            cnt++;
            add(x,cnt);
        }else if(op==2){
            printf("%d\n",a[1]);    //a[1]即是堆顶
        }else{
            remove();
        }
    }
    return 0;
}
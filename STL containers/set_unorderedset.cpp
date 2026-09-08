#include<bits/stdc++.h>
using namespace std;

set<int> s;
unordered_set<int> us;

int main(){

    //example of set
    for(int i=1;i<=10;i++){
        s.insert(i);
        s.insert(i);
    }
    auto hint = s.upper_bound(10);
    s.insert(hint,11);

    for(auto e:s) printf("%d ",e);
    printf("\n");

    auto it = s.find(10);
    if(it != s.end()) printf("YES\n");

    printf("size=%d\n",s.size());


    s.erase(s.find(3),s.find(6+1));

    for(auto e:s) printf("%d ",e);
    printf("\n");

    printf("size=%d\n",s.size());

    s.clear();

    //example of unordered_set

    printf("\n\n\n\nunordered set\n");

    for(int i=1;i<=10;i++){
        us.insert(i);
        us.insert(i);
    }
    us.insert(11);

    for(auto e:us) printf("%d ",e);

    us.erase(8);
    auto it2 = us.find(8);
    if(it2 == us.end()) printf("NO!\n");
    printf("\n");
    return 0;
}
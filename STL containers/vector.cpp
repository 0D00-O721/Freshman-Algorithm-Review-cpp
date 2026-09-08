#include<bits/stdc++.h>
using namespace std;
vector<int> v;


int main(){
    for(int i=1;i<=10;i++) v.push_back(i); //add elements

    printf("front=%d , back=%d , size=%d\n",v.front(),v.back(),v.size());

    v.pop_back();

    v.clear(); // O(n), equal to  v.erase(v.begin(),v.end())

    v={1,1,2,2,3,4,5,2,1,3,3};

    sort(v.begin(),v.end());
    auto last = unique(v.begin(),v.end());  //unique will leave some rubbish
    v.erase(last,v.end());                  //we should erase them

    printf("size=%d\n",v.size());
    for(auto e:v) printf("%d ",e);
    printf("\n");

    auto itl = lower_bound(v.begin(),v.end(),4);
    auto itu = upper_bound(v.begin(),v.end(),4);

    if(itl != v.end()) printf("the first pos that v[pos]>=4 is %d\n",*itl);
    if(itu != v.end()) printf("the first pos that v[pos]>4 is %d\n",*itu);

    






    return 0;
}
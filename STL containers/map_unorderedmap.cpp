#include<bits/stdc++.h>
using namespace std;
map<string,int> mp;
unordered_map<string,int> ump;

int main(){
    //example of map

    printf("\nexample of map\n");

    mp["aaa"]=1;
    mp.insert({"bbb",1});
    mp.emplace("ccc",1);    //usually faster than insert.

    for(auto e:mp){
        string s=e.first;
        int v=e.second;
        printf("first=%s,second=%d\n",s.c_str(),v);
    }

    auto it = mp.find("bbb");
    
    if(it != mp.end()){
        string s=(*it).first;   //how to use "it"
        int v=(*it).second;
        printf("will erase {%s,%d}\n",s.c_str(),v);
        mp.erase(it);
    }

    auto l=mp.lower_bound("aaa");   //use dictionary order to find the first key >= parameter string.
    auto r=mp.lower_bound("ccc");

    mp.erase(l,r);



    //example of unordered_map;

    printf("\n\n\nexample of unordered_map\n");

    ump["aaa"]=1;
    ump.insert({"bbb",1});
    ump.emplace("ccc",1);

    for(auto e:ump){
        string s=e.first;
        int v=e.second;
        printf("{%s,%d}\n",s.c_str(),v);
    }
    
    auto it2 = ump.find("bbb");

    if(it2 != ump.end()){
        string us = (*it2).first;
        int uv = (*it2).second;
        printf("will earse {%s,%d}\n",us.c_str(),uv);
        ump.erase(it2);
    }


    return 0;
}
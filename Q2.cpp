#include <bits/stdc++.h>
using namespace std;

class MyHashMap{
    vector<int>mp;
public:

    MyHashMap(){
        mp=vector<int>(1000001,-1);
    }
    
    void put(int key,int value){
        mp[key]=value;
    }
    
    int get(int key){
        return mp[key];
    }
    
    void remove(int key){
        mp[key]=-1;
    }
};

int main() {
    MyHashMap obj;
    obj.put(1, 10);
    obj.put(2, 20);
    cout<<obj.get(1)<<" ";       
    cout<<obj.get(3)<<" ";       
    obj.put(2, 30);   
    cout<<obj.get(2)<<" ";       
    obj.remove(2);
    cout<<obj.get(2)<<" ";
    return 0;
}
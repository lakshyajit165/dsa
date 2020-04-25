/*

Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache(2)

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4




*/


#include<bits/stdc++.h>
using namespace std;
class LRUCache {
    
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> mymap;
    
    void refreshPosition(int key, int value){
        
        cache.erase(mymap[key]);
        cache.push_front(make_pair(key, value));
        mymap[key] = cache.begin();
        
    }
    
    int capacity;
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        
        if(mymap.find(key)!=mymap.end()){
            
            refreshPosition(key, (*mymap[key]).second);
            return (*mymap[key]).second;
            
        }
        return -1;
    }
    
    void put(int key, int value) {
        
        if(mymap.find(key)!=mymap.end())
            refreshPosition(key, value);
        else{
            
            cache.push_front(make_pair(key, value));
            mymap[key] = cache.begin();
            if(mymap.size() > capacity){
                mymap.erase(cache.back().first);
                cache.pop_back();
            }
        }
    }
};

int main() {

    LRUCache cache = LRUCache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    cout<<cache.get(1)<<endl;       // returns 1
    cache.put(3, 3);    // evicts key 2
    cout<<cache.get(2)<<endl;       // returns -1 (not found)
    cache.put(4, 4);    // evicts key 1
    
    cout<<cache.get(1)<<endl;       // returns -1 (not found)
    cout<<cache.get(3)<<endl;       // returns 3
    cout<<cache.get(4)<<endl;  

    return 0;
}
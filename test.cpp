#include<bits/stdc++.h>
#include<map>
#include"lru.cpp"
using namespace std;
int main() {
    int n=4; //running on the example in the diagram
    //cin>>n;
    LRUCache cache(n); //input the cache capacity
    cache.put(1,1);
    cache.put(2,2);
    cache.put(3,3);
    cache.put(4,4);
    cache.put(5,5);
	cout << cache.getkey(5) << endl;
    cout << cache.getkey(4) << endl;
	cout << cache.getkey(3) << endl;
    cout << cache.getkey(2) << endl;
	cout << cache.getkey(1) << endl;
    cout << cache.getkey(2) << endl;
    cache.put(6,6);
    return 0;
}
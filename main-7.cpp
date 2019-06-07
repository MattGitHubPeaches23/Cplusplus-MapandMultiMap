// Copyright (c) 2019, Matthew Chalifoux.

#include <iostream>
#include "btree.h"
template <typename K, typename V>
struct Pair{
    K key;
    V value;

    Pair(const K& k=K(),  const V& v=V());
    template<typename R, typename U>
    friend ostream& operator <<(ostream& outs, const Pair<R, U>& print_me);
    template<typename R, typename U>
    friend bool operator ==(const Pair<K, V>& lhs, const Pair<K, V>& rhs);
    template<typename R, typename U>
    friend bool operator < (const Pair<K, V>& lhs, const Pair<K, V>& rhs);
    template<typename R, typename U>
    friend bool operator > (const Pair<K, V>& lhs, const Pair<K, V>& rhs);
    template<typename R, typename U>
    friend bool operator <= (const Pair<K, V>& lhs, const Pair<K, V>& rhs);
    template<typename R, typename U>
    friend Pair<K, V> operator + (const Pair<K, V>& lhs, const Pair<K, V>& rhs);
    template<typename R, typename U>
    friend bool operator != (const Pair<K, V>& lhs, const Pair<K, V>& rhs);
    template<typename R, typename U>
    friend bool operator >= (const Pair<K, V>& lhs, const Pair<K, V>& rhs);
};
template<typename K, typename V>
class Map
{
public:
    Map();
    void insert(const K& k, const V& v);
    void erase(const K& key);
    friend ostream& operator<<(ostream& outs, const Map<K, V>& print_me){
        outs<<print_me.map<<endl;
        return outs;
    }
private:
    int key_count;
    BTree<Pair<K, V> > map;
};
using namespace std;

int main()
{
//    Map<string,string> test;
//    test.insert("hi","one way");
//    test.insert("goodbye","giani");
//    test.insert("sometimes","here");
//    test.insert("last one down","iuop");
//    test.insert("afterwards", "yolo");
//    test.erase("goodbye");
//    cout << test;

//    Map<string,string> test2(test);
//    cout << "TEST 2 ******************" << endl;
//    test2 = test;
//    cout << test2;

    BTree<int> test;

    test.insert(50);
    test.insert(30);
    test.insert(40);
    test.insert(40);
    test.insert(60);
    test.insert(70);
    test.insert(20);
    test.insert(10);
    test.insert(10);
    test.insert(25);
    test.insert(80);
    test.insert(55);
    test.insert(53);
    test.insert(3);
    test.insert(4);
    test.insert(2);
    test.insert(45);
    test.insert(43);
    test.insert(35);
    test.insert(75);
    test.insert(1);
    test.insert(0);
    test.insert(99);
    test.insert(99);
    test.insert(41);
    test.insert(41);

    cout << "************ TEST *********************" << endl;
    cout << test;
    int num;
    num = 40;
    cout << "ERASING NUMBER " << num << endl;
    test.erase(num);
    cout << "************ TEST *********************" << endl;
    cout << test;






    return 0;
}
template<typename K, typename V>
Map<K,V>::Map(){
    key_count = 0;
}
template<typename K, typename V>
Pair<K,V>::Pair(const K &k, const V &v){
    key = k;
    value = v;
}
template<typename K, typename V>
void Map<K,V>::erase(const K& key){
    map.erase(key);
}

template<typename K, typename V>
void Map<K,V>::insert(const K &k, const V &v){
    Pair<K,V> sub(k,v);
    map.insert(sub);
}
template<typename R, typename U>
ostream& operator <<(ostream& outs, const Pair<R, U>& print_me){
    outs <<"{"<< print_me.key<<": "<<print_me.value<<"}";
}
template<typename R, typename U>
bool operator ==(const Pair<R, U>& lhs, const Pair<R, U>& rhs){
    if(lhs.key == rhs.key){
        return true;
    }
    else if(!(lhs.key == rhs.key)){
        return false;
    }

}
template<typename R, typename U>
bool operator < (const Pair<R, U>& lhs, const Pair<R, U>& rhs){
    if(lhs.key < rhs.key){
        return true;
    }
    else if(!(lhs.key < rhs.key)){
        return false;
    }
}
template<typename R, typename U>
bool operator > (const Pair<R, U>& lhs, const Pair<R, U>& rhs){
    if(lhs.key > rhs.key){
        return true;
    }
    else if(!(lhs.key > rhs.key)){
        return false;
    }
}
template<typename R, typename U>
bool operator <= (const Pair<R, U>& lhs, const Pair<R, U>& rhs){
    if(lhs.key <= rhs.key){
        return true;
    }
    else if(!(lhs.key <= rhs.key)){
        return false;
    }
}
template<typename R, typename U>
Pair<R, U> operator + (const Pair<R, U>& lhs, const Pair<R, U>& rhs){

}
template<typename R, typename U>
bool operator != (const Pair<R, U>& lhs, const Pair<R, U>& rhs){
    if(lhs.key != rhs.key){
        return true;
    }
    else if(!(lhs.key != rhs.key)){
        return false;
    }
}
template<typename R, typename U>
bool operator >= (const Pair<R, U>& lhs, const Pair<R, U>& rhs){
    if(lhs.key >= rhs.key){
        return true;
    }
    else if(!(lhs.key >= rhs.key)){
        return false;
    }
}

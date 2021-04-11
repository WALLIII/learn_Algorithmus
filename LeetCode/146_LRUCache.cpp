#include <iostream>
#include <list>
#include <unordered_map>

class LRUCache
{
public:
    LRUCache(int capacity)
    {
        this->cap = capacity;
    }

    int get(int key)
    {
        auto it=map.find(key);
        if(it==map.end()){
            // 哈希表中没有找到键值，要返回-1
            return -1;
        }
        else{
            // key在哈希表中找到了，返回value，同时要把(key,value)放在表头
            // 这里取迭代器的值为kv
            std::pair<int,int> kv=*map[key];
            cache.erase(map[key]);
            cache.push_front(kv);
            //在哈希表中的key对应的迭代器也要改
            map[key]=cache.begin();
            return kv.second;
        }
    }

    void put(int key, int value)
    {
        auto it=map.find(key);
        // 如果key不在哈希表中（即不在缓存区）
        if(it==map.end()){
            // 不在的话可以放缓冲区，但是要检查缓冲区有没有满
            if(map.size()==cap){
                // 如果cache满的话，就要把最久没更新的key删去，要从map和cache都删掉。cache中最就没更新的在尾部，back
                auto lastPair=cache.back();
                int lastKey=lastPair.first;
                map.erase(lastKey);
                cache.pop_back();
            }
            // 没有满，或者说满了的经过刚才的步骤已经删掉了一个位置
            cache.push_front(std::make_pair(key,value));
            // 把列表头的位置/迭代器放在哈希表对应的键值处/
            map[key]=cache.begin();
        }
        else{
            // key在哈希表中找到了，需要修改对应的value,list 可以用迭代器的位置来删去元素
            cache.erase(map[key]);
            cache.push_front(std::make_pair(key,value));
            map[key]=cache.begin();
        }
    }

private:
    int cap;
    // 保存（key,value)，双链表
    std::list<std::pair<int, int>> cache;
    // 哈希表，key映射当前到(key,value)在cache中的位置
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> map;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(){
    LRUCache* obj=new LRUCache(2);
    // obj是一个指向LRUCache的指针，所以要用->调用成员函数
    int param1=obj->get(1);
    std::cout<<"get(1):  "<<param1<<std::endl;
    obj->put(1,11);
    obj->put(2,21);
    std::cout<<"get(1):  "<<obj->get(1)<<std::endl;
}
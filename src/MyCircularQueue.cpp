#include<iostream>
#include<vector>

using namespace std;

class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k):start_ptr(0), end_ptr(0), capability(k+1){
        vector<int> data(capability, 0);        
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull()) return false;
        data[end_ptr]=value;
        end_ptr=(end_ptr+1)%capability;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty()) return  false;
        start_ptr=(start_ptr+1)%capability;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty()) return -1;
        return data[start_ptr];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty()) return -1;
        return data[end_ptr];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if(start_ptr==end_ptr)
            return true;
        else return false;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if((end_ptr+1)%capability==start_ptr) return true;
        else return false;
    }
    private:
    vector<int> data;
    int capability=0;
    int start_ptr=0;
    int end_ptr=0;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

// int main(){
//     MyCircularQueue* obj = new MyCircularQueue(2);
//     bool param_1 = obj->enQueue(1);
//     bool param_2 = obj->deQueue();
//     int param_3 = obj->Front();
//     int param_4 = obj->Rear();
//     bool param_5 = obj->isEmpty();
//     bool param_6 = obj->isFull();
// }

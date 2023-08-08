#include<queue>
class MyStack {
    private:
    queue<int> q1;
    queue<int> q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
        //q1 -> q2
        while(!q1.empty()){
            int data = q1.front();
            q1.pop();
            q2.push(data);
        }
        //swap
        queue<int> t = q1;
        q1 = q2;
        q2 = t;
    }
    
    int pop() {
        int data = q1.front();
        q1.pop();
        return data;
    }
    
    int top() {
        int data = q1.front();
        return data;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class MyQueue{
    private:
        stack<long long int> input;
        stack<long long int> output;
    public:
        void enq(long long int data);
        void dq();
        long long int front();
};
void MyQueue::enq(long long int data){
    input.push(data);
}
void MyQueue::dq(){
    if(output.empty()){
        while(!input.empty()){//input->output
            output.push(input.top());
            input.pop();
        }
    }
    if(!output.empty()){
        output.pop();    
    }
}
long long int MyQueue::front(){
    if(output.empty()){
        while(!input.empty()){//input->output
            output.push(input.top());
            input.pop();
        }
    }
    if(!output.empty()){
        return output.top();    
    }
    return -1;
}

int main() {
    MyQueue myq;
    int N;
    long long data;
    cin >> N;
    for(int I = 1; I <= N; I++){
        int op_id;
        cin >> op_id;
        switch(op_id){
            case 1: cin >> data; myq.enq(data); break;
            case 2: myq.dq(); break;
            case 3: data = myq.front(); cout << data << endl; break;
            
        }
    }
    return 0;
}

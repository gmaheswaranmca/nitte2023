#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

void enqueue(stack<long long int>& stk1, stack<long long int>& stk2, long long int data){
    stk1.push(data);
}
void dequeue(stack<long long int>& stk1, stack<long long int>& stk2){
    while(!stk1.empty()){//stk1 -> stk2
        stk2.push(stk1.top());
        stk1.pop();
    }
    if(!stk2.empty()){
        stk2.pop(); //deque
    }
    while(!stk2.empty()){//stk2 -> stk1
        stk1.push(stk2.top());
        stk2.pop();
    }
}
void front(stack<long long int>& stk1, stack<long long int>& stk2){
    while(!stk1.empty()){//stk1 -> stk2
        stk2.push(stk1.top());
        stk1.pop();
    }
    if(!stk2.empty()){
        cout << stk2.top() << endl; //front
    }
    while(!stk2.empty()){//stk2 -> stk1
        stk1.push(stk2.top());
        stk2.pop();
    }
}
int main() {
    stack<long long int> stk1;
    stack<long long int> stk2;
    int q;
    cin >> q;
    while(q--){
        int qt;
        cin >> qt;
        switch(qt){
            case 1: long long int data; cin >> data; enqueue(stk1, stk2, data); break;
            case 2: dequeue(stk1, stk2); break;
            case 3: front(stk1, stk2); break;
        }
    }    
    return 0;
}

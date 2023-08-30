#include<bits/stdc++.h>
using namespace std;

// using array
struct Stack{
    int top;
    int *arr;
    int size;
};


void push(struct Stack*s,int x){
    if(s->top == s->size-1){
        cout<<"stack overflow"<<endl;
    }
    else{
        s->top++;
        s->arr[s->top] = x;
    }
}

void pop(struct Stack* s){
    if(s->top == -1){
        cout<<"stack is empty"<<endl;
    }
    else{
        s->top--;
    }
}

int top(struct Stack*s){
    if(s->top==-1){
        cout<<"stack is empty";
        return -1;
    }
    else{
        return s->arr[s->top];
    }
}

// using linked list


int main(){

    struct Stack s;
    s.top = -1;
    s.size = 10;
    s.arr = (int*)malloc(s.size*sizeof(int));

    push(&s,2);
    push(&s,4);
    push(&s,5);
    push(&s,46);
    push(&s,456);
    push(&s,4236);

    pop(&s);
    pop(&s);

    cout<<top(&s)<<endl;

    return 0;
}

// two stacks in an array

// #include <bits/stdc++.h> 
// class TwoStack {
    
//     int*arr;
//     int top1;
//     int top2;
//     int size;

// public:

//     // Initialize TwoStack.
//     TwoStack(int s) {
//         this->size = s;
//         top1 = -1;
//         top2 = s;
//         arr = new int[s];
//     }
    
//     // Push in stack 1.
//     void push1(int num) {
//         if(top1 == top2-1){
//             return;
//         }
//         else{
//             top1++;
//             arr[top1] = num; 
//         }
//     }

//     // Push in stack 2.
//     void push2(int num) {
//         if(top1 == top2-1){
//             return;
//         }
//         else{
//             top2--;
//             arr[top2] = num; 
//         }
//     }

//     // Pop from stack 1 and return popped element.
//     int pop1() {
//         if(top1 == -1){
//             return -1;
//         }
//         else{
//             int ans = arr[top1];
//             top1--;
//             return ans;
//         }
//     }

//     // Pop from stack 2 and return popped element.
//     int pop2() {
//         if(top2 == size){
//             return -1;
//         }
//         else{
//             int ans = arr[top2];
//             top2++;
//             return ans;
//         }
//     }
// };


// delete middle element of stack

// #include <bits/stdc++.h> 
// void solve(stack<int>&inputStack,int count,int size){
//     if(count == size/2){
//         inputStack.pop();
//         return;
//     }
//     int num = inputStack.top();
//     inputStack.pop();
    
//     solve(inputStack,count+1,size);
//     inputStack.push(num);
// }
// void deleteMiddle(stack<int>&inputStack, int N){
	
//    // Write your code here
//     int count = 0;
//     solve(inputStack,count,N);
   
// }


// valid parenthesis


// bool isValidParenthesis(string expression)
// {
//     stack<char>s;
//     for(int i=0;i<expression.length();i++){
//         char ch = expression[i];
//         if(ch == '(' || ch == '{' || ch == '['){
//             s.push(ch);
//         }
//         else{
//             if(!s.empty()){
//                 char top = s.top();
//                 if(top == '(' && ch == ')' ||
//                  top == '{' && ch == '}' ||
//                  top == '[' && ch == ']' ){
//                     s.pop();
//                 }
//                 else{
//                     return false;
//                 }
//             }
//             else{
//                 return false;
//             }
//         }
//     }
//     if(s.empty()){
//         return true;
//     }
//     else{
//         return false;
//     }
// }


// insert at bottom

// #include <bits/stdc++.h> 
// stack<int> pushAtBottom(stack<int>& myStack, int x) 
// {
//     if(myStack.empty()){
//         myStack.push(x);
//     }
//     else{
//         int num = myStack.top();
//         myStack.pop();
        
//         pushAtBottom(myStack,x);
//         myStack.push(num);
//     }
//     return myStack;
// }

// reversing a stack

// void reverseStack(stack<int> &stack) {
//     // base case
//     if(stack.empty()){
//         return;
//     }
//     int top = stack.top();
//     stack.pop();
    
//     reverseStack(stack);
//     insertAtBottom(stack,top);
// }

// sort a stack


// void sortedInsert(stack<int> &stack, int num) {
//     //base case
//     if(stack.empty() || stack.top() < num) {
//         stack.push(num);
//         return;
//     }
    
//     int n = stack.top();
//     stack.pop();
    
//     //recusrive call
//     sortedInsert(stack, num);
    
//     stack.push(n);
// }

// void sortStack(stack<int> &stack)
// {
//         //base case
//         if(stack.empty()) {
//             return ;
//         }
    
//         int num = stack.top();
//         stack.pop();
    
//         //recursive call
//         sortStack(stack);
    
//         sortedInsert(stack, num);
// }

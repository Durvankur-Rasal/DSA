#include <iostream>
using namespace std;
#define MAX 1000;

class Stack{
   int *arr;
   int top;
   int size;

    public:
    Stack(){
        size=10;
        arr= new int[size];
        top=-1;
    }

    void push(int x){
        if(top== size-1){
            cout<<"Stack overflow"<<endl;
            return;
        }

        top++;
        arr[top]= x;
    }

    int pop(){
        if(top== -1){
            cout<<"Stack underflow"<<endl;
            return  -1;
        }

        top--;
        return arr[top+1];
    }

    int Top(){
        if(top== -1){
            cout<<"Stack is empty"<<endl;
            return -1;
        }

        return arr[top];
    }

    int Size(){
        return top+1;
    }

    
};



int main() {

  Stack s;
  s.push(6);
  s.push(3);
  s.push(7);
  cout << "Top of stack is before deleting any element " << s.Top() << endl;
  cout << "Size of stack before deleting any element " << s.Size() << endl;
  cout << "The element deleted is " << s.pop() << endl;
  cout << "Size of stack after deleting an element " << s.Size() << endl;
  cout << "Top of stack after deleting an element " << s.Top() << endl;
  return 0;
}
#include<iostream>
using namespace std;

class Node{
     public:
     int data;
     int size;
     Node* next;
     Node(int val){
        data =val;
        next =NULL;
     }
};

class stack{
      Node *top;
      int size;

      public:
      stack(){
        top =NULL;
        size =0;
      }

      void stackPush(int val){
        Node* n= new Node(val);
        if(top==NULL){
            top =n;
        }

        else{
            n->next =top;
            top=n;
        }
        size++;
      }

      int stackPop(){
        if(top== NULL){
            cout<<"Stack is empty"<<endl;
            return -1;
        }

        int ans = top->data;
        Node* temp= top;
        top = top->next;
        delete temp;
        size--;
        return ans;

      }

      int stackPeek(){
        if(top==NULL){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return top->data;
      }

        int stackSize(){
            return size;
        }
        bool stackIsEmpty(){
            return size==0;
        }
};

int main() {
  stack s;
  s.stackPush(10);
  cout << "Element popped: " << s.stackPop() << "\n";
  cout << "Stack size: " << s.stackSize() << "\n";
  cout <<"Stack empty or not? "<<s.stackIsEmpty()<<"\n";
  cout << "stack's top element: " << s.stackPeek() << "\n";
  return 0;
}
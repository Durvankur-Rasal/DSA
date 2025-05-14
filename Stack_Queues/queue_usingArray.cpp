#include<iostream>
using namespace std;

class Queue{
    int *arr;
    int front;
    int rear;
    int cnt;
    int maxSize;
    public:
    Queue(int s){
        maxSize=s;
        arr=new int[maxSize];
        front=-1;
        rear=-1;
        cnt=0;
    }

    void push(int x){

        if(cnt == maxSize){
            cout<<"Queue overflow"<<endl;
            return;
        }

        if(rear ==-1){
           front=0;
           rear=0;
        }

        else{
            rear= (rear +1)% maxSize;
        }

        arr[rear]=x;
        cnt++;
    }

    int pop(){
        if(cnt ==0){
            cout<<"Queue underflow"<<endl;
            return -1;
        }

        int ans = arr[front];

        if(cnt ==1){
            front=-1;
            rear=-1;
        }
        else{
            front = (front +1)%maxSize;
        }
        cnt--;
        return ans;
    }

    int top(){
        if(cnt ==0){
            cout<<"Queue is empty"<<endl;
            return -1;
        }

        return arr[front];
    }

    int size(){
        return cnt;
    }

};

int main() {
  Queue q(6);
  q.push(4);
  q.push(14);
  q.push(24);
  q.push(34);
  cout << "The peek of the queue before deleting any element " << q.top() << endl;
  cout << "The size of the queue before deletion " << q.size() << endl;
  cout << "The first element to be deleted " << q.pop() << endl;
  cout << "The peek of the queue after deleting an element " << q.top() << endl;
  cout << "The size of the queue after deleting an element " << q.size() << endl;

  return 0;
}
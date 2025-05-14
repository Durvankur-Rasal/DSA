#include <iostream>
#include<queue>
using namespace std;

class Stack{
     queue<int> q1;

     public:
        void Push(int x){
            int s=q1.size();
            q1.push(x);

            for (int i=0; i<s; i++){
                q1.push(q1.front());
                q1.pop();
            }
        }

        int Pop(){
            int ans = q1.front();
            q1.pop();
            return ans;
        }

        int Top(){
            return q1.front();
        }

        int Size(){
            return q1.size();
        }
};

int main() {
  Stack s;
  s.Push(3);
  s.Push(2);
  s.Push(4);
  s.Push(1);
  cout << "Top of the stack: " << s.Top() << endl;
  cout << "Size of the stack before removing element: " << s.Size() << endl;
  cout << "The deleted element is: " << s.Pop() << endl;
  cout << "Top of the stack after removing element: " << s.Top() << endl;
  cout << "Size of the stack after removing element: " << s.Size();

}
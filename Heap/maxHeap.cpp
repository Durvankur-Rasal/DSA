#include<iostream>
using namespace std;

class MaxHeap{
    int* arr;
    int capacity;
    int size;   

    public:
    MaxHeap(int cap){
        capacity=cap;
        size=0;
        arr=new int[cap];
    }

    // insert into the heap
    void insert(int val){
        // check if the heap is full
        if(size==capacity){
            cout<<"Heap is full"<<endl;
            return;
        }

        arr[size]=val;
        int index=size;
        size++;

        // compare it with its parent
        while(index > 0 && arr[(index-1)/2]< arr[index]){
            swap(arr[index],arr[(index-1)/2]);
            index=(index-1)/2;
        }
       
        cout<<val<<" inserted into the heap"<<endl;
    }

    void printHeap(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void Heapify(int index){
        int  largest=index;
        int left=2*index+1;
        int right=2*index+2;

        if(left<size && arr[left]>arr[largest]){
            largest=left;
        }

        if(right<size && arr[right]>arr[largest]){
            largest=right;
        }

        if(largest!=index){
            swap(arr[largest],arr[index]);
            Heapify(largest);
        }
    }

    void Delete(){
        if(size==0){
            cout<<"Heap is empty"<<endl;
            return;
        }

        cout<<arr[0]<<" deleted from the heap"<<endl;
        arr[0]= arr[size-1];
        size--;

        if(size==0){
            return;
        }

        Heapify(0);

    }

};


int main(){
    MaxHeap h(6);
    h.insert(3);
    h.insert(2);
    h.insert(15);
    h.insert(5);
    h.printHeap();
    return 0;

}
#include<iostream>
#include<vector>
using namespace std;

class Solution{
    
    public:

    void heapify(vector<int>& heap, int n, int i){

        int largest= i;
        int left= 2*i+1;
        int right= 2*i+2;

        if(left<n && heap[largest] < heap[left]){
            largest= left;
        }

        if(right < n && heap[largest ]< heap[right]){
            largest= right;
        }

        if(largest != i){
            swap(heap[i], heap[largest]);
            heapify(heap, n, largest);
        }
    }
    void convertMinHeapToMaxHeap(vector<int>& heap) {
        int n = heap.size();
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(heap, n, i);
        }

    }
};

int main (){
      vector<int> heap = {1, 3, 5, 7, 9, 2, 6, 8, 10};

    cout << "Original Min-Heap: ";
    for (int i : heap) {
        cout << i << " ";
    }
    cout << endl;

    Solution sol;

    sol.convertMinHeapToMaxHeap(heap);

    cout << "Converted Max-Heap: ";
    for (int i : heap) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
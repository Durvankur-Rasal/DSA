#include<iostream>

using namespace std;


void selection_sort(int arr[], int n){
    for(int i=0; i<n; i++){
        int mini= arr[i];
        for(int j=i+1; j<n; j++){
            if(mini > arr[j]){
                mini= arr[j];
            }
        }

        swap(arr[i], mini);
    }
}


void bubble_sort(int arr[], int n){

    for(int i=0; i<n; i++){
        for(int j=1; j<n-i; j++){
            if(arr[j-1] > arr[j]){
                swap(arr[j-1], arr[j]);
            }
        }
    }
}
int main() {
  int arr[] = {13,46,24,52,20,9};
  int n = sizeof(arr) / sizeof(arr[0]);
   cout << "Before selection sort: " << "\n";
   for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
  selection_sort(arr, n);
  return 0;
}
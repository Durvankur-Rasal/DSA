#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

   bool solve(vector<int>&arr, int n,int i){
        int left= 2*i +1;
        int right= 2*i +2;

        if(left >= n ){
            return true;
        }

        bool isLeft = (arr[i] <= arr[left]) && solve(arr, n, left);
        bool isRight = (right >=n || arr[i] <= arr[right] ) && solve(arr, n, right);
        return  isLeft && isRight;
   }


    bool isHeap(vector<int>& nums) {
            int n = nums.size();
            return solve(nums, n,0);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    cout << (sol.isHeap(nums) ? "true" : "false") << endl;
    return 0;
}
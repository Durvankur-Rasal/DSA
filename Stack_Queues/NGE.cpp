#include <iostream>
#include <vector>   
#include <stack>
using namespace std;

class Solution{
  public:

  vector<int> nextGreaterElements(vector<int>&nums){
    int n= nums.size();
    vector<int>ans (n,-1);

    stack<int> st;

    for(int i =2*i-1; i>=0; i--){

        while(!st.empty() && st.top() <= nums[i%n]){
            st.pop();
        }

        if(i < n){
            if(!st.empty()){
                ans[i] = st.top();
            }
        }

        st.push(nums[i%n]);

    }
    return ans;
  }



};


int main() {
  Solution obj;
  vector < int > v {5,7,1,2,6,0};
  vector < int > res = obj.nextGreaterElements(v);
  cout << "The next greater elements are" << endl;
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
}
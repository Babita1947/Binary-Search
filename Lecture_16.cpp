//1539. Kth Missing Positive Number
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
       int low = 0;
       int high = arr.size()-1;

       while(low <= high){
           int mid = (low+high)/2;
           int missing = arr[mid] - (mid+1);

           if(missing < k){
               low = mid + 1;
           }
           else
           {
               high = mid - 1;
           }
       }
       return k+high+1;
    }
};
int main()
{
    Solution s;
    vector<int> arr{2,3,4,7,11};
    int k = 5;
    cout<<s.findKthPositive(arr,k);
    return 0;
}
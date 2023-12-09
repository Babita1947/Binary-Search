//33. Search in Rotated Sorted Array
 
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
       int n=nums.size();
       int low=0,high=n-1; 

       while(low<=high){
          int mid=(low+high)/2;
          if(nums[mid] == target)
              return mid;
          //Identify sorted half
          //left sorted
          if(nums[low] <= nums[mid]){
              if(nums[low] <= target && target <= nums[mid])
                  high = mid-1;
               else
                  low = mid+1;
          }
          //right sorted
          else{
              if(nums[mid] <= target && target <= nums[high])
                 low = mid+1;
              else
                 high = mid - 1;
          }
       }
       return -1;
    }
};

// Brute Force Solution
// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int i;
//         for(i=0;i<nums.size();i++)
//         {
//           if(nums[i]==target)
//               return i;
//         }
//         return -1;
        
//     }
// };

int main()
{
    Solution s;
    vector<int> nums{4,5,6,7,0,1,2};
    int target=0;
    cout<<s.search(nums,target);
    return 0;
}

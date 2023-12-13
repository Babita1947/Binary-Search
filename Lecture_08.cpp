//540. Single Element in a Sorted Array

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
           return nums[0];
        if(nums[0] != nums[1])
           return nums[0];
        if(nums[n-2] != nums[n-1])
           return nums[n-1];
        int low = 1,high = n-2;

        while(low <= high){
           int mid = (low + high) / 2;
           if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])
              return nums[mid];
           //Check in which half single element is present   
           if((mid%2 != 0 && nums[mid]==nums[mid-1]) || (mid%2 == 0 && nums[mid]==nums[mid+1]))
                  low = mid + 1;   //eliminate left half
            else
                  high = mid - 1;  //eliminate right half
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> nums{1,1,2,3,3,4,4,8,8};
    cout<<s.singleNonDuplicate(nums);
    return 0;
}

//1283. Find the Smallest Divisor Given a Threshold
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi = 0;
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            maxi = max(maxi,nums[i]);
        }

        int low = 1,high = maxi;
        while(low <= high){
            int sum = 0;
            int mid = (low + high) / 2;
            for(int j=0;j<nums.size();j++){
                sum += ceil(nums[j]/float(mid));
                // if(nums[j]%i==0)
                //     sum+=nums[j]/i;
                // else sum+=nums[j]/i+1;
            }
            if(sum <= threshold){
                   ans = mid;
                   high = mid - 1;
            }
            else
               low = mid + 1;
            
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums{44,22,33,11,1};
    int threshold = 5;
    cout<<s.smallestDivisor(nums,threshold);
    return 0;
}
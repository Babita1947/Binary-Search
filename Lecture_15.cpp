//1011. Capacity To Ship Packages Within D Days
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDays(vector<int> &weights,int capacity)
    {
        int days = 1,load = 0;
        for(int i=0;i<weights.size();i++){
            if(load + weights[i] > capacity){
                days = days + 1;
                load = weights[i];
            }
            else
                load = load + weights[i];
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {

        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = 0;
        while(low <= high){
            int mid = (low + high)/2;
            if(findDays(weights,mid) <= days){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> weights{1,2,3,4,5,6,7,8,9,10};
    int days = 5;
    cout<<s.shipWithinDays(weights,days);
    return 0;
}
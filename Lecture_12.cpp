//875. Koko Eating Bananas
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMax(vector<int> &piles)
    {
        int maxi = INT_MIN;
        int n = piles.size();
        //find the maximum:
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, piles[i]);
    }
    return maxi;
    }

    long long calculateTotalHours(vector<int> &piles, int hourly) {
    long long totalH = 0;
    int n = piles.size();
    // find total hours:
    for (int i = 0; i < n; i++) {
        totalH += ceil((double)(piles[i]) / (double)(hourly));
    }
     return totalH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
       int low = 1;
       int high = findMax(piles);
       while(low <= high){
           int mid = (low + high)/2;
           long long totalH = calculateTotalHours(piles,mid);
           if(totalH <= h)
           {
               high = mid - 1;
           }
           else{
               low = mid + 1;
           }
       }
       return low;
    }
};
int main()
{
    Solution s;
    
    vector<int> v = {7, 15, 6, 3};
    int h = 8;
    int ans = s.calculateTotalHours(v, h);
    cout << "Koko should eat atleast " << ans << " bananas/hr.\n";
    return 0;
}
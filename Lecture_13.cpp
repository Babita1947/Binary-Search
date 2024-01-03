//1482. Minimum Number of Days to Make m Bouquets
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool possible(vector<int> &bloomDay,int Day,int m,int k){
        int cnt = 0;
        int noOfBouquet = 0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i] <= Day){
                cnt++;
            }
            else{
                noOfBouquet += (cnt/k);
                cnt = 0;
            }
        }
        noOfBouquet += (cnt/k);
        return noOfBouquet >= m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m*1LL*k*1LL;
        if(val > bloomDay.size())
           return -1;
        
        int mini = INT_MAX, maxi = INT_MIN;
        for(int i=0;i<bloomDay.size();i++){
            mini = min(mini,bloomDay[i]);
            maxi = max(maxi,bloomDay[i]);
        }
        int low = mini , high = maxi;
        while(low <= high){
            int mid = (low + high)/2;
            if(possible(bloomDay,mid,m,k)){
                high = mid - 1;
            }
            else{
                low  = mid + 1;
            }
        }
        return low;
    }
};

int main()
{
    Solution s;
    vector<int> bloomDay{1,10,3,10,2};
    int m = 3;
    int k = 1;
    cout<<s.minDays(bloomDay,m,k);
    return 0;
}

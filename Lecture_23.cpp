//2643. Row With Maximum Ones

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lowerBound(vector<int> arr,int n,int x){
    int low = 0,high = n-1;
    int ans = n;
    while(low <= high){
        int mid = (low + high)/2;
        //may be an answer
        if(arr[mid] >= x){
            ans = mid;
            //look for more small index on left
            high = mid - 1;
        }
        else{
            low = mid + 1;//look for right
        }
    }
    return ans;
    }
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();

        int cnt_max = 0;
        int index = 0;

        for(int i=0;i<n;i++){
            sort(mat[i].begin(),mat[i].end());
            int cnt_ones = m - lowerBound(mat[i],m,1);
            if(cnt_ones > cnt_max){
                cnt_max = cnt_ones;
                index = i;
            }
        }
        return {index,cnt_max};
    }
};

int main()
{
    Solution s;
    vector<vector<int>> mat{{0,0,0},{0,1,1}};
    vector<int> ans;
    ans = s.rowAndMaximumOnes(mat);
    for(int i=0;i<ans.size();i++)
      cout<<ans[i]<<" ";
    return 0;
}
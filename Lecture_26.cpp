//1901. Find a Peak Element II

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxIndex(vector<vector<int>> &mat,int n,int m,int col){
        int maxVal = -1;
        int index = -1;
        for(int i=0;i<n;i++){
            if(mat[i][col] > maxVal){
                maxVal = mat[i][col];
                index = i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0,high = m-1;
        while(low <= high)
        {
            int mid = (low+high)/2;
            int row = findMaxIndex(mat,n,m,mid);
            int left = mid - 1 >= 0 ? mat[row][mid-1] : -1;
            int right = mid + 1 < m ? mat[row][mid+1] : -1;
            if(mat[row][mid] > left && mat[row][mid] > right)
               return {row,mid};
            else if(mat[row][mid] < left)
               high = mid - 1;
            else
               low = mid + 1;
        }
        return {-1,-1};
    }
};

int main()
{
    Solution s;
    vector<vector<int>> mat{{10,20,15},{21,30,14},{7,16,32}};
    vector<int> ans;
    ans = s.findPeakGrid(mat);
    for(int i=0;i<ans.size();i++)
       cout<<ans[i]<<" ";
    return 0;
}
//Median in a row-wise sorted Matrix
#include<bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &arr, int x, int n){
	// Write your code here.	
	int low=0,high=n-1;
	int ans=n;
	while(low <= high){
		int mid=(low+high)/2;
		// may be an answer
		if(arr[mid] > x){
			ans=mid;
			//look for more small index on left
			high=mid-1;
		}
		else
		{
			low=mid+1;//look for right
		}
	}
	return ans;
}
int countSmallEqual(vector<vector<int>> &matrix,int n,int m,int x){
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        cnt += upperBound(matrix[i],x,m);
    }
    return cnt;
}
int median(vector<vector<int>> &matrix, int m, int n) {
    int low = INT_MAX;
    int high = INT_MIN;
    n = matrix.size();
    m = matrix[0].size();
    for(int i=0;i<n;i++)
    {
        low = min(low,matrix[i][0]);
        high = max(high,matrix[i][m-1]);
    }
    int req = (n*m)/2;
    while(low <= high){
        int mid = (low + high)/2;
        int smallEqual = countSmallEqual(matrix,n,m,mid);
        if(smallEqual <= req)
           low = mid+1;
        else 
           high = mid-1;
    }
    return low;
}

int main()
{
    vector<vector<int>> matrix{{1, 5, 7, 9, 11},{2, 3, 4, 8, 9 },{4, 11, 14, 19, 20 },{6, 10, 22, 99, 100},{ 7, 15, 17, 24, 28 }};
    int n = 5,m = 5;
    cout<<median(matrix,m,n);
    return 0;
}
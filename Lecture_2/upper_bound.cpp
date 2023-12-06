#include<bits/stdc++.h>
using namespace std;

int upperBound(vector<int> arr, int n, int x) {
	// Write your code here
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
int main()
{
    vector<int>arr{2,4,6,7};
    int n=arr.size();
    int x=5;
    cout<<"Index = "<<upperBound(arr,n,x);
    return 0;
}
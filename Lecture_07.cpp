//Rotation
#include<bits/stdc++.h>
using namespace std;
int findKRotation(vector<int> &arr){
    int n = arr.size();
	int low = 0, high = n-1;
	int ans = INT_MAX;
    int index = -1;
    
	while(low <= high){
		int mid = (low + high) / 2;

		// search space is already sorted
		// then always arr[low] is will be smaller
		// in that search space

		if(arr[low] <= arr[high]){
		    if(arr[low] < ans){
				index = low;
				ans = arr[low];
			}
			break;
		}
		if(arr[low] <= arr[mid]){
			if(arr[low] < ans){
               index = low;
			   ans = arr[low];
			}
			low = mid + 1;
		}
		else{
			high = mid - 1;
			if(arr[mid] < ans){
				index = mid;
				ans = arr[mid];
			}
		}
	}
	return index;   
}

int main()
{
    vector<int> arr{3,4,5,1,2};
    cout<<findKRotation(arr);
    return 0;
}
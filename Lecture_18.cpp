//Allocate Books

#include<bits/stdc++.h>
using namespace std;

int countStudents(vector<int> &arr,int pages){
  int students = 1;
  long long pagesStudent = 0;
  for(int i = 0;i<arr.size();i++){
    if(pagesStudent + arr[i] <= pages){
      pagesStudent += arr[i];
    }
    else{
      students += 1;
      pagesStudent = arr[i];
    }
  }
  return students;
}
int findPages(vector<int>& arr, int n, int m) {
    if(m > n)
      return -1;
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);
    int ans = 0;
    while(low <= high){
      int mid = (low + high)/2;
      int students = countStudents(arr,mid);
      if(students > m){
        low = mid + 1;
      }
      else{
        ans = mid;
        high = mid - 1;
      }
    }
    return ans;
}

int main()
{
    vector<int> arr{12, 34, 67, 90};
    int n = arr.size();
    int m = 2;
    cout<<findPages(arr,n,m);
    return 0;
}
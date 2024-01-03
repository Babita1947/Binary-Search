//Painter's Partition

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

int findLargestMinDistance(vector<int> &boards, int k)
{
    int n = boards.size();
    if(k > n)
      return -1;
    int low = *max_element(boards.begin(),boards.end());
    int high = accumulate(boards.begin(),boards.end(),0);
    int ans = 0;
    while(low <= high){
      int mid = (low + high)/2;
      int students = countStudents(boards,mid);
      if(students > k){
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
    vector<int> boards{2, 1, 5, 6, 2, 3};
    int k = 2;
    cout<<findLargestMinDistance(boards,k);
    return 0;
}
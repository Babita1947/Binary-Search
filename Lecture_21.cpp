//4. Median of Two Sorted Arrays

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n1 = nums1.size(), n2 = nums2.size();
        //if n1 is bigger swap the arrays:
        if (n1 > n2) return findMedianSortedArrays(nums2, nums1);

        int n = n1 + n2; //total length
        int left = (n1 + n2 + 1) / 2; //length of left half
        //apply binary search:
        int low = 0, high = n1;
        while (low <= high) {
            int mid1 = (low + high) >> 1;
            int mid2 = left - mid1;
            //calculate l1, l2, r1 and r2;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if (mid1 < n1) r1 = nums1[mid1];
            if (mid2 < n2) r2 = nums2[mid2];
            if (mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
            if (mid2 - 1 >= 0) l2 = nums2[mid2 - 1];

            if (l1 <= r2 && l2 <= r1) {
                if (n % 2 == 1) return max(l1, l2);
                else return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
            }

            //eliminate the halves:
            else if (l1 > r2) high = mid1 - 1;
            else low = mid1 + 1;
        }
        return 0; //dummy statement
    }
};

// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         vector<int>v;
//         int i=0,j=0,length;
//         double median=0;
//         while(i<nums1.size() && j<nums2.size())
//         {
//             if(nums1[i]<nums2[j])
//             {
//                 v.push_back(nums1[i]);
//                 i++;
//             }
//             else
//             {
//                 v.push_back(nums2[j]);
//                 j++;
//             }
            
            
//         }
//         while(i<nums1.size())
//         {
//             v.push_back(nums1[i]);
//             i++;
//         }
//         while(j<nums2.size())
//         {
//             v.push_back(nums2[j]);
//             j++;
//         }
//         length=v.size();
//         if(length%2==0)
//            median=(v[(length/2)-1]+v[length/2])/2.0;
//         if(length%2!=0)
//            median=v[((length+1)/2)-1]; 
//         return median;     
//     }
// };

int main()
{
    Solution s;
    vector<int> nums1{2, 4, 6};
    vector<int> nums2{1,3,5};
    cout<<s.findMedianSortedArrays(nums1,nums2);
    return 0;
}
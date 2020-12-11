// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays/

/**

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

**/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        
        int n=nums1.size();
        
        if(n&1){
            return nums1[(n+1)/2-1];
        }            
        else
        {
            return (nums1[n/2-1]+nums1[n/2])/2.0;
        }
    }
};

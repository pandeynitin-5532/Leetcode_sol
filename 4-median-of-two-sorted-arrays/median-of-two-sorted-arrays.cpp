class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> c;
        c.insert(c.end(), nums1.begin(), nums1.end());
        c.insert(c.end(), nums2.begin(), nums2.end());
        sort(c.begin(),c.end());
        if(c.size()%2!=0){
            return c[c.size()/2];
        }
        double m=c.size();
        double med=(c[m/2.0]+c[m/2.0 -1])/2.0;
        return med;
    }
};
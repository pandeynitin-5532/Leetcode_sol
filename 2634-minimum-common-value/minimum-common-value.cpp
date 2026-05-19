class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3;
        int k = 0;
        int i = 0;
        
        while(k < nums2.size() && i < nums1.size()){
            while(i < nums1.size() && nums1[i] < nums2[k]) {
                i++;
            }
            
            if(i < nums1.size() && nums1[i] == nums2[k]){
                nums3.push_back(nums1[i]);
            }
            
            k++;
        }
        
        if (nums3.empty()) {
            return -1;
        }
        
        return *min_element(nums3.begin(), nums3.end());
    }
};
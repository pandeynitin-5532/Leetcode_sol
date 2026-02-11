class Solution {
public:
    bool binsearch(vector<int>& nums, int target, int l, int h) {
        if (l > h) return false;
        int mid = l + (h - l) / 2;
        if (nums[mid] == target) return true;
        if (nums[l] == nums[mid] && nums[mid] == nums[h]) {
            return binsearch(nums, target, l + 1, h - 1);
        }
        if (nums[l] <= nums[mid]) {
            if (nums[l] <= target && target < nums[mid]) {
                return binsearch(nums, target, l, mid - 1);
            } else {
                return binsearch(nums, target, mid + 1, h);
            }
        }
        else {
            if (nums[mid] < target && target <= nums[h]) {
                return binsearch(nums, target, mid + 1, h);
            } else {
                return binsearch(nums, target, l, mid - 1);
            }
        }
    }
    bool search(vector<int>& nums, int target) {
        return binsearch(nums, target, 0, nums.size() - 1);
    }
};
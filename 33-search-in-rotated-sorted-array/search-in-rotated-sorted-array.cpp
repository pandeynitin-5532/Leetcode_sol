class Solution {
public:
    int binsearch(vector<int>& nums, int target, int l, int h) {
        if (l > h) return -1;

        int mid = l + (h - l) / 2;

        if (nums[mid] == target) return mid;

        // LEFT half is sorted
        if (nums[l] <= nums[mid]) {
            if (nums[l] <= target && target < nums[mid]) {
                return binsearch(nums, target, l, mid - 1);
            } else {
                return binsearch(nums, target, mid + 1, h);
            }
        }
        // RIGHT half is sorted
        else {
            if (nums[mid] < target && target <= nums[h]) {
                return binsearch(nums, target, mid + 1, h);
            } else {
                return binsearch(nums, target, l, mid - 1);
            }
        }
    }

    int search(vector<int>& nums, int target) {
        return binsearch(nums, target, 0, nums.size() - 1);
    }
};

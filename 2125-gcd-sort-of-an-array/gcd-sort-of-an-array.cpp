class Solution {
public:
    vector<int> parent, rnk;
    
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (rnk[px] < rnk[py]) swap(px, py);
        parent[py] = px;
        if (rnk[px] == rnk[py]) rnk[px]++;
    }
    
    bool gcdSort(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        parent.resize(mx + 1);
        rnk.assign(mx + 1, 0);
        for (int i = 0; i <= mx; i++) parent[i] = i;
        
        vector<int> minPrime(mx + 1, 0);
        for (int i = 2; i <= mx; i++) {
            if (minPrime[i] == 0) {
                for (int j = i; j <= mx; j += i) {
                    if (minPrime[j] == 0) minPrime[j] = i;
                }
            }
        }
        
        for (int num : nums) {
            int x = num;
            while (x > 1) {
                int p = minPrime[x];
                unite(num, p);
                while (x % p == 0) x /= p;
            }
        }
        
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            if (find(nums[i]) != find(sorted_nums[i])) return false;
        }
        
        return true;
    }
};
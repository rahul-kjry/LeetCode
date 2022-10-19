class Solution {
public:
    
    void merge(vector<int> & vec, int lo, int md, int hi){
        int i = lo, j = md + 1;
        vector<int> tmp;
        while (i <= md and j <= hi ) tmp.push_back(vec[i] <= vec[j] ? vec[i++] : vec[j++]);
        while (i <= md) tmp.push_back(vec[i++]);
        while (j <= hi) tmp.push_back(vec[j++]);
        for (int i = lo; i <= hi; vec[i] = tmp[i - lo], ++i);
    }

    void mergeSort(vector<int> & vec, int lo, int hi) {
        if (lo < hi) {
            int md = lo + (hi - lo) / 2;
            mergeSort(vec, lo, md);
            mergeSort(vec, md + 1, hi);
            merge(vec, lo, md, hi);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
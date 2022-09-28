class Solution {
public:
    int uniqueLetterString(string str) {        
        int n = str.size(), ans = 0;
        vector<int> left(n), right(n);
        for (int i = 0; i < n; ++i) {
            int j = i - 1;
            while (j >= 0) {
                if (str[j] == str[i]) break;
                j--;
            }
            left[i] = i-j;
            j = i + 1; ;
            while(j < n) {
                if(str[j] == str[i]) break;
                j++;
            }
            right[i] = j - i;
        }
        
        for(int i = 0; i < n; ++i) {
            ans += (left[i] * right[i]);
        }
        return ans;
    }
};
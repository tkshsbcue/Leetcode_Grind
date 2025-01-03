class Solution {
public:

//let's solve this question once more
    int waysToSplitArray(vector<int>& nums) {
        //we are going to use prefix and suffix sum for this question
        long long n = nums.size();
        if(n == 1) return 0;

        vector<long long> l_r(n,0);
        vector<long long> r_l(n,0);
        long long counter = 0;
        l_r[0] = nums[0];
        r_l[n - 1] = nums[n - 1];
        for(int i = 1; i < n; i++){
            l_r[i] = l_r[i - 1] + nums[i];
        }
        for(int i = n - 2; i >= 0; i--){
            r_l[i] = r_l[i + 1] + nums[i];
        }
        for(int i = 0; i < n - 1; i++){
            if(l_r[i] >= r_l[i + 1]){
                counter++;
            }
        }
        return counter;
    }
};

//this question is very good example for prefix and suffix sum the current algo has time complexity of O(N)
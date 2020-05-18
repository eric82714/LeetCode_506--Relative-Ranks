class Solution {
public:
    vector<int> sorted(vector<int> nums) {
        int N = nums.size();
        for(int i = 0; i < N-1; i++) {
            for(int j = i; j < N; j++) {
                if(nums[i] < nums[j]) {
                    int tmp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = tmp;
                }
            }
        }
        return nums;
    }
    
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<string> result;
        string top3[] = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        int len = nums.size();
        
        vector<int> sort = sorted(nums);
        for(int i = 0; i < len; i++) {
            for(int j = 0; j < len; j++) {
                if(nums[i] == sort[j]) {
                    if(j < 3) { 
                        result.push_back(top3[j]);
                        break;
                    }
                    result.push_back(to_string(j+1));
                }
            }
        }
        
        return result;        
    }
};

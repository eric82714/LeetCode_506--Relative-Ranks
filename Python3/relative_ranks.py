import numpy as np

class Solution:
    def findRelativeRanks(self, nums: List[int]) -> List[str]:
        ranks = np.argsort(np.array(nums))[::-1]
        result = list(map(str, ranks))
        top3 = ["Gold Medal", "Silver Medal", "Bronze Medal"]
        
        for i in range(len(nums)):
            if i < 3: 
                result[ranks[i]] = top3[i]
                continue
            result[ranks[i]] = str(i+1)
        
        return result

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sorted(int* nums, int size){
    for(int i = 0; i < size-1; i++){
        for(int j = i; j < size; j++){
            if(nums[i] < nums[j]){
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
    }
    return nums;
}

char** findRelativeRanks(int* nums, int numsSize, int* returnSize){
    char** result = malloc((numsSize+1) * sizeof(char*));
    char* top3[3] = {"Gold Medal", "Silver Medal", "Bronze Medal"};
    
    int* copy = malloc(numsSize * sizeof(int));
    for(int i = 0; i < numsSize; i++) *(copy+i) = *(nums+i);
    int* sort = sorted(copy, numsSize);
    
    for(int i = 0; i < numsSize; i++){
        for(int j = 0; j < numsSize; j++){
            if(nums[i] == sort[j]){               
                if(j == 0) result[i] = top3[j];
                if(j == 1) result[i] = top3[j];
                if(j == 2) result[i] = top3[j];
                if(j > 2){
                    result[i] = (char*)malloc(13 * sizeof(char));
                    sprintf(result[i], "%d", j + 1);
                }
            }
        }
    }
    
    *returnSize = numsSize;
    return result;
}

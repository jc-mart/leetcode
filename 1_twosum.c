/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int found = 0;
    *returnSize = 2;
    int *ans = malloc(*returnSize * sizeof(int));
    
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if ((nums[i] + nums[j]) != target)
                continue;

            ans[0] = i;
            ans[1] = j;
            found++;
            break;
        }

        if (found)
            break;
    }

    return ans;
}

//#define _CRT_SECURE_NO_WARNINGS 1 
//#include<stdio.h>
//#include<stdlib.h>
//int* twoSum(int* nums, int numsSize, int target, int* returnSize)
//{
//	int i, j;
//	int sum = 0;
//	for (i = 0; i < numsSize - 1; i++)
//	{
//		for (j = i + 1; j < numsSize; j++)
//		{
//			sum = nums[i] + nums[j];
//			if (sum == target)
//			{
//				returnSize = (int*)malloc(2 * sizeof(int));
//				returnSize[0] = i;
//				returnSize[1] = j;
//				return returnSize;
//			}
//		}
//	}
//	return NULL;
//}
//int main()
//{
//	int nums[] = { 3,2,4 };
//	int numsSize = sizeof(nums) / sizeof(nums[0]);
//	int target = 0;
//	int* returnSize = NULL;
//	scanf("%d", &target);
//	returnSize = twoSum(nums, numsSize, target, returnSize);
//	if (returnSize != NULL)
//	{
//		printf("%d,%d\n", returnSize[0], returnSize[1]);
//	}
//	else
//	{
//		printf("Can not find it!\n");
//	}
//	free(returnSize);
//	returnSize = NULL;
//	return 0;
//}
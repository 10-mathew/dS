class Solution(object):
    def topKFrequent(self, nums, k):
        size=len(nums)
        temp=[]
        for num in set(nums):
            temp.append((nums.count(num),num))
        temp.sort(reverse=True)
        result=[]
        for i in range(k):
            result.append(temp[i][1])
        return result
             


             
         
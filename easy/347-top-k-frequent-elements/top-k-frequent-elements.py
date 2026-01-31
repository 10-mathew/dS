class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        k_freq=defaultdict(int)
        for num in nums:
            k_freq[num]+=1
        sorted_key=sorted(k_freq,key=k_freq.get,reverse=True)
        top_key=sorted_key[:k]
        return top_key

        
            

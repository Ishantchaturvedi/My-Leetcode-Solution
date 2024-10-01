class Solution:
    def canArrange(self, arr: List[int], k: int) -> bool:
        remainderFreq = [0] * k
        
        for num in arr:
            remainder = (num % k + k) % k  
            remainderFreq[remainder] += 1
    
        for i in range(k // 2 + 1):
            if i == 0:
                
                if remainderFreq[i] % 2 != 0:
                    return False
            else:
                
                if remainderFreq[i] != remainderFreq[k - i]:
                    return False
        
        return True
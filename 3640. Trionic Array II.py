class Solution: 
    def maxSumTrionic(self, A: List[int]) -> int: 
        n=len(A) 
        ans=neg=-(1<<50) 
        i, l, p, q, r=0, 0, 0, 0, 0 
        while i<n-1: 
            # Find l set Sum=0
            while i<n-1 and A[i]>=A[i+1]: i+=1
            l=i
            Sum=0
            
            # 1st uphill & find p, if p==l skip the rest
            while i<n-1 and A[i]<A[i+1]:
                x=A[i]
                Sum+=(x if x>0 else 0)
                i+=1
            p=i
            if p==l or (p+1<n and A[p]==A[p+1]): continue
            if A[p-1]<0: Sum+=A[p-1]
        
            # 1st downhill & find q, if q==p skip the rest
            while i<n-1 and A[i]>A[i+1]:
                Sum+=A[i]
                i+=1
            q=i
            if q==p or (q+1<n and A[q]==A[q+1]): continue
            # 2nd uphill & find r, if r>q  update ans with Sum, back to i=q
            Sum+=A[q]
            inc, maxInc=0, neg
            while i<n-1 and A[i]<A[i+1]:
                inc+=A[i+1]
                maxInc=max(maxInc, inc)
                i+=1
            r=i
            if r>q:
                ans=max(ans, Sum+maxInc)
                i=q
            i+=(l==i) 
         
        return ans
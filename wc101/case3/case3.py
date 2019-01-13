class Solution:
    def atMostNGivenDigitSet(self, D, N):
        """
        :type D: List[str]
        :type N: int
        :rtype: int
        """
        def findless(d, n):
            i,j = 0,0
            for v in d:
                if v < n:
                    i+= 1
                elif v == n:
                    j = 1
                elif v>n:
                    break
            return i,j

        ld = len(D)
        d = [int(i) for i in D]
        n = len(str(N))

        if n == 1:
            less, equal = findless(d,N)
            return less+equal

        combs = [0]*n
        combs[0] = ld
        for i in range(1,n):
            if i < n-1:
                combs[i]= combs[i-1]*ld
            else:
                k = 0
                j = i
                for strn in str(N):
                    less, equal = findless(d,int(strn))
                    if j-1>=0:
                        k += less*combs[j-1]
                        if equal == 0:
                            break
                        j -= 1
                    else:
                        k+= less+equal
                combs[i] = k
        return sum(combs)


print(Solution().atMostNGivenDigitSet(["3","5"],4))
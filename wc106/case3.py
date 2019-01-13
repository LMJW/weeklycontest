class Solution:
    def threeSumMulti(self, A, target):
        """
        :type A: List[int]
        :type target: int
        :rtype: int
        """
        def caltwooverlap(a,b):
            i, j, res, count = 0,0,0,0
            for k in b:
                for i in a:
                    if i < k:
                        count += 1
                    else:
                        if count > 1:
                            res += count-1


        d = {} #value count

        for i,v in enumerate(A):
            if v in d:
                d[v].append(i)
            else:
                d[v] = [i]

        l = list(d.keys())
        res = 0

        for i in range(len(l)):
            v = l[i]
            if len(d[v])> 1:
                cursum = 2*v
                resdu = target - cursum
                if resdu in d:





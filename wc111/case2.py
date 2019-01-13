class Solution:
    def diStringMatch(self, S):
        """
        :type S: str
        :rtype: List[int]
        """
        N = len(S)

        def dfs(start, level, used, path):
            # print(start, level, used, path)
            if level == N:
                return path
            ss = S[level]
            for i in range(N+1):
                if ss == 'I' and start < i and i not in used:
                    newused = {i for i in used}
                    newpath = [i for i in path]
                    newused.add(i)
                    newpath.append(i)
                    v = dfs(i, level+1, newused, newpath)
                    if v:
                        return v
                elif ss == 'D' and start > i and i not in used:
                    newused = {i for i in used}
                    newpath = [i for i in path]
                    newused.add(i)
                    newpath.append(i)
                    v = dfs(i, level+1, newused, newpath)
                    if v:
                        return v

        for start in range(N+1):
            v = dfs(start, 0, set([start]), [start])
            if v:
                return v

print(Solution().diStringMatch("DIDI"))
print(Solution().diStringMatch("IDID"))



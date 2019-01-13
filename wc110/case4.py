class Solution:
    def distinctSubseqII(self, S):
        """
        :type S: str
        :rtype: int
        """
        d = set()
        t = set()

        for i in S:
            if i not in d:
                t.add(i)
            for v in d:
                if v+i not in d:
                    t.add(v+i)
            d.update(t)
            t = set()
        return len(d)

print(Solution().distinctSubseqII("abc"))
print(Solution().distinctSubseqII("aba"))
print(Solution().distinctSubseqII("aaa"))
print(Solution().distinctSubseqII("sdkajhsahufiahdisahiduahdiaushdiaushdiasuhdiauhdiasuhdiuasidhiashuiduhisuhaiduaisdhiauhfiauhsifauhfiasuhdiaushid"))
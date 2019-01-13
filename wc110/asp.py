class Solution:
    def reorderLogFiles(self, logs):
        """
        :type logs: List[str]
        :rtype: List[str]
        """
        def fff(a):
            return a[1]
        d = []
        for log in logs:
            w = log.split(" ")
            t = "".join([word[0] for word in w])
            d.append(t)
        x = zip(logs, d)

        y = sorted(x, key = fff)
        res = [i[0] for i in y]
        return res

print(Solution().reorderLogFiles(["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]))
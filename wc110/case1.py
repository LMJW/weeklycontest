class Solution:
    def reorderLogFiles(self, logs):
        """
        :type logs: List[str]
        :rtype: List[str]
        """
        dlog = []
        llog = []
        llog_key = {}
        for log in logs:
            w = list(log.split(" "))
            try:
                int(w[1])
                dlog.append(log)
            except:
                t = " ".join(w[1:])
                llog.append(t)
                llog_key[t] = w[0]

        llog = sorted(llog)
        nl = [llog_key[i]+' '+i for i in llog]
        return nl+dlog


print(Solution().reorderLogFiles(["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]))

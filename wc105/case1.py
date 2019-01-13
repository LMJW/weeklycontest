class Solution:
    def reverseOnlyLetters(self, S):
        """
        :type S: str
        :rtype: str
        """
        letters = set("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ")
        i, j = 0, len(S)-1
        arrs = list(S)
        while i<j:
            if arrs[i] in letters and arrs[j] in letters:
                arrs[i],arrs[j] = arrs[j],arrs[i]
                i+= 1
                j-= 1
            elif arrs[i] not in letters:
                i+=1
            elif arrs[j] not in letters:
                j-=1
        return "".join(arrs)

print(Solution().reverseOnlyLetters("ab-cd"))
print(Solution().reverseOnlyLetters("a-bC-dEf-ghIj"))
print(Solution().reverseOnlyLetters("Test1ng-Leet=code-Q!"))
print(Solution().reverseOnlyLetters("asbc"))
print(Solution().reverseOnlyLetters(""))


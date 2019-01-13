class Solution:
    def numUniqueEmails(self, emails):
        """
        :type emails: List[str]
        :rtype: int
        """
        def remail(email):
            local, domain = email.split('@')
            re = []
            for letter in list(local):
                if letter == '.':
                    continue
                elif letter = '+':
                    break
                else:
                    re.append(letter)
            res = ''.join(re)+domain
            return res

        d = set()
        for e in emails:
            x = remail(e)
            if x not in d:
                d.add(x)
        return len(d)

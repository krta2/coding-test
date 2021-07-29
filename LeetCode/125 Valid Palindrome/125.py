class Solution:
    def isPalindrome(self, s: str) -> bool:
        i = 0
        j = len(s) - 1

        s = s.lower()

        while i < j:
            while not s[i].isalnum() and i < len(s) - 1:
                i += 1
            while not s[j].isalnum() and j > 0:
                j -= 1

            if i < j and s[i] != s[j]:
                return False

            i += 1
            j -= 1

        return True


import string
from collections import Counter
import re


class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        word_list = []
        punctuations = string.punctuation + ' '
        for word in re.split(f'[{punctuations}]+', paragraph):
            word = word.lower()
            if word not in banned:
                word_list.append(word)

        count_dict = Counter(word_list)

        return count_dict.most_common(1)[0][0]



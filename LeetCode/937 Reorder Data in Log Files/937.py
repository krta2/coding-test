from typing import *
from functools import cmp_to_key


def custom_cmp(a, b):
    if a['content'] < b['content']:
        return -1
    elif a['content'] == b['content']:
        if a['identifier'] < b['identifier']:
            return -1
        else:
            return 1
    else:
        return 1


class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        letter_logs = []
        digit_logs = []
        for log in logs:
            first_space_position = log.find(' ')
            item = {
                'identifier': log[:first_space_position],
                'content': log[first_space_position + 1:],
            }

            if log[first_space_position + 1].isalpha():
                letter_logs.append(item)
            else:
                digit_logs.append(item)

        # Sorting two times is faster than custom sort
        # letter_logs.sort(cmp_to_key(custom_cmp))

        letter_logs.sort(key=lambda x: x['identifier'])
        letter_logs.sort(key=lambda x: x['content'])

        result = []
        for letter_log in letter_logs:
            result.append(letter_log['identifier'] + ' ' + letter_log['content'])
        for digit_log in digit_logs:
            result.append(digit_log['identifier'] + ' ' + digit_log['content'])

        return result

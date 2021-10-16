import operator
import re

score = {'A': 1, 'B': 3, 'C': 3, 'D': 2, 'E': 1, 'F': 4,
'G': 2, 'H': 4, 'I': 1, 'J': 8, 'K': 5, 'L': 1,
'M': 3, 'N': 1, 'O': 1, 'P': 3, 'Q': 10, 'R': 1,
'S': 1, 'T': 1, 'U': 1, 'V': 4, 'W': 4, 'X': 8,
'Y': 4, 'Z': 10}

words = dict()
with open("m2-scrabble-sample.txt") as file:
    for x in ' '.join(file.readlines()).split():
        m = re.match(".*?([a-zA-Z]+).*", x)
        if m and m.group(1).upper() not in words:
            words[m.group(1).upper()] = sum([score[c] for c in m.group(1).upper() if c in score])

for x in sorted(words.items(), key=operator.itemgetter(1), reverse=True):
    print("{0} ({1})".format(x[0], x[1]))

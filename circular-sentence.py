# Circular Sentence
class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        xs = sentence.split()
        for i in range(len(xs)-1):
            if xs[i][-1] != xs[i+1][0]:
                return False
        return xs[-1][-1] == xs[0][0]

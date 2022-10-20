# Todo import Counter
class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        x=list(Counter(words).items())
        x.sort(key=lambda x:(-x[1],x[0]))
        return [x[i][0] for i in range(k)]
    def largestOverlap(self, A, B):
        N = len(A)
        LA = [i / N * 100 + i % N for i in xrange(N * N) if A[i / N][i % N]]
        LB = [i / N * 100 + i % N for i in xrange(N * N) if B[i / N][i % N]]
        c = collections.Counter(i - j for i in LA for j in LB)
        return max(c.values() or [0])
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        frq=collections.defaultdict(int)
        need=len(t)
        for i in t:
            frq[i]+=1
        start=0
        end=0
        min_window_start=0
        min_size=len(s)+1
        while end<len(s):
            if s[end] in frq:
                if frq[s[end]]>0:
                    need-=1
                frq[s[end]]-=1
            while need==0:
                if end-start+1<min_size:
                    min_size=end-start+1
                    min_window_start=start
                if s[start] in frq:
                    frq[s[start]]+=1
                    if frq[s[start]]>0:
                        need+=1
                        
                start+=1
            end+=1
        if min_size==len(s)+1:
            return ""
        return s[min_window_start:min_size+min_window_start]
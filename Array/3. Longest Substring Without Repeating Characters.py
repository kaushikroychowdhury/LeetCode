class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if s == "":
            return 0
        
        fp, lp, ml = 0, 1, 1
        s_len = len(s)
        if s_len == 1:
            return 1
        
        while fp < s_len and lp < s_len:
            pos = s.find(s[lp], fp, lp)
            if pos == -1:
                l = len(s[fp : lp+1])
                if l > ml:
                    ml = l
            else:
                fp = pos + 1
            lp += 1
            
        return ml
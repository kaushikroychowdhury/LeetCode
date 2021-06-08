class Solution:
    def countMatches(self, items: List[List[str]], ruleKey: str, ruleValue: str) -> int:
        output = 0
        if ruleKey == 'type':
                for j in items:
                    if j[0] == ruleValue:
                        output += 1
        if ruleKey == 'color':
                for j in items:
                    if j[1] == ruleValue:
                        output += 1
        if ruleKey == 'name':
                for j in items:
                    if j[2] == ruleValue:
                        output += 1
        return output
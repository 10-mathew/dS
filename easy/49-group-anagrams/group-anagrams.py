
class Solution(object):
    def groupAnagrams(self, strs):
        d={}
        for j in strs:
            i=tuple(sorted(j))
            if i in d:
                d[i].append(j)
            else:
                d[i]=[j]
        return d.values()

        
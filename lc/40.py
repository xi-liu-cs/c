def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
    def dfs(pos: int, rest: int):
        nonlocal cur
        if rest == 0:
            res.append(cur)
            return
        if pos == len(freq) or rest < freq[pos][0]:
            return
        dfs(pos + 1, rest)
        most = min(rest // freq[pos][0], freq[pos][1])
        for i in range(1, most + 1):
            cur.append(freq[pos][0])
            dfs(pos + 1, rest - i * freq[pos][0])
        cur = cur[:-most] # rm 'most' char from cur right 
    freq = sorted(collections.Counter(candidates).items())
    res = []
    cur = []
    dfs(0, target)
    return res

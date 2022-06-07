def findSubstring(self, s: str, words: List[str]) -> List[int]:
    if not s or not words:
        return []
    word_len = len(words[0])
    all_len = len(words) * word_len # all words len
    s_len = len(s)
    words = Counter(words)
    ret = []
    for i in range(0, s_len - all_len + 1):
        tmp = s[i : i + all_len]
        tmp_c = []
        for j in range(0, all_len, word_len):
            tmp_c.append(tmp[j : j + word_len])
        if Counter(tmp_c) == words:
            ret.append(i)
    return ret

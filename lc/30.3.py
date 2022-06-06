def findSubstring(self, s: str, words: List[str]) -> List[int]:
  if not s or not words:
      return []
  from collections import Counter
  word_len = len(words[0])
  word_num = len(words)
  s_len = len(s)
  if s_len < word_len:
      return []
  words_cntr = Counter(words)
  res = []
  for i in range(0, word_len):
      cur_cnt = 0
      left = i
      right = i
      cur_cntr = Counter()
      while right + word_len <= s_len:
          right_w = s[right : right + word_len]
          right += word_len
          if right_w not in words:
              left = right
              cur_cntr.clear()
              cur_cnt = 0
          else:    
              cur_cntr[right_w] += 1
              cur_cnt += 1
              while cur_cntr[right_w] > words_cntr[right_w]:
                  left_w = s[left : left + word_len]
                  left += word_len
                  cur_cntr[left_w] -= 1
                  cur_cnt -= 1
              if cur_cnt == word_num:
                  res.append(left)
  return res

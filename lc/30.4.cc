vector<int> findSubstring(string s, vector<string> & words) 
{
    if(s.empty() || words.empty()) return {};
    int s_len = s.size(),
    word_len = words[0].size(),
    word_num = words.size();
    map<string, int> words_mp;
    for(auto & i : words)
        ++words_mp[i];
    vector<int> res;
    for(int i = 0; i < word_len; ++i)
    {
        int left = i,
        right = i,
        cnt = 0;
        map<string, int> cur_mp;
        while(right + word_len <= s_len)
        {
            string right_w = s.substr(right, word_len);
            right += word_len;
            if(!words_mp[right_w])
            {
                left = right;
                cur_mp.clear();
                cnt = 0;
            }
            else
            {
                ++cur_mp[right_w];
                ++cnt;
                while(cur_mp[right_w] > words_mp[right_w])
                {
                    string left_w = s.substr(left, word_len);
                    left += word_len;
                    --cur_mp[left_w];
                    --cnt;
                }
                if(cnt == word_num)
                    res.push_back(left);
            }
        }
    }
    return res;
}

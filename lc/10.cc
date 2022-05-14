bool isMatch(string s, string p) 
{
    auto cmp = [&](int i, int j)
    {
        if(!i)
            return false;
        if(p[j - 1] == '.') /* '.' can match any character */
            return true;
        return s[i - 1] == p[j - 1];
    };
    int s_l = s.size();
    int p_l = p.size();
    vector<vector<int>> a(s_l + 1, vector<int>(p_l + 1, false));
    a[0][0] = true;
    for(int i = 0; i <= s_l; ++i)
    {
        for(int j = 1; j <= p_l; ++j)
        {
            if(p[j - 1] != '*')
            {
                if(cmp(i, j))
                    a[i][j] = a[i - 1][j - 1];
            }
            else
            {
                a[i][j] = a[i][j - 2];
                if(cmp(i, j - 1))
                    a[i][j] |= a[i - 1][j];
            }
        }
    }
    return a[s_l][p_l];
}

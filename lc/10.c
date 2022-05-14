bool cmp(char * s, int i, char * p, int j)
{
    if(!i)
        return false;
    if(p[j - 1] == '.') /* '.' can match any character */
        return true;
    return s[i - 1] == p[j - 1];
}

bool isMatch(char * s, char * p)
{
    int s_l = strlen(s);
    int p_l = strlen(p);
    bool a[s_l + 1][p_l + 1];
    memset(a, false, sizeof(a));
    **a = true;
    for(int i = 0; i <= s_l; ++i)
    {
        for(int j = 1; j <= p_l; ++j)
        {
            if(p[j - 1] != '*')
            {
                if(cmp(s, i, p, j))
                    a[i][j] = a[i - 1][j - 1];
            }
            else
            {
                a[i][j] = a[i][j - 2];
                if(cmp(s, i, p, j - 1))
                    a[i][j] |= a[i - 1][j];
            }
        }
    }
    return a[s_l][p_l];
}

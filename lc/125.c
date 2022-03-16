bool isPalindrome(char * s)
{
    int s_len = strlen(s);
    char a[s_len + 1];
    int a_i = 0, s_i = 0;
    while(s_i < s_len)
    {
        if(s[s_i] != ' ' && !ispunct(s[s_i]))
        {
            a[a_i++] = tolower(s[s_i]);
        }
        s_i++;
    }
    a[a_i] = '\0';
    int a_len = strlen(a);
    int i = 0, j = a_len - 1;
    while(i < j)
        if(a[i++] != a[j--])
            return false;
    return true;
}

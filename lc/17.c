char * phone_map[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
char ** comb; int comb_sz;
char * digit; int digit_sz;
char * str; int str_sz;

void back_track(int i)
{
    if(i == digit_sz)
    {
        size_t sz = (str_sz + 1) * sizeof(char);
        char * buf = (char *)malloc(sz);
        memcpy(buf, str, sz);
        comb[comb_sz++] = buf;
    }
    else
    {
        char * str_in_map = phone_map[digit[i] - '0'];
        int str_in_map_len = strlen(str_in_map);
        for(int j = 0; j < str_in_map_len; ++j)
        {
            str[str_sz++] = str_in_map[j];
            str[str_sz] = '\0';
            back_track(i + 1);
            str[--str_sz] = '\0';
        }
    }
}

char ** letterCombinations(char * digits, int * return_size)
{
    digit = digits;
    digit_sz = strlen(digits);
    if(!digit_sz)
    {
        *return_size = 0;
        return comb;
    }
    int comb_cap = 1;
    for(int i = 0; i < digit_sz; ++i) 
        comb_cap *= 4;
    comb = (char **)malloc(comb_cap * sizeof(char *));
    str = (char *)malloc((digit_sz + 1) * sizeof(char));
    comb_sz = str_sz = 0;
    back_track(0);
    *return_size = comb_sz;
    return comb;
}

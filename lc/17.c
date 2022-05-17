/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

char * phone_map[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
char ** comb; int comb_sz;
char * str; int str_sz;
char * digit;

void back_track(int i)
{
    if(i == strlen(digit))
    {
        size_t sz = (str_sz + 1) * sizeof(char);
        char * buf = (char *)malloc(sz);
        memcpy(buf, str, sz);
        comb[comb_sz++] = buf;
        return;
    }
    else
    {
        char * str_in_map = phone_map[i];
        for(int j = 0; j < str_sz; ++j)
        {
            str[str_sz++] = str_in_map[j];
            back_track(i + 1);
            --str_sz;
        }
    }
}

char ** letterCombinations(char * digits, int * return_size)
{
    digit = digits;
    
}

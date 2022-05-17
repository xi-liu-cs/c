char * map[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
char ** comb;

char ** letterCombinations(char * digits, int * return_size)
{
    int n = strlen(digits);
    if(!n)
    {
        *return_size = 0;
        return comb;
    }
    comb = (char **)malloc();
    for(int i = 0; i < n; ++i)
    {
        
    }
}

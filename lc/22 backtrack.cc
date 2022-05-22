vector<string> ret;
string cur;
int _n;

void backtrack(int open, int close)
{
    if(cur.size() == 2 * _n)
    {
        ret.push_back(cur);
        return;
    }
    if(open < _n)
    {
        cur.push_back('(');
        backtrack(open + 1, close);
        cur.pop_back();
    }
    if(close < open)
    {
        cur.push_back(')');
        backtrack(open, close + 1);
        cur.pop_back();
    }
}

vector<string> generateParenthesis(int n) 
{
    _n = n;
    backtrack(0, 0);   
    return ret;
}

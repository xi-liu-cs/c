vector<string> ret;
string cur;
int _n;

bool valid()
{
    int balance = 0;
    for(int i = 0; i < cur.size(); ++i)
    {
        if(cur[i] == '(')
            ++balance;
        else if(cur[i] == ')')
            --balance;
        if(balance < 0)
            return false;
    }
    return balance == 0;
}

void generate()
{
    if(cur.size() == 2 * _n)
    {
        if(valid())
            ret.push_back(cur);
        return;
    }
    cur += '(';
    generate();
    cur.pop_back();
    cur += ')';
    generate();
    cur.pop_back();
}

vector<string> generateParenthesis(int n) 
{
    _n = n;
    generate();
    return ret;
}

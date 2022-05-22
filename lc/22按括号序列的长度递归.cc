vector<shared_ptr<vector<string>>> cache{9, nullptr};

shared_ptr<vector<string>> generate(int n)
{
    if(!n)
        cache[0] = shared_ptr<vector<string>>(new vector<string>{""});
    else
    {
        auto cur = shared_ptr<vector<string>>(new vector<string>);
        for(int i = 0; i < n; ++i)
        {
            auto lefts = generate(i);
            auto rights = generate(n - i - 1);
            for(string & left : *lefts)
                for(string & right : *rights)
                    cur->push_back('(' + left + ')' + right);
        }
        cache[n] = cur;
    }
    return cache[n];
}

vector<string> generateParenthesis(int n) 
{
    return *generate(n);
}

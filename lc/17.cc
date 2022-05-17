vector<string> letterCombinations(string digits) 
{
    vector<string> comb;
    if(!digits.size())
        return comb;
    comb.push_back("");
    map<char, string> phone_map
    {
        {'2', "abc"}, 
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"}, 
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };
    for(int i = 0; i < digits.size(); ++i)
    {
        string str_in_map = phone_map[digits[i]];
        while(comb.back().size() == i)
        {
            string last = comb.back();
            comb.pop_back();
            for(int j = 0; j < str_in_map.size(); ++j)
                comb.push_back(last + str_in_map[j]); 
        }
    }
    return comb;
}

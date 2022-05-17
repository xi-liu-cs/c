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
vector<string> comb;
string str;
string digit;

void back_track(int i)
{
    if(i == digit.size())
        comb.push_back(str);
    string str_in_map = phone_map[digit[i]];
    for(int j = 0; j < str_in_map.size(); ++j)
    {
        str += str_in_map[j];
        back_track(i + 1);
        str.erase(str.end() - 1);
    }
}

vector<string> letterCombinations(string digits) 
{
    digit = digits;
    if(!digits.size())
        return comb;
    back_track(0);
    return comb;
}

vector<int> pancakeSort(vector<int> & a) 
{
  vector<int> ret;
  for(int n = a.size(); n > 1; --n)
  {
      int max_i = max_element(a.begin(), a.begin() + n) - a.begin();
      if(max_i == n - 1)
          continue;
      reverse(a.begin(), a.begin() + max_i + 1);
      reverse(a.begin(), a.begin() + n);
      ret.push_back(max_i + 1);
      ret.push_back(n);
  }
  return ret;
}

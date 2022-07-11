#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
  
int main()
{
    int st, op;
    while(cin >> st >> op)
    {
        vector<int> stu(st);
        int a, b; char c;
        for(int i = 0; i < st; ++i) cin >> stu[i];
        for(int i = 0; i < op; ++i)
        {
            cin >> c >> a >> b;
            if(c == 'Q')
            {
                if(a > b) swap(a,b);
                cout << *max_element(stu.begin() + a - 1, stu.begin() + b) << endl;                   
            }   
            if(c == 'U')
                stu[a - 1] = b;        
        }
    }
}

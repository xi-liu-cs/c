/* every cell in n * n matrix has a number
need to periodically perform a '+' shaped
cut that removes 1 row and 1 col
maximize numbers cut in the '+' shape
for n times */

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<vector<int>> box(n, vector<int>(n, 0));
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> box[i][j];
   
    while(n)
    {
        int max_i = 0, max_j = 0, max_sum = 0;
        vector<int> row_sums(n, 0);
        vector<int> col_sums(n, 0);
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                row_sums[i] += box[i][j];
                col_sums[j] += box[i][j];
            }
        }
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                int cur_sum = row_sums[i] + col_sums[j] - box[i][j];
                if(cur_sum > max_sum) /* row_sums[i] + col_sums[j] will count box[i][j] twice */
                {  
                    max_sum = cur_sum;
                    max_i = i;
                    max_j = j;
                }
            }
        }
        cout << max_i + 1 << " " << max_j + 1 << endl;
        box.erase(box.begin() + max_i);
        for(int i = 0; i < box.size(); ++i)
            box[i].erase(box[i].begin() + max_j);
        --n;
    }
}

/* if there is a pair left-right or top-down adjacent traversable cells
then can go from one cell to another
each treasure chest is in a different traversable cell

strategy to collect all chests:
1. find an uncollected chest that has a least manhattan distance
from the current cell, call it k-chest
2. if cannot arrive k-chest from current cell, then attempt to collect fails
else, calculate shortest path length from current cell to k-chest
and follow the order of up-down-left-right to calculate whether
there is a decrease in distance to k-chest if moving in that direction
if decrease in distance, move one step in that direction
3. if current cell has an uncollected chest, then collect this chest
if some chests are uncollected, go back to step 1

manhattan distance between cell (x, y) and (u, v):
d = |x - u| + |y - v|

input:
1st line is t, represents t data sets
    each data set:
        1st line is m, n: num_rows = m; num_cols = n
        then m rows, each row has n characters, represents maze map
            #: obstacle
            *: current cell, traversable
            0-9: chest containing cell, traversable
            .: other traversable cell
1 <= t <= 5; 1 <= n, m <= 50; 1 <= num_chests <= 10

question: what is num cells walked using this strategy? */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <queue>
using namespace std;

struct cell
{
    int x, y, walk; /* num cells walked */
}box_cell[10]; /* cells that contain boxes */

char map[55][55]; /* map of maze */
bool visited[55][55];
int dp[55][55][10], /* shortest distance from each point to each box */
x_disp[] = {0, 0, -1, 1}, /* direction: up-down-left-right */
y_disp[] = {1, -1, 0, 0},
m, n, num_box;

void bfs(int x, int y, int box_id)
{
    memset(visited, false, sizeof(visited));
    visited[x][y] = true;
    cell a;
    a.x = x;
    a.y = y;
    a.walk = 0;
    queue<cell> q;
    q.push(a);
    while(!q.empty())
    {
        cell cur = q.front();
        q.pop();
        for(int i = 0; i < 4; ++i)
        {
            int x_new = cur.x + x_disp[i],
            y_new = cur.y + y_disp[i],
            walk_new = cur.walk + 1;
            if(1 <= x_new && x_new <= m
            && 1 <= y_new && y_new <= n
            && !visited[x_new][y_new]
            && map[x_new][y_new] != '#')
            {
                visited[x_new][y_new] = true;
                dp[x_new][y_new][box_id] = walk_new;
                q.push(cell{x_new, y_new, walk_new});
            }
        }
    }
}

int _bfs(int x, int y, int walk)
{
    memset(visited, false, sizeof(visited));
    visited[x][y] = true;
    cell a;
    a.x = x;
    a.y = y;
    a.walk = walk;
    queue<cell> q;
    q.push(a);
    int collected = 0;
    while(!q.empty())
    {
        cell cur = q.front();
        q.pop();
        if('0' <= map[cur.x][cur.y] && map[cur.x][cur.y] <= '9'
        && box_cell[map[cur.x][cur.y] - '0'].walk == 0)
        {
            memset(visited, false, sizeof(visited));
            visited[cur.x][cur.y] = 1;
            box_cell[map[cur.x][cur.y] - '0'].walk = 1;
            ++collected;
        }
        if(collected == num_box)
            return cur.walk;
        int min_dist = ((unsigned int)1 << 31) - 1, /* minimum manhattan distance */
        box_id;
        for(int i = 0; i < num_box; ++i)
        {
            if(abs(box_cell[i].x - cur.x) + abs(box_cell[i].y - cur.y) < min_dist
            && box_cell[i].walk == 0)
            {
                min_dist = abs(box_cell[i].x - cur.x) + abs(box_cell[i].y - cur.y);
                box_id = i;
            }
        }
        for(int i = 0; i < 4; ++i)
        {
            int x_new = cur.x + x_disp[i],
            y_new = cur.y + y_disp[i],
            walk_new = cur.walk + 1;
            if(1 <= x_new && x_new <= m
            && 1 <= y_new && y_new <= n
            && !visited[x_new][y_new]
            && map[x_new][y_new] != '#'
            && dp[x_new][y_new][box_id] < dp[cur.x][cur.y][box_id])
            {
                visited[x_new][y_new] = true;
                q.push(cell{x_new, y_new, walk_new});
            }
        }
    }
    return -1;
}

int main()
{
    int t, x, y;
    cin >> t;
    while(t--)
    {
        memset(dp, 0, sizeof(dp));
        cin >> m >> n;
        num_box = 0;
        for(int i = 1; i <= m; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                cin >> map[i][j];
                if(map[i][j] == '*')
                {/* obstacle */
                    x = i;
                    y = j;
                }
                else if('0' <= map[i][j] && map[i][j] <= '9')
                {/* cell containing box */
                    box_cell[map[i][j] - '0'].x = i;
                    box_cell[map[i][j] - '0'].y = j;
                    ++num_box;
                }
            }
        }
        for(int i = 0; i < num_box; ++i)
            bfs(box_cell[i].x, box_cell[i].y, i);
        int ret = _bfs(x, y, 0);
        cout << ret << "\n";
        memset(box_cell, 0, sizeof(box_cell));
    }
}

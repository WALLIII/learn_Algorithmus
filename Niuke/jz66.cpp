#include <deque>
#include <iostream>
#include <vector>
#include <queue>
// BFS
int get(int x)
{
    int sum = 0;
    while (x != 0)
    {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

// int movingCount(int m, int n, int k)
// {
//     if(k==0)
//         return 1;
//     std::queue<std::pair<int,int>> Q;
//     std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
//     Q.push(std::make_pair(0,0));
//     int res=0;
//     while(!Q.empty()){
//         auto [x, y] = Q.front();
      
//         Q.pop();
//         if(x>=m||y>=n||get(x)+get(y)>k||visited[x][y])
//             continue;
//         visited[x][y]=true;
//         res++;
//         Q.push(std::make_pair(x+1, y));
//         Q.push(std::make_pair(x,y+1));
//     }
//     return res;
// }

// DFS
int dfs(int threshold, int rows, int cols, int row, int col, std::vector<int> &isVisit)
{
    if (row < 0 || row >= rows || col < 0 || col >= cols 
                || get(row) + get(col) > threshold || isVisit[row * cols + col] == 1)
        return 0;
    isVisit[row * cols + col] = 1;
    return 1 + dfs(threshold, rows, cols, row + 1, col, isVisit) +
           dfs(threshold, rows, cols, row, col + 1, isVisit);
}
int movingCount(int m, int n, int k)
{
    std::vector<int> isVisit(m * n, 0);
    return dfs(k, m, n, 0, 0, isVisit);
}




int main()
{
    std::cout << movingCount(4, 12, 2) << std::endl;
    return 0;
}
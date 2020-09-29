#include <vector>
#include <iostream>
using namespace std;

void dfs(vector<vector<char>> &board, string &word, bool &res,  int depth, vector<vector<bool>> &used, int r, int c)
{
    if (depth == word.size())
    {
        res = true;
        return;
    }
    if (r == board.size() || c == board[0].size() || r == -1 || c == -1 || used[r][c] == true || board[r][c] != word[depth] || res)
        return;

    // path.push_back(board[r][c]);
    used[r][c] = true;
    dfs(board, word, res, depth + 1, used, r, c - 1);
    dfs(board, word, res, depth + 1, used, r, c + 1);
    dfs(board, word, res, depth + 1, used, r + 1, c);
    dfs(board, word, res, depth + 1, used, r - 1, c);
    used[r][c] = false;
    // path.pop_back();
    return;
}

bool exist(vector<vector<char>> &board, string word)
{
    if (board.size() == 0)
        return false;
    vector<vector<bool>> used(board.size(), vector<bool>(board[0].size(), false));
    bool res = false;
    // string path;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            dfs(board, word, res, 0, used, i, j);
        }
    }
    return res;
}

void dfs(char *matrix, int rows, int cols, int r, int c, bool &res,
         std::vector<std::vector<bool>> &used, std::string &words, int depth)
{
    if (depth == words.size())
    {
        res = true;
        return;
    }

    // 如果遇到边界或者没有匹配上或者已经搜索过了，就返回--->剪枝
    if(r==-1||c==-1||r==rows||c==cols||(words[depth]!=matrix[r*cols+c])||used[r][c]||res){
        return;
    }
    used[r][c]=true;
    dfs(matrix, rows, cols, r+1, c, res, used, words, depth+1);
    dfs(matrix, rows, cols, r, c+1, res, used, words, depth+1);
    dfs(matrix, rows, cols, r-1, c, res, used, words, depth+1);
    dfs(matrix, rows, cols, r, c-1, res, used, words, depth+1);
    used[r][c]=false;
    return;
}

bool hasPath(char *matrix, int rows, int cols, char *str)
{
    if (str == NULL || rows <= 0 || cols <= 0)
        return false;
    std::vector<std::vector<bool>> used(rows, std::vector<bool>(cols, false));

    std::string words(str);
    bool res = false;
    for (int i = 0; i < cols; ++i)
    {
        for (int j = 0; j < rows; ++j)
        {
            dfs(matrix, rows, cols, i, j, res, used, words, 0);
        }
    }
    return res;
}

int main()
{
    std::vector<std::vector<char>> board(3, std::vector<char>(4, 'a'));
    // char matrix[3][4] = {{'a', 'b', 'c', 'e'}, {'s', 'f', 'c', 's'}, {'a', 'd', 'e', 'e'}};
    // for (int i = 0; i < 3; ++i)
    // {
    //     for (int j = 0; j < 4; ++j)
    //     {
    //         board[i][j] = matrix[i][j];
    //     }
    // }
    char matrix[12] = {'a', 'b', 'c', 'e', 's', 'f', 'c', 's', 'a', 'd', 'e', 'e'};

    if (hasPath(matrix, 3, 4, "abbb"))
    {
        std::cout << "existed" << std::endl;
    }
    else
    {
        std::cout << "not existed" << std::endl;
    }
    return 0;
}
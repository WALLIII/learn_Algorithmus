#include <vector>
#include <string>
#include <iostream>

void dfs(std::vector<std::string> &ans, std::string path, int n, int lc, int rc)
{
    if (rc > lc || lc > n || rc > n)
    {
        return;
    }
    if (lc == rc && lc == n)
    {
        ans.push_back(path);
        return;
    }
    dfs(ans, path + '(', n, lc + 1, rc);
    dfs(ans, path + ')', n, lc, rc + 1);
}

std::vector<std::string> generateParenthesis(int n)
{
    std::vector<std::string> ans;
    dfs(ans, "", n, 0, 0);
    return ans;
}

int main()
{
    std::vector<std::string> ans = generateParenthesis(10);
    for (auto str : ans)
    {
        std::cout << str << std::endl;
    }
    return 0;
}

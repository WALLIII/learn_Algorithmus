#include <vector>
#include <iostream>

bool Find(int target, std::vector<std::vector<int>> vec)
{
    if (vec.size() == 0 || vec[0].size() == 0)
        return false;
    int colNum = vec[0].size();
    int rowNum = vec.size();
    // std::cout << "colNum:  " << colNum << "  rowNum: " << rowNum << std::endl;
    int i = 0, j = colNum-1;
    while (j >= 0 && i <= rowNum - 1)
    {
        if(vec[i][j]==target){
            // std::cout<<"row number: "<<i+1<<"  col number: "<<j+1<<std::endl;
            return true;
        }
        else if(vec[i][j]<target)
            ++i;
        else
            --j;
    }
    return false;
}

int main()
{
    std::vector<std::vector<int>> vec(5, std::vector<int>(4, 0));
    int a[5][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}, {7, 10, 16, 18}};
    for (int i = 0; i < vec.size(); ++i)
    {
        for (int j = 0; j < vec[0].size(); ++j)
        {
            vec[i][j] = a[i][j];
        }
    }
    if (Find(19, vec))
        std::cout << "find!" << std::endl;
    else
        std::cout << "not find!" << std::endl;
    return 0;
}
#include <iostream>
#include <vector>

bool Find(std::vector<std::vector<int>> vec, int target, int *targetRow, int *targetCol)
{

    int rowCount = vec.size();
    int colCount = vec[0].size();
    int row = rowCount - 1;
    int col = 0;
    int count = 0;
    while (row >= 0 && col < colCount)
    {
        if (vec[row][col] == target)
        {
            *targetRow = row;
            *targetCol = col;
            std::cout << "target is fund in Row:" << row + 1 << " in Col:" << col + 1 << std::endl;
            return true;
        }
        if (vec[row][col] < target)
        {
            std::cout << "count:" << count << "now in row:" << row + 1 << " in col:" << col + 1 << std::endl;
            col++;
            continue;
        }
        if (vec[row][col] > target)
        {
            std::cout << "count:" << count << "now in row:" << row + 1 << " in col:" << col + 1 << std::endl;
            row--;
            continue;
        }
        ++count;
    }
    return false;
}

int main()
{
    // std::vector<std::vector<int> > vec(4, std::vector<int>(4, 0));
    std::vector<std::vector<int>> vec(4);
    int *targetRow = new int[1];
    int *targetCol = new int[1];
    const int target = 7;
    for (int i = 0; i < vec.size(); ++i)
    {
        vec[i].resize(4);
    }
    int a[4][4] = {{1, 2, 8, 9},
                   {2, 4, 9, 12},
                   {4, 7, 10, 13},
                   {6, 8, 11, 15}};
    for (int i = 0; i < vec.size(); ++i)
    {
        for (int j = 0; j < vec[i].size(); ++j)
        {
            vec[i][j] = a[i][j];
            std::cout << vec[i][j] << "  ";
        }
        std::cout << std::endl;
    }

    std::cout << "vec.size() is:" << vec.size() << std::endl;

    std::cout << "vec[0].size() is:" << vec[0].size() << std::endl;
    bool isFinded = false;
    isFinded = Find(vec, target, targetRow, targetCol);
    std::cout << "!!!!" << isFinded << std::endl;
    // std::cout<<"!!!!"<<Find(vec, target)<<std::endl;
    if (isFinded == true)
    {
        std::cout << "targetRow: " << *targetRow << "targetCol:" << *targetCol << std::endl;
    }
    return 0;
}
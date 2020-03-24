#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> printMatrix(std::vector<std::vector<int>> matrix)
{
    int row = matrix.size();
    int colum = matrix[0].size();
    std::vector<int> result(0);
    double shortLength = (row < colum) ? row : colum;
    int circle_count = std::ceil(shortLength / 2);
    for (int i = 0; i < circle_count; ++i)
    {
        // top left to top right
        for (int j = i; j < colum - i; ++j)
        {
            result.push_back(matrix[i][j]);
        }
        // top right to bottom right
        for(int k=i+1;k<row-i;++k){
            result.push_back(matrix[k][colum-i-1]);
        }
        // bottom right to bottom left
        for(int l=colum-i-2;(l>=i)&&(row-1-i!=i);--l){
            result.push_back(matrix[row-1-i][l]);
        }
        // bottom left to top left
        for(int m=row-i-2;(m>i)&&(colum-i-1!=i);--m){
            result.push_back(matrix[m][i]);
        }
    }
    return result;
}

int main()
{
    std::vector<std::vector<int>> vec(1);
    for (int i = 0; i < 1; ++i)
    {
        vec[i].resize(4);
    }
    int a[1][4] = {
        {1, 2, 3, 4},
        };
    for (int i = 0; i < 1; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            vec[i][j] = a[i][j];
        }
    }
    std::vector<int> result(0);
    result=printMatrix(vec);
    for(auto a:result){
        std::cout<<"  "<<a;
    }
    std::cout<<std::endl;
    return 0;
}
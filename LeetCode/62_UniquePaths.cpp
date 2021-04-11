#include<iostream>


int uniquePaths(int m, int n){
    int **dp=(int**)malloc(sizeof(int *)*n);
    for(int i=0;i<n;++i){
        dp[i] = (int *)malloc(sizeof(int) * m);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || j == 0) {     //最上一行或者最左一列
                dp[i][j] = 1;
            }
            else {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }
    
    return dp[n-1][m-1];
}

int main(){
    std::cout<<uniquePaths(7,3)<<std::endl;
    return 0;
}
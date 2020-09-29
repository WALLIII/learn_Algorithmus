#include <string>
#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <queue>
using namespace std;

bool takeBack(vector<int> data, int &person)
{
    if (data.size() <= 0 || data[0] != 5)
        return false;
    int n=data.size();
    int res5=1, res10=0, res20=0;
    for(int i=1;i<n;++i){
        person++;
        if(data[i]%5!=0) return false;
        if(data[i]>30) data[i]=data[i]%30;
        int res=data[i]-5;       
        //cout<<res<<endl;
        //客户支付5元，肯定可以
        if(res==0 || res==15){
            res5++;
            continue;
        } 
        //支付10元，会剩下5元要找
        else if(res==5){
            res10++;
            if(res5>=1){
                res5--;
            }
            //如果5元的没有了，就只能返回
            else return false;
        }
        else if(res==10){
            if(res10>=1){
                res10-=1;
            }
            else if(res5>=2){
                res5-=2;
            }
        }
        //支付20元，要找15元
        else if(res==15){
            res20++;
            //5元找零
            if(res5>=3){
                res5-=3;
            }
            else if(res5>=2 && res10>=1){ //2张5元1张10元
                res5-=2;
                res10-=1;
            }
            else return false;
        }
        else{            
            return false;
        } 
    }
    return true;
    
}

// bool isValis(vector<vector<int>> grid, int s){
//     int m=grid.size(), n=grid[0].size();
//     vector<vector<bool> > dp(m, vector<bool>(n, false));
//     dp[0][0]=true;
//     for(int i=1;i<m;++i){
//         if(grid[i][0]==1  && i-s>=0)
//             dp[i][0]=dp[i-s][0];
//     }
//      for(int j=1;j<n;++j){
//         if(grid[0][j]==1 && j-s>=0)
//             dp[0][j]=dp[0][j-s];
//     }
//     for(int i=1;i<m;++i){
//         for(int j=1;j<n;++j){
//             if(grid[i][j]==1 && i-s>=0 && j-s>=0){
//                 dp[i][j]=dp[i-s][j] || dp[i][j-s];
//             }
//         }
//     }
//     return dp[m-1][n-1];
    
// }
bool help(vector<vector<int>> &grid, int s, vector<vector<bool> > &visited, 
                int x, int y){
    int m=grid.size(), n=grid[0].size();
    if(x>=m || y>=n || x<0 || y<0 || visited[x][y]==true || grid[x][y]==0) return false;
    if(x==m-1 && y==n-1) return true;
    visited[x][y]=true;
    return help(grid, s, visited,x+s, y) || help(grid, s, visited,x-s, y)||
            help(grid, s, visited,x, y+s) || help(grid, s, visited,x, y-s);

}
bool isValis(vector<vector<int>> grid, int s){
    int m=grid.size(), n=grid[0].size();
    vector<vector<bool> > visited(m, vector<bool>(n, false));
    return help(grid, s, visited, 0, 0);   
    
}
int main()
{
    // vector<int> data={5,5,40,42};
    // int tmp;
   
    // int person = 1;
    // bool res = takeBack(data, person);
    // if (res == true)
    //     cout << "true," << person << endl;
    // else if (res == false)
    //     cout << "false," << person << endl;
    // return 0;
    vector<vector<int>> grid={};
    // vector<vector<int>> grid={{1},{0},{1},{0},{1}};
    bool res = isValis(grid, 1);
    cout<<res<<endl;
}
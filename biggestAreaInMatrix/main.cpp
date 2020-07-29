#include<iostream>
#include<vector>

using namespace std;
template <class T>
void printMatrix(vector<vector<T>> m){
    cout<<"------------------\n";
    for(auto row: m){
        for(auto el: row){
            cout<<el<<" ";
        }
        cout<<"\n";
    }
}

vector<vector<int>> addZeroBorder(vector<vector<int>> matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> row = vector<int>(m+2,0);
    vector<vector<int>> res;
    for(int i=0;i<n+2;++i){
        res.push_back(row);
    }
    for(int i=1;i<n;++i){
        for(int j=1;j<m;++j){
            res[i][j]=matrix[i-1][j-1];
        }
    }
    return res;
}

void dfs(int x,int y,vector<int> dx ,vector<int> dy,vector<vector<bool>> visitedM ){
        visitedM[x][y] = true;
        for (size_t i = 0; i < 8; i++)
        {
            int newDx = x+dx[i];
            int newDy = y+dy[i];

            
            if((!visitedM[newDx][newDy])){
                dfs(newDx,newDy,dx,dy,visitedM);
            }
        }
    };


int findMaxArea(vector<vector<int>>  matrix){
    int res = 0;
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> dx = {0,0,1,1,1,-1,-1,-1};
    vector<int> dy = {1,-1,1,0,-1,1,0,-1};
    vector<vector<bool>> visitedM(n,vector<bool>(m, false));
    dfs(1,1,dy,dy,visitedM);
    return res;
} 

int main(){

    vector<vector<int>> testmatrix = {
        {1,1,1,0},
        {1,1,0,0},
        {0,1,0,0},
        {0,0,0,0},
        {0,0,1,0},
        {0,1,1,0},
        {0,0,0,1}
    };

    printMatrix<int>(addZeroBorder(testmatrix));
    findMaxArea(testmatrix);

    return 0;
}

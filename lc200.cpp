//leetcode:200. Number of Islands
//find a land, mark the entire island to water by dfs/bfs
//O(nm)

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        if(grid.empty()) return res;
        for(int i =0; i< grid.size(); i++){
            for(int j =0; j< grid[0].size();j++){
                if (grid[i][j] == '1'){
                    marker(grid, i, j);
                    res++;
                }
            }  
        }
        return res;
    }
    void marker(vector<vector<char>>& grid, int i, int j){
        if(i < 0 || j < 0|| i>= grid.size()||j >= grid[0].size() || grid[i][j] == '0') return ;
        grid[i][j] = '0';
        marker(grid, i-1,j); //up
        marker(grid, i+1,j);//down
        marker(grid, i,j-1);//left
        marker(grid, i,j+1);//right       
    }
};
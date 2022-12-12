#include <bits/stdc++.h>

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(){
    std::vector<std::string> grid;
    while(true){
        std::string in;
        std::cin >> in;
        if(in == "DONE") break;
        grid.push_back(in);
    }

    std::pair<int, int> start, end;

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if(grid[i][j] == 'S'){
                start = {i, j};
                grid[i][j] = 'a';
            }
            if(grid[i][j] == 'E'){
                end = {i, j};
                grid[i][j] = 'z';
            }
        }
    }
    
    std::vector<std::vector<int>> distance(grid.size(), std::vector<int>(grid[0].size(), -1));
    
    std::queue<std::pair<int, int>> qu;
    distance[end.first][end.second] = 0;
    qu.push(end);
    while (!qu.empty())
    {
        auto pos = qu.front(); qu.pop();
        
        for (auto i = 0; i < 4; i++)
        {
            if(pos.first + dx[i] < 0 || pos.first + dx[i] >= grid.size()) continue;
            if(pos.second + dy[i] < 0 || pos.second + dy[i] >= grid[pos.first + dx[i]].size()) continue;

            if(grid[pos.first + dx[i]][pos.second + dy[i]] >= grid[pos.first][pos.second] - 1){ // increases by at most 1 char
                if(distance[pos.first + dx[i]][pos.second + dy[i]] != -1) continue; // already looked at

                distance[pos.first + dx[i]][pos.second + dy[i]] = distance[pos.first][pos.second] + 1;
                qu.push({pos.first + dx[i], pos.second + dy[i]});
            }
        }
    }
    
    int out = 1999999999;
    for (int i = 0; i < distance.size(); i++)
    {
        for (int j = 0; j < distance[i].size(); j++)
        {
            if(distance[i][j] == -1) continue; // ughh, boundary cases
            if(grid[i][j] == 'a') out = std::min(out, distance[i][j]);
        }
    }
    std::cout << out;
}
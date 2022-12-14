#include <bits/stdc++.h>

char memo[1000][1000];

int main(){
    memset(memo, '.', sizeof(memo));
    int maxY = 0;

    while (true)
    {
        std::string in;
        std::getline(std::cin, in);
        if(in == "DONE") break;

        std::istringstream sin(in);
        std::vector<std::pair<int, int>> input;
        while (!sin.eof())
        {
            std::string x, y, dummy;
            std::getline(sin, x, ',');
            sin >> y;
            sin >> dummy;
            input.push_back({std::stoi(x), std::stoi(y)});
            maxY = std::max(maxY, std::stoi(y));
        }
        for (int i = 0; i < input.size()-1; i++)
        {
            for (int xp = std::min(input[i].first, input[i+1].first); xp <= std::max(input[i].first, input[i+1].first); xp++)
            {
                memo[xp][input[i].second] = '#';
            }
            for (int yp = std::min(input[i].second, input[i+1].second); yp <= std::max(input[i].second, input[i+1].second); yp++)
            {
                memo[input[i].first][yp] = '#';
            }
        }
        
    }

    for (int x = 0; x < 1000; x++)
    {
        memo[x][maxY+2] = '#';
    }
    
    
    std::pair<int, int> sandStart = {500, 0};
    int counter = 0;
    while (true)
    {
        std::pair<int, int> sand = sandStart;
        bool done = false;
        while (true)
        {
            if(memo[sand.first][sand.second+1] == '.') sand.second++;
            else if(memo[sand.first-1][sand.second+1] == '.'){sand.first--; sand.second++;}
            else if(memo[sand.first+1][sand.second+1] == '.'){sand.first++; sand.second++;}
            else break;
        }
        if(sand == sandStart){
            done = true;
        }
        if (!done)
        {
            memo[sand.first][sand.second] = 'o';
        } else{
            std::cout << counter+1; // Account for the grain of sand on sandStart
            return 0;
        }
        counter++;
    }
    

    return 0;
}
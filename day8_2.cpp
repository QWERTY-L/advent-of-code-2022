#include <bits/stdc++.h>

#define SIZE 99

// Note: Input size is small so prefix max is not required

int grid[SIZE + 10][SIZE+10];

int main(){
    for (int i = 0; i < SIZE; i++)
    {
        std::string in;
        std::cin >> in;
        for (int j = 0; j < SIZE; j++)
        {
            grid[i][j] = in[j] - '0';
        }
    }
    
    int out = 0;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            bool works = true;

            int dist1 = 0;
            int dist2 = 0;
            int dist3 = 0;
            int dist4 = 0;

            //fix j
            int maxi = -1000000000;
            for (int k = i-1; k >= 0; k--)
            {
                dist1++;
                if(grid[k][j] >= grid[i][j]) break;
                maxi = std::max(maxi, grid[k][j]);
            }
            if(maxi < grid[i][j]) works = false;

            //fix j
            maxi = -1000000000;
            for (int k = i+1; k < SIZE; k++)
            {
                dist2++;
                if(grid[k][j] >= grid[i][j]) break;
                maxi = std::max(maxi, grid[k][j]);
            }
            if(maxi < grid[i][j]) works = false;

            //fix i
            maxi = -1000000000;
            for (int k = j-1; k >= 0; k--)
            {
                dist3++;
                if(grid[i][k] >= grid[i][j]) break;
                maxi = std::max(maxi, grid[i][k]);
            }
            if(maxi < grid[i][j]) works = false;

            //fix i
            maxi = -1000000000;
            for (int k = j+1; k < SIZE; k++)
            {
                dist4++;
                if(grid[i][k] >= grid[i][j]) break;
                maxi = std::max(maxi, grid[i][k]);
            }
            if(maxi < grid[i][j]) works = false;

            out = std::max(out, dist1*dist2*dist3*dist4);
            //std::cout << dist1*dist2*dist3*dist4 << " ";
            //if(i == 2 && j == 1) std::cout << dist1 << " " << dist2 << " " << dist3 << " " << dist4;
        }
        //std::cout << "\n";
    }
    
    std::cout << out;
    return 0;
}
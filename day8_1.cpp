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
            if(i == 0 || j == 0 || i == SIZE-1 || j == SIZE-1){
                out++; continue;
            }
            
            bool works = true;

            //fix j
            int maxi = -1000000000;
            for (int k = 0; k < i; k++)
            {
                maxi = std::max(maxi, grid[k][j]);
            }
            if(maxi < grid[i][j]) works = false;

            //fix j
            maxi = -1000000000;
            for (int k = i+1; k < SIZE; k++)
            {
                maxi = std::max(maxi, grid[k][j]);
            }
            if(maxi < grid[i][j]) works = false;

            //fix i
            maxi = -1000000000;
            for (int k = 0; k < j; k++)
            {
                maxi = std::max(maxi, grid[i][k]);
            }
            if(maxi < grid[i][j]) works = false;

            //fix i
            maxi = -1000000000;
            for (int k = j+1; k < SIZE; k++)
            {
                maxi = std::max(maxi, grid[i][k]);
            }
            if(maxi < grid[i][j]) works = false;

            out += !works; // works == false ==> visible == true
        }
        
    }
    
    std::cout << out;
    return 0;
}
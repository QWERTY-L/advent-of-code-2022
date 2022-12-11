#include <bits/stdc++.h>

char out[6][40];

int main(){

    std::deque<std::pair<int, int>> toDo; // time at which to do, amount to add
    toDo.push_back({0, 0});
    int timer = 1;

    // Input

    while(true){
        std::string command;
        std::cin >> command;

        if(command == "done") break;
        if(command == "noop"){
            toDo.push_back({std::max(timer, toDo.back().first) + 1, 0});
            continue;
        }

        if(command == "addx"){
            int x; std::cin >> x;
            toDo.push_back({std::max(timer, toDo.back().first) + 2, x});
        }
        timer++;
    }

    int X = 1;
    toDo.pop_front(); // remove the (0, 0) sentinel
    for (timer = 1; timer <= 240; timer++)
    {
        while (!toDo.empty() && toDo.front().first == timer)
        {
            auto top = toDo.front(); toDo.pop_front();
            X += top.second;
        }
        int ypos = timer/40 - (timer%40 == 0);
        int xpos = timer % 40 + 40*(timer%40 == 0) - 1;

        if(std::abs(X-xpos) <= 1) out[ypos][xpos] = '#';
        else out[ypos][xpos] = '.';
    }
    
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 40; j++)
        {
            std::cout << out[i][j];
        }
        std::cout << "\n";
    }
    
    return 0;
}
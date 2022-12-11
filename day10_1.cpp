#include <bits/stdc++.h>

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
    int out = 0;
    for (timer = 0; timer <= 220; timer++)
    {
        while (!toDo.empty() && toDo.front().first == timer)
        {
            auto top = toDo.front(); toDo.pop_front();
            X += top.second;
        }
        if(timer >= 20 && (timer - 20) % 40 == 0){
            //std::cout << timer << ", " << X*timer << "\n";
            out += X*timer;
        }
    }
    
    std::cout << out;
    return 0;
}
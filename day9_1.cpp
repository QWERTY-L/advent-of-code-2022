#include <bits/stdc++.h>

int main(){
    std::pair<int, int> head = {0, 0}, tail = {0, 0};
    std::set<std::pair<int, int>> visited;
    visited.insert({0, 0});

    std::map<char, std::pair<int, int>> dir;
    dir['U'] = {0, 1};
    dir['D'] = {0, -1};
    dir['L'] = {-1, 0};
    dir['R'] = {1, 0};

    while(true){
        char a;
        int b;
        std::cin >> a;
        if(a == 'Z') break;
        std::cin >> b;

        for (int i = 0; i < b; i++)
        {
            head.first += dir[a].first;
            head.second += dir[a].second;

            if((head.first - tail.first)*(head.first - tail.first) + (head.second - tail.second)*(head.second - tail.second) <= 2) continue;

            if(head.first == tail.first){
                tail.second += (head.second > tail.second)*2 - 1;
            }
            else if(head.second == tail.second){
                tail.first += (head.first > tail.first)*2 - 1;
            }
            else{
                tail.second += (head.second > tail.second)*2 - 1;
                tail.first += (head.first > tail.first)*2 - 1;
            }
            visited.insert(tail);
            //std::cout << tail.first << ", " << tail.second << "\n";
        }
        //std::cout << "\n";
    }
    
    std::cout << visited.size();
    return 0;
}
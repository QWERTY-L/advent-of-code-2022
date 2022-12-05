#include <bits/stdc++.h>

#define MAX_SIZE 9

int main(){
    std::vector<std::deque<char>> crates(MAX_SIZE+1, (std::deque<char>){});

    // Input crates
    while(true){
        std::string top;
        std::getline(std::cin, top);
        if(top[1] == '1') break;
        for (int i = 0; i < (top.length()+1)/4; i++)
        {
            if(top[4*i + 1] == ' ') continue;
            crates[i+1].push_front(top[4*i + 1]);
        }
    }

    while(true){
        std::string d_;
        int num, a, b;
        std::cin >> d_;
        if(d_ == "DONE"){
            for (int i = 1; i < MAX_SIZE+1; i++)
            {
                std::cout << crates[i].back();
            }
            return 0;
        }
        std::cin >> num >> d_ >> a >> d_ >> b;
        std::vector<char> buffer;
        for (int i = 0; i < num; i++)
        {
            auto x = crates[a].back(); crates[a].pop_back();
            buffer.push_back(x);
        }
        std::reverse(buffer.begin(), buffer.end());
        for(auto x : buffer) crates[b].push_back(x);
    }

    return 0;
}
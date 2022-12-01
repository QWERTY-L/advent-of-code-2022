#include <bits/stdc++.h>

int main(){
    int best = 0;
    int current = 0;

    while(true){
        std::string in;
        std::getline(std::cin, in);
        if(in == "DONE") break;
        if(in == "" || in == "\n"){
            current = 0; continue;
        }
        current += std::stoi(in);
        best = std::max(current, best);
    }

    std::cout << best;
    return 0;
}
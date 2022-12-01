#include <bits/stdc++.h>

int main(){
    std::vector<int> out;
    int current = 0;

    while(true){
        std::string in;
        std::getline(std::cin, in);
        if(in == "DONE") break;
        if(in == "" || in == "\n"){
            out.push_back(-current);
            current = 0;
            continue;
        }
        current += std::stoi(in);
    }

    std::sort(out.begin(), out.end());

    std::cout << out[0] + out[1] + out[2];
    return 0;
}
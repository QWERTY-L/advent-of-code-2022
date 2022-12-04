#include <bits/stdc++.h>

int main(){
    int out = 0;

    while (true)
    {
        std::string a1, a2, b1, b2;
        std::getline(std::cin, a1, '-');
        if(a1[0] == 'D'){
            std::cout << out;
            return 0;
        }
        std::getline(std::cin, a2, ',');
        std::getline(std::cin, b1, '-');
        std::getline(std::cin, b2, '\n');

        if(stoi(a1) <= stoi(b1) && stoi(b2) <= stoi(a2)) out++;
        else if(stoi(b1) <= stoi(a1) && stoi(a2) <= stoi(b2)) out++;
    }
    return 0;
}
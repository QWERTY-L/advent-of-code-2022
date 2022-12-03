#include <bits/stdc++.h>

int val(char a){
    if(a <= 'z' && a >= 'a') return a - 'a' + 1;
    else return a - 'A' + 27;
}

int count[1000];

int main(){
    int out = 0;
    while(true){
        std::string a, b, c; std::cin >> a;
        if(a == "DONE") break;
        std::cin >> b >> c;
        memset(count, 0, sizeof(count));
        for (auto cha : a)
        {
            count[cha] = 1;
        }
        for (auto cha : b)
        {
            if(count[cha] == 1) count[cha] = 2;
        }
        for (auto cha : c)
        {
            if(count[cha] == 2){
                out += val(cha); break;
            }
        }
    }

    std::cout << out;
    return 0;
}
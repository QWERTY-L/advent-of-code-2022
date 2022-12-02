#include <bits/stdc++.h>

int win(char opponent, char you){
    if(opponent == 'A' && you == 'Y') return 6;
    if(opponent == 'B' && you == 'Z') return 6;
    if(opponent == 'C' && you == 'X') return 6;
    
    if(opponent == 'A' && you == 'X') return 3;
    if(opponent == 'B' && you == 'Y') return 3;
    if(opponent == 'C' && you == 'Z') return 3;
    

    return 0;
}

int bonus(char you){
    return (you == 'X') + 2*(you == 'Y') + 3*(you == 'Z');
}

int main(){
    int out = 0;

    while(true){
        char a, b;
        std::cin >> a >> b;

        if(a == '0') break;
        out += win(a, b) + bonus(b);
    }


    std::cout << out;
    return 0;
}
#include <bits/stdc++.h>

int win(char opponent, char you){
    if(you == 'X') return 0;
    if(you == 'Y') return 3;
    if(you == 'Z') return 6;

    return 0;
}

int bonus(char opponent, char you){
    if(you == 'X'){
        if(opponent == 'A') return 3;
        if(opponent == 'B') return 1;
        if(opponent == 'C') return 2;
    }
    if(you == 'Y'){
        if(opponent == 'A') return 1;
        if(opponent == 'B') return 2;
        if(opponent == 'C') return 3;
    }
    if(you == 'Z'){
        if(opponent == 'A') return 2;
        if(opponent == 'B') return 3;
        if(opponent == 'C') return 1;
    }
    return 0;
}

int main(){
    int out = 0;

    while(true){
        char a, b;
        std::cin >> a >> b;

        if(a == '0') break;
        out += win(a, b) + bonus(a, b);
    }


    std::cout << out;
    return 0;
}
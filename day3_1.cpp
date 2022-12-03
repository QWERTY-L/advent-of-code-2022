#include <bits/stdc++.h>

int val(char a){
    if(a <= 'z' && a >= 'a') return a - 'a' + 1;
    else return a - 'A' + 27;
}

int count[1000];

int main(){
    int out = 0;
    while(true){
        std::string in; std::cin >> in;
        if(in == "DONE") break;
        memset(count, 0, sizeof(count));
        int len = in.length();
        for (int i = 0; i < len/2; i++)
        {
            count[in[i]] = 1;
        }
        for (int i = len/2; i < len; i++)
        {
            if(count[in[i]] == 1) count[in[i]]++;
        }
        for (int i = 0; i < 300; i++)
        {
            if(count[i] == 2) out += val(i);
        }
    }

    std::cout << out;
    return 0;
}
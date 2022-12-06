#include <bits/stdc++.h>

#define LEN 14

bool works(std::vector<char> &a){
    for (int i = 0; i < LEN - 1; i++)
    {
        for (int j = i+1; j < LEN; j++)
        {
            if(a[i] == a[j]) return false;
        }
    }
    return true;
}

int main(){
    std::string in; std::cin >> in;
    std::vector<char> a;

    int iter = LEN;
    for(int i = 0; i < LEN; i++) a.push_back(in[i]);

    if(works(a)){
        std::cout << iter;
        return 0;
    }

    for (int i = LEN; i < in.size(); i++)
    {
        iter++;
        for(int k = 0; k < LEN - 1; k++) a[k] = a[k+1];
        a[LEN-1] = in[i];
        if(works(a)){
            std::cout << iter;
            return 0;
        }
    }

    return 0;
}
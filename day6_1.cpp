#include <bits/stdc++.h>

bool works(std::vector<char> &a){
    for (int i = 0; i < 3; i++)
    {
        for (int j = i+1; j < 4; j++)
        {
            if(a[i] == a[j]) return false;
        }
    }
    return true;
}

int main(){
    std::string in; std::cin >> in;
    std::vector<char> a;

    int iter = 4;
    a.push_back(in[0]);
    a.push_back(in[1]);
    a.push_back(in[2]);
    a.push_back(in[3]);

    if(works(a)){
        std::cout << iter;
        return 0;
    }

    for (int i = 4; i < in.size(); i++)
    {
        iter++;
        a[0] = a[1];
        a[1] = a[2];
        a[2] = a[3];
        a[3] = in[i];
        if(works(a)){
            std::cout << iter;
            return 0;
        }
    }

    return 0;
}
#include <bits/stdc++.h>

#define numMonkeys 8

typedef std::pair<std::vector<int>, std::pair<std::pair<char, int>, std::pair<int, std::pair<int, int>>>> Monkey; // items, (operation, amount), (testInt, trueMonkey, falseMonkey)

std::vector<int> business(numMonkeys, 0);

int main(){
    
    std::vector<Monkey> monkeys;
    
    for (int i = 0; i < numMonkeys; i++)
    {
        std::string useless;
        std::getline(std::cin, useless);
        while(useless == "" || useless == "\n") std::getline(std::cin, useless);
std::cout << useless << "\n\n\n";
        std::string line;

        std::getline(std::cin, line);
        std::istringstream items(line);
        std::vector<int> ite;

        items >> useless >> useless;
        while (!items.eof() && line.size() != 0)
        {
            std::string a; items >> a;
            if(a[a.size()-1] == ',') ite.push_back(std::stoi(a.substr(0, a.size()-1)));
            else{
                ite.push_back(std::stoi(a));
                break;
            }
        }
        
        char op;
        std::string valS;
        int val = 0;
        std::cin >> useless >> useless >> useless >> useless >> op >> valS;
        if(valS == "old") op = 'S'; // square
        else val = std::stoi(valS);

        int test, trueM, falseM;
        std::cin >> useless >> useless >> useless >> test;
        std::cin >> useless >> useless >> useless >> useless >> useless >> trueM;
        std::cin >> useless >> useless >> useless >> useless >> useless >> falseM;

        monkeys.push_back({ite, {{op, val}, {test, {trueM, falseM}}}});
        //std::cout << op << " " << val << " " << "; " << test << " " << trueM << " " << falseM << " ";
        std::getline(std::cin, useless);
    }
    
    for (int i = 0; i < 20; i++)
    {
        for(int j = 0; j < numMonkeys; j++){
            for(int ki = monkeys[j].first.size() - 1; ki >= 0; ki--){
                auto k = monkeys[j].first[ki];
                business[j]++;
                if(monkeys[j].second.first.first == 'S') k = k*k;
                else if(monkeys[j].second.first.first == '*') k *= monkeys[j].second.first.second;
                else k += monkeys[j].second.first.second;

                k /= 3;

                if(k % monkeys[j].second.second.first == 0){
                    monkeys[monkeys[j].second.second.second.first].first.push_back(k);
                } else{
                    monkeys[monkeys[j].second.second.second.second].first.push_back(k);
                }
                monkeys[j].first.pop_back();
            }
        }
    }
    
    std::sort(business.begin(), business.end());
    int out = business[numMonkeys - 1] * business[numMonkeys - 2];

    std::cout << out;
    return 0;
}
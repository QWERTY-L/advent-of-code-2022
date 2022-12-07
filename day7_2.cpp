#include <bits/stdc++.h>

#define TOTAL 70000000
#define REQUIRED 30000000

std::map<std::string, int> memo;
std::map<std::string, std::pair<int, std::vector<std::string>>> graph; // file values, file subsets

std::string compute(std::vector<std::string>& in){
    std::string out = "";
    for(auto x : in){
        out += "/" + x;
    }
    return out;
}

int dfs(std::string current){
    if(memo.count(current) == 1) return memo[current];
    int childrenSize = 0;
    for(auto child : graph[current].second){
        childrenSize += dfs(child);
    }
    memo[current] = graph[current].first + childrenSize;
    return memo[current];
}

int main(){
    std::string dummy;
    std::cin >> dummy >> dummy >> dummy; // take in root
    std::vector<std::string> state = {}; // currently in root
    std::set<std::string> read;
    graph[compute(state)] = {0, (std::vector<std::string>){}};
    bool dontRead = false;
    while(true){
        std::string first;
        std::cin >> first;
        if(first == "DONE") break;
        if(first == "$"){
            std::string command; std::cin >> command;
            if(command == "ls"){
                if(read.count(compute(state)) == 1){
                    dontRead = true;
                    continue;
                }
                else{
                    dontRead = false;
                    read.insert(compute(state));
                    continue;
                }
            }
            else if(command == "cd"){
                std::string in; std::cin >> in;
                if(in == "/"){
                    state.empty();
                    state.push_back("");
                }
                else if(in == ".."){
                    state.pop_back();
                }
                else{
                    state.push_back(in);
                    if(graph.count(compute(state)) == 1) continue;
                    graph[compute(state)] = {0, std::vector<std::string>({})};
                }
            }
        }
        else{
            if(first == "dir"){
                std::string a; std::cin >> a;
                if(dontRead) continue;
                graph[compute(state)].second.push_back(compute(state) + "/" + a);
            }
            else{
                std::string a; std::cin >> a;
                if(dontRead) continue;
                graph[compute(state)].first += std::stoi(first);
            }
        }
    }

    int used = 0;

    for(auto x : graph){
        if(memo.count(x.first) == 1) continue;
        used += dfs(x.first);
    }

    int needed = REQUIRED - (TOTAL - used);

    int out = TOTAL+9999; // Large sentinel value
    for(auto x : memo){
        if(x.second >= needed) out = std::min(out, x.second);
    }

    std::cout << out;
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    
    std::vector<int> llist;
    std::vector<int> rlist;
    int sumd = 0;

    int l;
    int r;


    for(;std::cin >> l >> r;){

        llist.push_back(l);
        rlist.push_back(r);
    }

    std::sort(llist.begin(), llist.end());
    std::sort(rlist.begin(), rlist.end());

    for(unsigned i = 0; i != llist.size(); ++i){

        sumd = sumd + abs(llist.at(i) - rlist.at(i));
    } 

    std::cout << sumd << std::endl;
    
    return 0;
}
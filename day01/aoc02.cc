#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    
    std::vector<int> llist;
    std::vector<int> rlist;
    
    int l;
    int r;


    for(;std::cin >> l >> r;){

        llist.push_back(l);
        rlist.push_back(r);
    }

    int similarity = 0;

    for(unsigned i = 0; i != llist.size(); ++i){

        int c = count(rlist.begin(),rlist.end(),llist.at(i));

        similarity = similarity + c  * llist.at(i);
    } 

    std::cout << similarity << std::endl;
    
    return 0;
}
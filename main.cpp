#include <iostream>
#include "heterogenous list.cpp"

bool odd(const int& n){
    return n % 2 != 0;
}

int main() {
    HeterogenousList<int> hl;
    hl.extractFromFileIntoContainer("containers.txt");
    cout << hl.isFoundUnderCondition(odd);
    hl.printToFile("containers_out.txt");


}
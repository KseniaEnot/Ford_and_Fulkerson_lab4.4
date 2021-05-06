#include <iostream>
#include "Ford_and_Fulkerson.h"
using namespace std;

int main()
{
    Ford_and_Fulkerson alg;
    alg.readList("test.txt");
    int res = alg.MaxFlow();
    cout << res;
}

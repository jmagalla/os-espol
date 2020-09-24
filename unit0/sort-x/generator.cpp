#include <random>
#include <iostream>
#include "utils.h"
using namespace std;

string randomString(int L, string alpha);

int main (int argc, char* argv[]) {
    if (argc < 4) {
        std::cerr << "Usage: se esperan 3 argumentos"<<endl;
        return 1;
    }
    int N = atoi(argv[1]);
    int L = atoi(argv[2]);
    string strbase = string(argv[3]);
    for (int i = 0; i < N; i++)
        std::cout << randomString(L, strbase)<< endl;

    return 0;
}

string randomString(int L, string alpha)
{
    int lalpha = alpha.length();
    char a[L+1];
    a[L] = '\0';
    for (int i = 0; i < L; i++)
    {
        int t = random_uniform(lalpha - 1);
        a[i] = alpha[t];
    }
    return string(a);
}

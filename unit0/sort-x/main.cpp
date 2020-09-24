#include <vector>
#include <iostream>
#include "utils.h"
using namespace std;

void intercambio(vector<string> &a, int, int);
void sort(vector<string> &a);
void sortdescent(vector<string> &a);

int main(int argc, char* argv[]) {
	vector<string> words = readAllStrings();
	sort(words);
	for (int i=0; i < words.size(); i++)
        cout << words[i] << endl;
	return 0;
}

void sort(vector<string> &a) {
    int N = a.size();
    for (int i = 1; i < N; i++)
        for (int j = i; j > 0; j--)
            if (a[j] < a[j-1])
                intercambio(a, j, j-1);
            else
                break;
}

void sortdescent(vector<string> &a) {
    int N = a.size();
    for (int i = N; i > 0; i--)
        for (int j = i; j < N; j++)
            if (a[j] > a[j-1])
                intercambio(a, j, j-1);
            else
                break;
}

void intercambio(vector<string> &v, int i, int j) {
    string t = v[i];
    v[i] = v[j];
    v[j] = t;
}

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{
    string line;
    
    if (argc > 2) {
        cout << "Use: mycat namefile." << endl;
        return 0;
    }

    if (argc == 1)  {
        while (getline(cin, line))
            cout << line << endl ;
    }
    else {
        string namefile = argv[1];
        ifstream MyReadFile(namefile);
        while (getline(MyReadFile, line))
            cout << line<< endl;
        
    }
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main() {
    string input;
    cin >> input;
    unsigned int rightl;
    unsigned int leftr;
    unsigned int pos;
    unsigned int last;
    pos=input.find("RL");
    while(pos != string::npos) {
        cout << "pos = " << pos << endl;
        last = input.rfind("RL");
        if (pos == last) {
            input.erase(pos, 1);
        }
        else {
            input.erase(pos+1, 1);
        }

        cout << input << endl;
        pos=input.find("RL");
    }
    return 0;
}
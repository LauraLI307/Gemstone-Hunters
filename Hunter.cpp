
#include <iostream>
#include <string>
#include "Hunter.h"

using namespace std;

Hunter::Hunter(string t) : team(t) {
}

string Hunter::getTeam() {
    return team;
}

void Hunter::setTeam(string t) {
    team = t;
}

string Hunter::info() {
    return getTeam();
};

bool Hunter::getInt(int& num) {
    cin >> num;
    if (!cin.good()) {
        cin.clear();
        string tmp;
        getline(cin, tmp);  // clear the buffer
        cout << "Invalid input: " << tmp << endl;
        return false;
    }
    return true;
}

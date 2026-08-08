#include <iostream>
#include <string>
#include <vector>
#include "Board.h"
#include "MasterMiner.h"

using namespace std;

struct Team {
    string name;              // Name of the team
    int score;                // Score of the team
    vector<Hunter*> members;  // Vector of team members

    // A constructor to initialize a Team instance
    Team(const string& teamName, int teamScore, const vector<Hunter*>& teamMembers)
        : name(teamName), score(teamScore), members(teamMembers) {
    }
};

int runRound(Board& board, vector<Hunter*>& hunters) {
    int teamscore = 0;
    for (int i = 0; i < hunters.size(); i++) {
        cout << hunters[i]->info()<<endl;
        MasterMiner* masterMiner = dynamic_cast<MasterMiner*>(hunters[i]);
        if (masterMiner != nullptr) {
            masterMiner->swapRows(board);
            board.print();
        }
        teamscore += hunters[i]->hunt(board);
        board.print();
        cout << "Stones left: " << board.getStones()<<endl;
    }
    return teamscore;
}

int main() {
    string filename;
    cout << "Enter board file name: ";
    getline(cin, filename);
    Board board(filename);

    string team1Name = "Aces", team2Name = "King";
    Adventurer a1(team1Name), a2(team2Name);
    JewelHunter j1(team1Name), j2(team2Name);
    MasterMiner m1(team1Name), m2(team2Name);

    Team team1(team1Name, 0, { &a1, &j1, &m1 });
    Team team2(team2Name, 0, { &a2, &j2, &m2 });

    int rounds;
    cout << "How many rounds to play? ";
    cin >> rounds;

    cout << "Initial board:" << endl;
    board.print();
    for (int i = 1; i <= rounds; i++) {
        if (board.getStones() <= 0)
            break;
        cout << "Round " << i << ":" << endl;
        if (i % 2 != 0)
            team1.score += runRound(board, team1.members);
        else
            team2.score += runRound(board, team2.members);
        cout << "Score: " << team1.name << " " << team1.score
            << " vs. " << team2.name << " " << team2.score << endl;
    }

    cout << "Game Over!" << endl;
    if (team1.score > team2.score)
        cout << team1.name + " wins!" << endl;
    else
        if (team1.score < team2.score)
            cout << team2.name + " wins!" << endl;
        else
            cout << "Game draws!" << endl;

    return 0;
}

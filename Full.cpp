#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
int num_players;
string players[20][4];
ofstream record;
// currently only working with dimesion [i][0]
// other dimesions for later implementation, will try atof as way to do math on
// array elements
void new_line() {
  char next;
  do {
    cin.get(next);
  } while (next != '\n');
}
void getplayers(string players[20][4], int &num_players) {
  char next, letter;
  ofstream cin_out;
  ifstream cin_in;
  cout << "\nIf this is a team game please enter teammates next to each "
          "other.\n";
  cout << "When entering initials there should be no spaces or other "
          "characters.\n";
  for (int i = 0; i < num_players; i++) {
    cout << "\nPlayer " << i + 1 << " enter your initails and press enter.\n";
    cin_out.open("players.doc");
    if (cin_out.fail()) {
      cout << "There was an error while trying to open players.txt!\n";
      cout << "Enter any character and hit return to end the program.\n";
      cin >> letter;
      exit(1);
    }
    do {
      cin.get(next);
      cin_out.put(toupper(next));
    } while (next != '\n');
    cin_out.close();
    cin_in.open("players.doc");
    if (cin_in.fail()) {
      cout << "There was an error while trying to open players.txt!\n";
      cout << "Enter any character and hit return to end the program.\n";
      cin >> letter;
      exit(1);
    }
    getline(cin_in, players[i][0], '\n');
    cin_in.close();
  }

  // for (int i = 0; i < num_players; i++)
  //{
  // cout << players[i][0] << "\n";
  //}
}
void playerscom() {
  // future changes will have this doing for (i=0, i>num_players,i++) so that it
  // can work 2 or more players.
  // adding another "vs. " and players[i][0] plus the apropriet table section.
  // same loop would then be used for life output once life is set to
  // players[i][1].
  cout << "Start Game\n";
  cout << players[0][0];
  cout << " vs. ";
  cout << players[1][0];
  cout << " vs.";
  cout << players[2][0];
  cout << " vs. ";
  cout << players[3][0];
  cout << "\n\n";
  // table creation
  cout.width(4);
  cout << left << players[0][0];
  cout << " | ";
  cout.width(4);
  cout << left << players[1][0];
  cout << " | ";
  cout.width(4);
  cout << left << players[2][0];
  cout << " | ";
  cout.width(4);
  cout << left << players[3][0];
  cout << "\n_____|______|______|_____\n";
}
void players2hg() {
  // future implementation shal have it so that it will run with 2+ teams
  // also implement way of setting team size so that Emporor format or i-headed
  // giant can be run
  cout << "Start Game\n";
  cout << players[0][0];
  cout << "/";
  cout << players[1][0];
  cout << " vs.";
  cout << players[2][0];
  cout << "/";
  cout << players[3][0];
  cout << "\n\n";
  cout.width(7);
  cout << left << "Team 1";
  cout << " | ";
  cout.width(7);
  cout << right << "Team 2\n";
  cout << "________|________\n";

  // were record table creation should go
}

void players1v1();
int main() {
  using namespace std;
  char letter, style, playercheck;
  ofstream record;
  int life_1, life_2, life_3, life_4, chan_1, chan_2, chan_3, chan_4,
      num_players = 2, gamecount = 0;
  // life_1 shall later become players[0][1] and life_2 becoming players[1][1],
  // ext. chan_1 shall be part of a loop or funtion that gets the change for
  // first life aplays it to the life
  // and then getts the next change. Effectively becoming chan_[i].
  // once implemented commander no longer to be specified players.
  cout << "This program will keep track of life totals in a game of Magic.\n";
  // cout << "It can also keep track of deck size and poison counters if you
  // tern those features on.\n\n"; cout << "The program can do 1v1, 2 headed
  // giant, and multiplayer, with draft, commander and 60 card decks.\n";
  // deck size to be players[i][2] and poison to be players[i][3]
  cout << "The program can do 1v1, 2 headed giant, and 4 player commander.\n";
  cout << "Whenever a life total changes, enter the changes to each player's, "
          "or team's, life starting with player one.\n";
  cout << "No change in life is entered as 0, and life loss is entered with a "
          "-.\n\n";
  record.open("game.doc");
  if (record.fail()) {
    cout << "There was an error while trying to open players.txt!\n";
    cout << "Enter any character and hit return to end the program.\n";
    cin >> letter;
    exit(1);
  }
  do {
    do {
      if (gamecount == 0) {
        cout << "How many players?(up to 4)\n";
        cin >> num_players;
        new_line();
        getplayers(players, num_players);
      } else {
        cout << "Same players (Y or N)?\n";
        cin >> playercheck;
        if (toupper(playercheck) == 'N') {
          cout << "How many players?(up to 4)\n";
          cin >> num_players;
          new_line();
          getplayers(players, num_players);
        }
      }
      cout << "What play style is this (enter the corisponding number)?\n";
      cout << "1) 1v1   2) 2 headed giant 3) Commander\n";
      cin >> style;

      if (style == '1') {
        // could latter be chnged to multiplayer for loops
        players1v1();
        // was inside function but did not output to file, for lood did
        record << "\nStart Game\n";
        record << players[0][0] << " vs. " << players[1][0] << "\n\n";
        record << setw(4) << left << players[0][0];
        record << " | ";
        record << setw(4) << left << players[1][0];
        record << "\n_____|_____\n";
        life_1 = 20;
        life_2 = 20;
        cout.width(4);
        cout << left << life_1;
        cout << " | ";
        cout.width(4);
        cout << right << life_2;
        cout << "\n";

        record << setw(4) << left << life_1;
        record << " | ";
        record << setw(4) << right << life_2;
        record << "\n";
        do {
          cin >> chan_1;
          cin >> chan_2;
          life_1 = life_1 + chan_1;
          life_2 = life_2 + chan_2;
          cout.width(4);
          cout << left << life_1;
          cout << " | ";
          cout.width(4);
          cout << right << life_2;
          cout << "\n";

          record << setw(4) << left << life_1;
          record << " | ";
          record << setw(4) << right << life_2;
          record << "\n";
        } while (life_1 > 0 && life_2 > 0);
        cout << "\nGame Over\n";
        record << "\nGame Over\n";
        if (life_1 > life_2) {
          cout << players[0][0] << " Wins\n";
          record << players[0][0] << " Wins\n";
        } else {
          cout << players[1][0] << " Wins\n";
          record << players[1][0] << " Wins\n";
        }
      }
      if (style == '2') {

        players2hg();

        record << "\nStart Game\n";
        record << players[0][0];
        record << "/";
        record << players[1][0];
        record << " vs. ";
        record << players[2][0];
        record << "/";
        record << players[3][0];
        record << "\n\n";
        record << setw(7) << left << "Team 1";
        record << " | ";
        record << setw(7) << right << "Team 2\n";
        record << "________|________\n";
        record << "\n";

        life_1 = 30;
        life_2 = 30;
        cout.width(7);
        cout << left << life_1;
        cout << " | ";
        cout.width(7);
        cout << right << life_2;
        cout << "\n";

        record << setw(7) << left << life_1;
        record << " | ";
        record << setw(7) << right << life_2 << "\n";
        do {
          cin >> chan_1;
          cin >> chan_2;
          life_1 = life_1 + chan_1;
          life_2 = life_2 + chan_2;
          cout.width(7);
          cout << left << life_1;
          cout << " | ";
          cout.width(7);
          cout << right << life_2;
          cout << "\n";

          record << setw(7) << left << life_1;
          record << " | ";
          record << setw(7) << right << life_2 << "\n";

        } while (life_1 > 0 && life_2 > 0);
        cout << "\nGame Over\n";
        if (life_1 > life_2) {
          cout << "Team 1 Wins\n";
          record << "Team 1 Wins\n";
        } else {
          cout << "Team 2 Wins\n";
          record << "Team 2 Wins\n";
        }
      }
      if (style == '3') {
        int winner, replay = 0;
        cout << "Even if a player loses continue entering 0 for life change.\n";
        // see if possible to skip a player so that number of inputs can go down
        playerscom();

        record << "\nStart Game\n";
        record << players[0][0] << " vs. " << players[1][0] << " vs. "
               << players[2][0] << " vs. " << players[3][0] << "\n\n";
        record << setw(4) << left << players[0][0];
        record << " | ";
        record << setw(4) << left << players[1][0];
        record << " | ";
        record << setw(4) << left << players[2][0];
        record << " | ";
        record << setw(4) << left << players[3][0];
        record << "\n_____|______|______|_____\n";

        // life setting shall become a for loop
        life_1 = 40;
        life_2 = 40;
        life_3 = 40;
        life_4 = 40;
        cout.width(4);
        cout << left << life_1;
        cout << " | ";
        cout.width(4);
        cout << right << life_2;
        cout << " | ";
        cout.width(4);
        cout << left << life_3;
        cout << " | ";
        cout.width(4);
        cout << right << life_4;
        cout << "\n";

        record << setw(4) << left << life_1;
        record << " | ";
        record << setw(4) << left << life_2;
        record << " | ";
        record << setw(4) << left << life_3;
        record << " | ";
        record << setw(4) << left << life_4 << "\n";
        do {
          replay = 0;
          cin >> chan_1;
          cin >> chan_2;
          cin >> chan_3;
          cin >> chan_4;
          life_1 = life_1 + chan_1;
          life_2 = life_2 + chan_2;
          life_3 = life_3 + chan_3;
          life_4 = life_4 + chan_4;
          cout.width(4);
          if (life_1 < 1) {
            cout << left << "L";
            record << setw(4) << left << "L";
          } else {
            cout << left << life_1;
            record << setw(4) << left << life_1;
          }
          cout << " | ";
          record << " | ";
          cout.width(4);
          if (life_2 < 1) {
            cout << left << "L";
            record << setw(4) << left << "L";
          } else {
            cout << right << life_2;
            record << setw(4) << left << life_2;
          }
          cout << " | ";
          record << " | ";
          cout.width(4);
          if (life_3 < 1) {
            cout << left << "L";
            record << setw(4) << left << "L";
          } else {
            cout << left << life_3;
            record << setw(4) << left << life_3;
          }
          cout << " | ";
          record << " | ";
          cout.width(4);
          if (life_4 < 1) {
            cout << left << "L";
            record << setw(4) << left << "L";
          } else {
            cout << right << life_4;
            record << setw(4) << left << life_4;
          }
          cout << "\n";
          record << "\n";
          if (life_1 > 0) {
            replay++;
            winner = 1;
          }
          if (life_2 > 0) {
            replay++;
            winner = 2;
          }
          if (life_3 > 0) {
            replay++;
            winner = 3;
          }
          if (life_4 > 0) {
            replay++;
            winner = 4;
          }
        } while (replay != 1);
        int i;
        i = winner;
        cout << "\nGame Over\n";
        record << "\nGame Over\n";
        cout << players[i - 1][0] << " Wins.\n";
        record << players[i - 1][0] << " Wins.\n";
      }
      gamecount = 0;
    } while (gamecount > 0);
    new_line();
    cout << "\nAnother game (Y or N)?\n";
    gamecount++;
    cin >> letter;

  } while (toupper(letter) == 'Y');
  record.close();
  return 0;
}
void players1v1() {
  cout << "Start Game\n";
  cout << players[0][0];
  cout << " vs. ";
  cout << players[1][0];
  cout << "\n\n";
  cout.width(4);
  cout << left << players[0][0];
  cout << " | ";
  cout.width(4);
  cout << right << players[1][0];
  cout << "\n_____|_____\n";
}

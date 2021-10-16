#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <strings.h>
#include <unordered_map>
#include <chrono>
#include <random>
#include <algorithm>

using namespace std;

class Card {
  public:
    string color;
    int number;
    Card(string col, int num) {
        color = col;
        number = num;
    }
};

char asciitolower(char in) {
    if (in <= 'Z' && in >= 'A')
        return in - ('Z' - 'z');
    return in;
}

int main() {
    string line;

    int startingHandSize;
    int unoCalloutPenalty;
    int badUnoCalloutPenalty;
    int drawLimit; 
    bool mustPlayCardEachTurn;
    bool reneging;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    auto gen = default_random_engine(seed);
    
    ifstream ruleFile("rules.txt");
    if (ruleFile.is_open()) {
        while (getline(ruleFile,line)) {
            //cout << line << endl;
            stringstream linestream(line);
            string label;
            string arg;
            linestream >> label;
            if (label == "StartingHandSize:") {
                linestream >> arg;
                startingHandSize = stoi(arg);
            } else if (label == "UnoCalloutPenalty:") {
                linestream >> arg;
                unoCalloutPenalty = stoi(arg);
            } else if (label == "BadUnoCalloutPenalty:") {
                linestream >> arg;
                badUnoCalloutPenalty = stoi(arg);
            } else if (label == "DrawLimit:") {
                linestream >> arg;
                drawLimit = stoi(arg);
            } else if (label == "MustPlayCardEachTurn:") {
                linestream >> arg;
                mustPlayCardEachTurn = arg.compare("true") == 0;
            } else if (label == "Reneging") {
                linestream >> arg;
                reneging = arg.compare("Any") == 0;
            }
        }
        ruleFile.close();
    } else {
        cout << "Unable to open rule file" << endl;
        return 0;
    }

    vector<Card> deck;
    ifstream deckFile("deck.txt");
    if (deckFile.is_open()) {
        while (getline(deckFile,line)) {
            stringstream linestream(line);
            string label;
            string cardCount, cardColor, cardNumber;
            linestream >> cardCount >> cardColor >> cardNumber;
            transform(cardColor.begin(), cardColor.end(), cardColor.begin(), ::tolower);
            for (int i = 0; i < stoi(cardCount); ++i) {
                deck.push_back(Card(cardColor, stoi(cardNumber)));
            }
        }
        deckFile.close();
    }

    shuffle(deck.begin(), deck.end(), gen);
    vector<Card> discard;

    int players = -1;
    while (players < 2) {
        cout << "Please enter the number of players: ";
        cin >> players;
        cout << endl;
    }
    vector<string> names;

    unordered_map<string, vector<Card> > hands;
    for (int i =0; i < players; ++i) {
        while (true) {
            cout << "Please enter the name of player " << i+1 << ": ";
            string newPlayer;
            cin >> newPlayer;
            transform(newPlayer.begin(), newPlayer.end(), newPlayer.begin(), ::tolower);
            if (hands.find(newPlayer) == hands.end()) {
                vector<Card> newHand;
                for (int j = 0; j < startingHandSize; ++j) {
                    Card card = deck.back();
                    deck.pop_back();
                    cout << card.color << card.number << endl;
                    vector<Card>::iterator it = newHand.begin();
                    while(it < newHand.end()) {
                        if (it->color.compare(card.color) > 0) {
                            break;
                        }
                        if (it->color.compare(card.color) == 0 && card.number > it->number) {
                            newHand.insert(it, card);
                            break;
                        }
                        ++it;
                    }
                    newHand.insert(it, card);
                }
                hands[newPlayer] = newHand;
                names.push_back(newPlayer);
                break;
            } else {
                cout << "Cannot use the same name for two players" << endl;
            }
        }
    }
    while (true) {
        for(vector<string>::iterator it = names.begin(); it < names.end(); ++it) {
            cout << "It is " << *it << "'s turn" << endl;
            for(vector<Card>::iterator it2 = hands[*it].begin(); it2 < hands[*it].end(); ++it2) {
                cout << it2->color << " " << it2->number << ",";
            }
            cout << endl;

            cout << "What's your move?" << endl;
            string move;
            cin >> move;
            string arg1, arg2, arg3;
            stringstream linestream(move);
            linestream >> arg1 >> arg2 >> arg3;
            if (arg1.compare("play") == 0) {
            }
            //regex re1("play (.+?) (.+?) (uno)?");
            //regex re2("draw");
            //regex re3("uno (.+?)");
            //regex re4("skip");
            //regex re5("quit");
            //regex re6("help");
        }
    }
}


#include "stiva_loser.hpp"
class winners{
    echipa team;
    winners *next;
public:
    friend void addWinner(winners*&, echipa);
    friend echipa deleteWinner(winners *&);
    friend void deleteWinners(winners *&);
    friend void showWinners(winners *, ofstream &, int);
    echipa getTeam();
    winners* getNext();
};

#include "stiva_winner.hpp"
class coada{
    echipe* first;
    echipe* rear;
public:
    friend coada* makeCoada();
    friend void addMembers(coada*, lista*);
    friend void addWinners(coada*, winners*);
    friend void deleteMember(coada*);
    friend void deleteCoada(coada *);
    friend void showCoada(coada *, ofstream& , int);
    friend void addStive(coada*, winners *&, losers *&);
    echipe* getFirst();
};

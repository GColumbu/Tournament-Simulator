#include "echipe.hpp"
void echipe::setTeam1(echipa a){
    team1=a;
}
void echipe::setTeam2(echipa a){
    team2=a;
}
void echipe::setNext(echipe* a){
    next=a;
}
echipe* echipe::getNext(){
    return next;
}
echipa echipe::getTeam1(){
    return team1;
}
echipa echipe::getTeam2(){
    return team2;
}

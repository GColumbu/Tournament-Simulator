#include "stiva_winner.hpp"
void addWinner(winners *& top, echipa temp){
    winners* newNode;
    newNode=new winners;
    newNode->team=temp;
    newNode->next=top;
    top=newNode;
}
echipa winners::getTeam(){
    return team;
}
winners* winners::getNext(){
    return next;
}
echipa deleteWinner(winners *& top){
    winners* temp=top;
    echipa aux;
    aux=temp->team;
    top=top->next;
    delete temp;
    return aux;
}
void showWinners(winners *top, ofstream &file, int m){
    winners *p;
    int n;
    /*ofstream file(cale, ios::app);
    if(!file){
        cerr<<"Eroare la deschiderea fisierului!";
    }*/
    file<<"WINNERS OF ROUND NO:"<<m<<endl;
    for(p=top; p!=NULL; p=p->next){
        file<<p->team.getTeamName();
        n=p->team.getTeamName().length();
        for(int i=0; i< 34-n; i++){
            file<<" ";
        }
        file<<"-  "<<setprecision(2)<<fixed<<p->team.getPoints()<<endl;
    }
}
void deleteWinners(winners *& top){
    winners *q;
    for(q=top; q!=NULL; q=q->getNext()){
        deleteWinner(top);
    }
}

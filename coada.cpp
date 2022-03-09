#include "coada.hpp"
coada* makeCoada(){
    coada *q;
    q=new coada;
    q->first=q->rear=NULL;
    return q;
}
void addMembers(coada *q, lista *head){
    lista *p;
    for(p=head; p!=NULL; p=p->getNext()->getNext()){
        echipe* newNode;
        newNode = new echipe;
        newNode->setTeam1(p->getTeam());
        newNode->setTeam2(p->getNext()->getTeam());
        newNode->setNext(NULL);
        if(q->rear==NULL)
            q->rear=newNode;
        else{
            (q->rear)->setNext(newNode);
            (q->rear)=newNode;
        }
        if(q->first==NULL)
            q->first=q->rear;
    }
}
void addWinners(coada *q, winners *top){
    winners *p;
    for(p=top; p!=NULL; p=p->getNext()->getNext()){
        echipe* newNode;
        newNode = new echipe;
        newNode->setTeam1(p->getTeam());
        newNode->setTeam2(p->getNext()->getTeam());
        newNode->setNext(NULL);
        if(q->rear==NULL)
            q->rear=newNode;
        else{
            (q->rear)->setNext(newNode);
            (q->rear)=newNode;
        }
        if(q->first==NULL)
            q->first=q->rear;
    }
}
void deleteMember(coada* q){
    echipe *p;
    p=q->first;
    q->first=(q->first)->getNext();
    delete p;
}
void deleteCoada(coada *q){
    echipe *p;
    for(p=q->first; p!=NULL; p=p->getNext()){
        deleteMember(q);
    }
    if(q->first==NULL){
        q->rear=NULL;
    }
}
void showCoada(coada *q, ofstream & file, int m){
    echipe *p;
    int i;
    /*ofstream file(cale, ios::app);
    if(!file){
        cerr<<"Eroare la deschiderea fisierului!";
    }*/
    file<<endl<<"--- ROUND NO:"<<m<<endl;
    for(p=q->first; p!=NULL; p=p->getNext()){
        file<<p->getTeam1().getTeamName();
        i=p->getTeam1().getTeamName().length();
        for(int j=0; j<33-i; j++){
            file<<" ";
        }
        file<<"-";
        i=p->getTeam2().getTeamName().length();
        for(int j=0; j<33-i; j++){
            file<<" ";
        }
        file<<p->getTeam2().getTeamName()<<endl;
    }
    file<<endl;
}
void addStive(coada *q, winners *& topWinners, losers *& topLosers){
    echipe *p;
    for(p=q->first; p!=NULL; p=p->getNext()){
        if(p->getTeam1().getPoints()>p->getTeam2().getPoints()){
            for(int i=0; i<p->getTeam1().getNumberPlayers(); i++){
                p->getTeam1().getPlayers()[i].setPoints(p->getTeam1().getPlayers()[i].getPoints()+1);
            }
            addWinner(topWinners, p->getTeam1());
            addLoser(topLosers, p->getTeam2());
        }else{
            for(int i=0; i<p->getTeam2().getNumberPlayers(); i++){
                p->getTeam2().getPlayers()[i].setPoints(p->getTeam2().getPlayers()[i].getPoints()+1);
            }
            addWinner(topWinners, p->getTeam2());
            addLoser(topLosers, p->getTeam1());
        }
    }
}
echipe* coada::getFirst(){
    return getFirst();
}

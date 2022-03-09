#include "echipa.hpp"
istream & operator>>(istream & dev, echipa &temp){
    char buf[256];
    dev>>temp.numberPlayers;
    dev.getline(buf, 256, ' ');
    dev.getline(buf, 256, '\n');
    temp.teamName=buf;
    if(temp.teamName[temp.teamName.length()-1]==' '){
        temp.teamName.erase(temp.teamName.length()-1, 1);
    }
    if(temp.numberPlayers<=0){
        cerr<<"Nu se poate face alocarea";
    }else{
    temp.players=new player[temp.numberPlayers];
    }
    for(int i=0; i<temp.numberPlayers; i++){
        dev>>(player &)temp.players[i];
    }
    dev.getline(buf, 256, '\n');
    return dev;
}
ostream & operator<<(ostream & dev, echipa &temp){
    dev<<temp.numberPlayers<<" ";
    dev<<temp.teamName<<"  ";
    dev<<"Score: "<<temp.getPoints()<<endl;
    for(int i=0; i<temp.numberPlayers; i++){
        dev<<(player &)temp.players[i];
    }
    dev<<endl<<endl;
    return dev;
}
echipa & echipa::operator=(const echipa &aux){
    numberPlayers=aux.numberPlayers;
    teamName=aux.teamName;
    if(players==NULL){
        players=new player[numberPlayers];
    }
    for(int i=0; i<numberPlayers; i++){
        players[i]=aux.players[i];
    }
    return *this;
}
string echipa::getTeamName(){
    return teamName;
}
int echipa::getNumberPlayers(){
    return numberPlayers;
}
player* echipa::getPlayers(){
    return players;
}
float echipa::getPoints(){
    float medie=0;
    for(int i=0; i<numberPlayers; i++){
            medie+=players[i].getPoints();
    }
    medie/=(float)numberPlayers;
    return medie;
}

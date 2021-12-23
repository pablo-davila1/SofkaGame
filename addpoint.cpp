#include "addpoint.h"

addpoint::addpoint(string _player_name)
{
    player_name = _player_name;
}

void addpoint::pluspoint(string player_name)
{
    int auxplayerpoint=0;
    read_arch.open(arch_name);
    aux.open("auxiliar.txt", ios::out);//archivo auxiliar

    if(!read_arch){ // verifico que jugador es el usuario
        cout<<"No fue posible abrir el archivo: "<<arch_name<<endl;
    }
    else{
        while(!read_arch.eof()){
            read_arch>>playerArch;
            read_arch>>playerspoint;
            if (playerArch == player_name){
                aux<<playerArch;
                aux<<" ";
                auxplayerpoint = playerspoint +5;
                cout<<"USTED ACABA DE GANAR 5 PUNTOSSS, PASARA AL SIGUENTE NIVEL"<<endl<<endl;
                aux<<auxplayerpoint;
                aux<<endl;
            }
            else{
                aux<<playerArch;
                aux<<" ";
                aux<<playerspoint;
                aux<<endl;
            }
        }
    }
    read_arch.close();
    aux.close();
    remove("points.txt");
    rename ("auxiliar.txt","points.txt");
}

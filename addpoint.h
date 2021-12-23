#ifndef ADDPOINT_H
#define ADDPOINT_H
#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;


class addpoint
{
    ifstream read_arch;
    ofstream aux;
    string arch_name= "points.txt", playerArch="", player_name="";
    int playerspoint = 0;
public:
    addpoint(string);//sobrecarga
    void pluspoint(string player_name);
};

#endif // ADDPOINT_H

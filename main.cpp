#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

bool questionsload(string player);//prototipo de la fncion



int main()
{
    int dec= 1;
    string player= "";
    bool conf = false;

    while (dec !=0){
        if(conf == false){
        cout<<".___________________________________________."<<endl;
        cout<<"|             Menu de eleccion              |"<<endl;
        cout<<".-------------------------------------------."<<endl;
        cout<<"|Para ser el jugador 1 presione 1 (1)       |"<<endl;
        cout<<"|Para ser el jugador 2 presione 2 (2)       |"<<endl;
        cout<<"|Para ser el jugador 3 presione 3 (3)       |"<<endl;
        cout<<"|Para ser el jugador 3 presione 4 (4)       |"<<endl;
        cout<<"|Para ser el jugador 3 presione 5 (5)       |"<<endl;
        cout<<"|Para salir presione (0)                    |"<<endl;
        cout<<"---------------------------------------------"<<endl;

        cin>>dec;
    }

    switch (dec) {
    case 1:{
        cout<<"ejecutando caso 1---"<<endl;
        player="player1";
        conf= questionsload(player);
        break;}
    case 2:{
        cout<<"ejecutando caso 2---"<<endl;
        player="player2";
        conf= questionsload(player);

        break;}

    case 3:{
        cout<<"ejecutando caso 3---"<<endl;
        player="player3";
        conf= questionsload(player);
        break;}

    case 4:{
        cout<<"ejecutando caso 4---"<<endl;
        player="player4";
        conf= questionsload(player);
        break;}
    case 5:{
        cout<<"ejecutando caso 5---"<<endl;
        player="player5";
        conf= questionsload(player);
        break;}

    default :{
        break;}
    }
    }



    return 0;
}

bool questionsload(string player){
    srand(time(NULL));//elijo un numero aleatorio, se usara para obtener pregunta aleatoria
    int num1=rand()%5, num2=0, playerspoint=0;
    ifstream arch_points, arch;
    string playerArch = "", name_arch = "";
    string question = "", option_a = "", option_b = "", option_c = "", option_d = "", answer = "", answer_player="";
    vector <string> text;
    bool conf=false;

    cout<<"pregunta numero: "<<num1+1<<endl;

    if (num1 == 0)
        num1 = 0;
    else if (num1 == 1)
        num1=6;
    else if (num1 == 2)
        num1=12;
    else if (num1 == 3)
        num1=18;
    else if (num1 == 4)
        num1=24;

    string name_points = "points.txt";

    arch_points.open(name_points);

    if(!arch_points){ // verifico que jugador es el usuario
        cout<<"No fue posible abrir el archivo: "<<name_points<<endl;
    }
    else{
        while(!arch_points.eof()){
            arch_points>>playerArch;
            arch_points>>playerspoint;
            if (playerArch == player){
                break;
            }
        }
    }


    if (playerspoint < 5){ // se le informa al usuario en que nivel esta
        cout<<"usted esta en el nivel 1";
        name_arch = "level1.txt"; // adquiero el jugador y su puntaje, y  se abre el archivo de preguntas correpondiente
        arch.open(name_arch);
    }
    else if (playerspoint >= 5 && playerspoint < 10){
        cout<<"usted esta en el nivel 2";
        name_arch = "level2.txt";
        arch.open(name_arch);
    }
    else if (playerspoint >= 10 && playerspoint < 15){
        cout<<"usted esta en el nivel 3";
        name_arch = "level3.txt";
        arch.open(name_arch);
    }
    else if (playerspoint >= 15 && playerspoint < 20){
        cout<<"usted esta en el nivel 4";
        name_arch = "level4.txt";
        arch.open(name_arch);
    }
    else if (playerspoint > 19 ){
        cout<<"usted esta en el nivel 5";
        name_arch = "level5.txt";
        arch.open(name_arch);
    }
    cout<<endl<<endl;

    if(!arch){
        cout<<"No fue posible abrir el archivo: "<<name_arch<<endl;
    }
    else{
        while(!arch.eof()){ // leo las preguntas del archivo y recibo una respuesta del jugador
            if (num2 == num1){ //mecanismo para encontrar la pregunta aleatoria
                getline(arch, question,'\n');
                if(question == "end")
                    break;

                text.push_back(question);

                getline(arch, option_a,'\n');
                text.push_back(option_a);

                getline(arch, option_b,'\n');
                text.push_back(option_b);

                getline(arch, option_c,'\n');
                text.push_back(option_c);

                getline(arch, option_d,'\n');
                text.push_back(option_d);

                getline(arch, answer,'\n');
                //text.push_back(answer);

                for (unsigned int i = 0; i < text.size() ; i++){
                    cout<<text[i]<<endl;
                }

                cout<<"seleccione una opcion o 0 para salir: ";
                cin>>answer_player;
                cin.ignore();


                if (answer == answer_player){
                    system("cls");
                    cout<<"Acertaste la respuesta!, FELICIDADES."<<endl;
                    conf=true;
                }
                else if(answer_player == "0"){
                    return conf =false;
                }
                else{
                    system("cls");
                    cout<<"Respuesta incorrecta"<<endl;
                    conf = false;
                }
                text.clear();
            }
            else{
                getline(arch, question,'\n');
                getline(arch, option_a,'\n');
                getline(arch, option_b,'\n');
                getline(arch, option_c,'\n');
                getline(arch, option_d,'\n');
                getline(arch, answer,'\n');
            }
            num2+=6;
        }
    }
    arch_points.close();
    arch.close();
    return conf;

}

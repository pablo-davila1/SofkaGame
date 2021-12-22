#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    ifstream arch; //inicializo archivo de preguntas
    ifstream arch_points; //inicializo archivo de usuarios
    string question = "", option_a = "", option_b = "", option_c = "", option_d = "", answer = "", answer_player="";
    string player="", playerArch = "", name_arch = "";
    int playerspoint=0, dec=0;
    vector <string> text;
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
    cin.ignore();

    if(dec == 1)// se le asigna el jugador que el usuario elige
        player="player1";
    else if (dec==2)
        player="player2";
    else if (dec==3)
        player="player3";
    else if (dec==4)
        player="player4";
    else if (dec==5)
        player="player5";

    srand(time(NULL));//elijo un numero aleatorio, se usara para obtener pregunta aleatoria
    int num1=rand()%5, num2=0;

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



//    if(playerspoint == 0){ // adquiero el jugador y su puntaje, y  se abre el archivo de preguntas correpondiente
//        name_arch = "level1.txt";
//        arch.open(name_arch);
//    }
//    else if(playerspoint == 5){
//        name_arch = "level2.txt";
//        arch.open(name_arch);
//    }
//    else if(playerspoint == 10){
//        name_arch = "level3.txt";
//        arch.open(name_arch);
//    }
//    else if(playerspoint == 15){
//        name_arch = "level4.txt";
//        arch.open(name_arch);
//    }
//    else if(playerspoint == 20){
//        name_arch = "level5.txt";
//        arch.open(name_arch);
//    }

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

                cout<<"seleccione una opcion: ";
                cin>>answer_player;
                cin.ignore();


                if (answer == answer_player){
                    system("cls");
                    cout<<"Acertaste la respuesta!, FELICIDADES."<<endl;
                }
                else{
                    system("cls");
                    cout<<"Respuesta incorrecta"<<endl;
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
    return 0;
}

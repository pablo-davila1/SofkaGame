#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ifstream arch;
    string question = "", level = "", option_a = "", option_b = "", option_c = "", option_d = "", answer = "", answer_player="";
    vector <string> text;
    string name_arch = "Questions.txt";
    arch.open(name_arch);
    if(!arch){
        cout<<"No fue posible abrir el archivo: "<<name_arch<<endl;
    }
    else{

        while(!arch.eof()){
            getline(arch, level,'\n');

            if(level == "end")
                break;

            text.push_back(level);

            getline(arch, question,'\n');
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
            text.push_back(answer);

            cout<<"usted esta en el "<<text[0]<<endl;
            for (unsigned int i = 1; i < text.size() ; i++){
                cout<<text[i]<<endl;
            }

            cout<<"seleccione una opcion: ";
            cin>>answer_player;
            cin.ignore();




            if (answer == answer_player){
                cout<<"¡Acertaste la respuesta!, FELICIDADES."<<endl;
            }
            else{
                cout<<"Respuesta incorrecta"<<endl;
            }
            text.clear();
        }
    }


    arch.close();
    return 0;
}

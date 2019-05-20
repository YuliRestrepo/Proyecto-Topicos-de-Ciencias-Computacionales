#include<iostream>
#include <iostream>
#include <fstream>

using namespace std;

class cifrado{

public:
    char linea[128];
    string clavecifrado;
    string clavedescifrado;
    string contenido2;
    void leerarchivo ();
    void encriptar();
    void desencriptar();
    void guardarencrip();
    void guardardesencrip();

};


void cifrado::leerarchivo(){
//Se debe crear un archivo txt con el nombre de "nombre" para que realice correctamente este procedimiento
    ifstream fs("nombre.txt", ios:: in );
    long contador = 0L;
    if (fs.fail())
      cerr << "El fichero no existe" << endl;
    else
      while (!fs.eof()) {
        fs.getline(linea, sizeof(linea));
        cout << linea << endl;
        if ((++contador % 100) == 0) {
          cout << "continuar...";
          cin.get();
        }
      }
    fs.close();
}


void cifrado::encriptar(){

    cout<<"Inserte una clave para cifrar la informacion: ";
    cin>>clavecifrado;

    int x=0;
    while(linea[x] != '\0' && linea[x]>=0){
        x++;
    }
    cout<<"\n";

    for(x=x-1; x>=0; x--){
        linea[x]=linea[x]-27+230;
        cout<<linea[x];
    }

}

void cifrado::guardarencrip(){

        ifstream fs("nombre.txt"); //leer de este archivo
        ofstream fstemp("nombretemp.txt"); //escribir en este archivo

        if(!fs || !fstemp){
          cout << "Error al abrir el archivo!" << endl;
        }

        while(fs >> contenido2){
            fstemp<<linea<<endl;
        }

        fs.close();
        fstemp.close();
        remove("nombre.txt");
        rename("nombretemp.txt", "nombre.txt");

}

void cifrado::guardardesencrip(){

        ifstream fs("nombre.txt"); //leer de este archivo
        ofstream fstemp("nombretemp.txt"); //escribir en este archivo

        if(!fs || !fstemp){
          cout << "Error al abrir el archivo!" << endl;
        }

        while(fs >> linea){
            fstemp<<contenido2<<endl;
        }

        fs.close();
        fstemp.close();
        remove("nombre.txt");
        rename("nombretemp.txt", "nombre.txt");

}


void cifrado::desencriptar (){

    cout<<"Ingrese clave de cifrado: ";
    cin>>clavedescifrado;

    if(clavedescifrado==clavecifrado){
        int x=0, a=0;
        while(linea[x] != '\0' && linea[x]>=0){
            x++;
        }
        cout<<"\n";

        for(a=0; a<=x-1; a++){
            linea[a]=linea[a]+27-230;
            cout<<linea[a];
        }
    }else{
        cout<<"La clave es incorrecta :("<<endl;
    }


}


int main()
{
    cifrado c;
    int opcion; //opcion del menu

    cout<<"BIENVENIDO";

    do
    {
        cout << "\nMENU DE OPCIONES" << endl;
        cout << "1. Leer Archivo" << endl;
        cout << "2. Cifrar" << endl;
        cout << "3. Descifrar" << endl;
        cout << "4. Cerrar programa" << endl;
        cout << "Opcion: ";

        cin >> opcion;

        switch(opcion)
        {
        case 1:

            c.leerarchivo();

            break;

        case 2:

            c.encriptar();
            c.guardarencrip();

            break;

        case 3:

            c.desencriptar();
            c.guardardesencrip();

            break;

        case 4:
            return 0;
            break;
        }
    }while(1);
}


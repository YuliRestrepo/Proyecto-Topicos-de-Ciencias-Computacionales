lavecifrado;

    cout<<"Inserte numero de desplazamientos: ";
    cin>>despl;

    int j;
     for(int i=0;i<strlen(linea);i++){
      j=0;
      while(j<52){
       if(linea[i]==alf[j] && (j<23||(j>=26 &&j<49))){
        linea[i]=alf[j+despl];
        j=52;
          }
       if(linea[i]==alf[j] && (j>=23 && j<26)){
           if(linea[i]=='x'){
            linea[i]='a';
        }
        if(linea[i]=='y'){
            linea[i]='b';
        }
        if(linea[i]=='z'){
            linea[i]='c';
        }
        j=52;
       }
       if(linea[i]==alf[j] && (j>=49 && j<52)){
           if(linea[i]=='X'){
            linea[i]='A';
        }
        if(linea[i]=='Y'){
            linea[i]='B';
        }
        if(linea[i]=='Z'){
            linea[i]='C';
        }
        j=52;
       }
          j++;
      }
     }
     cout<<linea;
     cout<<"\n";

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
        int j;
         for(int i=0;i<strlen(linea);i++){
          j=0;
          while(j<52){
           if(linea[i]==alf[j] && (j<23||(j>=26 &&j<49))){
            linea[i]=alf[j-despl];
            j=52;
              }
           if(linea[i]==alf[j] && (j>=23 && j<26)){
               if(linea[i]=='x'){
                linea[i]='a';
            }
            if(linea[i]=='y'){
                linea[i]='b';
            }
            if(linea[i]=='z'){
                linea[i]='c';
            }
            j=52;
           }
           if(linea[i]==alf[j] && (j>=49 && j<52)){
               if(linea[i]=='X'){
                linea[i]='A';
            }
            if(linea[i]=='Y'){
                linea[i]='B';
            }
            if(linea[i]=='Z'){
                linea[i]='C';
            }
            j=52;
           }
              j++;
          }
         }
         cout<<linea;
         cout<<"\n";
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

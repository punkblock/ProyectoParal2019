#include <stdio.h>
#include <string.h>
#include <iostream>
#include <xlnt/xlnt.hpp>
#include "xlsxwriter.h"

using namespace std;

//Se devine variable global con arreglo de salas lleno
string edificio_y_numSala[500];
// string Docente_Lunes[3000];
// string Docente_Martes[3000];
// string Docente_Miercoles[3000];
// string Docente_Jueves[3000];
// string Docente_Viernes[3000];
// string Docente_Sabado[3000];
vector<vector<string>> hoja_Docente;

void recorrer_dias_docentes(char *argumento){
  // Lee sample1.xlsx e imprime un 2-dimensional
  // representación de cada hoja. Las celdas están separadas por comas.
  // Cada nueva línea es una nueva fila.
  xlnt::workbook wb;
  wb.load(argumento);
  auto ws = wb.active_sheet();

   // La clase de libro de trabajo tiene métodos de inicio y fin, por lo que puede repetirse.
   // Cada elemento es una hoja en el libro de trabajo.
   //vector<vector<string>> hoja_Docente;

   for(const auto sheet : wb){

       // Imprime el título de la hoja en su propia línea.
       //cout << sheet.title() << ": " << endl;

       // Iterando en un rango, como en la hoja de trabajo :: rows, produce cell_vectors.
       // Los vectores celulares en realidad no contienen celdas para reducir la sobrecarga.
       // En su lugar, contienen una referencia a una hoja de cálculo y la referencia de celda actual.
       // Internamente, llamar a la hoja de trabajo :: get_cell con la cell_reference actual produce la siguiente celda.
       // Esto permite una iteración fácil y rápida sobre una fila (a veces una columna) en la hoja de trabajo.

           for(auto row : sheet.rows()){
                 vector<string> filas;
                   for(auto cell : row){
                       //cout << cell << ", ";
                       filas.push_back(cell.to_string());
                       //Arreglo con la info del lunes
                      // Docente_Lunes[cell];
                   }
                   hoja_Docente.push_back(filas);
                   //cout <<endl;

         }


       }
       // if(sheet.title()=="Martes"){
       //     for(auto row : sheet.rows()){
       //       vector<string> fila_lunes;
       //         for(auto cell : row){
       //             //cout << cell << ", ";
       //             fila_lunes.push_back(cell.to_string());
       //             //Arreglo con la info del lunes
       //            // Docente_Lunes[cell];
       //         }
       //         hoja_Docente.push_back(fila_lunes);
       //         //cout <<endl;
       //     }
       //     string Id,Nombre,Apellido,Bloque1,Bloque2,Bloque3,Bloque4,Bloque5,Bloque6,Bloque7;
       //     for (int fila = 1; fila < hoja_Docente.size(); fila++){
       //       Id = hoja_Docente.at(fila).at(0); Nombre = hoja_Docente.at(fila).at(1);
       //       Apellido = hoja_Docente.at(fila).at(2); Bloque1 = hoja_Docente.at(fila).at(3);
       //       Bloque2 = hoja_Docente.at(fila).at(4); Bloque3 = hoja_Docente.at(fila).at(5);
       //       Bloque4 = hoja_Docente.at(fila).at(6); Bloque5 = hoja_Docente.at(fila).at(7);
       //       Bloque6 = hoja_Docente.at(fila).at(8); Bloque7 = hoja_Docente.at(fila).at(9);
       //       Docente_Lunes[fila] = Id +" "+ Nombre+" "+ Apellido+" "+ Bloque1+" "+ Bloque2+" "+ Bloque3+" "+ Bloque4+" "+ Bloque5+" "+ Bloque6+" "+ Bloque7;
       //       //std::cout <<  Docente_Lunes[fila] << '\n';


  // }

      }

// void Verificar_arreglos(){
//       for (int fila = 1; fila <240; fila++){
//         std::cout <<Docente_Lunes[1][1] << '\n';
//       }
// }

void leer(){
    xlnt::workbook wb;
    wb.load("/home/charls/libxlsxwriter/Salas.xlsx");
    auto ws = wb.active_sheet();

    /* Lee toda la hoja de cálculo */
  	vector<vector<string>> hoja_calculo;
  	vector<vector<string>> columna_c;
    for (auto row : ws.rows(false)){
        vector<string> fila_simple; // Creando un vector nuevo solo para esta fila en la hoja de cálculo
  		    for (auto cell : row){
  		        fila_simple.push_back(cell.to_string());  //Añadiendo esta celda a la fila;
  		    }
  		    hoja_calculo.push_back(fila_simple); //Agregando esta fila completa al vector que almacena toda la hoja de cálculo;
      }

       // Definimos variables y vectores a utilizar
       string nombre_edificio; // Nombre del edificio
       int numero_sala = 0;
       string nombreNumero;
       int numeros[500];
       string nombree;
       string nombre_llenado[500];
       string numeros_salas[500];

      // Primer For para recorrer el archivo completo
      for (int fila = 1; fila < hoja_calculo.size(); fila++){
          nombre_edificio = hoja_calculo.at(fila).at(0); // Se guarda nombre el edificio
          nombreNumero = hoja_calculo.at(fila).at(1); // Se guarda el numero de salas
          numero_sala = stoi(nombreNumero, nullptr); // Se Convierte de string a entero
          numeros_salas[fila] = nombreNumero; // LLenamos vector con numero de salas
          nombre_llenado[fila] = nombre_edificio; // LLenamos vector con nombre de edificios
          nombree = nombre_llenado[fila]+"_"+numeros_salas[fila]; // Unimos nombre de edifico y numero correspondiente
          edificio_y_numSala[fila] = nombree; // LLenamos el vector que definimos como global con el edificio y numero (ej:M1_201..)
   }
}

void crear_hojas(){
	int hoja = 0;
	int bloques = 0;
  char buffer[500];
  lxw_workbook  *workbook  = workbook_new("Horario.xlsx");

  //Escribimos el edificio + numero de sala en cada hoja
  for (int i = 1; i<54; i++){
    strcpy(buffer,edificio_y_numSala[i].c_str());
    lxw_worksheet *worksheet = workbook_add_worksheet(workbook, buffer);

    // Escribir bloques en cada hoja de sala
    string cadena_bloques[9] = {"8:00-9:30","9:40-11:10","11:20-12:50","13:00-14:30","14:40-16:10","16:20-17:50","18:00-19:30","19:40-21:10","21:20-22:50"};
    char buffer_bloques[500];
    for (int c = 0; c<9; c++){
      strcpy(buffer_bloques,cadena_bloques[c].c_str()); //Convierte la cadena de String a Chart
      worksheet_write_string(worksheet,c, 0, buffer_bloques, NULL); // Escribe la cadena convertida
    }

    // Escribir dias en cada hoja de sala
    string cadena[7] = {"Bloques/Días","Lunes","Martes","Miércoles","Jueves","Viernes"};
    char buffer_cadena[500];
    for (int p = 0; p<7; p++){
      strcpy(buffer_cadena,cadena[p].c_str());
      worksheet_write_string(worksheet, 0, p, buffer_cadena, NULL);
    }
  }
	workbook_close(workbook);
}

//crear estructuras
typedef struct InfoSala {
    char nombreSala[30];
    int codigoProfesor;
} InfoSala;

typedef struct InfoBloque {
  int dia;
  int bloque;
  int codigoAsignatura;
  int sala;
} InfoBloque;

typedef struct Ramos{
  char codigoRamo[20];
  //char nombreAsignatura[50];
  int codigoProfesor;
  int  horasRamo; //si llega a 0 es que ya esta lista no asignar
  int estado;
} Ramos;

typedef struct Profesor {
  int codigoProfesor;
  //char nombreProfesor[30];
  //int diasDisponible[6];
  int prioridad;
  int diasBloques[6][7];
  int estado;
} Profesor;

//asignar los ramos con menor horas
void prioridad(char *argumento){
    int profes = 239;
    while(profes != 0){
        for (int i=0; i<239; i++ ){
            // if(prioridad)

        }
    }
}

void infoProfe(char *argumento){
    xlnt::workbook wb;
    wb.load(argumento);// Cursos.xlsx
    int contador = 0;
    auto ws = wb.active_sheet();
    //auto ws = wb.sheet_by_id(0);

	/* toda la hoja de cálculo */
	std::vector< std::vector<std::string> > hoja_calculo;
	std::vector< std::vector<std::string> > columna_c;
	for (auto row : ws.rows(false)){

		// Creando un vector nuevo solo para esta fila en la hoja de cálculo
		vector<string> fila_simple;

		for (auto cell : row){
		    //Añadiendo esta celda a la fila;
		    fila_simple.push_back(cell.to_string());
		}

		//Agregando esta fila completa al vector que almacena toda la hoja de cálculo;
		hoja_calculo.push_back(fila_simple);
        }

    Profesor profes[239];
    //excel docentes;
    int hoja$=0;
    int j=0,k=0;
    int fila[500];
    int columna[20];
    int cont = 1;
    for (int fila = 1; fila < hoja_Docente.size(); fila++){
        //cambiar por los datos del excel
        int codProfe = std::atoi (hoja_Docente.at(fila).at(0).c_str());
        profes[fila].codigoProfesor = codProfe;
        cout << "Cod Profe: " << profes[fila].codigoProfesor << endl << endl;
        k=0;//dia
        hoja$=0;//primera hoja -- dia lunes
        int dsp=0;
        for (int k=0; k<8; k++){
            j=0;//bloque
            for (int z=3; z<10; z++){
                string disp = "DISPONIBLE";
                string noDisp = "NO DISPONIBLE";
                string sss=hoja_calculo.at(fila).at(z).c_str();
                cout << sss << endl;
                if(sss == disp){
                    dsp=0;
                }
                if(sss == noDisp){
                    dsp=1;
                }
                //int bloque = std::atoi (hoja_calculo.at(fila).at(z).c_str());
                profes[fila].diasBloques[j][k] = dsp; //z desde 4 a 10 excepto dia sabado
                cout << "Bloquelibre: " << j << k << ": " << profes[fila].diasBloques[j][k] << endl;
                j++;
            }
        }
        profes[fila].estado = 1; // bloques y codigo cargado
    }
}

void infoRamos(char *argumento){
    xlnt::workbook wb;
    wb.load(argumento);// Cursos.xlsx
    int contador = 0;
    auto ws = wb.active_sheet();

	/* toda la hoja de cálculo */
	std::vector< std::vector<std::string> > hoja_calculo;
	std::vector< std::vector<std::string> > columna_c;
	for (auto row : ws.rows(false)){

		// Creando un vector nuevo solo para esta fila en la hoja de cálculo
		vector<string> fila_simple;

		for (auto cell : row){
		    //Añadiendo esta celda a la fila;
		    fila_simple.push_back(cell.to_string());
		}

		//Agregando esta fila completa al vector que almacena toda la hoja de cálculo;
		hoja_calculo.push_back(fila_simple);
        }
    Ramos ramoss[346];

    for (int fila = 1; fila < hoja_calculo.size(); fila++){
        string cRamo = hoja_calculo.at(fila).at(0);
        char cstr[cRamo.size() + 1];
	    strcpy(cstr, cRamo.c_str());
        strcpy(ramoss[fila].codigoRamo, cstr);// codigo ramo
        int codProfe = std::atoi (hoja_calculo.at(fila).at(2).c_str());
        ramoss[fila].codigoProfesor = codProfe;
        int horRamo = std::atoi (hoja_calculo.at(fila).at(5).c_str());
        ramoss[fila].horasRamo = horRamo;

        cout << "CodRamo: " << ramoss[fila].codigoRamo << endl;
        cout << "CodProfe: " << ramoss[fila].codigoProfesor << endl;
        cout << "HoraRamos: " << ramoss[fila].horasRamo << endl;
    }

}

void infoSalas(char *argumento){
    InfoSala salass[53];
    int excel[500][20]; //excel cursos
    for (int i=0; i<346; i++){
        //strcpy(salass[i].nombreSala, excel[i][0]);//concatena M1
        //strcpy(salass[i].nombreSala, excel[i][1]);//concatena 301
    }
}

void infoBlock(char *argumento){
    InfoBloque block[7][6];
    for (int i=0; i<8; i++){
        for (int j=0; j<7; j++){

        }
    }
}

int contarFilas(char *argumento){
    xlnt::workbook wb;
    wb.load(argumento);
    int contador = 0;
    auto ws = wb.active_sheet();
    for (auto row : ws.rows(false))
    {
	contador = contador + 1;
    }
    return contador;
}

int main( int argc, char *argv[]) {

    leer();
    crear_hojas();
    //Verificar_arreglos();

    //argc: numero total de argumentos pasados por linea de comandos
    //argv: array con los argumentos pasados por linea de comandos

    //Variable para guardar el argumento
    string argumento;


    //Leyendo los argumentos por argumentos
    for (int i = 0; i < argc; i++)
    {
	argumento = argv[i];
	//Si argumento es igual a -s, se utiliza Salas.xlsx
	if (argumento == "-s")
        {
            cout << "Numero de filas en " << argv[i + 1] << ": " << contarFilas(argv[i + 1]) << endl;
        }
	//Si argumento es igual a -d, se utiliza Docentes.xlsx
        else if (argumento == "-d")
        {
          recorrer_dias_docentes(argv[i +1]);
            cout << "Numero de filas en " << argv[i + 1] << ": " << contarFilas(argv[i + 1]) << endl;
            cout << "Funcion de Info de profe " << endl;
            infoProfe(argv[i +1]);

        }
	//Si argumento es igual a -c, se utiliza Cursos.xlsx
	else if(argumento == "-c")
        {
            cout << "Funcion de Info de ramos " << endl;
            //infoRamos(argv[i +1]);
            //cout << "Numero de filas en " << argv[i + 1] << ": " << contarFilas(argv[i + 1]) << endl;
            //cout << "Funcion de materias repetidas " << endl;
            //MateriasProfesor(argv[i +1]);
        }
    }

    return 0;
}

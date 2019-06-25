#include <iostream>
#include <xlnt/xlnt.hpp>
#include <string.h>
#include <cstdlib>
#include <string>

using namespace std;

//Funcion para contar filas de los archivos.xlsx
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

// Funcion materias repetidas
void MateriasProfesor(char *argumento)
{
    xlnt::workbook wb;
    wb.load(argumento);
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

    // Cantidad de materias que tiene un profesor
	int contador_bloques = 0;
    // Variable para ver si existe más de una vez el profesor
    int existe = 0;
    // Nombre del profesor
    string nombre;
    // id del profesor
    int idNumero = 0;
    // Arreglo con los id de cada profesor
    int idNumeros[500];
    // Variable auxiliar donde se guarda idNumero como string
    string nombreNumero;
    // Primer For para recorrer el archivo completo
    for (int fila = 1; fila < hoja_calculo.size(); fila++){
        contador_bloques = 0;
        existe = 0;
        // Se guarda nombre del profesor
        nombre = hoja_calculo.at(fila).at(3);
        // Se guarda idNumero como string
        nombreNumero = hoja_calculo.at(fila).at(2);
        // Se convierte idNumero a entero
        idNumero = stoi(nombreNumero, nullptr);
        // Se agrega el idNumero al arreglo de los id
        idNumeros[fila] = idNumero;
        // Se recorre idNumeros[] para saber si ya se conto la cantidad de materias
        // Que tiene asignadas el profesor
        for (int i = 0 ; i < 500; i++)
        {
            // Si existe el id en el arreglo, entonces existe++
            if (idNumero == idNumeros[i+1])
            {
                //cout << "EXISTE ID: " << idNumeros[i] << endl;
                existe++;
            }
        }
        // Si no existe el id en el arreglo se cuenta cuantas veces se repite el id del profesor
        // Para saber cuantas materias tiene asignadas
        if (existe < 2)
                {
		    //cout << "No existe ID: " << endl;
            // Se recorre Cursos.xlsx 
	        for (int fila2 = 0; fila2 < hoja_calculo.size(); fila2++)
	        {
		      for (int columna2 = 0; columna2 < hoja_calculo.at(fila2).size(); columna2++)
		      {

		      }
                // Se compara el nombre del profesor en el archivo
	            if(nombre==(hoja_calculo.at(fila2).at(3)))
                {
                    // Se guarda la cantidad de veces que existe el nombre del profesor
		            contador_bloques++;
		        
	            }
	        }
            // Muestra el numero de fila que aparece el profesor por primera vez
	        cout << "NUMERO DE FILA" << fila << endl;
            // Muestra el nombre del profesor y la cantidad de ramos
            cout<<"Profesor: "<<nombre<<" , cantidad de ramos: "<<contador_bloques<<endl;
        }
    }

}

/*********************************************************/

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

typedef struct Profesor {
  int codigoProfesor;
  //char nombreProfesor[30];
  //int diasDisponible[6];
  int prioridad;
  int diasBloques[6][7];
  int estado;
} Profesor;

typedef struct Ramos{
  char codigoRamo[20];
  //char nombreAsignatura[50];
  int codigoProfesor;
  int  horasRamo; //si llega a 0 es que ya esta lista no asignar
  int estado;
} Ramos;

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
    Profesor profes[239];
    int hoja$=0;
    int j=0,k=0;
    int fila[500];
    int columna[20];
    int excel[500][20];//excel docentes;
    for (int i=0; i<239; i++){
        //cambiar por los datos del excel
        profes[i].codigoProfesor = excel[i][0];
        k=0;//dia
        hoja$=0;//primera hoja -- dia lunes
        for (int k=0; k<8; k++){
            j=0;//bloque
            for (int z=4; z<11; z++){
                profes[i].diasBloques[j][k] = hoja$,excel[i][z]; //z desde 4 a 10 excepto dia sabado
                j++;
            }
            hoja$++;//6 hojas
        }
        profes[i].estado = 1; // bloques y codigo cargado
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
        
    // Ramos ramoss[346];
    // int excel[500][20]; //excel cursos
    // for (int i=0; i<346; i++){
    //     ramoss[i].codigoRamo= excel[i][0];
    //     ramoss[i].codigoProfesor = excel[i][2];
    //     ramoss[i].horasRamo = excel[i][5];
    // }
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

/*********************************************************/

int main( int argc, char *argv[])
{
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
            cout << "Numero de filas en " << argv[i + 1] << ": " << contarFilas(argv[i + 1]) << endl;
        }
	//Si argumento es igual a -c, se utiliza Cursos.xlsx
	else if(argumento == "-c")
        {
            cout << "Funcion de Info de Ramos " << endl;
            //infoRamos(argv[i +1]);
            //cout << "Numero de filas en " << argv[i + 1] << ": " << contarFilas(argv[i + 1]) << endl;
            //cout << "Funcion de materias repetidas " << endl;
            //MateriasProfesor(argv[i +1]);
        }
    }
    
    return 0;
}

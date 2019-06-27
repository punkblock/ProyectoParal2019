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
    char nombreEdificio[30];
    char numeroSala[30];
    int lab;
    int codigoProfesor;
} InfoSala;

typedef struct InfoBloque {
  int dia;
  int bloque;
  int codigoAsignatura;
  int sala;
} InfoBloque;

//Listo
typedef struct Ramos{
  char codigoRamo[20];
  int codigoProfesor;
  int  horasRamo;
  int estado;
} Ramos;

//Listo
typedef struct Profesor {
  int codigoProfesor;
  //char nombreProfesor[30];
  //int diasDisp[6];
  int prioridad;
  int diasBloques[7][6];
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
    wb.load(argumento);// Docentes.xlsx
    auto ws = wb.active_sheet();

	/* toda la hoja de cálculo */
	std::vector< std::vector<std::string> > hoja_calculo;
	// std::vector< std::vector<std::string> > columna_c;
        for(const auto sheet : wb){ 
            for(auto row : sheet.rows()){
                vector<string> filas;
                for(auto cell : row){
                    //cout << cell << ", ";
                    filas.push_back(cell.to_string());
                }
                hoja_calculo.push_back(filas);
                //cout <<endl;
            }
        }

    Profesor profes[239];
    //excel docentes;
    int j=0;
    int k=0;
    // int filaa[500];
    // int columna[20];
    int cont = 0;
    int cont2 = 0;
    int auxxx=1;
    int hoja=1;
    int dsp=0;//disponible
    string disp;
    string noDisp;
    string bloquee;
    for  (int fila = 1; fila < hoja_calculo.size(); fila++){
        //std::cout << hoja_calculo.at(fila).at(0) << endl;
        //std::cout  << "Fila : " << fila<< endl;
        if(fila == 240 || fila == 480 || fila == 720 || fila == 960 || fila == 1200){
            //std::cout << endl << "Fin Hoja : " << hoja << endl << endl;
            //std::cout << hoja_calculo.at(fila).at(0) << endl;
            hoja++;
            cont=0;
            cont2=0;
            k++;//dia
        }else{
            // if(fila == 1439){
                 //std::cout << endl << "Fin Hoja : " << hoja << endl << endl;
            // }
            if(cont<239){
                int codProfe = std::atoi (hoja_calculo.at(fila).at(0).c_str());
                profes[cont].codigoProfesor = codProfe;//guarda codProfe
                //std::cout << "Cod Profe: " << profes[cont].codigoProfesor << endl << endl;
                //cuenta profesores (desde 1 a 240)
                cont++;
            }
                // cout << "Fila N: " << cont << endl;
            if(fila<1201){
                j=0;//bloque
                // std::cout << "CodProfe: " << profes[cont2].codigoProfesor << endl;
                for (int z=3; z<10; z++){//z: columnas
                    disp = "DISPONIBLE";
                    noDisp = "NO DISPONIBLE";
                    bloquee=hoja_calculo.at(fila).at(z).c_str();//guarda dia bloque
                    //cout << sss << endl;
                    if(bloquee == disp){
                        dsp=0;
                    }
                    if(bloquee == noDisp){
                        dsp=1;
                    }
                    if(cont2<239){
                        profes[cont2].diasBloques[j][k] = dsp; //z desde 4 a 10 excepto dia sabado
                    }
                    // std::cout << "CodProfe: " << profes[cont2].codigoProfesor << endl;
                    // std::cout << "Bloquelibre: " << j << k << ": " << profes[cont2].diasBloques[j][k] << endl;
                    j++;
                }
            }
            if(fila>1200){
                j=0;//bloque
                // std::cout << "CodProfe: " << profes[cont2].codigoProfesor << endl;
                for (int z=3; z<7; z++){//z: columnas
                    disp = "DISPONIBLE";
                    noDisp = "NO DISPONIBLE";
                    bloquee=hoja_calculo.at(fila).at(z).c_str();//guarda dia bloque
                    //cout << sss << endl;
                    if(bloquee == disp){
                        dsp=0;
                    }
                    if(bloquee == noDisp){
                        dsp=1;
                    }
                    if(cont2<239){
                        profes[cont2].diasBloques[j][k] = dsp; //z desde 4 a 10 excepto dia sabado
                    }
                    // std::cout << "CodProfe: " << profes[cont2].codigoProfesor << endl;
                    // std::cout << "Bloquelibre: " << j << k << ": " << profes[cont2].diasBloques[j][k] << endl;
                    j++;
                }
            }
            cont2++;
            //profes[fila].estado = 1; // bloques y codigo cargado
        }
    }   
    std::cout << "FIN Docentes.xlsx" << endl;
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
      int cont2= 0;
      string tipo;
      string tSala;
      int tLab=0;
      int j;
      string lab="LAB";
      string esLab;

      xlnt::workbook wb;
      wb.load(argumento);// Salas.xlsx
      auto ws = wb.active_sheet();

    /* toda la hoja de cálculo */
    std::vector< std::vector<std::string> > hoja_sala;
    for(const auto sheet : wb){
        for(auto row : sheet.rows()){
            vector<string> filas;
            for(auto cell : row){
                filas.push_back(cell.to_string());
            }
            hoja_sala.push_back(filas);
        }
    }
    InfoSala salass[54];

    for (int fila = 1; fila < hoja_sala.size(); fila++){

        string eSala = hoja_sala.at(fila).at(0);
        char cstr[eSala.size() + 1];
	      strcpy(cstr, eSala.c_str());
        strcpy(salass[fila].nombreEdificio, cstr);// nombre edificio

        string numSala = hoja_sala.at(fila).at(1);
        char num[numSala.size() + 1];
	    strcpy(num, numSala.c_str());
        strcpy(salass[fila].numeroSala, num);// nombre sala
        
        esLab=hoja_sala.at(fila).at(0);
        cout<< esLab << "==" << lab << endl << endl;
        if (lab== esLab){
            salass[fila].lab = 1;//Si es lab
        }
        if (lab!= esLab){
            salass[fila].lab = 0;//No es lab
        }
        cout << "Edificio:"<< salass[fila].nombreEdificio << " " <<"NumSala: " << salass[fila].numeroSala<< " "<<"Lab?: "<<salass[fila].lab<< endl;

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
            //cout << "Numero de filas en " << argv[i + 1] << ": " << contarFilas(argv[i + 1]) << endl;
            cout << "Funcion de Info de salas " << endl;
            infoSalas(argv[i + 1]);
        }
	//Si argumento es igual a -d, se utiliza Docentes.xlsx
        else if (argumento == "-d")
        {
            //cout << "Numero de filas en " << argv[i + 1] << ": " << contarFilas(argv[i + 1]) << endl;
            cout << "Funcion de Info de profe " << endl;
            //infoProfe(argv[i +1]);
        }
	//Si argumento es igual a -c, se utiliza Cursos.xlsx
	else if(argumento == "-c")
        {
            cout << "Funcion de Info de ramos " << endl;
            //infoRamos(argv[i +1]);
            //MateriasProfesor(argv[i +1]);
        }
    }
    
    return 0;
}

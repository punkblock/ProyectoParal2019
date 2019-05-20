#include <iostream>
#include <xlnt/xlnt.hpp>
#include <string.h>

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
            cout << "Numero de filas en " << argv[i + 1] << ": " << contarFilas(argv[i + 1]) << endl;
            cout << "Funcion de materias repetidas " << endl;
            MateriasProfesor(argv[i +1]);
        }
    }
    
    return 0;
}

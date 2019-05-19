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
            cout << contarFilas(argv[i + 1]) << endl;
        }
	//Si argumento es igual a -d, se utiliza Docentes.xlsx
        else if (argumento == "-d")
        {
            cout << contarFilas(argv[i + 1]) << endl;
        }
	//Si argumento es igual a -c, se utiliza Cursos.xlsx
	else if(argumento == "-c")
        {
            cout << contarFilas(argv[i + 1]) << endl;
        }
    }

    return 0;
}

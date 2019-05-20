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

    /*
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
    */

    //Funcion materia repetida

    xlnt::workbook wb;
    wb.load("/home/ubuntu/Escritorio/Cursos.xlsx");
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

	// Recorremos el vector y lo mostramos por pantalla


    int contador_bloques = 0;
    int existe = 0;
    string nombre;
    int idNumero = 0;
    int idNumeros[500];
    string nombreNumero;
    for (int fila = 1; fila < hoja_calculo.size(); fila++){
        contador_bloques = 0;
        existe = 0;
        nombre = hoja_calculo.at(fila).at(3);
        nombreNumero = hoja_calculo.at(fila).at(2);
        idNumero = stoi(nombreNumero, nullptr);
        idNumeros[fila] = idNumero;
        for (int i = 0 ; i < 500; i++)
        {
            if (idNumero == idNumeros[i+1])
            {
                //cout << "EXISTE ID: " << idNumeros[i] << endl;
                existe++;
            }
        }
        if (existe < 2)
                {
		//cout << "No existe ID: " << endl;
	        for (int fila2 = 0; fila2 < hoja_calculo.size(); fila2++)
	        {
		      for (int columna2 = 0; columna2 < hoja_calculo.at(fila2).size(); columna2++)
		      {

		      }
	            if(nombre==(hoja_calculo.at(fila2).at(3)))
                {
		            contador_bloques++;
		        
	            }
	        }
            //Muestra el numero de fila que aparece el profesor por primera vez
	        cout << "NUMERO DE FILA" << fila << endl;
            //Muestra el nombre del profesor y la cantidad de ramos
            cout<<"Profesor: "<<nombre<<" , cantidad de ramos: "<<contador_bloques<<endl;
        }
    }

    return 0;
}

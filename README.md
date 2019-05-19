# Tarea05-Paralela
Tarea05 de la ayudantia de paralela 2019

## Stack de Construcción
Este proyecto está construido sobre la base de estar usando Ubuntu 18.04 LTS de 64 bits y las herramientas usadas fueron

- CMake (apt-get install cmake)
- Gcc  (apt-get install build-essential)
- xlnt ($ git clone https://github.com/tfussell/xlnt.git
        $ cd xlnt
        $ cmake .
        $ make -j 2
        $ sudo make install
        $ sudo ldconfig
        
### Compilar/Ejecutar
Para compilar y ejecutar el proyecto hay que pararse en la carpeta Tarea05-Paralela además tener los archivos Salas.xlsx, Docentes.xlsx y Cursos.xlsx:

        Compilar con:
        $ g++ main.cpp -o tarea -std=c++14 -Ixlnt/include -lxlnt
        
        Ejecutar con:
        $./tarea -s Salas.xlsx -d Docentes.xlsx -c Cursos.xlsx

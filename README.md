# Proyecto-Paralela
Proyecto de paralela 2019


## Stack de Construcción
Este proyecto está construido sobre la base de estar usando Ubuntu 18.04 LTS de 64 bits y las herramientas usadas fueron

- C++

        $ sudo apt-get install g++
         
- CMake

        $ sudo apt-get install cmake
        
- Gcc  

        $ sudo apt-get install build-essential

- Git

        $ sudo apt-get install git
   
- Curl

        $ sudo apt-get install curl
        
### Instalar libreria xlnt para leer los archivos.

        $ git clone https://github.com/tfussell/xlnt.git
        $ cd xlnt
        $ cmake .
        $ make -j 2
        $ sudo make install
        $ sudo ldconfig
        
### Instalar libreria libxlsxwriter para escribir y crear hojas.

        $ sudo apt-get install -y zlib1g-dev
        $ git clone https://github.com/jmcnamara/libxlsxwriter.git
        $ cd libxlsxwriter
        $ make
        $ sudo make install

        $ curl -O -L  http://www.zlib.net/zlib-1.2.11.tar.gz
        $ tar zxf zlib-1.2.11.tar.gz
        $ sudo apt-get install -y python-pytest
        
### Instalar OpenMP 

        $ sudo apt-get install libomp-dev
        
### Para que ambas librerias funcionen, se tienen que combinar las carpetas xlnt y libxlsxwriter...

### Compilar y Ejecutar el programa:

        Compilar con:
        $ g++ main.cpp -o tarea -std=c++14 -lxlsxwriter -Ixlnt/include -lxlnt
        
        Ejecutar con:
        $ ./tarea -s Salas.xlsx -d Docentes.xlsx -c Cursos.xlsx
        
### Compilar y Ejecutar el programa con OpenMP:

        Compilar con:
        $ mpic++ main.cpp -o tarea -lxlsxwriter -lxlnt -fopenmp
        
        Ejecutar con:
        $ ./tarea --hostfile hostfile.txt -np n ./tarea -s Salas.xlsx -d Docentes.xlsx -c Cursos.xlsx
        

# Proyecto-Paralela
Proyecto de paralela 2019


## Stack de Construcción
Este proyecto está construido sobre la base de estar usando Ubuntu 18.04 LTS de 64 bits y las herramientas usadas fueron

- CMake
        $ sudo apt-get install cmake
        
- Gcc  
        $ sudo apt-get install build-essential
        
- Libreria xlnt

        $ git clone https://github.com/tfussell/xlnt.git
        $ cd xlnt
        $ cmake .
        $ make -j 2
        $ sudo make install
        $ sudo ldconfig
        
### Instalacion libreria para escribir y crear hojas.
        $ sudo apt-get install -y zlib1g-dev
        $ git clone https://github.com/jmcnamara/libxlsxwriter.git
        $ cd libxlsxwriter
        $ make
        $ sudo make install

        $ curl -O -L  http://www.zlib.net/zlib-1.2.11.tar.gz
        $ tar zxf zlib-1.2.11.tar.gz
        $ sudo apt-get install -y python-pytest
        
### Para que ambas librerias funcionen, se tienen que combinar las carpetas xlnt y libxlsxwriter...

### Compilar/Ejecutar
Para compilar y ejecutar el proyecto:

        Compilar con:
        $ g++ main.cpp -o tarea -std=c++14 -lxlsxwriter -Ixlnt/include -lxlnt
        
        Ejecutar con:
        $ ./tarea -s Salas.xlsx -d Docentes.xlsx -c Cursos.xlsx

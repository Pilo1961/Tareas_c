1. Estudia y entiende los archivos definiciones.h y funciones.c de ahí, en particular investiga por qué se usan "" en la línea que tiene #include en funciones.c en lugar de usar < >. Investiga el uso de static en la definición de variables externas de funciones.c .
En definiciones se definen expresiones que nos permiten acceder a los valores que están dentro de una estructura de acuerdo al tipo de estructura que tenemos, ya sea una estructura 2d o un vector.
En funciones se definen las funciones que se tienen para definir e imprimir una matriz y un vector. LA funciones de inicializació leen los valores de la esztructura desde un archivo y los guradan usando las expresiones entrada deifinidas en definciones, pasan el nombre (identificador) de estructura como parámetro.
LAs funciones impirme imprimen las estructuras.

En c, cuando se usa la sentencia #include se debe de poner "" para que el compilador busque el archivo indicado dentro de la ruta en la que estamos trabajando. Se utiliza la notación <> cuando quremos que el compilador busque el paquete dentro de la ruta establecida para los directorios estandar del sistema.
El comando static se puede utilizar de dos maneras:
* Definir variables static dentro de una función. Esto hara que el valor de la variable se guarde entre invocaciones a la función. Cuando la función se termine de ejectura cualquier variable no static definida dentro de la función perderá el valor incluso cuando la función se vuelva a invocar, en las variables static es posible conservar y acceder a esa valor de nuevo al invocar la función. La posición de memoria en la que se guarda el valor es estátiaca.
* En un ambiente global también es posible definir variables y funciones static. Estas solamente estará accesibles desde el archivo en el que fueron creadas. Si se tiene un programa que ocuopa otros módulos o programas, no podemos acceder a una variable o función static definida en uno de nuestros archivos desde otro programa. Si en un archivo está el main y en otro está una función definida como static no es posible accesarla, tendría que ser a partir de otra función dentro del mimso archivo. Un uso de esto es para control de accesos.

2. Investiga* sobre BLAS, CBLAS, LAPACK, ATLAS y las operaciones de nivel 1, nivel 2 y nivel 3 de BLAS y reporta sobre esta investigación que realizas. Es una investigación que contiene principalmente una descripción sobre los paquetes y niveles anteriores.
BLAS
BLAS (Basic Linear Algebra Subprograms) es un conjunto de funciones estandar de álgebra lineal para hacer operaciones con matrices y vectores. BLAS es muy común, eficiente y facil de acceder, lo que lo hace muy utilizable al desarrollar software que ocupa operaciones de álgebra lineal. Originalmente está escrito en Fortran 77 y la documentación la encontramos en Netlib.
CBLAS es la interfaz de referencia del lenguaje C para BLAS
ATLAS (Automatically Tuned Linear Algebra Software) Es un softaware de distribución libre con implementaciones que proporciona una API de BLAS para C y fortran 77. ATLAS permite generar una librería de BLAS optimizada para los recursos que tiene la máquina en la que se está corriendo el código.

Tiene 3 niveles de operaciones que se distinguen por el tipo de operaciones que realizan:
* Nivel 1 - Soporta operaciones esntre escalares, vectores con escalares y vectores con vectores.
* Nivel 2 - Soprota operaciones entre vectores y matrices.
* Nivel 3 - Soporta operaciones entre matrices y matrices.
Todos los niveles soportan operaciones de prcisión sencilla, doble y números complejos en precisión sencilla y doble.

LAs rutinas que cada nivel tiene son las siguientes:
1. Nivel 1
* Setup aplicación de la rotación Givens y la rotación Givens modificada.
* Escalar vectores
* Copiar y cambiar vectores
* Aplicar el producto punto
* Calcular la norma euclidiana
* Sumar los valores absolutos
* Encontrar el ínicide del máximo

2. Nivel 2
* Multiplicación de matriz por vector
* Multiplicar matrices simétricas y vectotres
* Solución de problemas de matrices triangulares
* Hacer la operación de rank 1
* Hacer la operación de rank 2
En los tres casos se tienen funciones para matrices comunes, para matrices de banda y matrices en formato "empacado" (packed)

3. Nivel 3
* Multiplicación de matriz con matriz
* Multipliacioón de matrices simétricas
* Actualización simétrica de rank-k a una matriz
* Actualización simétrica de rank-2k a una matriz
* Multiplicación de matrices traingulares
* Solución de matrices triangulares con lado derecho

LAPACK (Linear Algebra PACKage) es un paquete esccrito en fortran 90 para realizar operaciones de álgebra lineal. La meta de LAPACK es hacer los paquetes EISPACK y LINPACK eficientes al usar procesamiento en paralelo. LAPACK está escrito para aprovechar al máximo la eficiencia de BLAS, hace uso de sus subrutinas de nivel 3 constantemente.
Las rutinas de LAPACK permiten resolver los siguientes problemas:
* Sistemas de ecuaciones lineales
* Mínimos cuadrados
* Problemas de eigenvalores y eigenvectores
* Factoraización de matrices (LU, Cholesky, QR, SVD, Shur, generalized Shur)
* Estimar número de condición
Se pueden operar matrices densas y en bandas (no matrices "sparse") con presición sencilla y doble, para número reales o complejos.

3. En la carpeta analisis-numerico-computo-cientifico/C/BLAS/ejemplos/level1/ ejecuta el programa dot_product.c y realiza pruebas con diferentes vectores definidos por ti.
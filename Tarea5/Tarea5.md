# Tarea 5


1. Estudia y entiende los archivos definiciones.h y funciones.c de ah�, en particular investiga por que se usan "" en la l�nea que tiene #include en funciones.c en lugar de usar < >. Investiga el uso de static en la definición de variables externas de funciones.c .
En definiciones se definen expresiones que nos permiten acceder a los valores que están dentro de una estructura de acuerdo al tipo de estructura que tenemos, ya sea una estructura 2d o un vector.
En funciones se definen las funciones que se tienen para definir e imprimir una matriz y un vector. LA funciones de inicialización leen los valores de la estructura desde un archivo y los guardan usando las expresiones entrada definidas en definiciones, pasan el nombre (identificador) de estructura como par�metro.
Las funciones imprime imprimen las estructuras.

En c, cuando se usa la sentencia #include se debe de poner "" para que el compilador busque el archivo indicado dentro de la ruta en la que estamos trabajando. Se utiliza la notaci�n <> cuando quremos que el compilador busque el paquete dentro de la ruta establecida para los directorios estandar del sistema.
El comando static se puede utilizar de dos maneras:
* Definir variables static dentro de una funci�n. Esto hara que el valor de la variable se guarde entre invocaciones a la funci�n. Cuando la funci�n se termine de ejectura cualquier variable no static definida dentro de la funci�n perder� el valor incluso cuando la funci�n se vuelva a invocar, en las variables static es posible conservar y acceder a esa valor de nuevo al invocar la funci�n. La posici�n de memoria en la que se guarda el valor es est�tiaca.
* En un ambiente global tambi�n es posible definir variables y funciones static. Estas solamente estar� accesibles desde el archivo en el que fueron creadas. Si se tiene un programa que ocuopa otros m�dulos o programas, no podemos acceder a una variable o funci�n static definida en uno de nuestros archivos desde otro programa. Si en un archivo est� el main y en otro est� una funci�n definida como static no es posible accesarla, tendr�a que ser a partir de otra funci�n dentro del mimso archivo. Un uso de esto es para control de accesos.

2. Investiga* sobre BLAS, CBLAS, LAPACK, ATLAS y las operaciones de nivel 1, nivel 2 y nivel 3 de BLAS y reporta sobre esta investigación que realizas. Es una investigación que contiene principalmente una descripción sobre los paquetes y niveles anteriores.

**BLAS**
BLAS (Basic Linear Algebra Subprograms) es un conjunto de funciones estándar de álgebra lineal para hacer operaciones con matrices y vectores. BLAS es muy común, eficiente y fácil de acceder, lo que lo hace muy utilizable al desarrollar software que ocupa operaciones de álgebra lineal. Originalmente está escrito en Fortran 77 y la documentación la encontramos en Netlib.

**CBLAS** es la interfaz de referencia del lenguaje C para BLAS

**ATLAS** (Automatically Tuned Linear Algebra Software) Es un softaware de distribución libre con implementaciones que proporciona una API de BLAS para C y fortran 77. ATLAS permite generar una librería de BLAS optimizada para los recursos que tiene la máquina en la que se está corriendo el código.

Tiene 3 niveles de operaciones que se distinguen por el tipo de operaciones que realizan:
* Nivel 1 - Soporta operaciones entre escalares, vectores con escalares y vectores con vectores.
* Nivel 2 - Soporta operaciones entre vectores y matrices.
* Nivel 3 - Soporta operaciones entre matrices y matrices.
Todos los niveles soportan operaciones de precisión sencilla, doble y números complejos en precisión sencilla y doble.

Las rutinas que cada nivel tiene son las siguientes:
1. Nivel 1
* Setup y aplicación de la rotación Givens y la rotación Givens modificada.
* Escalar vectores
* Copiar y cambiar vectores
* Aplicar el producto punto
* Calcular la norma euclidiana
* Sumar los valores absolutos
* Encontrar el índice del máximo

2. Nivel 2
* Multiplicación de matriz por vector
* Multiplicar matrices simétricas y vectores
* Solución de problemas de matrices triangulares
* Hacer la operación de rank 1
* Hacer la operación de rank 2
En los tres casos se tienen funciones para matrices comunes, para matrices de banda y matrices en formato "empacado" (packed)

3. Nivel 3
* Multiplicación de matriz con matriz
* Multiplicación de matrices simétricas
* Actualización simétrica de rank-k a una matriz
* Actualización simétrica de rank-2k a una matriz
* Multiplicación de matrices triangulares
* Solución de matrices triangulares con lado derecho

**LAPACK** (Linear Algebra PACKage) es un paquete escrito en fortran 90 para realizar operaciones de álgebra lineal. La meta de LAPACK es hacer los paquetes EISPACK y LINPACK eficientes al usar procesamiento en paralelo. LAPACK está escrito para aprovechar al máximo la eficiencia de BLAS, hace uso de sus subrutinas de nivel 3 constantemente.
Las rutinas de LAPACK permiten resolver los siguientes problemas:
* Sistemas de ecuaciones lineales
* Mínimos cuadrados
* Problemas de eigenvalores y eigenvectores
* Factorización de matrices (LU, Cholesky, QR, SVD, Shur, generalized Shur)
* Estimar número de condición
Se pueden operar matrices densas y en bandas (no matrices "sparse") con presición sencilla y doble, para número reales o complejos.

3. En la carpeta analisis-numerico-computo-cientifico/C/BLAS/ejemplos/level1/ ejecuta el programa dot_product.c y realiza pruebas con diferentes vectores definidos por ti.
El programa realiza la operación de producto punto entre dos vectores que alimentamos por medio de los archivos **v1.txt** y **v2.txt**. Es necesario pasar como parámetro al programa el número de dimensiones que tienen los vectores a operar. Si los vectores tiene diferentes dimensiones el programa rellena de ceros. Si pasamos un número de dimensiones como parámetro que no corresponde a la dimensión de los vectores entonces el programa opera como si ambos vectores tuvieran el número de entradas que pasamos como parámetro.
4. Investiga* sobre la subrutina de Fortran ddot (parámetros que recibe y la salida).
La subrutina ddot de fortran tiene la función principal de llamar a la función ddot que calcula el producto punto entre dos vectores. Recibe los siguientes parámetros de entrada:
* n -> N- número de dimensiones que tiene el vector.
* x -> DX - arreglo de dimensión N
* incx -> INCX - incremento en X, espaciado entre las entradas del vector DX.
* y -> DY - vector Y de N dimensiones.
* incy -> INCY - incremento en el vector y.
* dot - Resultado que regresa la subrutina. Es el resultado de llamar a la función ddot con los 4 parámetros mencionados anteriormente. Es un número de doble precisión.

5. Haz un programa que utilice la subrutina daxpy de Fortran.

1. Estudia y entiende los archivos definiciones.h y funciones.c de ah�, en particular investiga por qu� se usan "" en la l�nea que tiene #include en funciones.c en lugar de usar < >. Investiga el uso de static en la definici�n de variables externas de funciones.c .
En definiciones se definen expresiones que nos permiten acceder a los valores que est�n dentro de una estructura de acuerdo al tipo de estructura que tenemos, ya sea una estructura 2d o un vector.
En funciones se definen las funciones que se tienen para definir e imprimir una matriz y un vector. LA funciones de inicializaci� leen los valores de la esztructura desde un archivo y los guradan usando las expresiones entrada deifinidas en definciones, pasan el nombre (identificador) de estructura como par�metro.
LAs funciones impirme imprimen las estructuras.

En c, cuando se usa la sentencia #include se debe de poner "" para que el compilador busque el archivo indicado dentro de la ruta en la que estamos trabajando. Se utiliza la notaci�n <> cuando quremos que el compilador busque el paquete dentro de la ruta establecida para los directorios estandar del sistema.
El comando static se puede utilizar de dos maneras:
* Definir variables static dentro de una funci�n. Esto hara que el valor de la variable se guarde entre invocaciones a la funci�n. Cuando la funci�n se termine de ejectura cualquier variable no static definida dentro de la funci�n perder� el valor incluso cuando la funci�n se vuelva a invocar, en las variables static es posible conservar y acceder a esa valor de nuevo al invocar la funci�n. La posici�n de memoria en la que se guarda el valor es est�tiaca.
* En un ambiente global tambi�n es posible definir variables y funciones static. Estas solamente estar� accesibles desde el archivo en el que fueron creadas. Si se tiene un programa que ocuopa otros m�dulos o programas, no podemos acceder a una variable o funci�n static definida en uno de nuestros archivos desde otro programa. Si en un archivo est� el main y en otro est� una funci�n definida como static no es posible accesarla, tendr�a que ser a partir de otra funci�n dentro del mimso archivo. Un uso de esto es para control de accesos.

2. Investiga* sobre BLAS, CBLAS, LAPACK, ATLAS y las operaciones de nivel 1, nivel 2 y nivel 3 de BLAS y reporta sobre esta investigaci�n que realizas. Es una investigaci�n que contiene principalmente una descripci�n sobre los paquetes y niveles anteriores.
BLAS
BLAS (Basic Linear Algebra Subprograms) es un conjunto de funciones estandar de �lgebra lineal para hacer operaciones con matrices y vectores. BLAS es muy com�n, eficiente y facil de acceder, lo que lo hace muy utilizable al desarrollar software que ocupa operaciones de �lgebra lineal. Originalmente est� escrito en Fortran 77 y la documentaci�n la encontramos en Netlib.
CBLAS es la interfaz de referencia del lenguaje C para BLAS
ATLAS (Automatically Tuned Linear Algebra Software) Es un softaware de distribuci�n libre con implementaciones que proporciona una API de BLAS para C y fortran 77. ATLAS permite generar una librer�a de BLAS optimizada para los recursos que tiene la m�quina en la que se est� corriendo el c�digo.

Tiene 3 niveles de operaciones que se distinguen por el tipo de operaciones que realizan:
* Nivel 1 - Soporta operaciones esntre escalares, vectores con escalares y vectores con vectores.
* Nivel 2 - Soprota operaciones entre vectores y matrices.
* Nivel 3 - Soporta operaciones entre matrices y matrices.
Todos los niveles soportan operaciones de prcisi�n sencilla, doble y n�meros complejos en precisi�n sencilla y doble.

LAs rutinas que cada nivel tiene son las siguientes:
1. Nivel 1
* Setup aplicaci�n de la rotaci�n Givens y la rotaci�n Givens modificada.
* Escalar vectores
* Copiar y cambiar vectores
* Aplicar el producto punto
* Calcular la norma euclidiana
* Sumar los valores absolutos
* Encontrar el �nicide del m�ximo

2. Nivel 2
* Multiplicaci�n de matriz por vector
* Multiplicar matrices sim�tricas y vectotres
* Soluci�n de problemas de matrices triangulares
* Hacer la operaci�n de rank 1
* Hacer la operaci�n de rank 2
En los tres casos se tienen funciones para matrices comunes, para matrices de banda y matrices en formato "empacado" (packed)

3. Nivel 3
* Multiplicaci�n de matriz con matriz
* Multipliacio�n de matrices sim�tricas
* Actualizaci�n sim�trica de rank-k a una matriz
* Actualizaci�n sim�trica de rank-2k a una matriz
* Multiplicaci�n de matrices traingulares
* Soluci�n de matrices triangulares con lado derecho

LAPACK (Linear Algebra PACKage) es un paquete esccrito en fortran 90 para realizar operaciones de �lgebra lineal. La meta de LAPACK es hacer los paquetes EISPACK y LINPACK eficientes al usar procesamiento en paralelo. LAPACK est� escrito para aprovechar al m�ximo la eficiencia de BLAS, hace uso de sus subrutinas de nivel 3 constantemente.
Las rutinas de LAPACK permiten resolver los siguientes problemas:
* Sistemas de ecuaciones lineales
* M�nimos cuadrados
* Problemas de eigenvalores y eigenvectores
* Factoraizaci�n de matrices (LU, Cholesky, QR, SVD, Shur, generalized Shur)
* Estimar n�mero de condici�n
Se pueden operar matrices densas y en bandas (no matrices "sparse") con presici�n sencilla y doble, para n�mero reales o complejos.

3. En la carpeta analisis-numerico-computo-cientifico/C/BLAS/ejemplos/level1/ ejecuta el programa dot_product.c y realiza pruebas con diferentes vectores definidos por ti.
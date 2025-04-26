# Proyecto 1 Estructura de Datos
## Integrantes del grupo
- [Antonio Jesus Benavides Puentes](https://github.com/AntoCreed777) **(2023455954)**
- [Javier Alejandro Campos Contreras](https://github.com/huebitoo) **(2023432857)**

## Tecnologias utilizadas en el proyecto
<p align="center">
  <a href="https://skillicons.dev">
    <img src="https://skillicons.dev/icons?i=git,github,vscode&perline=5" />
  </a>
</p>
<p align="center">
  <a href="https://skillicons.dev">
    <img src="https://skillicons.dev/icons?i=cpp&perline=5" />
  </a>
</p>

## Definicion del Problema

<details>
  <summary>Haz clic para expandir/contraer</summary>

En el pintoresco pueblo de Olognia habitan talentosos ingenieros informáticos, los cuales han estado desarrollando el Programa Experimental de Poder Extremo (PEPE por sus iniciales). Sin embargo por un error de programación, ¡PEPE se ha salido de control y está apunto de atacar al pueblo!

PEPE tiene la capacidad de generar esbirros los cuales tienen puntos de vida y de ataque variables (no todos los esbirros fueron creados iguales) los cuales atacarán la ciudad de manera secuencial, uno a la vez y en el mismo orden en el que fueron creados. Además, PEPE es capaz de crear Clones Avanzados de Naturaleza Orgánica (CANO por sus iniciales), los cuales al ser atacados una cierta cantidad de veces, son capaces de dividirse una única vez en dos partes iguales, donde cada parte tendrá los puntos de vida y ataque disminuidos en uno respecto a los que tenía antes de ser dividido. Note que estos esbirros resultantes de la división serán los siguientes en atacar el pueblo y se cuentan como esbirros independientes.

Los habitantes de Olognia si bien son muy inteligentes, no se caracterizan por su valentía, por la cual han puesto a cargo de la defensa de la ciudad a un mechón de informática, quien está dispuesto a dar su vida si fuese necesario a cambio de certámenes pasados de Cálculo I.

Nuestro héroe tiene V puntos de vida y está equipado con la última tecnología armamentística desarrollada en Olognia: arco, flechas y un modelo de machine learning que mejora el ataque de las flechas. El arco empieza con 2 puntos de ataque, mientras que el modelo de machine learning incrementa en 1 estos puntos después de 5 esbirros eliminados por el arma.

Los ingenieros más ilustres de Olognia han sido capaces de descifrar la cantidad y el orden en el cual atacarán los esbirros. Por cada cada esbirro sabemos su vida, ataque y si es o no un CANO. Ahora quieren simular el ataque y saber si es que el mechón será capaz de salvar al pueblo. ¡Pero! Cuando intentaron simularlo se dieron cuenta que olvidaron todo lo que aprendieron en el curso de estructuras de datos, y sin esos conocimientos fundamentales nunca serán capaces de saber el resultado de la batalla de antemano.

Es por esto que las autoridades han decidido contactarles a ustedes, estudiantes del curso de estructuras de datos, para conocer el destino final de Olognia. Como regla general, la simulación termina cuando la vida del mechón o la cantidad de esbirros restantes llega a 0.

¡Qué viva Olognia y toda su gente!

 
### Formato de Entrada

Se proporcionarán las siguientes 4 líneas de datos, las cuales deberán ser leídas desde teclado:

1. La primera línea consta de un número v, el cual corresponde a la vida del héroe mechón.
2. La segunda línea consta de un número n, el cual corresponde al número total de esbirros generados por PEPE.
3. La tercera línea consta de n números separados por espacios, indicando la vida de los esbirros, en el mismo orden en el que atacarán la ciudad.
4. La cuarta línea consta de n números separados por espacios, indicando el ataque de cada esbirro, en el mismo orden en el que atacarán la ciudad.
5. La quinta línea consta de n valores binarios separados por espacios, indicando con un 1 si el i-ésimo esbirro es un CANO o 0 en caso contrario. Para efectos del trabajo, asumiremos que todos los CANO se dividirán luego del segundo ataque recibido.

### Salida Esperada

Tu deber será imprimir un valor numérico y un texto separados por un salto de línea. El valor numérico corresponde al daño total que el mechón causó a los esbirros, mientras que el texto será "EZ pizi" si el mechón logra salvar al pueblo o "RIP mechón" si es que este no logra su cometido.

</details>

## 📄 Supuestos

- El Mechon y los Esbirros se atacan a la vez, esto implica que, aunque uno de los 2 muera en algun turno, ambos lograran hacer su respectivo daño.
- Se considera que el mechon logra salvar al pueblo si ya no queda ningun enemigo, independiente de si el Mechon murio o no. 



## ⚙ **Comandos de Compilacion con Make**

### Compilar Todo
```bash
make all
```
Esta regla compila todos los archivos fuente y genera el ejecutable ``main.out`` en el directorio raíz.

### Ejecutar el programa
```bash
make run
```
Compila (si es necesario) y ejecuta el programa. El ejecutable ``main.out`` se ejecutará automáticamente.

### Debuggear el programa
```bash
make debug
```
Compila (si es necesario) el programa y abre el ejecutable ``main.out`` con ``gdb`` para depuración.

### Investigar fugas de memoria
```bash
make memoria
```
Compila (si es necesario) y ejecuta el programa bajo ``valgrind`` para identificar posibles fugas de memoria. Muestra información detallada sobre las fugas y sus causas.

### Limpiar archivos generados
```bash
make clean
```
Elimina los archivos generados durante la compilación, incluyendo:

  - Todos los archivos objeto en ``build/``.

  - El ejecutable ``main.out``.

## Comandos de compilacion sin Make

### Compilar Todo
```bash
g++ -Wall -g -I ./include ./src/cola_mechon.cpp ./src/enemigo.cpp ./src/main.cpp ./src/mechon.cpp ./src/nodo_cola_mechon.cpp -o main.out
```
Compila todos los archivos fuente y genera el ejecutable ``main.out`` en el directorio raíz.

### Ejecutar el programa
```bash
./main.out
```
Ejecuta el programa el ejecutable ``main.out``.

## 📂 Estructura del Proyecto
```plaintext
Protecto_1_Estructura_de_Datos/
├── Makefile              # Archivo para automatizar la compilación
├── README.md             # Documentación del proyecto
├── build                 # Archivos compilados (objetos y binarios)
│   ├── cola_mechon.o
│   ├── enemigo.o
│   ├── main.o
│   ├── mechon.o
│   └── nodo_cola_mechon.o
├── conventions.md        # Convenciones de estilo de código y estándares
├── include               # Archivos de cabecera (header files)
│   ├── cola_mechon.hpp
│   ├── enemigo.hpp
│   ├── mechon.hpp
│   └── nodo_cola_mechon.hpp
├── main.out              # Archivo ejecutable principal
├── src                   # Implementación del código fuente
│   ├── cola_mechon.cpp
│   ├── enemigo.cpp
│   ├── main.cpp
│   ├── mechon.cpp
│   └── nodo_cola_mechon.cpp
└── test                  # Pruebas del proyecto
    ├── Makefile          # Archivo de compilación para pruebas
    ├── test1.cpp         # Codigo de pruebas
    └── testeo            # Archivos de datos para las pruebas
        ├── test1.txt
        ├── test2.txt
        ├── test3.txt
        └── test4.txt

```


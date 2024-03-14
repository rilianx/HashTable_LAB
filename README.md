
Implementando un Mapa (HashMap)
=====

---
**Antes de comenzar**

* Importe el repositorio desde su cuenta en repl.it (si no tiene siga [este tutorial](https://chartreuse-goal-d5c.notion.site/C-mo-comenzar-con-los-labs-b4dd8c7abc5a425d8f25e2eaa060e5b5?pvs=4))
* Sólo puede modificar los archivos *hashmap.c* y *main.c*
* Para testear sus códigos basta con que apriete el botón **Run**
* Si no funciona el botón **Run** puede abrir un terminal (shell) y ejecutar el comando `./test.sh`
* Verifique que sus cambios se hayan subido a este repositorio
* **No está permitido usar comandos de git** (a menos que el profesor o ayudantes lo indiquen)
---



En este laboratorio implementaremos un **mapa**. Para ello usaremos la siguiente estructura (tabla hash) que se encuentra en el archivo *hashmap.c*

    //en hashmap.h
    struct Pair {
        char * key;
        void * value;
    };

    struct HashMap {
        Pair ** buckets;
        long size; //cantidad de datos/pairs en la tabla
        long capacity; //capacidad de la tabla
        long current; //indice del ultimo dato accedido
    };

    Pair * createPair( char * key,  void * value) {
        Pair * new = (Pair *)malloc(sizeof(Pair));
        new->key = key;
        new->value = value;
        return new;
    }

La estructura HashMap cuenta con un arreglo de punteros **Pair*** (buckets). Cada Pair a su vez cuenta con dos variables: una clave (key) y el valor asociado (value). *size* corresponde a la cantidad de elementos que tiene el mapa y *capacity* es el tamaño actual del arreglo buckets.

![image](https://i.ibb.co/RpQmMns/tabla-hash.png)

En la figura se muestra un HashMap de ejemplo. Observe que el arreglo intercala casillas ocupadas con casillas nulas. La cantidad de pares válidos almacenados en la estructura es 6. La capacidad actual del arreglo es 10.
Para acceder a una clave o valor del mapa, podemos acceder a través del arreglo buckets. Por ejemplo si tenemos un mapa HashMap* map, accedemos a la primera clave de esta manera:
    
    char* primera_clave = map->buckets[0]->key;
    
Para poder ubicar datos dentro del arreglo, la tabla necesita dos funciones: la función hash (para transformar claves en posiciones) y la función is_equal (para comparar claves). En este laboratorio consideraremos que las **claves son de tipo string** (char*). Usaremos la siguiente función hash para transformar claves en posiciones dentro del arreglo:

    long hash( char * key, long capacity) {
        unsigned long hash = 0;
        char * ptr;
        for (ptr = key; *ptr != '\0'; ptr++) {
            hash += hash*32 + tolower(*ptr);
        }
        return hash%capacity;
    }

La función is_equal por su parte, simplemente debe indicar si dos claves son iguales (retorna 1) o no lo son (retorna 0):

    int is_equal(void* key1, void* key2){
        if(key1==NULL || key2==NULL) return 0;
        if(strcmp((char*)key1,(char*)key2) == 0) return 1;
        return 0;
    }

En la mayoría de las pruebas de código se usa una tabla inicializada como la figura de arriba. El siguiente código muestra como se inicializa la tabla:

    info_msg("inicializando la tabla...");
    HashMap * map = (HashMap *)malloc(sizeof(HashMap));
    map->buckets = (Pair **) calloc (10,sizeof(Pair *));
    map->capacity = 10;

    char words[6][8]={"casa","carro","saco","olla","cesa","case"};
    int hashs[6]={8,7,6,0,4,2}; //using function in hashmap.c
    int i;
    for(i=0;i<6;i++)
        map->buckets[hashs[i]] = createPair(_strdup(words[i]),_strdup("exist"));
    
    map->size=6; 

Las pruebas/tests se encuentran en el archivo *test.c*

Ejercicios
----



[Revise las diapositivas](https://docs.google.com/presentation/d/1WTMXgVcZNQZc8ezeEwoyt6TFVmVl-ezDuGSNnRfsbjQ/edit#slide=id.p) si necesita más detalles para implementar las operaciones. También puede consultar el capítulo 11 del libro **Introduction to Algorithms**.

Recuerde que todas las funcionalidades se implementan en *hashmap.c*


1.- Implemente la función *createMap* en el archivo hashmap.c. Esta función crea una variable de tipo HashMap, inicializa el arreglo de buckets con casillas nulas, inicializa el resto de variables y retorna el mapa. Inicialice el índice current a -1.

    HashMap * createMap(long capacity) {


        return NULL;
    }


2.- Implemente la función void insertMap(HashMap * map, char * key, void * value). Esta función inserta un nuevo dato (key,value) en el mapa y actualiza el índice current a esa posición.
Recuerde que para insertar un par (clave,valor) debe:

a - Aplicar la función hash a la clave para obtener la posición donde debería insertar el nuevo par

b - Si la casilla se encuentra ocupada, avance hasta una casilla disponible (*método de resolución de colisiones*). Una casilla disponible es una casilla nula, pero también una que tenga un par inválido (key==NULL).

c - Ingrese el par en la casilla que encontró.

No inserte claves repetidas. 
Recuerde que el arreglo es **circular**.
Recuerde actualizar la variable size.
   
    void insertMap(HashMap * map, char * key, void * value){


    }



3.- Implemente la función Pair * searchMap(HashMap * map,  char * key), la cual retorna el **Pair** asociado a la clave ingresada. 
Recuerde que para buscar el par debe:

a - Usar la función hash para obtener la posición donde puede encontrarse el par con la clave

b - Si la clave no se encuentra avance hasta encontrarla (*método de resolución de colisiones*)

c - Si llega a una casilla nula, retorne NULL inmediatamente (no siga avanzando, la clave no está)

Recuerde actualizar el índice current a la posición encontrada.
Recuerde que el arreglo es **circular**.

    Pair * searchMap(HashMap * map,  char * key) {


        return NULL;
    }




4.- Implemente la función void eraseMap(HashMap * map,  char * key). Está función elimina el dato correspondiente a la clave key. Para hacerlo debe buscar el dato y luego *marcarlo* para que no sea válido.
**No elimine el par**, sólo invalídelo asignando NULL a la clave (pair->key=NULL).
Recuerde actualizar la variable size.

    void eraseMap(HashMap * map,  char * key){



    }


5.- Implemente las funciones para recorrer la estructura: Pair * firstMap(HashMap * map) retorna el primer **Pair** válido del arreglo buckets. Pair * nextMap(HashMap * map) retorna el siguiente **Pair** del arreglo buckets a partir índice current. Recuerde actualizar el índice.

    Pair * firstMap(HashMap * map) {
        

        return NULL;
    }

    Pair * nextMap(HashMap * map)  {
       

        return NULL;
    }


6.- Implemente la función void enlarge(HashMap * map). Esta función agranda la capacidad del arreglo buckets y reubica todos sus elementos. Para hacerlo es recomendable mantener referenciado el arreglo *actual/antiguo* de la tabla con un puntero auxiliar. Luego, los valores de la tabla se reinicializan con un nuevo arreglo con el **doble de capacidad**. Por último los elementos del arreglo antiguo se insertan en el mapa *vacío* con el método *insertMap*.
Puede seguir los siguientes pasos:

a - Cree una variable auxiliar de tipo Pair** para matener el arreglo map->buckets (*old_buckets*);

b - Duplique el valor de la variable capacity.

c - Asigne a map->buckets un nuevo arreglo con la nueva capacidad.

d - Inicialice size a 0.

e - Inserte los elementos del arreglo *old_buckets* en el mapa (use la función insertMap que ya implementó).


    void enlarge(HashMap * map){

        /* se duplica la capacidad */
        map -> capacity *= 2;

    }


### Ya implementó todas las funcionalides del TDA Mapa.



Ahora ya puede comenzar a utilizar su mapa. Puede comenzar viendo el código de ejemplo del archivo *main.c*. Para compilar y ejecutar:
    
    gcc main.c hashmap.c -o main; ./main
    ./main

Y voilá!

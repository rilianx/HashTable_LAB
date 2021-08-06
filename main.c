/**
 * Contador de palabras
 * El código hace uso de un HashMap para contar la cantidad
 * de veces que aparece cada palabra en un arreglo
**/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashmap.h"


char * _strdup(const char * str) {
    char * aux = (char *)malloc(strlen(str) + 1);
    strcpy(aux, str);
    return aux;
}


typedef struct{
   char* word;
    int count;
}Palabra;

Palabra* creaPalabra(char* word){
    Palabra* new = (Palabra*) malloc(sizeof(Palabra));
    new->count = 1;
    new->word = _strdup(word);
    return new;
}

int main() {
    HashMap *map = createMap(100);
    char words[57][15]={"Alice","was","beginning","to","get","very","tired",
    "of","sitting","by","her","sister","on","the","bank,","and","of","having",
    "nothing","to","do","once","or","twice","she","had","peeped","into",
    "the","book","her","sister","was","reading","but","it","had","no",
    "pictures","or","conversations","in","it","and","what","is","the","use",
    "of","a","book","thought","Alice","without","pictures","or","conversation"};
    int i;
    for(i=0;i<57;i++){
        Pair* aux=searchMap(map,words[i]); //clave: palabra, valor: int*
        
        if(aux!=NULL){
            (*(int*)aux->value)++;
        }else{
            int* cont = (int*) malloc (sizeof(int));
            *cont=1;
            insertMap(map,_strdup(words[i]),cont);
        }
    }

    printf("Recorriendo el mapa:\n");
    Pair* par = firstMap(map);
    while(par!=NULL){
        printf("%s: %d\n", (char*) par->key, *(int*) par->value);
        par = nextMap(map);
    }


    return 0;
}

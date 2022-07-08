#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>

#define _MATRICE_ char**
#define _MSIZE_ unsigned int;
#define _MNORM_ char*
#define _MWRITE_ FILE*;

const char* INVALID_SORT_TYPE = "Invalid sort type";
const char* DUPLICATION_KEY = "Duplicate key";


typedef enum Sort{
   ByKey,
   Byvalue,
};


typedef struct{
   _MATRICE_ entrySet;
   size_t size;
   void(*allocate)(struct HashMap*, size_t sz);
   void(*put_by_natural)(struct HashMap*, const char, _MNORM_);
   void(*m_prt)(struct HashMap*);
   void(*map_to_file)(struct HashMap*, FILE* fl, const char* locale);
   void(*sort_type)(struct HashMap* ref, enum Sort type);
} HashMap;

void allocate(HashMap* ref, size_t sz){
   ref->size = sz;
   ref->entrySet = (_MATRICE_)malloc(sizeof(_MNORM_) * ref->size);
   for (int i = 0; i < ref->size; ++i){
       ref->entrySet[i] = (_MNORM_)calloc(ref->size, sizeof(char));
   }
}
void m_prt(HashMap* ref){
    for (int i = 0; i < ref->size; ++i){
        printf("\nKey-> %c\nValues-> ", ref->entrySet[i][0]);
       for (int s = 0; s < INT_MAX; ++s){
           if(ref->entrySet[i][s] == 0){
               goto Decora;
           }
           printf("%c", ref->entrySet[i][s]);
       }
       Decora:
           break;
    }
}

inline uint32_t equation(const _MNORM_ val){
    uint32_t s = 0;
    while(val[s] != 0){
        s++;
    }
    return s;
}

//receiving a clone of the original hashmap after it's been modified//ordered clone
_MATRICE_ clone_sorted(HashMap* ref,  _MNORM_ values){
    char** recep1 = (char**)malloc(sizeof(char*) * ref->size);
    auto int sec = 0;
    auto int indexOfSortedValue = 0;
    while(indexOfSortedValue <= ref->size){
         for (size_t i = 0; i < ref->size; ++i){
            if(ref->entrySet[i][0] == values[indexOfSortedValue]){
            for (int k = 0; k < INT_MAX; ++k){
            if(ref->entrySet[i][k] == 0){
                goto infusion;//superfluous goto statement
            }
           infusion:
               recep1[indexOfSortedValue] = (char*)malloc(sizeof(char*) * sec);
               for (int s = 0; s < sec; s++){
                recep1[indexOfSortedValue][s] = ref->entrySet[i][k];
               }
               indexOfSortedValue++;
               i = 0;
               break;
          sec++;
        }
      }
    }
 }
     return recep1;
}

int sort_facility (const void * a, const void * b) {
   return ( *(char*)a - *(char*)b );
}

void sort_by_key(HashMap* ref){
    auto char* recep = (char*)malloc(sizeof(int)* ref->size);
    int d = 0;
    while(d <= ref->size){
        recep[d] = ref->entrySet[d][0];
        d++;
    }
    //sorting the arr containing the keys
    qsort(recep, ref->size, sizeof(char), sort_facility);//sorted
    //
    ref->entrySet = clone_sorted(ref, recep);
    //loop over recep, re-adjust the elements within the matrice by key
}

void sort_type(HashMap* ref, enum Sort type){
    switch(type){
       case 0 : sort_by_key(ref);
       case 1 : printf("by value");
       default : perror(INVALID_SORT_TYPE);
    }
}

void map_to_file(HashMap* ref, FILE* fl, const char* locale){
    assert(fl != NULL);
    fl = fopen(fl, "w");
    for (int i = 0; i < ref->size; ++i){
        for (int k = 0; k < INT_MAX; ++k){
            if(ref->entrySet[i][k] == 0){
                break;
            }
            fputc(ref->entrySet[i][k], fl);
        }
    }
}

bool duplication_ver(HashMap* ref, const char se){
    for (int s = 0; s < ref->size; s++){
        printf("act");
        if(ref->entrySet[s][0] == se){
            perror(DUPLICATION_KEY);
        }
    }
    return true;
}
//RE-DO
void put_by_natural(HashMap* ref, const char s, const _MNORM_ value){
    //checking for non-assigned elements
    if(duplication_ver(ref, s)){
        auto int emptied = 0;
    while(ref->entrySet[emptied][0] != '0' && ref->size <= emptied){
        emptied++;
    }
    //checking if the unassigned elements are depleted
    if(ref->entrySet[emptied][0] != 9){
        ref->entrySet = (char**) realloc(ref->entrySet, ref->size);
        ref->size = ref->size * 2;
    } else {
         ref->size++;
    }
    //do verification for non=duplication
    ref->entrySet[emptied][0] = s;
    //verifying the size of the passed value for insertion
    auto int value_sz = 0;
    for (int g = 0; g < INT_MAX; ++g){
        if(value[g] == 0){
            break;
        }
        value_sz++;
    }
     if(ref->size < value_sz){
        ref->entrySet[emptied] = (char*)realloc(ref->entrySet[emptied], sizeof(char) * value_sz);
     }
     strcpy(ref->entrySet[emptied], value);

    }
}



int main()
{
    exit(EXIT_SUCCESS);
}

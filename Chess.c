#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <assert.h>

#define _MATRICE_ wchar_t**
#define _LOCALE_ unsigned int**
#define _LEN_ 8
#define _BL_ 'b'
#define _WT_ 'w'

unsigned _MATRICE_ executive(const unsigned int* ind){
	assert (ind != NULL);
    _MATRICE_ recep = (_MATRICE_)malloc(sizeof(wchar_t*) * *ind);
	wchar_t inp[8];
	for (int i = 0; i < *ind; ++i){
		recep[i] = (wchar_t*)malloc(sizeof(wchar_t) * *ind);
		for (int k = 0; k < *ind; ++k){
		    scanf("%c", &inp[k]);
		}
		*(recep + i) = (wchar_t*) inp;
	 }
	return recep;
}

_LOCALE_ identification(_MATRICE_* des){
    _LOCALE_ indexation = (int*) malloc(sizeof(int) * 2);
    for (int i = 0; i < _LEN_; ++i){
        for (int j = 0; j < _LEN_; j++){
            if(des[i][j] == _BL_ || des[i][j] == _WT_)
                for (int l = 0; l < 2; l++)
                    indexation = (int*)malloc(sizeof(int) * 2);
                    *(indexation + l) = *(des + i);
        }
    }
    return indexation;
}

//print the corresponding chess location
const char finalize(_LOCALE_ * exec){
    switch(exec[0][1]){
        case 0 : return 'a';
        case 1 : return 'b';
        case 2 : return 'c';
        case 3 : return 'd';
        case 4 : return 'e';
        case 5 : return 'f';
        case 6 : return 'g';
        case 7 : return 'h';
    }
}


void finalization_of(_MATRICE_* decal){
    for (int i = 0; i < _LEN_; ++i){
        for (int k = 0; k < _LEN_; k++){
            printf("%c", decal[i][k]);
        }
        printf("\n");
    }
}



int main(int argc, const char** argv){
	//loop until row index irrespective of the color reaches its boundary(continuously verify whether bl(row) - wt(row) == 1, check diagonals to verify if available pawning(pawn/print current location/terminate)
	//verify whether the pawn is able to move in in its intended direction
	const unsigned int _IND_ = 8;
	unsigned _MATRICE_ des = executive(&_IND_);
	_LOCALE_ coor = identification(&des);
	while(coor[0][0] != 0 || coor[1][0] != 7){
        while(true){
                //liable for diagonal verification
            if(coor[0][0] - coor[1][0] == 1 || coor[0][0] - coor[1][0] == -1}{
                //
                //verify whose turn is
                if(coor[0][1++] <= _LEN_){
                    if(coor[0][1++] ==  coor[1][1]){
                         des[coor[1][0][coor[1][1] = '-';
                         printf("Finalized! %s capture on %c%d.", "white", finalize(&coor), &coor[1][1]);
                         finalization_of(&des);
                         return 0;
                     }
                }
                if(coor[0][1--] >= 0){
                    if(coor[0][1--] == coor[1][1]){
                        des[coor[1][0][coor[1][1]] = '-';
                        printf("Finalized! %s capture on %c%d.", "white", finalize(&coor), &coor[1][1]);
                        finalization_of(&des);
                        return 0;
                    }
                }
                
            }
            coor[1][0--];//wt(first)
            coor[0][0++];//bl
        }
        //edit the field
        printf("Finalized! %s capture on %c%d.", "white", finalize(&coor), coor[0][1]);
        finalization_of(&des);
        free(des);
        free(coor);
        exit(EXIT_SUCCESS);
   } 



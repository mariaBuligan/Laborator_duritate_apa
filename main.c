//
//  main.c
//  CHIMIE
//
//  Created by Maria Buligan on 16.04.2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "fct_chimie.h"

int main() {
    int optiune;
    char rasp;
    do{
        afisare_meniu();
        printf("Ce optiune doriti?:");
        scanf("%d",&optiune);
        getchar();
        printf("\n");
        alegere(optiune);
        printf("Doriti sa continuati?(D/N):");
        scanf("%c",&rasp);
        
    } while(rasp=='d' || rasp =='D');

    printf("\n-VA MULTUMIM PENTRU ATENTIE-\n");
    return 0;
}
//4
//3.5 5.1
//8.3 9.9
//13.7 15.5
//15.5 16.9

//3
//16.9 17.2
//17.2 17.4
//17.4 17.6

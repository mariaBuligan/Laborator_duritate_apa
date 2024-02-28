//
//  fct_chimie.c
//  CHIMIE
//
//  Created by Maria Buligan on 16.04.2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "fct_chimie.h"

void afisare_meniu(){
    printf("MENIU:\n");
    printf("1 -> Scopul si principiul lucrarii\n");
    printf("2 -> Modalitatea de lucru prin 'Titrarea cu HCl'\n");
    printf("3 -> Modalitatea de lucru prin 'Metoda conductometrica'\n");
    printf("4 -> Afisare tabel interpretare rezultate\n");
    printf("5 -> Calculul duritatii apei\n");
    printf("6 -> Calculator pentru reactii de combinare\n");
}
void ScopLucrare(){
    printf("În această lucrare se va determina duritatea temporară a apei.Duritatea apei se măsoară în grade de duritate (germane - dH, franceze - TH, engleze - e, americane...= şi în mE/L (miliechivalenţi/litru de apă). În România se foloseşte gradul de duritate german (dH)\n.Carbonaţii acizi sau bicarbonaţii au un caracter bazic (baze slabe). Prin reacţia cu un acid tare (HCl), ei se neutralizează formând o sare şi un acid slab, H2CO3, care se descompune în CO2 şi apă.\n");
    
    printf("                                ^        \n");
    printf("Ca(HCO3)2 + 2HCl → CaCl2 + 2CO2 | + 2H2O\n");
    printf("                                ^        \n");
    printf("Mg(HCO3)2 + 2HCl → MgCl2 + 2CO2 | + 2H2O\n");
}

void Modalitate_Titrare(){
    printf("Titrare cu HCl. Se măsoară cu ajutorul unui cilindru gradat un volum de 100 mL de apă de la robinet şi se introduce într-un flacon conic Erlenmyer. Se adaugă 3 ÷ 4 picături de indicator, cu ajutorul “sticluţei picurătoare”, având grijă ca cele două fante de pe gâtul sticluţei şi al dopului să se suprapună.\n Conţinutul flaconului va căpăta culoarea caracteristică indicatorului în mediul respectiv.\n\n");
}

void Modalitate_conductometrica(){
    printf("Se măsoară cu ajutorul cilindrului gradat un volum de 100 mL de apă de la robinet şi se introduce în flaconul Erlenmeyer. Se introduce celula de conductivitate bine spălată cu apă distilată în proba de analizat şi se citeşte conductivitatea soluţiei după fiecare adaos de 0,2 mL soluţie de titrant din biuretă (HCl 0,1 M). Se notează datele obţinute necesare pentru trasarea graficului care descrie dependența conductivitate în funcţie de volumul de titrant. Volumul total de titrant adăugat trebuie să fie cel puţin (a+1) mL.\nSe trasează graficul şi se citeşte volumul de soluţie acidă (a) corespunzător punctului de echivalenţă.\n\n");
}

void Tabel_rezultate(){
    
    printf("Interpretarea rezultatelor se poate face astfel:\n");
    printf("\t <4 dH ........... foarte mica\n");
    printf("\t 4-8 dH ..........  mica\n");
    printf("\t 8-16 dH .......... mijlocie\n");
    printf("\t 16-30 dH ......... dura\n");
    printf("\t >30 dH ........... foarte mica\n");
}

void Calcul_duritate(){
    int k,ml;
    float *Vi,*Vf,*a;
    float ma,d,s=0;
    
    printf("Folositi o proba de 50 de mL sau de 100 de mL?:");
    scanf("%d",&ml);
    printf("Cate probe doriti sa faceti?:");
    scanf("%d",&k);
    
    Vi=(float*)malloc(k*sizeof(float));
    Vf=(float*)malloc(k*sizeof(float));
    a=(float*)malloc(k*sizeof(float));
    
    printf("Introduceti volumul initial si final pentru fiecare proba apoi apasati Enter:\n");
    for(int i=0;i<k;i++){
        scanf("%f %f",&Vi[i],&Vf[i]);
        a[i]=Vf[i]-Vi[i];
        s=s+a[i];
    }
    getchar();
    ma=s/k;
   if(ml==100) d=2.8*ma;
   if(ml==50) d=1.4*ma;
    printf("\nDuritatea este de %f dH in grade de duritate germane.\n",d);
    printf("\t=%f TH grade franceze\n",d*1.7848);
    printf("\t=%f e grade engleze\n",d*1.2522);
    printf("\t=%f mg/L CaCO(3)\n",d*17.848);
    
    if(d<4)printf("=> duritatea este FOARTE MICA");
        else if(d<8)printf("=> duritatea este MICA");
            else if(d<16)printf("=> duritatea este MIJLOCIE");
                else if(d<30)printf("=> duritatea este MARE");
                    else printf("=> duritatea este FOARTE MARE");
    
    printf("\n\n");
}
int cmmdc(int a, int b)
{
    if (b == 0)
        return a;
    return cmmdc(b, a % b);
}

void balance(int a, int b, int c, int d,int *coef1,int *coef2, int *coef3)
{
    int aux;
    if (c % a == 0 && d % b == 0)
    {   *coef1 = c / a;
        *coef2 = d / b;
        *coef3 = 1;
    }
    else
    {
        c*=b;
        d*=a;
        *coef3 = a*b;
        aux=cmmdc(c,cmmdc(d,*coef3));
        *coef1 = c/aux;
        *coef2 = d/aux;
        *coef3 = (*coef3)/aux;
    }
}
int find(char *string)
{
    if((strcmp(string,"O")==0) || (strcmp(string,"H")==0) ||  (strcmp(string,"Cl")==0) || (strcmp(string,"N")==0) || (strcmp(string,"Br")==0) )
        return 2;
    else return 1;
}
void Calculator_reactie()
{
    int x, y;
    int p,q;
    int b1,b2,b3;
    char first[3],second[3];

    printf("Introduceti 2 elemente chimice pentru a forma o rectie de combinare!\n");
    printf("Introduceti primul element!");
    fflush(stdin);
    scanf("%s",first);
    printf("Introduceti valenta pentru %s:",first);
    scanf("%d",&p);
    printf("Introduceti cel de-al doilea element!");
    fflush(stdin);
    scanf("%s",second);
    printf("Introduceti valenta pentru %s:",second);
    fflush(stdin);
    scanf("%d",&q);
    getchar();
    
    int copie_p=p;
    p/=cmmdc(p,q);
    q/=cmmdc(copie_p,q);
    x=find(first);
    y=find(second);
    //printf("\n%d %d %d %d \n",x,y,q,p);
    balance(x, y, q, p,&b1,&b2,&b3);

    if(strcmp(second,"H")==0 || strcmp(first,"O")==0)
        printf("\n%d*%s(%d) + %d*%s(%d) --> %d*%s(%d)%s(%d)\n",b1,first,x,b2,second,y,b3,second,p,first,q);

    else
        printf("\n%d*%s(%d) + %d*%s(%d) --> %d*%s(%d)%s(%d)\n",b1,first,x,b2,second,y,b3,first,q,second,p);

}

void alegere(int opt){
    switch (opt) {
        case 1:
            ScopLucrare();
            break;
        case 2:
            Modalitate_Titrare();
            break;
        case 3:
            Modalitate_conductometrica();
            break;
        case 4:
            Tabel_rezultate();
            break;
        case 5:
            Calcul_duritate();
            break;
        case 6:
            Calculator_reactie();
            break;
        default:
            printf("Va rugam alegeti o optiune regasita in meniu.");
            break;
    }
    
}

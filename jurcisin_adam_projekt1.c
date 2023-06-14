/*
	Meno: Adam Jurcisin
	Predmet: Zaklady Proceduralneho Programovania 2
	Skupina: 53
	Tema: Projekt 1
    IDE: VS Code
    Termin: 20.3.2022
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void funkcia_v(FILE **subor, char **prispevok_pole , char **autor_pole, char **typ_prezentovania_pole, char **cas_prezentovania_pole, char **datum_pole, int *pocet_zaznamov);
void funkcia_o(FILE **subor);
void funkcia_n(FILE **subor, char ***prispevok_pole , char ***autor_pole, char ***typ_prezentovania_pole, char ***cas_prezentovania_pole, char ***datum_pole, int *pocet_zaznamov);
void funkcia_s(char **prispevok_pole , char **autor_pole, char **typ_prezentovania_pole, char **cas_prezentovania_pole, char **datum_pole,int *pocet_zaznamov);
void funkcia_h(char **prispevok_pole , char **autor_pole, char **typ_prezentovania_pole, char **cas_prezentovania_pole, char **datum_pole,int *pocet_zaznamov);
void funkcia_z(char ***prispevok_pole, char ***autor_pole, char ***typ_prezentovania_pole, char *** cas_prezentovania_pole, char ***datum_pole, int *pocet_zaznamov);
void funkcia_p(char ***prispevok_pole, char***autor_pole, char ***typ_prezentovania_pole, char***cas_prezentovania_pole, char ***datum_pole, int *pocet_zaznamov);

int main(){
    char znak, **prispevok_pole = NULL, **autor_pole = NULL, **typ_prezentovania_pole = NULL, **cas_prezentovania_pole = NULL, **datum_pole = NULL;
    FILE *subor = NULL;
    int pocet_zaznamov = 0, zistujeme = 0;

    while(znak != 'k'){
        scanf("%c", &znak);
        switch(znak){
            case 'v':
                funkcia_v(&subor, prispevok_pole, autor_pole, typ_prezentovania_pole, cas_prezentovania_pole, datum_pole, &pocet_zaznamov);
                break;
            case 'o':
                funkcia_o(&subor);
                break;
            case 'n':
                funkcia_n(&subor, &prispevok_pole, &autor_pole, &typ_prezentovania_pole, &cas_prezentovania_pole, &datum_pole, &pocet_zaznamov);
                break;
            case 's':
                funkcia_s(prispevok_pole, autor_pole, typ_prezentovania_pole, cas_prezentovania_pole, datum_pole, &pocet_zaznamov);
                break;
            case 'h':
                funkcia_h(prispevok_pole, autor_pole, typ_prezentovania_pole, cas_prezentovania_pole, datum_pole, &pocet_zaznamov);
                break;
            case 'z':
                funkcia_z(&prispevok_pole, &autor_pole, &typ_prezentovania_pole, &cas_prezentovania_pole, &datum_pole, &pocet_zaznamov);
                break;
            case 'p':
                funkcia_p(&prispevok_pole, &autor_pole, &typ_prezentovania_pole, &cas_prezentovania_pole, &datum_pole, &pocet_zaznamov);    
                break;
            default:
                break;
        }
    }

    //zatvorenie suboru
    if(subor != NULL){
        fclose(subor);  
        subor = NULL;  
    }

    //dealokovanie poli pred ukoncenim programu
    for(int i = 0; i < pocet_zaznamov; i++){
        free(prispevok_pole[i]);
        prispevok_pole[i] = NULL;
        free(autor_pole[i]);
        autor_pole[i] = NULL;
        free(typ_prezentovania_pole[i]);
        typ_prezentovania_pole[i] = NULL;
        free(cas_prezentovania_pole[i]);
        cas_prezentovania_pole[i] = NULL;
        free(datum_pole[i]);
        datum_pole[i] = NULL;
    }
    free(prispevok_pole);
    prispevok_pole = NULL;
    free(autor_pole);
    autor_pole = NULL;
    free(typ_prezentovania_pole);
    typ_prezentovania_pole = NULL;
    free(cas_prezentovania_pole);
    cas_prezentovania_pole = NULL;
    free(datum_pole);
    datum_pole = NULL;

    return 0;
}

void funkcia_v(FILE **subor, char **prispevok_pole , char **autor_pole, char **typ_prezentovania_pole, char **cas_prezentovania_pole, char **datum_pole,int *pocet_zaznamov){
    char precitany_riadok[150];

    //overenie ci bol subor otvoreny
    if(*subor == NULL) {
        *subor = fopen("OrganizacnePodujatia.txt", "r"); //otvorenie suboru
        if(*subor == NULL) { //ak sa subor nepodarilo otvorit
            printf("Neotvoreny subor.\n");
            return;
        }
    }
    
    if(prispevok_pole == NULL){ //ak polia nie su vytvorene
        fseek(*subor, 0, SEEK_SET); //nastavenie kurzoru na zaciatok suboru
        while((fgets(precitany_riadok, 150, *subor)) != NULL){ //citanie 1 riadku kym nie je koniec suboru
            if(precitany_riadok[0] == '\n') continue; //vynechanie prazdnych riadkov
            printf("Nazov prispevku: %s", precitany_riadok);
            fgets(precitany_riadok, 150, *subor);
            printf("Mena autorov: %s", precitany_riadok);
            fgets(precitany_riadok, 150, *subor);
            printf("Typ prezentovania: %s", precitany_riadok);
            fgets(precitany_riadok, 150, *subor);
            printf("Cas prezentovania: %s", precitany_riadok);
            fgets(precitany_riadok, 150, *subor);
            printf("Datum: %s\n", precitany_riadok);
        }
    }
    else if(prispevok_pole != NULL){ //ak su polia vytvorene
        for(int x = 0; x < *pocet_zaznamov;){ //vypisanie udajov z poli 
            printf("Nazov prispevku: %s\n", prispevok_pole[x]);
            printf("Mena autorov: %s\n", autor_pole[x]);
            printf("Typ prezentovania: %s\n", typ_prezentovania_pole[x]);
            printf("Cas prezentovania %s\n", cas_prezentovania_pole[x]);
            printf("Datum: %s\n\n", datum_pole[x++]);
        }
    }
}
void funkcia_o(FILE **subor){
    char **prispevok_pole = NULL, **autor_pole = NULL, **typ_prezentovania_pole = NULL, **cas_prezentovania_pole = NULL, **datum_pole = NULL;
    char precitany_riadok[150];
    char nacitany_datum[8];
    int pocet_zaznamov = 0, pomocna_vymena = 0, *cislo_indexu_UPUD = NULL, *cislo_indexu_PPPD = NULL;
    int indexUPUD = 0, indexPPPD = 0;

    if(*subor == NULL) return; //kontrola ci bol subor otvoreny
    
    //zistenie poctu zaznamov
    fseek(*subor, 0, SEEK_SET);
    while(fgets(precitany_riadok, 150, *subor) != NULL) {
        if(precitany_riadok[0] == '\n') continue; //ignorovanie prazdnych riadkov
        pocet_zaznamov++;
    }
    pocet_zaznamov /= 5;

    //alokovanie pamate poli
    prispevok_pole = (char**) malloc((pocet_zaznamov + 1) * sizeof(char*));
    autor_pole = (char**) malloc((pocet_zaznamov + 1) * sizeof(char*));
    typ_prezentovania_pole = (char**) malloc((pocet_zaznamov + 1) * sizeof(char*));
    cas_prezentovania_pole = (char**) malloc((pocet_zaznamov + 1) * sizeof(char*));
    datum_pole = (char**) malloc((pocet_zaznamov + 1) * sizeof(char*));

    for(int j = 0; j < (pocet_zaznamov + 1); j++){
        prispevok_pole[j] = (char *)calloc(151, sizeof(char));
        autor_pole[j] = (char *)calloc(101, sizeof(char));
        typ_prezentovania_pole[j] = (char *)calloc(3, sizeof(char));
        cas_prezentovania_pole[j] = (char *)calloc(5, sizeof(char));
        datum_pole[j] = (char *)calloc(9, sizeof(char));
    }
    fseek(*subor, 0, SEEK_SET); //nastavenie kurzoru na zaciatok suboru

    //cyklus na nacitanie udajov do pola podla poctu zaznamov
    for(int i = 0; i < pocet_zaznamov + 1; i++){ 
        fgets(precitany_riadok, 150, *subor);
        if((precitany_riadok[strlen(precitany_riadok) - 1]) == '\n') precitany_riadok[strlen(precitany_riadok) - 1] = '\0'; //odstranenie znakov noveho riadku
        strcpy(prispevok_pole[i], precitany_riadok);

        fgets(precitany_riadok, 150, *subor);
        if((precitany_riadok[strlen(precitany_riadok) - 1]) == '\n') precitany_riadok[strlen(precitany_riadok) - 1] = '\0'; //odstranenie znakov noveho riadku
        strcpy(autor_pole[i], precitany_riadok);

        fgets(precitany_riadok, 150, *subor);
        if((precitany_riadok[strlen(precitany_riadok) - 1]) == '\n') precitany_riadok[strlen(precitany_riadok) - 1] = '\0'; //odstranenie znakov noveho riadku
        strcpy(typ_prezentovania_pole[i], precitany_riadok);
        
        fgets(precitany_riadok, 150, *subor);
        if((precitany_riadok[strlen(precitany_riadok) - 1]) == '\n') precitany_riadok[strlen(precitany_riadok) - 1] = '\0'; //odstranenie znakov noveho riadku
        strcpy(cas_prezentovania_pole[i], precitany_riadok);

        fgets(precitany_riadok, 150, *subor);
        if((precitany_riadok[strlen(precitany_riadok) - 1]) == '\n') precitany_riadok[strlen(precitany_riadok) - 1] = '\0'; //odstranenie znakov noveho riadku
        strcpy(datum_pole[i], precitany_riadok);

        fgets(precitany_riadok, 150, *subor); //nacitanie prazdneho riadku, ktory nikde neulozime
    }

    scanf("%s", &nacitany_datum); //nacitanie hladaneho datumu

    //vytvorenie poli na ukladanie pozicii z pola typov
    cislo_indexu_UPUD = (int *)calloc((pocet_zaznamov + 1), sizeof(int));
    cislo_indexu_PPPD = (int *)calloc((pocet_zaznamov + 1), sizeof(int));
       
    //cyklus na zistenie pozicii v poli typov 
    for(int m = 0; m < pocet_zaznamov; m++){
        //zhoda datumu
        if(strcmp(datum_pole[m], nacitany_datum) == 0){
            //zhoda typu prezentovania
            if((strcmp(typ_prezentovania_pole[m], "UP") == 0) || (strcmp(typ_prezentovania_pole[m], "UD") == 0)){
                cislo_indexu_UPUD[indexUPUD] = m; //ulozenie pozicie v poli typu prezentovania 
                indexUPUD++; //inkrementovanie poctu zhodnych vysledkov
            }
            //zhoda typu prezentovania
            else if((strcmp(typ_prezentovania_pole[m], "PP") == 0) || (strcmp(typ_prezentovania_pole[m], "PD") == 0)){
                cislo_indexu_PPPD[indexPPPD] = m; //ulozenie pozicie v poli typu prezentovania
                indexPPPD++; //inkrementovanie poctu zhodnych vysledkov
            }
        }
    }

    //cyklus na prehodenie pozicii v poli cisel indexov od najmensich casov podla metody bubble sort
    for(int k = 0; k < indexUPUD; k++){
        for(int l = 0; l < (indexUPUD - k - 1); l++){
            if(atoi(cas_prezentovania_pole[cislo_indexu_UPUD[l]]) > atoi(cas_prezentovania_pole[cislo_indexu_UPUD[l + 1]])){
                pomocna_vymena = cislo_indexu_UPUD[l];
                cislo_indexu_UPUD[l] = cislo_indexu_UPUD[l + 1];
                cislo_indexu_UPUD[l + 1] = pomocna_vymena;   
            }
        }
    }
    //cyklus na prehodenie pozicii v poli cisel indexov od najmensich casov podla metody bubble sort
    for(int g = 0; g < indexPPPD; g++){
        for(int h = 0; h < (indexPPPD - g - 1); h++){
            if(atoi(cas_prezentovania_pole[cislo_indexu_PPPD[h]]) > atoi(cas_prezentovania_pole[cislo_indexu_PPPD[h + 1]])){
                pomocna_vymena = cislo_indexu_PPPD[h];
                cislo_indexu_PPPD[h] = cislo_indexu_PPPD[h + 1];
                cislo_indexu_PPPD[h + 1] = pomocna_vymena;   
            }
        }
    }

    //vypis
    for(int y = 0; y < indexUPUD; y++){
        printf("%s\t%s\t%s\t%s\n", cas_prezentovania_pole[cislo_indexu_UPUD[y]], typ_prezentovania_pole[cislo_indexu_UPUD[y]], autor_pole[cislo_indexu_UPUD[y]], prispevok_pole[cislo_indexu_UPUD[y]]);
    }
    printf("\n");
    for(int y = 0; y < indexPPPD; y++){
        printf("%s\t%s\t%s\t%s\n", cas_prezentovania_pole[cislo_indexu_PPPD[y]], typ_prezentovania_pole[cislo_indexu_PPPD[y]], autor_pole[cislo_indexu_PPPD[y]], prispevok_pole[cislo_indexu_PPPD[y]]);
    }

    //uvolnenie pamate
    for(int x = 0; x < pocet_zaznamov + 1; x++){
        free(prispevok_pole[x]);
        free(autor_pole[x]);
        free(typ_prezentovania_pole[x]);
        free(cas_prezentovania_pole[x]);
        free(datum_pole[x]);
        prispevok_pole[x] = NULL;
        autor_pole[x] = NULL;
        typ_prezentovania_pole[x] = NULL;
        cas_prezentovania_pole[x] = NULL;
        datum_pole[x] = NULL;
    }
    free(cislo_indexu_PPPD);
    free(cislo_indexu_UPUD);
    free(prispevok_pole);
    free(autor_pole);
    free(typ_prezentovania_pole);
    free(cas_prezentovania_pole);
    free(datum_pole);
    datum_pole = NULL;
    cas_prezentovania_pole = NULL;
    typ_prezentovania_pole = NULL;
    autor_pole = NULL;
    prispevok_pole = NULL;
    cislo_indexu_PPPD = NULL;
    cislo_indexu_UPUD = NULL;
}
void funkcia_n(FILE **subor, char ***prispevok_pole , char ***autor_pole, char ***typ_prezentovania_pole, char ***cas_prezentovania_pole, char ***datum_pole,int *pocet_zaznamov){
    char precitany_riadok[150];

    //overenie ci bol subor otvoreny
    if(*subor == NULL){
        printf("Neotvoreny subor.\n");
        return;
    }
    *pocet_zaznamov = 0;
    fseek(*subor, 0, SEEK_SET); //nastavenie kurzoru na zaciatok suboru

    //zistenie poctu zaznamov
    while(fgets(precitany_riadok, 150, *subor) != NULL) {
        if(precitany_riadok[0] == '\n') continue; //ignorovanie prazdnych riadkov
        (*pocet_zaznamov)++;
    }
    *pocet_zaznamov /= 5;
    fseek(*subor, 0, SEEK_SET); //nastavenie kurzoru na zaciatok suboru

    //dealokovanie poli pred novym zapisom
    if((*prispevok_pole) != NULL){ 
        //dealokovanie poli
        for(int i = 0; i <= *pocet_zaznamov; i++){
            free((*prispevok_pole)[i]);
            (*prispevok_pole)[i] = NULL;
            free((*autor_pole)[i]);
            (*autor_pole)[i] = NULL;
            free((*typ_prezentovania_pole)[i]);
            (*typ_prezentovania_pole)[i] = NULL;
            free((*cas_prezentovania_pole)[i]);
            (*cas_prezentovania_pole)[i] = NULL;
            free((*datum_pole)[i]);
            (*datum_pole)[i] = NULL;
        }
        free((*prispevok_pole));
        (*prispevok_pole) = NULL;
        free((*autor_pole));
        (*autor_pole) = NULL;
        free((*typ_prezentovania_pole));
        (*typ_prezentovania_pole) = NULL;
        free((*cas_prezentovania_pole));
        (*cas_prezentovania_pole) = NULL;
        free((*datum_pole));
        (*datum_pole) = NULL;
    }

    //alokovanie poli
    (*prispevok_pole) = (char**) malloc((*pocet_zaznamov + 1) * sizeof(char*));
    (*autor_pole) = (char**) malloc((*pocet_zaznamov + 1) * sizeof(char*));
    (*typ_prezentovania_pole) = (char**) malloc((*pocet_zaznamov + 1) * sizeof(char*));
    (*cas_prezentovania_pole) = (char**) malloc((*pocet_zaznamov + 1) * sizeof(char*));
    (*datum_pole) = (char**) malloc((*pocet_zaznamov + 1) * sizeof(char*));
    
    for(int j = 0; j < *pocet_zaznamov; j++){
        (*prispevok_pole)[j] = (char *)calloc(151, sizeof(char));
        (*autor_pole)[j] = (char *)calloc(101, sizeof(char));
        (*typ_prezentovania_pole)[j] = (char *)calloc(3, sizeof(char));
        (*cas_prezentovania_pole)[j] = (char *)calloc(5, sizeof(char));
        (*datum_pole)[j] = (char *)calloc(9, sizeof(char));
    }

    //cyklus na nacitanie udajov do pola podla poctu zaznamov
    for(int i = 0; i < *pocet_zaznamov; i++){ 
        fgets(precitany_riadok, 150, *subor);
        if((precitany_riadok[strlen(precitany_riadok) - 1]) == '\n') precitany_riadok[strlen(precitany_riadok) - 1] = '\0'; //odstranenie znakov noveho riadku
        strcpy((*prispevok_pole)[i], precitany_riadok);

        fgets(precitany_riadok, 150, *subor);
        if((precitany_riadok[strlen(precitany_riadok) - 1]) == '\n') precitany_riadok[strlen(precitany_riadok) - 1] = '\0'; //odstranenie znakov noveho riadku
        strcpy((*autor_pole)[i], precitany_riadok);

        fgets(precitany_riadok, 150, *subor);
        if((precitany_riadok[strlen(precitany_riadok) - 1]) == '\n') precitany_riadok[strlen(precitany_riadok) - 1] = '\0'; //odstranenie znakov noveho riadku
        strcpy((*typ_prezentovania_pole)[i], precitany_riadok);
        
        fgets(precitany_riadok, 150, *subor);
        if((precitany_riadok[strlen(precitany_riadok) - 1]) == '\n') precitany_riadok[strlen(precitany_riadok) - 1] = '\0'; //odstranenie znakov noveho riadku
        strcpy((*cas_prezentovania_pole)[i], precitany_riadok);

        fgets(precitany_riadok, 150, *subor);
        if((precitany_riadok[strlen(precitany_riadok) - 1]) == '\n') precitany_riadok[strlen(precitany_riadok) - 1] = '\0'; //odstranenie znakov noveho riadku
        strcpy((*datum_pole)[i], precitany_riadok);

        fgets(precitany_riadok, 150, *subor); //nacitanie prazdneho riadku, ktory nikde neulozime
    }
    printf("Nacitane data.\n\n");
}
void funkcia_s(char **prispevok_pole , char **autor_pole, char **typ_prezentovania_pole, char **cas_prezentovania_pole, char **datum_pole,int *pocet_zaznamov){
    int nacitany_datum = 0;
    char nacitany_typ[3];
    memset(nacitany_typ, 0, 3); //nastavenie nul do pola znakov
    int zaznam_existuje = 0;

    //kontrola ci boli polia vytvorene
    if(prispevok_pole == NULL){
        printf("Polia nie su vytvorene.\n");
        return;
    }

    scanf("%d %s", &nacitany_datum, &nacitany_typ); //nacitanie udajov

    for(int i = 0; i < *pocet_zaznamov; i++){
        //ak sa datum a typ prezentovania zhoduju vypise potrebne informacie
        if((atoi(datum_pole[i]) == nacitany_datum) && (strcmp(nacitany_typ, typ_prezentovania_pole[i]) == 0)){
            printf("%s\t%s\t%s\n", cas_prezentovania_pole[i], autor_pole[i], prispevok_pole[i]);
            zaznam_existuje = 1;
        }
    }

    //zhoda sa nenasla
    if(zaznam_existuje == 0){
        printf("Pre dany vstup neexistuju zaznamy.\n");
    }
}
void funkcia_h(char **prispevok_pole , char **autor_pole, char **typ_prezentovania_pole, char **cas_prezentovania_pole, char **datum_pole,int *pocet_zaznamov){
    int pocet_UP = 0, pocet_UD = 0, pocet_PP = 0, pocet_PD = 0, typ = 1, opakovanie = 0;
    int hladany_cas_min = 0, hladany_cas_max = 0;
    char hladany_cas_string[15];

    if(prispevok_pole == NULL){ //kontrola ci boli polia vytvorene
        printf("Polia nie su vytvorene.\n");
        return;
    }

    printf("  hodina\t\tUP\tUD\tPP\tPD\n");

    //cyklus na zistovanie podla jednotlivych casovych usekov
    while(typ < 7){

        //cyklus, opakujuci sa podla poctu zaznamov
        for(int i = 0; i < *pocet_zaznamov; i++){

            //priaradenie inych casovych limitov
            if(typ == 1) {strcpy(hladany_cas_string, "08:00 - 09:59 :"); hladany_cas_min = 800; hladany_cas_max = 959;}
            else if(typ == 2) {strcpy(hladany_cas_string, "10:00 - 11:59 :"); hladany_cas_min = 1000; hladany_cas_max = 1159;}
            else if(typ == 3) {strcpy(hladany_cas_string, "12:00 - 13:59 :"); hladany_cas_min = 1200; hladany_cas_max = 1359;}
            else if(typ == 4) {strcpy(hladany_cas_string, "14:00 - 15:59 :"); hladany_cas_min = 1400; hladany_cas_max = 1559;}
            else if(typ == 5) {strcpy(hladany_cas_string, "16:00 - 17:59 :"); hladany_cas_min = 1600; hladany_cas_max = 1759;}
            else if(typ == 6) {strcpy(hladany_cas_string, "18:00 - 19:59 :"); hladany_cas_min = 1800; hladany_cas_max = 1959;}

            //ak cas pola splna casove limity
            if((atoi(cas_prezentovania_pole[i]) >= hladany_cas_min) && (atoi(cas_prezentovania_pole[i]) <= hladany_cas_max)){
                //porovnavanie typu prezentovania, ak su si rovne, inkrementuje pocet
                if(strcmp(typ_prezentovania_pole[i],"UP") == 0) pocet_UP++;
                if(strcmp(typ_prezentovania_pole[i],"UD") == 0) pocet_UD++;
                if(strcmp(typ_prezentovania_pole[i],"PP") == 0) pocet_PP++;
                if(strcmp(typ_prezentovania_pole[i],"PD") == 0) pocet_PD++;
            }
        }

        //vypis jedneho casoveho useku
        printf("%s\t\t%d\t%d\t%d\t%d\n", hladany_cas_string, pocet_UP, pocet_UD, pocet_PP, pocet_PD);
        
        typ++;

        //vynulovanie poctov pre nasledne casove limity
        pocet_UP = 0;
        pocet_UD = 0;
        pocet_PP = 0;
        pocet_PD = 0;
    }
}
void funkcia_z(char ***prispevok_pole, char ***autor_pole, char ***typ_prezentovania_pole, char *** cas_prezentovania_pole, char ***datum_pole, int *pocet_zaznamov){
    char odstranenie_zaznamu[150];
    int pocet_vymazanych_zaznamov = 0;

    //ak polia nie su vytvorene
    if(*prispevok_pole == NULL){
        printf("Polia nie su vytvorene\n");
        return;
    }
    getc(stdin); //zachytenie nevhodneho znaku z main slucky
    fgets(odstranenie_zaznamu, 150, stdin); //nacitanie nazvu prispevku ktory chceme odstranit

    //odstranenie znaku noveho riadku na konci stringu
    if(odstranenie_zaznamu[strlen(odstranenie_zaznamu) - 1] == '\n') odstranenie_zaznamu[strlen(odstranenie_zaznamu) - 1] = '\0'; //odstranenie znaku noveho riadku na konci zadaneho zaznamu

    for(int i = 0; i < *pocet_zaznamov;i++){
        //porovnanie nacitaneho nazvu a nazvov z poli 
        if(strcmp(odstranenie_zaznamu, (*prispevok_pole)[i]) == 0){
            pocet_vymazanych_zaznamov++; 
            (*pocet_zaznamov) -= 1;
            for(int x = i; x < *pocet_zaznamov; x++){
                //v pripade ze sa zhoduje nacitanie priradime aktualnemu prvku pola nasledujuci prvok
                strcpy((*prispevok_pole)[x], (*prispevok_pole)[x + 1]);
                strcpy((*autor_pole)[x], (*autor_pole)[x + 1]);
                strcpy((*typ_prezentovania_pole)[x], (*typ_prezentovania_pole)[x + 1]);
                strcpy((*cas_prezentovania_pole)[x], (*cas_prezentovania_pole)[x + 1]);
                strcpy((*datum_pole)[x], (*datum_pole)[x + 1]);
            }
            //ak sa po posune stale nachadza na danej pozicii zhodny nazov na odstranenie, premenna i sa pri nasledujucej iteracii nezvacsi a vykona posun znova
            if(strcmp(odstranenie_zaznamu, (*prispevok_pole)[i]) == 0) i--;
        }
    }

    //realokacia poli a uvolnenia pamate 
    for(int j = *pocet_zaznamov + pocet_vymazanych_zaznamov; j > *pocet_zaznamov + 1; j--){
        free((*prispevok_pole)[j]);
        free((*autor_pole)[j]);
        free((*typ_prezentovania_pole)[j]);
        free((*cas_prezentovania_pole)[j]);
        free((*datum_pole)[j]);    
        (*prispevok_pole)[j] = NULL;
        (*typ_prezentovania_pole)[j] = NULL;
        (*autor_pole)[j] = NULL;
        (*cas_prezentovania_pole)[j] = NULL;
        (*datum_pole)[j] = NULL;
    }
    (*prispevok_pole) = (char**)realloc((*prispevok_pole), (*pocet_zaznamov) * sizeof(char *));
    (*autor_pole) = (char**)realloc((*autor_pole), (*pocet_zaznamov) * sizeof(char *));
    (*typ_prezentovania_pole) = (char**)realloc((*typ_prezentovania_pole), (*pocet_zaznamov) * sizeof(char *));
    (*cas_prezentovania_pole) = (char**)realloc((*cas_prezentovania_pole), (*pocet_zaznamov) * sizeof(char *));
    (*datum_pole) = (char**)realloc((*datum_pole), (*pocet_zaznamov) * sizeof(char *));

    //vypis poctu vymazanych zaznamov
    printf("Vymazalo sa: %d", pocet_vymazanych_zaznamov);
    if(pocet_vymazanych_zaznamov == 0 || pocet_vymazanych_zaznamov > 4) printf(" zaznamov!\n");
    else if(pocet_vymazanych_zaznamov == 1) printf(" zaznam!\n");
    else if(pocet_vymazanych_zaznamov  == 2 || pocet_vymazanych_zaznamov == 3 || pocet_vymazanych_zaznamov == 4) printf(" zaznamy!\n");
}
void funkcia_p(char ***prispevok_pole, char***autor_pole, char ***typ_prezentovania_pole, char***cas_prezentovania_pole, char ***datum_pole, int *pocet_zaznamov){
    char pridany_zaznam[150];
    if((*prispevok_pole) == NULL){
        printf("Polia nie su vytvorene\n");
        return;
    }   

    (*pocet_zaznamov) += 1; //pripocitanie noveho zaznamu

    //realokovanie poli
    (*prispevok_pole) = (char **)realloc((*prispevok_pole), (*pocet_zaznamov + 1) * sizeof(char*));
    (*autor_pole) = (char **)realloc((*autor_pole), (*pocet_zaznamov + 1) * sizeof(char*));
    (*typ_prezentovania_pole) = (char **)realloc((*typ_prezentovania_pole), (*pocet_zaznamov + 1) * sizeof(char*));
    (*cas_prezentovania_pole) = (char **)realloc((*cas_prezentovania_pole), (*pocet_zaznamov + 1) * sizeof(char*));
    (*datum_pole) = (char **)realloc((*datum_pole), (*pocet_zaznamov + 1) * sizeof(char*));

    (*prispevok_pole)[*pocet_zaznamov] = (char *)malloc(151 * sizeof(char));
    (*autor_pole)[*pocet_zaznamov] = (char *)malloc(101 * sizeof(char));
    (*typ_prezentovania_pole)[*pocet_zaznamov] = malloc(3 * sizeof(char));
    (*cas_prezentovania_pole)[*pocet_zaznamov] = malloc(5 * sizeof(char));
    (*datum_pole)[*pocet_zaznamov] = malloc(9 * sizeof(char));
    
    //pridanie noveho zaznamu do pola
    getc(stdin); //zachytenie nevhodneho znaku z main slucky
    fgets(pridany_zaznam, 150, stdin); //zapis noveho zaznamu
    if((pridany_zaznam[strlen(pridany_zaznam) - 1]) == '\n') pridany_zaznam[strlen(pridany_zaznam) - 1] = '\0'; //odstranenie znaku noveho riadku na konci zadaneho zaznamu
    strcpy((*prispevok_pole)[(*pocet_zaznamov) - 1], pridany_zaznam); //vlozenie noveho zaznamu do pola    
    fgets(pridany_zaznam, 150, stdin); //zapis noveho zaznamu
    if((pridany_zaznam[strlen(pridany_zaznam) - 1]) == '\n') pridany_zaznam[strlen(pridany_zaznam) - 1] = '\0'; //odstranenie znaku noveho riadku na konci zadaneho zaznamu
    strcpy((*autor_pole)[(*pocet_zaznamov) - 1], pridany_zaznam); //vlozenie noveho zaznamu do pola
    fgets(pridany_zaznam, 150, stdin); //zapis noveho zaznamu
    if((pridany_zaznam[strlen(pridany_zaznam) - 1]) == '\n') pridany_zaznam[strlen(pridany_zaznam) - 1] = '\0'; //odstranenie znaku noveho riadku na konci zadaneho zaznamu
    strcpy((*typ_prezentovania_pole)[(*pocet_zaznamov) - 1], pridany_zaznam); //vlozenie noveho zaznamu do pola
    fgets(pridany_zaznam, 150, stdin); //zapis noveho zaznamu
    if((pridany_zaznam[strlen(pridany_zaznam) - 1]) == '\n') pridany_zaznam[strlen(pridany_zaznam) - 1] = '\0'; //odstranenie znaku noveho riadku na konci zadaneho zaznamu
    strcpy((*cas_prezentovania_pole)[(*pocet_zaznamov) - 1], pridany_zaznam); //vlozenie noveho zaznamu do pola
    fgets(pridany_zaznam, 150, stdin); //zapis noveho zaznamu
    if((pridany_zaznam[strlen(pridany_zaznam) - 1]) == '\n') pridany_zaznam[strlen(pridany_zaznam) - 1] = '\0'; //odstranenie znaku noveho riadku na konci zadaneho zaznamu
    strcpy((*datum_pole)[(*pocet_zaznamov) - 1], pridany_zaznam); //vlozenie noveho zaznamu do pola

    printf("Zaznam sa podarilo pridat\n");
}

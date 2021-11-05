#include <stdlib.h> 
#include <stdio.h> 
#include <string.h> 
 
 
void contaCaratteri(char stringa[100][100], int lunghezza,char carattere ,int * num) 
{ 
    for(int j = 0; j < lunghezza ; j++) 
    { 
        for(int i = 0; i < strlen(stringa[j]) ; i++){ 
            if(stringa[j][i] == carattere) 
                ++(*num) ; 
        } 
    } 
} 
 
void contaStringhe(char stringa[100][100], int lunghezza, char * parola ,int * num) 
{ 
    for(int j = 0; j < lunghezza ; j++){ 
        if(strcmp(stringa[j], parola) == 0) 
            ++(*num) ; 
         
    }     
} 
 
void scriviOutput(char * argv[], char * stringa ,int num){ 
    FILE* stream; 
     
    if((stream = fopen(argv[2], "w")) == NULL){ 
        printf("Errore nell'apertura del file output\n"); 
        exit(4); 
    } 
    
    if(num == 0){
        fprintf(stream, "La ricerca non ha prodotto risultati");
    }
    else{
        fprintf(stream,"%s", stringa);          
    }
                     
    fclose(stream); 
} 
 
 
int main(int argc, char * argv[]){ 
    FILE* stream; 
    char  stringa[100][100];  
    int numParole = 0; 
    char str[100]; 
    int num = 0; 
 
    if (argc != 5){ 
        printf("Argomenti errati\n"); 
        exit(1);     
    } 
     
    if(argv[3][1] != 'c' && argv[3][1] != 'p'){ 
        printf("Metodo errato\n"); 
        exit(2); 
    } 
     
    //apro stream input 
         
    if((stream = fopen(argv[1], "r")) == NULL){ 
        printf("Errore nell'apertura del file input\n"); 
        exit(3); 
    }     
         
    //prelevo stringa da  stream input 

    while(!feof(stream)){
        fscanf((stream), "%s\t", stringa[numParole]);
        numParole++;
    }
 
    fclose(stream); 
                     
     
         
    switch(argv[3][1]){ 
        case 'c' :  
            contaCaratteri(stringa, numParole, argv[4][0] ,&num); 
            sprintf(str, "Il carattere %c compare %d volte", argv[4][0], num); 
            scriviOutput(argv, str, num); 
            break; 
        case 'p' : 
            contaStringhe(stringa, numParole , argv[4], &num); 
            sprintf(str, "la stringa %s compare %d volte", argv[4], num); 
            scriviOutput(argv, str, num); 
            break; 
    } 
 
    return 0; 

}

//le projet realiser par : mohamed ennakri GI-2024 
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <windows.h>
#include <conio.h>
#define FILE_NAME "scores.txt"
#define KEY_UP 72
#define KEY_DOWN 80
#define ENTER_KEY 13
	  char password[20];
    char ch;
typedef struct {
    char nome[50];
    int score;
} Joueur;
 const char *nomesFileName = "nomes.txt";
    const char *scoresFileName = "scores.txt";
void Color(int couleurDuTexte,int couleurDeFond)
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
// Fonction pour afficher le menu avec l'option sélectionnée en surbrillance
void afficherMenu(const char* options[], int currentSelection, int numberOfOptions) {
   system("cls");
   Color(12,0);
   printf("\n\n\n\n\n\t\t\t\t  /***********************************************/\n"
    "\t\t\t\t  |                    MENU                       |\n"
    "\t\t\t\t  |===============================================|\n"
	"\t\t\t\t  |                                               |\n");
    for (int i = 0; i < numberOfOptions; i++) {
        if (i == currentSelection) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY);
        } else {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        }
        printf("%s\n", options[i]);
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // Remet la couleur par défaut
    printf( 
	 "\t\t\t\t  |                                               |\n"
    "\t\t\t\t /************************************************/\n");
    Color(15,0);
	    printf("\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t  COPYRIGHT_BY_GR8_FILALI");
}

// Fonction pour faire une animation de chargement
void animationLoading() {
    printf("\n\t\t\t\t\t\tChargement..");
    for (int i = 0; i < 10; ++i) {
        printf(".");
        Sleep(500); // Délai de 0.5 secondes
    }
    printf("\n");
}
int i,j,bp,tentative=1,mp,T[5],U[5],joker,position;
char jouer2;
void monScore(char *nomJoueur, int score) {
FILE *nomeFichier, *scoresFichier;
  nomeFichier= fopen("nomes.txt", "w");
 scoresFichier= fopen("scores.txt", "w");
if ( nomeFichier == NULL && scoresFichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier de scores\n");
    } else {
        fprintf(nomeFichier, "%s ", nomJoueur);
        fprintf(scoresFichier, "%d essais\n",score);
        fclose(nomeFichier);
        fclose(scoresFichier);
}

  }
void meilleurscore(const char *nomesFileName, const char *scoresFileName) {
    FILE *nomeFichier = fopen(nomesFileName, "r");
    FILE *scoresFichier = fopen(scoresFileName, "r");

    if (nomeFichier == NULL &&scoresFichier == NULL) {
        printf("Erreur lors de la lecture des fichiers.\n");
        return;
    }

    int mScore = 100;
    char mName[50];
    char nome[50];
    int score;

    while (fscanf(scoresFichier, "%d", &score) == 1) {
        if (score < mScore) {
            mScore = score;
            
            if (fscanf(nomeFichier, "%49s", nome) == 1) { 
                strcpy(mName, nome);
            }
        } else {
            
            fscanf(nomeFichier, "%*s");
        }
    }

    fclose(nomeFichier);
    fclose(scoresFichier);

    if (mScore != 100) {
    
    	char mscore[] = "\n\n\t\t\t\t\tMEILLEUR SCORE : \n";
      for (i = 0; i < strlen(mscore); i++)
        {
        printf("%c", mscore[i]);

        Sleep(50);
      }
    	printf("\t\t\t\t ________________________\n");
    	printf("\t\t\t\t|            |           |  \n");
    	printf("\t\t\t\t|    NAME    |   SCORE   |  \n");
        printf("\t\t\t\t|____________|___________|  \n");
    	printf("\t\t\t\t|            |           |  \n");
    	printf("\t\t\t\t|            |           |  \n");
    	printf("\t\t\t\t|  %s       :    %d      |\n",mName,mScore);
    	printf("\t\t\t\t|            |           |  \n");
    	printf("\t\t\t\t|____________|___________|  \n");
    	
    	
//       , mScore, mName);
    } else {
        printf("Aucun score enregistré.\n");
    }
}
void deviner (int U[5]){

char devinez[] = "DEVINEZ LES NOMBRES TENTATIVE ";
    for (i = 0; i < strlen(devinez); i++)
    {
       printf("%c", devinez[i]);
        Sleep(50);
    }
              printf("%d : \n",tentative);
		for(j=0;j<5;j++){
		printf("entrer le nombre %d:",j+1);
		scanf("%d",&U[j]);
    }
    mp=0;
    bp=0;

    for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(T[i]==U[j] && i==j) {
	     	bp++;
	        U[j]=-1;
	        j=5;
            }else{ if(T[i]==U[j] && i!=j){ mp++;
                                           U[j]=-1;
                                         break;}
		    }
		}}

    

      if (bp != 0){
      	
	  	  Color (10,15);  
	  	  puts("");
		    printf("  %d BIEN  PLACEES ",bp);
			puts("");}
		if ( mp != 0 ) {
		    Color (12,15);
		    puts("");
		    printf("  %d MAL PLACEES ",mp);
			puts(""); }
if (bp == 0  && mp == 0) printf("LES NOMBRES N'EXCISTENT PAS ! \n");
		    
	tentative++;

    
if (bp == 5) {
	Color(0,10);
	system("cls");
		printf("\n\n\n\n");
printf("\t\t\xdb\xdb     \xdb\xdb      \xdb\xdb\xdb\xdb\xdb\xdb\xdb       \xdb\xdb       \xdb\xdb           \xdb\xdb          \xdb\xdb      \xdb\xdb\xdb\xdb\xdb\xdb     \xdb\xdb\xdb       \xdb\xdb\n");
printf("\t\t \xdb\xdb   \xdb\xdb      \xdb\xdb      \xdb\xdb     \xdb\xdb       \xdb\xdb           \xdb\xdb          \xdb\xdb        \xdb\xdb       \xdb\xdb \xdb\xdb     \xdb\xdb\n");    
printf("\t\t  \xdb\xdb\xdb\xdb\xdb       \xdb\xdb      \xdb\xdb     \xdb\xdb       \xdb\xdb           \xdb\xdb    \xdb\xdb    \xdb\xdb        \xdb\xdb       \xdb\xdb   \xdb\xdb   \xdb\xdb\n"); 
printf("\t\t    \xdb\xdb        \xdb\xdb      \xdb\xdb     \xdb\xdb       \xdb\xdb           \xdb\xdb  \xdb\xdb  \xdb\xdb  \xdb\xdb        \xdb\xdb       \xdb\xdb     \xdb\xdb \xdb\xdb\n"); 
printf("\t\t    \xdb\xdb          \xdb\xdb\xdb\xdb\xdb\xdb         \xdb\xdb\xdb\xdb\xdb\xdb\xdb               \xdb\xdb      \xdb\xdb        \xdb\xdb\xdb\xdb\xdb\xdb     \xdb\xdb       \xdb\xdb\xdb\n");
   printf("\n\t\t\t\t\t\t      .-\"\"\"\"\"\"\"-.\n");
    printf("\t\t\t\t\t\t    .'           '.\n");
    printf("\t\t\t\t\t\t   /   O      O   \\\n");
    printf("\t\t\t\t\t\t  :                :\n");
    printf("\t\t\t\t\t\t  :   .        .   :\n");
    printf("\t\t\t\t\t\t  :    '------'    :\n");
    printf("\t\t\t\t\t\t   \\              /\n");
    printf("\t\t\t\t\t\t    '.          .'\n");
    printf("\t\t\t\t\t\t      '-......-'\n");
    
    printf("\t\t\t\t\t\t _________________________\n");
    printf("\t\t\t\t\t\t|                         |\n");
    printf("\t\t\t\t\t\t|   your score : %d        |\n",tentative-1);
    printf("\t\t\t\t\t\t|_________________________|\n");
    
}
}
	
			char ereure[] = "\n\t\tEREUR VOUS AVEZ NE RESPECT PAS LE NIVEAU QUI CHOISI  ";
void respect(){
	for (i=1;i<5;i++){
	if (T[0] == T[i]){
    for (i = 0; i < strlen(ereure); i++)
    {
     Color(12,0);
        printf("%c", ereure[i]);
        Sleep(50);
   }
   }
}
}



int main() {
     int code_hex = 0xDB;
    const int maxProgress = 50;

Color(13,0);

 char welcomeMessage[] ="\t\tBBBBB     IIIIII   EEEEEEE    N    N    V    V   EEEEEEE   N    N    U    U    EEEEEEE\n\t\tB    B      II     E          NN   N    V    V   E         NN   N    U    U    E      \n\t\tB    B      II     E          N N  N    V    V   E         N N  N    U    U    E      \n\t\tBBBBB       II     EEEEE      N  N N    V    V   EEEEE     N  N N    U    U    EEEEE  \n\t\tB    B      II     E          N   NN     V  V    E         N   NN    U    U    E      \n\t\tB    B      II     E          N    N      VV     E         N    N    U    U    E      \n\t\tBBBBB     IIIIII   EEEEEEE    N    N       V     EEEEEEE   N    N     UUUU     EEEEEEE\n\n\n\n " ; 

    for (i = 0; i < strlen(welcomeMessage); i++)
    {
        printf("%c", welcomeMessage[i]);
        Sleep(1);
    }

	printf("\n");
  Color(12,0);
  printf ("\t\t\t\t\t\tLOADING... \n\n");
for (i = 0; i <= maxProgress; i++) {
    printf("\r\t\t\t\t");
    int na = (i*100)/maxProgress;
    if (na<30){
    	Color(12,0);
	}
	else if (na<70){
		Color(14,0);
	}
	else{
		Color(10,0);
	}
    // Print characters representing progress
    for (int j = 0; j < i; j++) {
        printf("%c", code_hex);
        
    }
     
    // Fill remaining space with something or leave it empty
    for (int j = i; j < maxProgress; j++) {
        printf("");
    }

    // Print the percentage on a separate line
    
    fflush(stdout);
    usleep(100000); // Wait for 100 ms
}
char downloade[] = "\n\n\t\t\t\t\t\tDOWNLOAD COMPLETED !";
 for (i = 0; i < strlen(downloade); i++)
    {
        printf("%c", downloade[i]);

        Sleep(50);

    }
puts("\n\n\n\n\n                      Click any key for PLAY");
  
    getch();
    system("cls");
    const char* options[] = {
    "\t\t\t\t  |                     PLAY                      |  \n",
    "\t\t\t\t  |                     INFO                      | \n",
    "\t\t\t\t  |                  MEILLEUR SCORE               | \n",
    "\t\t\t\t  |                    QUITTER                    | "};
    int currentSelection = 0;
    int numberOfOptions = sizeof(options) / sizeof(options[0]);
    int keyPressed;

    afficherMenu(options, currentSelection, numberOfOptions);

    // Boucle pour gérer les entrées du clavier
    while (1) {
        if (_kbhit()) { // Si une touche est pressée
            keyPressed = _getch(); // Obtient la touche

            // Vérifie les entrées spécifiques des touches fléchées
            if (keyPressed == 224) {
                keyPressed = _getch();

                switch(keyPressed) {
                    case KEY_UP:
                        currentSelection--;
                        if (currentSelection < 0) {
                            currentSelection = numberOfOptions - 1;
                        }
                        break;
                    case KEY_DOWN:
                        currentSelection++;
                        if (currentSelection >= numberOfOptions) {
                            currentSelection = 0;
                        }
                        break;
                }

                afficherMenu(options, currentSelection, numberOfOptions);
            }

            // Si la touche Entrée est pressée
            if (keyPressed == ENTER_KEY) {
                system("cls"); // Nettoie l'écran

                switch(currentSelection) {
                    case 0: // Jouer
             for (i=0;i<1;i++){
			  animationLoading();
                       int k;
            
                       Color(11,0);
        char jouer1[] = "\n\n\t\t ENTRER LE NOM  DE JOUEUR 1 ET TAPER ENTRER POUR CONTINUER --> ";
 for (i = 0; i < strlen(jouer1); i++)
    {
        printf("%c", jouer1[i]);

        Sleep(50);
} gets(jouer1);Color(11,0);
      printf("\n\t\t\tBONJOUR %s !!\n",jouer1);
	char nv;
	char niveau[] = "\n\n\t\t --> VOULEZ-VOUS NIVEAU DEBUTANT (TAPER 1) OU NIVEAU EXPERT (TAPER 2) : ";
 for (i = 0; i < strlen(niveau); i++)
    {
        printf("%c", niveau[i]);
        Sleep(50);
}scanf("%c",&nv);Color(11,0);
if (nv == '1'){
		char niveau1[] = "\n\n\t\t --> tous les chiffres du code sont distincts  ";
 for (i = 0; i < strlen(niveau1); i++)
    {
        printf("%c", niveau1[i]);

        Sleep(50);

}
}

else 	if (nv == '2'){Color(11,0);
		char niveau2[] = "\n\n\t\t -->  les chiffres peuvent se repeter : ";
 for (i = 0; i < strlen(niveau2); i++)
    {
        printf("%c", niveau2[i]);

        Sleep(50);
	} }
	else {Color(11,0);
		char ereur[] = "\n\n\t\t -->LE NIVEAU N'EXISTE PAS ";
 for (i = 0; i < strlen(ereur); i++)
    {
        printf("%c", ereur[i]);

        Sleep(50);
	}
	break;}
	Color(11,0);

	char code[] = "\nENTRE LE CODE \n";
 for (i = 0; i < strlen(code); i++)
    {
        printf("%c", code[i]);

        Sleep(50);}
	for(i=0;i<5;i++){
		printf("entrer le nombre %d : ",i+1);
		scanf("%d",&T[i]);
		}Color(11,15);
if (nv == '1'){
respect();
}
	system("cls");


Color(13,15);

	char jouer2[] = "\n\n\t\t ENTRER LE NOM  DE JOUEUR 2 ET TAPER ENTRER POUR CONTINUER --> ";
 for (i = 0; i < strlen(jouer2); i++)
    {
        printf("%c", jouer2[i]);

        Sleep(50);
}//sans utilise espace  
scanf(" %s",jouer2);
Color(11,15);
printf ("\n\t\tBONJOURE %s !!\n",jouer2);

	do{Color(11,15);
    deviner(U);
	Color(11,15);
     if (tentative >= 10 && tentative<= 17 && !joker) {
            printf("Voulez-vous utiliser le joker? (0-Non, 1-Oui): ");
            int useJoker;
            scanf("%d", &useJoker);
            if (useJoker) {
                printf("Quel position du chiffre voulez-vous reveler? (1-5): ");
                scanf("%d", &position);
                printf("Le chiffre en position %d est %d\n", position, T[position-1]);
                joker = 1;
                tentative += 3;
            }
        }
	}while(bp!=5 && tentative<=20);
	monScore(jouer2,tentative-1);
		if(tentative==21){	
		Color(0,12);
		system("cls");
		printf("\n\n\n\n");
 printf("\t\t\xdb\xdb   \xdb\xdb     \xdb\xdb\xdb\xdb\xdb\xdb     \xdb\xdb      \xdb\xdb               \xdb\xdb             \xdb\xdb\xdb\xdb\xdb        \xdb\xdb\xdb\xdb\xdb\xdb        \xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
    printf("\t\t\xdb\xdb   \xdb\xdb    \xdb\xdb     \xdb\xdb   \xdb\xdb      \xdb\xdb               \xdb\xdb           \xdb\xdb     \xdb\xdb     \xdb\xdb                \xdb\xdb\n");
    printf("\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb    \xdb\xdb     \xdb\xdb   \xdb\xdb      \xdb\xdb               \xdb\xdb           \xdb\xdb     \xdb\xdb       \xdb\xdb\xdb\xdb            \xdb\xdb\n");
    printf("\t\t   \xdb\xdb      \xdb\xdb     \xdb\xdb   \xdb\xdb      \xdb\xdb               \xdb\xdb           \xdb\xdb     \xdb\xdb           \xdb\xdb          \xdb\xdb\n");
    printf("\t\t   \xdb\xdb       \xdb\xdb\xdb\xdb\xdb\xdb       \xdb\xdb\xdb\xdb\xdb\xdb                  \xdb\xdb\xdb\xdb\xdb\xdb        \xdb\xdb\xdb\xdb\xdb       \xdb\xdb\xdb\xdb\xdb\xdb            \xdb\xdb\n");
    printf("\n");
	printf("\t\t\t\t\t\t      .-\"\"\"\"\"\"\"-.\n");
    printf("\t\t\t\t\t\t    .'          '.\n");
    printf("\t\t\t\t\t\t   /   O      O   \\\n");
    printf("\t\t\t\t\t\t  :           `    :\n");
    printf("\t\t\t\t\t\t  :                :\n");
    printf("\t\t\t\t\t\t  :    .------.    :\n");
    printf("\t\t\t\t\t\t   \\  '        '  /\n");
    printf("\t\t\t\t\t\t    '.          .'\n");
    printf("\t\t\t\t\t\t      '-......-'\n");
break;	}
                        // Code pour démarrer le jeu...
                        }break;
                  	 case 1: // Info
                  	 Color(0,15);
                  	 system("cls");
	{	printf("\n\n");
		char INFO[] = "\n\n\t\t\t\t\tPOUR LES INFORMATIONS SUR GAME : \n";
      for (i = 0; i < strlen(INFO); i++)
        {
        printf("%c", INFO[i]);

        Sleep(50);
      }
printf("\t\t\t                                                                          \n");
printf("\t\t\t __________________________________________________________________________\n");
printf("\t\t\t|                                                                          |\n");
printf("\t\t\t|                                                                          |\n");
printf("\t\t\t|                                                                          |\n");
printf("\t\t\t|     > le jeu se compose de deux niveaux (debutant et expert):            |\n");
printf("\t\t\t|           >le niveau debutant: les chiffres sont distincts               |\n");
printf("\t\t\t|           >le niveau expert: les chiffres peuvent se repeter             |\n");
printf("\t\t\t|     >une fois le joeur 1 choisi le niveau il doit                        |\n");
printf("\t\t\t|       proposee un code de 5 chiffres.                                    |\n");
printf("\t\t\t|     > le joeur 2 doit devinez ce code                                    |\n");
printf("\t\t\t|     >le joeur 2 a 20 tentatives pour trouver ce code                     |\n");
printf("\t\t\t|     > de la tentatives 10 jusqu'a 17 vous avez la possibilite            |\n");
printf("\t\t\t|           d'utiliser un joker                                            |\n");         
printf("\t\t\t|     >cette fonction joker vous permet de savoir un nombre de votre choix |\n");
printf("\t\t\t|     >une fois utiliser le joker vous ne pouvez pas l'utiliser autrefois  |\n");
printf("\t\t\t|     > le joker si utiliser vous perte 3 tentatives                       |\n");
printf("\t\t\t|           (tentatives=tentatives+3)                                      |\n");
printf("\t\t\t|                                                                          |\n");
printf("\t\t\t|                                                                          |\n");
printf("\t\t\t|__________________________________________________________________________|\n");}
                        // Code pour afficher les informations du jeu...
                        break;
                    case 2: // Meilleur score
                    Color(6,15);
                    system("cls");
                       meilleurscore(nomesFileName,scoresFileName);
                        // Code pour afficher les meilleurs scores...
                        break;
                    case 3: // Quitter
                        printf("Fin du programme.");
                        return 0;
                }
                 Color(9,15);
                 printf("\n\nAppuyez sur une touche pour revenir au menu.");
                _getch();
                afficherMenu(options, currentSelection, numberOfOptions);
         }
    }   
}
    return 0;
}
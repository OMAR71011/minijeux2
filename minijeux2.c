#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_TENTATIVES 10
#define NOMBRE_MAX 100

void effacer_ecran() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {
    int dev, proposition, essais;
    char reponse[10];
    srand(time(NULL));

    do {
        dev = rand() % NOMBRE_MAX + 1;
        essais = 0;

        printf("====================================================\n");
        printf("        BIENVENUE DANS LE JEU DU NOMBRE MYSTÈRE\n");
        printf("====================================================\n");
        printf("Devinez le nombre entre 1 et %d en moins de %d essais.\n", NOMBRE_MAX, MAX_TENTATIVES);
        printf("Appuyez sur Entrée pour commencer...\n");
        getchar();

        while (essais < MAX_TENTATIVES) {
            essais++;
            effacer_ecran();
            printf("Essai %d sur %d : Entrez votre proposition : ", essais, MAX_TENTATIVES);
            
            if (scanf("%d", &proposition) != 1) {
                printf("Entrée invalide. Veuillez entrer un nombre entier.\n");
                while (getchar() != '\n'); 
                essais--; 
                continue;
            }

            if (proposition < dev) {
                printf("Le nombre %d est plus petit que le nombre mystère.\n", proposition);
            } else if (proposition > dev) {
                printf("Le nombre %d est plus grand que le nombre mystère.\n", proposition);
            } else {
                printf("Félicitations ! Vous avez trouvé le nombre mystère en %d essais.\n", essais);
                break;
            }

            printf("\nAppuyez sur Entrée pour continuer...\n");
            getchar(); getchar(); 
        }

        if (proposition != dev) {
            printf("Désolé, vous n'avez pas trouvé le nombre mystère.\n");
            printf("Le nombre recherché était : %d\n", dev);
        }

        printf("\nSouhaitez-vous rejouer ? (o/n) : ");
        scanf("%s", reponse);
        getchar(); 

        effacer_ecran();

    } while (reponse[0] == 'o' || reponse[0] == 'O');

    printf("Merci d'avoir joué ! À bientôt.\n");
    printf("Ce jeu a été programmé par M. Fall, O. Diop et L. Faye.\n");

    
}

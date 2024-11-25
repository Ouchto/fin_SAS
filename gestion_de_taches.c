#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure pour date d'échéance 
typedef struct 
{
    int jour;
    int mois;
    int anee;
}date;

// Structure representant une tache
typedef struct {
    char titre[100];
    char description[400];
    date tarikh;
    char priorite[10];
} tache;

// Tableau pour stocker les taches
tache taches[100];
int tacheNum = 0;

// Fonction pour creer une tache
void cree_tache() {
    if (tacheNum >= 100) {
        printf("Limite de taches atteinte\n");
    }
    
    printf("Entrez le titre de la tache: ");
    scanf(" %[^\n]", taches[tacheNum].titre);
    printf("Entrez la description de la tache: ");
    scanf(" %[^\n]", taches[tacheNum].description);
    printf("Entrez la date d'echeance (jj/mm/aaaa): \n");
    printf("jour:");
    scanf("%d,",&taches[tacheNum].tarikh.jour);
    printf("mois:");
    scanf("%d",&taches[tacheNum].tarikh.mois);
    printf("anee:");
    scanf("%d",&taches[tacheNum].tarikh.anee);
    printf("Entrez la priorite (high/low): ");
    scanf(" %[^\n]", taches[tacheNum].priorite);
    tacheNum++;
        
    printf("Tache ajoutee avec succes.\n");
}

// Fonction pour afficher la list des taches 
void afficher_tache(){

    if (tacheNum == 0)
    {
        printf("Aucune tache a afficher");
    }

    printf("\nListe des taches : \n");
    for (int i = 0; i < tacheNum; i++){
        printf("\nTache Num %d:\n",i + 1);
        printf("Titre : %s\n",taches[i].titre);
        printf("Description : %s\n",taches[i].description);
        printf("date d'echeance : %d/%d/%d \n",taches[i].tarikh.jour,taches[i].tarikh.mois,taches[i].tarikh.anee);
        printf("Priorite : %s\n",taches[i].priorite);

    }
}








int main() {
    int choix;

    do {
        printf("\n\n============[gestion de taches]============\n\n");
        printf("1. Creer une tache\n\n");
        printf("2. Afficher les taches\n\n");
        printf("3. Modifier une tache\n\n");
        printf("4. Supprimer une tache\n\n");
        printf("5. Filtrer les taches par priorite\n\n");
        printf("6. Quitter\n\n");
        printf("Votre choix : ");
        scanf("%d", &choix);


        switch (choix) {
            case 1:
                cree_tache();
                break;

            default:
                printf("Choix invalide.\n");
                break;
        }
    } while (choix != 6);


    return 0;
}

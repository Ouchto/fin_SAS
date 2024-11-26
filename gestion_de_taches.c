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


// Fonction pour afficher la liste des tàches 

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

// Fonction pour modifier une tache

void modifier_tache(){
    int index;
    printf("Entrez le numero de la tache a modifier : ");
    scanf("%d",&index);
    if(index < 1 || index > tacheNum){
        printf("Numero de tache invalide");
    }
    index--;
    int choix;
    do
    {
        printf("1. Modifier le titre. \n");
        printf("2. Modifier la description. \n");
        printf("3. Modifier la date d'echeance. \n");
        printf("4. Modifier la priorite. \n");
        printf("5. Quitter. \n");
        printf("Entrer votre choix :");
        scanf("%d",&choix);

        switch (choix)
        {
        case 1:
            printf("Modifier le titre : ");
            scanf(" %[^\n]", taches[index].titre);
            break;
        case 2:
            printf("Modifier la description : ");
            scanf(" %[^\n]", taches[index].description);
            break;
        case 3:
            printf("Modifier la date d'echeance : \n");
            printf("jour:");
            scanf("%d",&taches[index].tarikh.jour);
            printf("mois:");
            scanf("%d",&taches[index].tarikh.mois);
            printf("anee:");
            scanf("%d",&taches[index].tarikh.anee);
            break;

        case 4:
            printf("Modifier la priorite : ");
            scanf(" %[^\n]", taches[index].priorite);
            break;
        case  5:
            printf("Tache modifiee avec succes \n");
            break;
        default: 
            printf("choix invalide.");
            break;
        }

    } while (choix != 6);
}

// Fonction pour supprimer une tache 
void supprimer_tache(){
    int index;
    printf("Entrez le numero de la tache a supprimrer : ");
    scanf("%d",&index);
    if (index < 1 || index > tacheNum){
        printf("Numero de tache invalide");
    }
    index--;
    for(int i= index; i < tacheNum - 1; i++){
        taches[i] = taches[i + 1];
    }
    tacheNum--;
    printf("Tache supprimee avec succes \n");
}

// Fonction pour filtrer les taches par priorite
void filtrer_taches(){
    char priorite[10];
    printf("Entrez la priorite pour filtrer (high/low) : ");
    scanf(" %[^\n]", priorite);

    printf("\nTaches avec priorite '%s' : \n",priorite);
    int trouve = 0;
    tache hold[100];
    int holdNum = 0;
    for (int i = 0; i < tacheNum; i++){
        
        if (strcmp(taches[i].priorite, priorite) == 0 )
            {
                hold[holdNum] = taches[i];
                holdNum++;
                trouve = 1;
            }
        
    }
    if (trouve != 1){
            printf("Aucune tache trouvee avec cette priorite.\n");
        }
    for (int j = 0; j <  holdNum; j++)
        {
            printf("\n Tache Num %d \n", j + 1);
            printf("Titre : %s\n", hold[j].titre);
            printf("Description : %s \n",hold[j].description);
            printf("Date d'echeance : %d/%d/%d \n",hold[j].tarikh.jour,hold[j].tarikh.mois,hold[j].tarikh.anee);
            printf("Priorite : %s\n",hold[j].priorite);
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
            case 2:
                afficher_tache();
                break;
            case 3:
                modifier_tache();
                break;
            case 4:
                supprimer_tache();
                break;
            case 5:
                filtrer_taches();
                break;
            case 6:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide.\n");
                break;
        }
    } while (choix != 6);


    return 0;
}

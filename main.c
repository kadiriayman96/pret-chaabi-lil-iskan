#include <stdio.h>
#include <stdbool.h>

const int max_tentatives = 10;
const int duree_min = 5;
const int taux_min = 3;
const int taux_max = 7;

float calculer_mensualite(float montant_pret, float taux_interet, int duree_annees) {

    float taux_interet_mensuel = taux_interet / 12 / 100;
    int duree_mois = duree_annees * 12;
    float mensualite = montant_pret * taux_interet_mensuel / (1 - pow(1 + taux_interet_mensuel, -duree_mois)); // formule pret , taux fixe

    return mensualite;
}

int main() {
    float montant_pret, taux_interet;
    int duree_annees;
    int tentatives = 0;

    while (tentatives < max_tentatives) {
        tentatives++;
        printf("\nTentatives restantes : %d\n", max_tentatives - tentatives + 1);
        printf("-------------------------\n");

        printf("\nEntrez le montant du pret : ");
        scanf("%f", &montant_pret);

        while (montant_pret <= 0) {
            printf("STP entrer un montant positif : ");
            scanf("%f", &montant_pret);
        }

        printf("Entrez le taux d'interet (entre 3 et 7 pourcents) : ");
        scanf("%f", &taux_interet);

        while (taux_interet < taux_min || taux_interet > taux_max) {
            printf("Le taux d'interet doit etre entre 3%% et 7%%. Reessayez : ");
            scanf("%f", &taux_interet);
        }

        printf("Entrez la duree de remboursement (en annees, au moins 5 ans) : ");
        scanf("%d", &duree_annees);

        while (duree_annees < duree_min) {
            printf("La duree doit etre d'au moins 5 ans. Reessayez : ");
            scanf("%d", &duree_annees);
        }

        float mensualite = calculer_mensualite(montant_pret, taux_interet, duree_annees);
        printf("\nMensualite estimee : %.2f\n", mensualite);

        char choix;
        printf("\n-->Souhaitez-vous calculer un autre pret ? (o/n) : ");
        scanf(" %c", &choix);

        if (choix != 'o' && choix != 'O') {
            printf("\nBye Bye ...");
            break;
        }
    }

    if (tentatives >= max_tentatives) {
        printf("\nNombre maximum de tentatives atteint. Bye Bye ...\n");
    }

    return 0;
}

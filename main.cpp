#include "BSTImplemetation.h"

int main(int argc, char const *argv[])
{
    BST bst;
    double value;
    int NBN;
    Node *node;
    double values[] = {2, 21, 4, 26, 5, 10};
    for (double value : values)
    {
        bst.addElement(value);
    }

    // **---------------------- INITIALISATION ------------------------------

    do
    {
        system("cls");
        int choix;
        std::cout << "GESTION D'UNE BST :" << std::endl;
        std::cout << "_--_-_-_-_-_--_-_-_-_-_-_-_-_-_-__-" << std::endl;
        std::cout << "1) ajouter un noeud dons l'arbre.." << std::endl;
        std::cout << "2) supprimer un noeud dons l'arbre.." << std::endl;
        std::cout << "3) modifier un noeud dons l'arbre.." << std::endl;
        std::cout << "4) chercher un noeud dons l'arbre.." << std::endl;
        std::cout << "5) afficher l'arbre toute entier .." << std::endl;
        std::cout << "6) quite .." << std::endl;
        std::cout << "entrer votre choix .." << std::endl;
        std::cin >> choix;
        switch (choix)
        {
        case 1:
            system("cls");
            std::cout << "enter le nombre des noeuds que vous voulez ajouter ";
            std::cin >> NBN;
            for (int index = 0; index < NBN; index++)
            {
                std::cout << "la valeur du noeud [ " << index + 1 << "] ";
                std::cin >> value;
                bst.addElement(value);
            }
            break;

            // **---------------------- L'AJOUT D'UN NEOUD ------------------------

        case 2:
            system("cls");
            std::cout << "enter le noeud que vous voulez supprimer ";
            std::cin >> value;
            bst.removeNode(value);
            break;

            // **---------------------- SUPPRESION D'UN NEOUD ------------------------

        case 3:
            system("cls");
            system("cls");
            std::cout << "enter le noeud que vous voulez modifier ";
            std::cin >> value;
            break;

            // **---------------------- MODIFICATION D'UN NEOUD ------------------------

        case 4:
            system("cls");
            std::cout << "enter le noeud que vous voulez rechercher ";
            std::cin >> value;
            node = bst.getNode(value);
            if (node != nullptr)
                std::cout << "\nle node a rechercher est : " << node->value << std::endl;
            getchar();
            getchar();
            break;

            // **---------------------- RECHERCHE D'UN NEOUD ------------------------

        case 5:
            system("cls");
            std::cout << "l'affichage de BST :" << std::endl;
            bst.display();
            getchar();
            getchar();
            break;

            // **---------------------- AFFICHAGE ----------------------------------

        case 6:
            std::cout << "fin de programme merci ..." << std::endl;
            return 0;
            break;
        default:
            std::cout << "votre saisie est erronée" << std::endl;
            break;
        }

    } while (1);

    return 0;
}

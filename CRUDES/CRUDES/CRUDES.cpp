#include <iostream>
#include <vector>
#include <string>


struct livre
{
    std::string titre;
    std::string auteur;
    std::string datedeparution;
};

class Bibliotheque
{
private:
    std::vector<livre> livres;

public:

    Bibliotheque() {
    }


    void ajouterunlivre()
    {
        std::string nouveautitre;
        std::string nouvelauteur;
        std::string nouvelledatedeparution;
        std::cin.ignore();

        std::cout << "entrez le titre: ";
        std::getline(std::cin, nouveautitre);
        std::cout << "et l'auteur: ";
        std::getline(std::cin, nouvelauteur);
        std::cout << "et la date de parution: ";
        std::getline(std::cin, nouvelledatedeparution);

        livres.push_back({ nouveautitre, nouvelauteur, nouvelledatedeparution });
    }

    void supprimerlivre()
    {
        if (livres.empty())
        {
            std::cout << "il n'y a aucun livre à supprimer." << std::endl;
            return;
        }

        int index;
        std::cout << "entrez l'index du livre à supprimer (1 à " << livres.size() << "): ";
        std::cin >> index;
        if (index < 1 || index > livres.size())
        {
            std::cout << "index invalide." << std::endl;
            return;
        }

        livres.erase(livres.begin() + index - 1);
        std::cout << "livre supprimé avec succès." << std::endl;
    }

    void afficherlivres()
    {
        if (livres.empty())
        {
            std::cout << "il n'y a aucun livre à afficher." << std::endl;
            return;
        }

        std::cout << "liste des livres :" << std::endl;
        for (int i = 0; i < livres.size(); i++)
        {
            std::cout << "livre " << i + 1 << " : " << livres[i].titre << " de l'auteur " << livres[i].auteur << " paru le " << livres[i].datedeparution << std::endl;
        }
    }

    void modifierlivre()
    {
        if (livres.empty())
        {
            std::cout << "il n'y a aucun livre à modifier." << std::endl;
            return;
        }

        int index;
        std::cout << "entrez l'index du livre à modifier (1 à " << livres.size() << "): ";
        std::cin >> index;
        if (index < 1 || index > livres.size())
        {
            std::cout << "index invalide." << std::endl;
            return;
        }

        std::string nouveautitre;
        std::string nouvelauteur;
        std::string nouvelledatedeparution;

        std::cin.ignore();

        std::cout << "entrez le nouveau titre: ";
        std::getline(std::cin, nouveautitre);
        std::cout << "et le nouveau auteur: ";
        std::getline(std::cin, nouvelauteur);
        std::cout << "et la nouvelle date de parution: ";
        std::getline(std::cin, nouvelledatedeparution);

        livres[index - 1] = { nouveautitre, nouvelauteur, nouvelledatedeparution };
        std::cout << "livre modifié avec succès." << std::endl;
    }


    ~Bibliotheque() {}
};

int main()
{
    Bibliotheque* bibliotheque = new Bibliotheque;



    int choix;
    do
    {
        std::cout << "\nmenu : " << std::endl;
        std::cout << "1. ajouter un livre" << std::endl;
        std::cout << "2. supprimer un livre" << std::endl;
        std::cout << "3. afficher les livres" << std::endl;
        std::cout << "4. modifier un livre" << std::endl;
        std::cout << "5. quitter" << std::endl;
        std::cout << "entrez votre choix : ";
        std::cin >> choix;

        switch (choix)
        {
        case 1:
            bibliotheque->ajouterunlivre();
            break;
        case 2:
            bibliotheque->supprimerlivre();
            break;
        case 3:
            bibliotheque->afficherlivres();
            break;
        case 4:
            bibliotheque->modifierlivre();
            break;
        case 5:
            std::cout << "au revoir !" << std::endl;
            break;
        default:
            std::cout << "choix invalide. veuillez réessayer." << std::endl;
        }
    } while (choix != 5);

    delete bibliotheque;
    std::cout << " destruction  " << std::endl;
    return 0;

}















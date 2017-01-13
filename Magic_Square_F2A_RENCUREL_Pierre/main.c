//Librairies et constantes utilisees
#include <stdio.h>  //Librairie "standard input output" (gestion des commandes "print" et du clavier notamment)
#include <stdlib.h> //Librairie "standard library" (gestion des operations simples et de l'allocation de la memoire notamment)
#define TAILLE 7    //Constante definissant la taille du carre magique (tableau)

//BUT       Realiser un carre magique qui avance d'un pas vers le "nord-est" et, si cette case n'est pas disponible, avance vers le "nord-ouest"
//ENTREE    Utilisateur lance le programme
//SORTIE    Affiche le carre de dimension TAILLE rempli avec les valeurs requises


typedef struct Pos  //Type structure permettant l'enregistrement de la position x et y du "curseur"
{
    int x;
    int y;
}Pos;

//Prototypes des fonctions et procedures utilises dans le programme
void Debut(Pos *ptPosition,int tabCarre[][TAILLE]); //Procedure initialisant le tableau du carre magique
void Forward(Pos *ptPosition,int tabCarre[][TAILLE],int nCase); //Procedure faisant avancer le "curseur"
int Increase(int value);    //Fonction d'incrementation des positions
int Decrease(int value);    //Fonction de decrementation des positions

int main()      //Programme principal
{
    int tabCarre[TAILLE][TAILLE];   //Declaration du tableau de taille TAILLE
    int nEmplacement = TAILLE * TAILLE; //Recuperation du nombre de cases total du tableau
    int nCase;  //Variable contenant la valeur a affecter a la case sur laquelle le "curseur" se trouve
    Pos Position;   //Variable "curseur" contenant la position actuelle du "curseur" susmentionner

    Pos *ptPosition = &Position;    //Pointeur pointant vers la variable ptPosition utilisee dans les procedures

    Debut(ptPosition,tabCarre); //Appel de la procedure "Debut"

    for(nCase=2;nCase<=nEmplacement;nCase++)    //Affectation de la valeur initiale de nCase et incrementation tant qu'il rest des cases libres (valeur 0)
    {
        Forward(ptPosition,tabCarre,nCase); //Appel de la procedure "Forward"
    }

    for(Position.y=TAILLE-1;Position.y>=0;Position.y--) //Pour x et y dans le tableau
    {
        for(Position.x=0;Position.x<=TAILLE-1;Position.x++)
        {
            printf("%d \t",tabCarre[Position.x][Position.y]);   //Afficher la valeur de nCase affectee aux coordonnees actuelles du "curseur"
        }

        printf("\n");
    }

    return 0;
}

void Debut(Pos *ptPosition,int tabCarre[][TAILLE])  //Procedure initialisant le tableau du carre magique
{

    //BUT       Initialiser le tableau
    //ENTREE    Recupere la TAILLE du tableau de depart
    //SORTIE    Affecte et enregistre une valeur "placeholder" a chaque case et la valeur initiale 1 a la case de depart

    for(ptPosition->x=0;ptPosition->x<=TAILLE-1;ptPosition->x++)        //Affecte la valeur "placeholder" 0 a chaque case du tableau
    {
        for(ptPosition->y=0;ptPosition->y<=TAILLE-1;ptPosition->y++)
        {
            tabCarre[ptPosition->x][ptPosition->y]=0;
        }
    }

    ptPosition->x = TAILLE / 2;     //Place le "curseur" a la "case de depart" et y affecte la valeur 1
    ptPosition->y = TAILLE / 2 + 1;
    tabCarre[ptPosition->x][ptPosition->y]=1;
}

void Forward(Pos *ptPosition,int tabCarre[][TAILLE],int nCase)  //Procedure faisant avancer le "curseur"
{

    //BUT       Faire avancer le "curseur" en verifiant que sa prochaine position soit valide
    //ENTREE    Recupere la position precedente du "curseur"
    //SORTIE    Deplace le "curseur" vers la prochaine case valide

    int check=1;    //Variable utilisee comme BOOLEEN dans le but de verifier que la prochiane case soit valide
    ptPosition->x = Increase(ptPosition->x);
    ptPosition->y = Increase(ptPosition->y);

    while(check)    //Tant que check corresspond vaut 1 executer les instructions qui suivent (la valeur 1 est implicite
    {
        if(tabCarre[ptPosition->x][ptPosition->y] == 0)
        {
            tabCarre[ptPosition->x][ptPosition->y] = nCase; //Affecte a la case corresspondant a la position actuelle du "curseur" la valeur de nCase
            check=0;    //Affecter 0 a check permet de sortir de la boucle
        }

        else
        {
            ptPosition->x = Decrease(ptPosition->x);    //Appel des procedure d'increment et decrement pour modifier les valeurs de x et y
            ptPosition->y = Increase(ptPosition->y);
        }
    }
}

int Increase(int value) //Fonction d'incrementation des positions
{

    //BUT       Incrementer la variable de position (x ou y)
    //ENTREE    Recupere la valeur (de x ou de y)
    //SORTIE    Affecte la valeur (de x ou y) en y ajoutant 1

    if(value == TAILLE-1)
        return 0;
    else
        return ++value;
}

int Decrease(int value) //Fonction de decrementation des positions
{

    //BUT       Decrementer la variable de position (x ou y)
    //ENTREE    Recupere la valeur (de x ou de y)
    //SORTIE    Affecte la valeur (de x ou y) en y soustrayant 1

    if(value == 0)
        return TAILLE-1;
    else
        return --value;
}

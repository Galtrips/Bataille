#include <iostream>
#include <ctime>
using namespace std;

const int NB_CARTES=32;

/*----------------------------------------------------------------*/

void defaultjeu(int jeu[]) {
	for (int i = 0; i < 32; i++) {
		jeu[i] = -1;
	}
}



void initjeu(int jeu[]) /* remplit le tableau avec les 32 cartes */
{

	for (int i = 0; i < 32; i++) {
		jeu[i] = i;
	}

}
/*----------------------------------------------------------------*/
void permute(int& carte1, int& carte2) /* permute 2 cartes */
{



}
/*----------------------------------------------------------------*/
void melange(int jeu[]) /* melange les cartes */
{
	int x;
	int y;

	for (int i = 0; i <= 100; i++) {
		
		int w;
		int v;
		x = rand() % 32;
		y = rand() % 32;

		w = jeu[y];
		v = jeu[x];
		jeu[x] = w;
		jeu[y] = v;

	}
}
/*----------------------------------------------------------------*/
void affiche_carte(int x) /* affiche une carte (valeur,couleur)*/
{
	char couleur;
	int valeur;
	char valeurF = ' ';
	if (0 <= x && x <= 7) {

		valeur = (x % 8) + 7;
		if (x == 0)valeur = 7;
		couleur = 'P';
		if (valeur == 11) {
			valeurF = 'V';
			cout << valeurF << couleur;
		}
		else if (valeur == 12) {
			valeurF = 'D';
			cout << valeurF << couleur;
		}
		else if (valeur == 13) {
			valeurF = 'R';
			cout << valeurF << couleur;
		}

		else if (valeur == 14) {
			valeurF = '1';
			cout << valeurF << couleur;
		}
		else {
			cout << valeur << couleur;
		}
		
		
	}
	else if (8 <= x && x <= 15) {
		x = x - 8;
		if (0 <= x && x <= 7) {

			valeur = (x % 8) + 7;
			if (x == 0)valeur = 7;
			couleur = 'C';
			if (valeur == 11) {
				valeurF = 'V';
				cout << valeurF << couleur;
			}
			else if (valeur == 12) {
				valeurF = 'D';
				cout << valeurF << couleur;
			}
			else if (valeur == 13) {
				valeurF = 'R';
				cout << valeurF << couleur;
			}

			else if (valeur == 14) {
				valeurF = '1';
				cout << valeurF << couleur;
			}
			else {
				cout << valeur << couleur;
			}

		}
	}
	else if (16 <= x && x <= 23) {
		x = x - 16;
		if (0 <= x && x <= 7) {

			valeur = (x % 8) + 7;
			if (x == 0)valeur = 7;
			couleur = 'K';
			if (valeur == 11) {
				valeurF = 'V';
				cout << valeurF << couleur;
			}
			else if (valeur == 12) {
				valeurF = 'D';
				cout << valeurF << couleur;
			}
			else if (valeur == 13) {
				valeurF = 'R';
				cout << valeurF << couleur;
			}

			else if (valeur == 14) {
				valeurF = '1';
				cout << valeurF << couleur;
			}
			else {
				cout << valeur << couleur;
			}
		}
	}
	else if (24 <= x && x <= 31) {
		x = x - 24;
		if (0 <= x && x <= 7) {

			valeur = (x % 8) + 7;
			if (x == 0)valeur = 7;
			couleur = 'T';
			if (valeur == 11) {
				valeurF = 'V';
				cout << valeurF << couleur;
			}
			else if (valeur == 12) {
				valeurF = 'D';
				cout << valeurF << couleur;
			}
			else if (valeur == 13) {
				valeurF = 'R';
				cout << valeurF << couleur;
			}

			else if (valeur == 14) {
				valeurF = '1';
				cout << valeurF << couleur;
			}
			else {
				cout << valeur << couleur;
			}
		}
	}
	else {
		cout << ".";
	}
}
/*----------------------------------------------------------------*/

void affiche(int jeu[],int taille,int n) /* affiche N cartes */
{
	if (n <= taille) {

		for (int i = 1; i <= n; i++) {

			affiche_carte(jeu[i - 1]);
			cout << " ";

		}
	}
	else cout << "il n'y a pas assez de cartes" << endl;
}
/*-------------------9 83 108 32 122 108 106 118 117 107 32 116 108 122 122 104 110 108 32 107 98 32 106 111 104 117 117 
108 115 32 108 122 97 32 115 104 32 106 115 108 109 32 99 108 121 122 32 115 104 32 122 98 112 97 108--------------------------------*/

void distribution(int jeu[], int jeu1[], int jeu2[])
	/* distribue les cartes aux deux joueurs */
{
	int t = 0;
	int r = 0;
	for (int i = 0; i < 32; i++) {

		if (i % 2 == 0) {
			

				jeu1[t] = jeu[i];
				t++;
			
		}
		else {
			

				jeu2[r] = jeu[i];
				r++;
			
		}
	}
}
/*----------------------------------------------------------------*/
void jouer1coup( int jeu1[], int jeu2[], int& n1, int& n2)
	/* gere le resultat d'une bataille (1 coup) */
{
	int carte1 = jeu1[0];
	int carte2 = jeu2[0];
	int t;

	for (int i = 1; i <= n1+1; i++) {
		t = jeu1[i];
		jeu1[i-1] = t;
	}
	for (int i = 1; i <= n2+1; i++) {
		t = jeu2[i];
		jeu2[i - 1] = t;
	}

	if ((carte1 % 8) > (carte2 % 8)) {
		jeu1[n1] = carte1;
		jeu1[n1 + 1] = carte2;
		n1 = n1 + 1;
		n2 = n2 - 1;

	}
	else if ((carte2 % 8) > (carte1 % 8)) {
		jeu2[n2] = carte2;
		jeu2[n2 + 1] = carte1;
		n2 = n2 + 1;
		n1 = n1 - 1;
	}
	else if (carte1 % 8 == carte2 % 8) {
		if (carte1 < carte2) {


			jeu1[n1] = carte1;
			jeu1[n1 + 1] = carte2;
			n1 = n1 + 1;
			n2 = n2 - 1;
		}
		else if (carte1 > carte2) {


			jeu2[n2] = carte2;
			jeu2[n2 + 1] = carte1;
			n2 = n2 + 1;
			n1 = n1 - 1;
		}
	}
}
/*----------------------------------------------------------------*/
int main(){
	int jeu[NB_CARTES]; /*ensemble de toutes les cartes*/
	int jeu1[NB_CARTES]; /* cartes du joueur 1 */
	int jeu2[NB_CARTES]; /*cartes du joueur 2*/
	int n1=15; /* indice de la derniere carte joueur 1 */
	int n2=15; /* indice de la derniere carte joueur 2 */
	const int VM = 1000;
	srand(time(NULL));

	int moyenne = 0;
	for (int u = 0; u < VM; u++) {
		n1 = 15;
		n2 = 15;

		defaultjeu(jeu1);
		defaultjeu(jeu2);
		
		//remplissage du tableau jeu avec toutes les cartes
		initjeu(jeu);
		//mélange des cartes
		melange(jeu);
		//distribution des cartes dans les tableaux jeu1 et jeu2
		distribution(jeu, jeu1, jeu2);
		
		//affichage des deux jeux pour tester vos premières fonctions
		/*cout << "J1 : ";
		affiche(jeu1, 32, 32);
		cout << endl;
		cout << "J2 : ";
		affiche(jeu2, 32, 32);
		cout << endl;*/
	
	
		int inc = 0;

		//Tant que la partie est pas finit
		while (n1 >= 0 && n2 >= 0)
		{
			inc++;
			jouer1coup(jeu1, jeu2, n1, n2);
		}
		/* afficher qui gagne et en combien de coups */
		cout << endl;
		if (n1 < 0) cout << "J2 gagnant en " << inc << " coups" << endl;
		else if (n2 < 0) cout << "J1 gagnant en " << inc << " coups" << endl;
		moyenne = moyenne + inc;
	}
	cout << endl;
	moyenne = moyenne / VM;
	cout << "La valeur moyenne de coup est : " << moyenne << endl;
	
	return 0;
}

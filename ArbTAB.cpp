#include <iostream>
#include <malloc.h>
#define NbElem 15

typedef struct Nd
{
	int TAB[3][NbElem];
	int IdNoeud;
}arb;

/*******************************************************************/
/****************************Creer_Arb******************************/
/*
				Entrées:			

				Sorties: le nouvel arbre alloué
La focntion sert à creer un arbre		
*/
arb *Creer_Arb()
{
	arb *Arb;
	Arb=(arb*)malloc(sizeof(arb));//allocation de la mémoire
	//Test si l'allocation est bien fait
	if(!Arb)//mémoire insuffisante
	{
		printf("erreur\n");
		exit(0);
	}
	return ((arb*)Arb);
}
/****************************Creer_Arb******************************/
/*
				Entrées:l'adress de l'arbre		
				Sorties:
fonction d'initialisation
 */

int init_Arb(arb *Arb)
{
	Arb->IdNoeud=-1;
	return((int)1);
}
/*******************************************************************/

/****************************Creer_Arb******************************/
/*
				Entrées:l'adress de l'arbre	
				Sorties:
La focntion sert à tester si l'arbre est saturee	
*/
int Est_saturee(arb Arb)
{
	return((int)Arb.IdNoeud == (NbElem-1));
}
/*******************************************************************/


/****************************Creer_Arb******************************/
/*
				Entrées:l'adress de l'arbre	
				Sorties:
La focntion sert à tester si l'arbre est saturee	
*/
int Est_vide(arb Arb)
{
	return((int)Arb.IdNoeud == -1);
}
/*******************************************************************/



/****************************Creer_Arb******************************/
/*
				Entrées:
					Arb:l'adress d'un arbre	
					val:la valeur a inserer
				Sorties:
La focntion sert à inserer la valeur passe au paramaetre a la bon place
*/
int inserer_Arb(arb *Arb,int val)
{
	int ind=0;
	//tester si l'arbre n'existe pas
	if(!Arb)return((int)-1);
	//tester si l'arbre est saturee
	if(Est_saturee(*Arb))return((int)-1);
	
	//inserer le nouveau noeud
	Arb->TAB[0][++Arb->IdNoeud]=val;
	// mettre l'indice de son fils gauche a -1
	Arb->TAB[1][Arb->IdNoeud]=-1;
	// mettre l'indice de son fils droit a -1
	Arb->TAB[2][Arb->IdNoeud]=-1;
	
	//tester si l'arbre a un seul noeud
	if(Arb->IdNoeud == 0)return((int)1);
	
	//boucler pour trouver le pere de ce nouveau noeud
	while(1)
	{
		// //Test si val est plus grand que l'element acctuel
		if(val<Arb->TAB[0][ind])
		{
			//tester si l
			if(Arb->TAB[1][ind] == -1)
			{
				Arb->TAB[1][ind]=Arb->IdNoeud;
				break;
			}
			ind=Arb->TAB[1][ind];
		}
		
		if(val > Arb->TAB[0][ind])
		{
			if(Arb->TAB[2][ind] == -1)
			{
				Arb->TAB[2][ind]=Arb->IdNoeud;
				break;
			}
			ind=Arb->TAB[2][ind];
		}
	}
	return((int)1);

}



int afficher(arb Arb)
{
	if(Est_vide(Arb))
	{
		printf("l\'arbre est vide");
		return((int)0);
	}
	for(int i=0;i<=Arb.IdNoeud;i++)printf("%d\t",i);
	printf("\n");
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<=Arb.IdNoeud;j++)
			printf("%d\t",Arb.TAB[i][j]);
		printf("\n");
	}
	printf("\n");
	return((int)1);
}

void tasser(arb *Arb,int ind)
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<Arb->IdNoeud;j++)
		{	
			if(j>=ind)Arb->TAB[i][j]=Arb->TAB[i][j+1];
			if((i !=0 ) && (Arb->TAB[i][j] >= ind))Arb->TAB[i][j]--;
		}
	}
	Arb->IdNoeud--;
}

int supprimer(arb *Arb,int val)
{
	int ind=0,pere=0,plus_dt,v;
	if(!Arb)return((int)-1);
	while((Arb->TAB[0][ind] != val) && (ind != -1))
	{
		pere=ind;
		if(val<Arb->TAB[0][ind])ind=Arb->TAB[1][ind];
		if(val>Arb->TAB[0][ind])ind=Arb->TAB[2][ind];
	}
	if(ind == -1)return((int)-2);
	
	if((Arb->TAB[1][ind] != -1) && (Arb->TAB[2][ind] != -1))
	{
		plus_dt=Arb->TAB[1][ind];
		while(Arb->TAB[2][plus_dt] != -1)
			plus_dt=Arb->TAB[2][plus_dt];
			
		v=Arb->TAB[0][plus_dt];
		supprimer(Arb,v);
		Arb->TAB[0][ind]=v;
	}
	
	if(Arb->TAB[1][ind] == -1)
	{
		if(Arb->TAB[1][pere] == ind)Arb->TAB[1][pere]=Arb->TAB[2][ind];
		if(Arb->TAB[2][pere] == ind)Arb->TAB[2][pere]=Arb->TAB[2][ind];
		tasser(Arb,ind);
		return((int)1);
	}
	
	if(Arb->TAB[2][ind] == -1)
	{
		if(Arb->TAB[1][pere] == ind)Arb->TAB[1][pere]=Arb->TAB[1][ind];
		if(Arb->TAB[2][pere] == ind)Arb->TAB[2][pere]=Arb->TAB[1][ind];
		tasser(Arb,ind);
		return((int)1);
	}
	
}


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int rst;
	arb *Arb;
	Arb=Creer_Arb();
	
	rst=init_Arb(Arb);
	
	rst=inserer_Arb(Arb,13);
	

	rst=inserer_Arb(Arb,10);
	rst=inserer_Arb(Arb,20);
	rst=inserer_Arb(Arb,11);
	rst=inserer_Arb(Arb,4);
	rst=inserer_Arb(Arb,14);
	rst=inserer_Arb(Arb,5);
	rst=inserer_Arb(Arb,2);
	rst=inserer_Arb(Arb,6);
	rst=inserer_Arb(Arb,9);
	rst=inserer_Arb(Arb,8);
	rst=inserer_Arb(Arb,7);
	
	rst=afficher(*Arb);
	
	rst=supprimer(Arb,10);
	
	rst=afficher(*Arb);

	return 0;
}




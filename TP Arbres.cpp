#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

//structure d'un arbre à l'aide des pointeurs
typedef struct Nd
{
	int info;//contient l'information
	struct Nd* fgche;//pointeur sur le fils gauche
	struct Nd* fdt;//pointeur sur le fils droit
}Noeud;

//structure d'un arbre à l'aide de tableau
typedef struct Nd
{
	int TAB[4][NbElem];
	int IdNoeud;
}arb;


/********************************Creer_Noeud************************/
/*
	Entée: int val : la valeur a mettre dans le nouvel element
	Sorties: le nouvel element alloué
	la fonction prends la valeur et fait une allocation memoire, 
	et initialise cette nouvel element avec val
*/
Noeud * Creer_Noeud(int val)
{
	Noeud *arb;
	
	//allocation memoire du nouvel element
	arb=(Noeud*)malloc(sizeof(Noeud));
	
	//Test si l'allocation est bien fait
	if(!arb)
	{
		printf("\nErreur d'allocation");
		exit(0);
	}
	/*Initialisation Noeud*/
	arb->info=val;
	arb->fgche=NULL;
	arb->fdt=NULL;
	
	return (Noeud*) arb;
}

/*******************************************************************/

/****************************longeur_Arb***************************/
/*
	Entrées:
				Noeud *arb: la racine de l'arbre
				
	Sorties:
				int: la longeur de l'arbre
	la fonction calcule le chemin le plus long reliant la racine et
	une feuille  
				
*/
int longeur_Arb(Noeud *Arb)
{
	int Lg_fgche,Lg_fdt;
	//test si l'arbre est vide
	if(!Arb)return((int)-1);
	//test s'il est un noeud unique	
	if((!Arb->fgche) && (!Arb->fdt))return((int)0);
	
	//calculer la longeur de sous arbre gauche
	Lg_fgche=longeur_Arb(Arb->fgche);
	//calculer la longeur de sous arbre droit
	Lg_fdt=longeur_Arb(Arb->fdt);
	
	/*test si la longeur de sous arbre gauche est
	 plus grand que la longeur de sous arbre droit*/
	if(Lg_fgche > Lg_fdt)
		return((int)(Lg_fgche+1));
	return((int)(Lg_fdt+1));
	
}

/*******************************************************************/



/****************************taille_Arb_BinO***************************/
/*
	Entrées:
				Noeud *arb: la racine de l'arbre
				
	Sorties:
				int: la taille de l'arbre c'est a dire le nombre de noeuds
	La fonction sert a calculer le nombre de noeud constituant l'arbre
				
*/
int taille_Arb_BinO(Noeud *Arb)
{
	//test si l'arbre est vide
	if(!Arb)return((int)0);
	/*retourner la taille de sous arbre gauche 
	plus la taille de sous arbre gauche plus 1*/
	return((int)1+taille_Arb_BinO(Arb->fgche)+taille_Arb_BinO(Arb->fdt));
}

/*******************************************************************/



/****************************min_arbre******************************/

/*
	Entrées:
				Noeud *arb: la racine de l'arbre
				
	Sorties:
				int *min: variable contenant le min de l'arbre
				d'où le passage par adresse

La focntion sert à calculer le min d'une arbre non ordoner ou ordonne
				
*/
int min_arbre(Noeud *Arb,int *min)
{
	int rst;
	//test si l'arbre est vide
	if(!Arb)return((int)-1);
	
	/*Test si l'element acctuel est plus petit que le 
	minimum , il devient minimum*/
	if(*min>Arb->info)*min=Arb->info;
	
	//cherche le minimum dans le sous arbre gauche
	rst=min_arbre(Arb->fgche,min);
	//cherche le minimum dans le sous arbre droit
	rst=min_arbre(Arb->fdt,min);
	return (int)1;
}

/*******************************************************************/

/****************************max_arbre******************************/

/*
	Entrées:
				Noeud *arb: la racine de l'arbre
				
	Sorties:
				int *max: variable contenant le max de l'arbre
				d'où le passage par adresse

La focntion sert à calculer le max d'une arbre non ordoner ou ordonne
				
*/
int max_arbre(Noeud *Arb,int *max)
{
	int rst;
	//test si l'arbre est vide
	if(!Arb)return((int)-1);
	
	/*Test si l'element acctuel est plus grands que le 
	maximum , il devient maximum*/
	if(*max<Arb->info)*max=Arb->info;
	
	//cherche le minimum dans le sous arbre gauche
	rst=max_arbre(Arb->fgche,max);
	//cherche le minimum dans le sous arbre droit
	rst=max_arbre(Arb->fdt,max);
	return (int)1;
}

/*******************************************************************/

/***********************Affichage_infix*****************************/

/*
	Entrée: 
			Noeud *arb: le pointeur sur la racine de l'arbre
			
La focntion sert a afficher les elements de l'arbre selon le 
parcour infixé 
*/

void Affichage_infix(Noeud * arb)
{
	if(arb)
	{
		//parcourir le sous arbre gauche
		Affichage_infix(arb->fgche);
		//on affiche l'element courant
		printf("%d\n",arb->info);
		//parcourir le sous arbre droit
		Affichage_infix(arb->fdt);
	}
}
/********************************************************************/

/***********************Affichage_prefix*****************************/

/*
	Entrée: 
			Noeud *arb: le pointeur sur la racine de l'arbre
			
La focntion sert a afficher les elements de l'arbre selon le 
parcour prefixé 
*/

void Affichage_prefix(Noeud * arb)
{
	if(arb)
	{
		//on affiche l'element courant
		printf("%d\n",arb->info);
		
		//parcourir le sous arbre gauche
		Affichage_prefix(arb->fgche);
		
		//parcourir le sous arbre droit
		Affichage_prefix(arb->fdt);
	}
}
/********************************************************************/

/**************************Affichage_postfix*************************/
/*
	Entrée: 
			Noeud *arb: le pointeur sur la racine de l'arbre
			
La focntion sert a afficher les elements de l'arbre selon le 
parcour postfixé 
*/

void Affichage_postfix(Noeud * arb)
{
	if(arb)
	{		
		//parcourir le sous arbre gauche
		Affichage_postfix(arb->fgche);
		
		//parcourir le sous arbre droit
		Affichage_postfix(arb->fdt);
		
		//on affiche l'element courant
		printf("%d\n",arb->info);
	}
}
/********************************************************************/


/**********************afficher_Arb_horizontal***************************/

/*
	Entrées:
			Noeud * arb: pointeur sur la racine de l'arbre.
			int niveau : variable permettant de renseigner sur le 
			niveau de l'element courant.
	Sorties:
			int : entier permet de renseigner sur l'etat de la focntion
			
La focntion permet d'afficher l'arbre horizontalement ceci en parcourant 
la pratie droite de l'arbre et en l'affichant puis afficher la partie 
gauche
*/
int afficher_Arb_horizontal(Noeud * arb,int niveau)
{
	int rst;
	//Test si l'element courant est NULL
	if(!arb)
		return (int)0;
	//afficher le sous arbre droit 
	rst=afficher_Arb_horizontal(arb->fdt,++niveau);
	//ajouter auttant de tabulation que le niveau de l'element courant
	for(int i=0;i<niveau;i++)printf("\t");
	//afficher l'elemnt courant et retourner a la ligne
	printf("%d\n",arb->info,niveau);
	//afficher le sous arbre gauche
	rst=afficher_Arb_horizontal(arb->fgche,niveau);
	
	return (int)1;	
}
/*******************************************************************/


/********************aff_feuilles*****************************/

/*
	Entrée:
			Noeud *Arb: pointeur sur la racine de l'arbre.
			
La focntion sert a afficher les feuilles de l'arbre passé en parametre
*/
int aff_feuilles(Noeud *Arb)
{
	int rst;
	//Test si l'arbre est vide
	if(!Arb)return((int)-1);
	//test s'il est un noeud unique 
	if((!Arb->fdt) && (!Arb->fgche))printf("%d\t",Arb->info);
	
	// afficher les feuilles de sous arbre gauche
	rst=aff_feuilles(Arb->fgche);
	// afficher les feuilles de sous arbre gauche
	rst=aff_feuilles(Arb->fdt);
	return((int)1);
	
}

/*******************************************************************/


/********************insertion_Arb_BinO*****************************/

/*
	Entrée:
			Noeud *Arb: pointeur sur la racine de l'arbre.
			int val :la valaur a inserer dans l'arbre
	Sotries:
			Noeud * : pointeur de type Noeud
			
La focntion insere dans un arbre de maniere a ce que les elements
de l'arbre soit ordoné horizontalement
*/
Noeud *insertion_Arb_BinO(Noeud *Arb,int val)
{
	Noeud *NE;
	//Test si l'arbre est vide
	if(!Arb)
	{
		NE=Creer_Noeud(val);
		return((Noeud*)NE);
	}
	//Test si val est plus petite que l'element acctuel
	if(val<Arb->info)
		Arb->fgche=insertion_Arb_BinO(Arb->fgche,val);
	//Test si val est plus grands que l'element acctuel
	if(val>Arb->info)
		Arb->fdt=insertion_Arb_BinO(Arb->fdt,val);
	return((Noeud*)Arb);
}

/*******************************************************************/

/********************fusion_2Arb_BinO*****************************/

/*
	Entrée:
			Noeud *Arb1: pointeur sur la racine d'un arbre.
		 	Noeud *Arb2: pointeur sur la racine d'un l'arbre.
	Sotries:
			Noeud * : pointeur de type Noeud
			
La focntion qui sert a fusionner deux arbres de façon ordonne
*/
Noeud *fusion_Arb_BinO(Noeud *Arb1,Noeud *Arb2)
{
	//Test si le premier arbre est vide
	if(!Arb1)return((Noeud*)Arb2);
	//Test si le deuxieme arbre est vide
	if(!Arb2)return((Noeud*)Arb1);
	
	//inserer la racine dans la premier arbe
	Arb1=insertion_Arb_BinO(Arb1,Arb2->info);
	// inserer tous les elememts de sous arbre gauche
	Arb1=fusion_Arb_BinO(Arb1,Arb2->fgche);
	// inserer tous les elememts de sous arbre droit
	Arb1=fusion_Arb_BinO(Arb1,Arb2->fdt);
	return((Noeud*)Arb1);
}

/*******************************************************************/

/********************supprimer*****************************/

/*
	Entrée:
			Noeud *Arb: pointeur sur la racine de l'arbre.
			int val :la valaur a supprimer
	Sotries:
			Noeud * : pointeur de type Noeud
			
La focntion qui sert a supprimer une valeur donne d'une arbre
*/
Noeud *supprimer(Noeud *Arb , int val)
{
	Noeud *Nd;
	int max;
	if(!Arb)return((Noeud*)NULL);
	if(val>Arb->info)Arb->fdt=supprimer(Arb->fdt,val);
	if(val<Arb->info)Arb->fgche=supprimer(Arb->fgche,val);	
	if((val == Arb->info) && (!Arb->fgche))
	{
		Nd=Arb;
		Arb=Arb->fdt;
		free(Nd);
		return (Noeud*)Arb;
	}
	
	if((val == Arb->info) && (!Arb->fdt))
	{
		Nd=Arb;
		Arb=Arb->fgche;
		free(Nd);
		return (Noeud*)Arb;
	}
	
	
	if((val == Arb->info) && (Arb->fdt) && (Arb->fdt))
	{
		max_arbre(Arb->fgche,&max);
		Arb->fgche=supprimer(Arb->fgche,max);
		Arb->info=max;
	}
		
	return((Noeud*)Arb);
}
/*******************************************************************/



/*******************************************************************/


int menu_arbre_pointeur(void)
{
	int reponse2,reponse3,val1,garbage;
	int min,max,taille;
	Noeud * arb=NULL;
	do
	{
	
		printf("\n\n\nveuillez choisir une opperation\n");
		printf( "1 inserer un element dans l'arbre\n"
				"2 afficher l'arbre\n"
				"3 chercher le minimum de l'arbre\n"
				"4 chercher le maximum de l'arbre\n"
				"5 afficher les feuils de l'arbre\n"
				"6 afficher le nombre d'elements de l'arbre\n"
				"7 afficher la longeur de l'arbre\n"
				"8 Supprimer un element de l'arbre\n"
				
				"0 sortir\n"
		);
		printf("Votre reponse : ");
		scanf("%d",&reponse2);
		
		switch(reponse2)
		{
			case 1:
				printf("\nSaisir la valeur a inserer: ");
				scanf("%d",&val1);
				arb=insertion_Arb_BinO(arb,val1);
				printf("------------Affichage de l'arbre-----------\n");
				garbage=afficher_Arb_horizontal(arb,-1);
				break;
			case 2:
				garbage=afficher_Arb_horizontal(arb,-1);
				printf("\n----------FIN de l'affichage----------\n");
				
				break;
			case 3:
				if(!arb)
					printf("\nVous n'avez pas enore saisi votre arbre\n");
				else
				{
					min=arb->info;
					garbage=min_arbre(arb,&min);
					printf("\nLe minimum de l'arbre est:%d \n",min);
				}
				break;
			case 4:
				if(!arb)
					printf("\nVous n'avez pas enore saisi votre arbre\n");
				else
				{
					max=arb->info;
					garbage=max_arbre(arb,&max);
					printf("\nLe maximum de l'arbre est:%d \n",max);
				}
				break;
			case 5:
				printf("\n-----Affichage des feuils de l'arbre------\n");
				aff_feuilles(arb);
				break;
			case 6:
				taille=taille_Arb_BinO(arb);
				printf("\nLa taille de l'arbre est %d\n",taille);
				break;
			case 7:
				taille=longeur_Arb(arb);
				printf("\nLa longeur de l'arbre est %d\n",taille);
				break;
			case 8:
				printf("\nSaisir la valeur a supprimer: ");
				scanf("%d",&val1);
				arb=supprimer(arb,val1);
				garbage=afficher_Arb_horizontal(arb,-1);
				break;
				
			case 0:
			default:
				break;
		}
	
	printf("Voulez vous continuez? (1:oui/0:non): ");
	scanf("%d",&reponse3);
	}while(reponse3==1);
	
	return (int)1;	
	
}

int main(void)
{
	int reponse1;

	printf("choisissez l'impementation des arbres: \n");
	printf("1 implementation avec pointeur\n"
		   "2 implementation avec Tableau\n"
		   "0 pour sortir\n"
	);
	scanf("%d",&reponse1);
	
	switch(reponse1)
	{
		case 1:
			printf("Vous avez choisi l'implementation des arbres avec pointeurs");
			menu_arbre_pointeur();
			break;
		case 2:
			break;
		case 0:
		default:
			printf("\nVous avez choisi de sortir");
			break;
	}
	
}


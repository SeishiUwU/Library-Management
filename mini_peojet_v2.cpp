#include <iostream>
#include <conio.h>
using namespace std ;
struct liv {//structure of book
	int Num_liv ; 
	string titre ;
	string N_aute ;
	string P_aute ;
	int edition ;
	int Num_exmp ;
};
struct maillionL {
	liv ele ; 
	maillionL *suiv;
};
typedef maillionL *listeL;
struct date {
	int jour ; 
	int mois ;
	int anne ;
};
struct empr {//structure of borrow
	int Num_livE ; 
	int Num_E ;
	string N_E ;
	string P_E ;
	date emp ;
	date ret ;
};
struct maillionE {
	empr ele ; 
	maillionE *suiv;
};
typedef maillionE *listeE;
bool verifierILN(listeL L, int x){//verify if book number exixst
	 	listeL courrant;
	 	bool F;
	 	courrant =L;
	 	F=false;
	 	while (courrant!= NULL&F==false){
	 		if(courrant->ele.Num_liv==x){
	 		F=true;
	 	}
	 		else{
			 courrant = courrant->suiv;
		}
	 }
	 return (F);
}
bool verifierILNE(listeE E, int x){//verify if book number exixst in list E
	 	listeE courrant;
	 	bool F;
	 	courrant =E;
	 	F=false;
	 	while (courrant!= NULL&F==false){
	 		if(courrant->ele.Num_livE==x){
	 		F=true;
	 	}
	 		else{
			 courrant = courrant->suiv;
		}
	 }
	 return (F);
}
bool verifierILT(listeL L , string x){//verify if book title exist
	 	listeL courrant; 
	 	bool F;
	 	courrant =L;
	 	F=false;
	 	while (courrant!= NULL&F==false){
	 		if(courrant->ele.titre==x){
	 		F=true;
	 	}
	 		else{
			 courrant = courrant->suiv;
		}
	 }
	 return (F);
}
bool verifierDEN(listeL L, int x){//verify if the book availble
listeL courrant;
	 	bool F;
	 	courrant =L;
	 	F=false;
	 	while (courrant!= NULL&F==false){
	 		if(courrant->ele.Num_liv==x){
	 		    if(courrant->ele.Num_exmp>0){
	 			F==true;
			 }
	 	}
	 		else{
			 courrant = courrant->suiv;
		}
	 }
	 return (F);
}
void downL(listeL L, int x){//remove 1 copy from book
	listeL courrant;
	 	bool F;
	 	courrant =L;
	 	F=false;
	 	while (courrant!= NULL&F==false){
	 		if(courrant->ele.Num_liv==x){
	 		    courrant->ele.Num_exmp=courrant->ele.Num_exmp-1;
	 			F==true;
			 }
	 		else{
			 courrant = courrant->suiv;
		}
	 }
}
void upL(listeL L, int x){//add 1 copy from book
	listeL courrant;
	 	bool F;
	 	courrant =L;
	 	F=false;
	 	while (courrant!= NULL&F==false){
	 		if(courrant->ele.Num_liv==x){
	 		    courrant->ele.Num_exmp=courrant->ele.Num_exmp+1;
	 			F==true;
			 }
	 		else{
			 courrant = courrant->suiv;
		}
	 }
}
void upLA(listeL L, int x){//add 1 copy from book
	listeL courrant;
	 	bool F;
	 	int x1;
	 	courrant =L;
	 	F=false;
	 	cout<<"le nobr de exmplaire ajouter"<<endl;
	 	cin>>x1;
	 	while (courrant!= NULL&F==false){
	 		if(courrant->ele.Num_liv==x){
	 		    courrant->ele.Num_exmp=courrant->ele.Num_exmp+x1;
	 			F==true;
			 }
	 		else{
			 courrant = courrant->suiv;
		}
	 }
}
void affiche_menu (){//display operations menu
	system("cls");
	cout<<"------------------Bibliotheaue Univ-Mila----------------- "<<endl;
	cout<<"***choiser une option dans le menu suivent***"<<endl;
			cout<<"1- ajouter un livre dans la liste . "<<endl; 
			cout<<"2- afficher les livre dans la liste . "<<endl; 
					cout<<"3- recherche une livre dans la liste (par Num) . "<<endl;
					cout<<"4- recherche une livre dans la liste (par titre) . "<<endl;
					cout<<"5- verifier si une livre disponible ou non (par Num) . "<<endl;
					cout<<"6- afficher les livre dans la liste par order alphabetique . "<<endl; 
					cout<<"7- traiter l'operation de emprunter de un livre . "<<endl;
					cout<<"8- afficher la liste de livres emprunter . "<<endl;
					cout<<"9- traiter l'operation de retoure de un livre . "<<endl;
					cout<<"10- afficher les livres emprunte par un etudiant . "<<endl;
					cout<<"11- afficher la liste non retourner dans le periode donnes : "<<endl;
					cout<<"0- pour quiter .         "<<endl;
					cout<<"---------------------------------------------------------"<<endl;
						cout<<"\n\n-enter votre choix        : ";
						 
}
	 void ajouterL (listeL &L ){//add a book to the list
	 int x1; string x2 ; string x3 ; string x4 ; int x5 ; int x6 ; bool F ;
	 int R;
			cout<<"enter le num de livre: "<<endl;
				cin>> x1 ;
				F=verifierILN(L,x1);
				if(F==false){
				cout<<"enter le titre de livre: "<<endl;
				cin>> x2 ;
				F=verifierILT(L,x2);
				if(F==false){
				cout<<"enter le nom de auteure de livre: "<<endl;
				cin>> x3 ;
				cout<<"enter le prenom de auteure de livre: "<<endl;
				cin>> x4 ;
				cout<<"enter l'anne d'edition de livre: "<<endl;
				cin>> x5 ;
				cout<<"enter le num d' exemplaire de livre: "<<endl;
				cin>> x6 ;
	 listeL p;
	 p = new maillionL;
	 p->ele.Num_liv=x1;
	 p->ele.titre=x2;
	 p->ele.N_aute=x3;
	 p->ele.P_aute=x4;
	 p->ele.edition=x5;
	 p->ele.Num_exmp=x6;
	 p -> suiv = L;
	 L=p;
}
else{
	cout<<"operation invalide (le titre existe daja)"<<endl;
}
}
else{
	cout<<"operation invalide (le num de livre existe daja)"<<endl;
	cout<<"1- voulez-vous ajouter des copies(tapez 1) ? "<<endl;
	cin>>R;
	if(R==1){
		upLA(L,x1);
	}
}
}
	 void afficherL(listeL L){//display book list
	 	listeL courrant; 
	 	courrant =L;
	 	cout<<"les livre dans le stocke sont : "<<endl;
	 	while (courrant!= NULL){
	 		cout<<"   "<<"Titre :"  << courrant-> ele.titre<<"   " <<"l'auteure :" << courrant-> ele.N_aute<<" " << courrant-> ele.P_aute<< endl ;
	 		cout <<endl;
			 courrant = courrant->suiv;
		 }
	}
		 void afficherI(listeL L,listeL courrant){ //display book informations
	 		cout<<" num de livre : "<<courrant-> ele.Num_liv<<"   le titre de livre : " << courrant-> ele.titre<<"   nom et prenom de l'auteure : " << courrant-> ele.N_aute<<" "<< courrant-> ele.P_aute<<"   l'anne de l'edition : "<< courrant-> ele.edition<<"   Num d'exemplaire : "<< courrant-> ele.Num_exmp<< endl ;
	 		cout <<endl;
		 }
		 void afficherIE(listeL L,listeL courrant){ //display book informations borrowed
	 		cout<<" num de livre : "<<courrant-> ele.Num_liv<<"   le titre de livre : " << courrant-> ele.titre<<"   nom et prenom de l'auteure : " << courrant-> ele.N_aute<<" "<< courrant-> ele.P_aute<<"   l'anne de l'edition : "<< courrant-> ele.edition<< endl ;
	 		cout <<endl;
		 }
	void rechercheNEL(listeL L ,int x){//searche for a book borrowed by a student 
	 	listeL courrant;
	 	bool F;
	 	courrant =L;
	 	F=false;
	 	while (courrant!= NULL&F==false){
	 		if(courrant->ele.Num_liv==x){
	 		F=true;
	 		afficherIE(L,courrant);
	 	}
	 	else{
	 		courrant = courrant->suiv;
		 }
	 }
}
	 void rechercheN(listeL L){//searche for a book by numbre
	 	listeL courrant;
	 	int R;
		 int x;
	 	bool F;
			cout<<"entrer le Num de livre pour recherche : "<<endl;
			cin>> x ;
	 	courrant =L;
	 	F=false;
	 	while (courrant!= NULL&F==false){
	 		if(courrant->ele.Num_liv==x){
	 		F=true;
	 		afficherI(L,courrant);
	 	}
	 		else{
			 courrant = courrant->suiv;
		}
	 }
	 if(F==false){
	 	cout<<"le livre n'exist pas"<<endl;
	 	cout<<"pour ajouter un livre tapez 1 : "<<endl;
	 	cin>>R;
	 	if(R=1){
	 		ajouterL(L);
		 }
	 }
}
	 void rechercheT(listeL L){//search for a book by title
	 	listeL courrant; 
	 	bool F;
	 	int R;
	 	string x;
			cout<<"entrer le titre de livre pour recherche : "<<endl;
			cin>> x ;
	 	courrant =L;
	 	F=false;
	 	while (courrant!= NULL&F==false){
	 		if(courrant->ele.titre==x){
	 		F=true;
	 		afficherI(L,courrant);
	 	}
	 		else{
			 courrant = courrant->suiv;
		}
	 }
	 if(F==false){
	 	cout<<"le livre n'exist pas"<<endl;
	 	cout<<"pour ajouter un livre tapez 1 : "<<endl;
	 	cin>>R;
	 	if(R=1){
	 		ajouterL(L);
		 }
	 }
}
void verifier(listeL L){//verify a book if availble
	 	listeL courrant; 
	 	bool F;
	 	int x;
			cout<<"entrer le Num de livre pour verifier : "<<endl;
			cin>> x ;
	 	courrant =L;
	 	F=false;
	 	while (courrant!= NULL&F==false){
	 		if(courrant->ele.Num_liv==x){
	 		F=true;
	 		if(courrant->ele.Num_exmp>0){
	 		cout<<"est disponible"<<endl;
	 	}
	 		else{
	 			cout<<"ne pas disponible"<<endl;
			 }
	 	}
	 		else{
			 courrant = courrant->suiv;
		}
	 }
	 if(F==false){
	 	cout<<"le livre n'exist pas"<<endl;
	 }
}
void retourdate (listeE x , int x1 ){// calculate date of back
	int jour ;
	int mois ;
	jour=x1%30;
	mois=x1/30;
	x->ele.ret.jour=x->ele.emp.jour+jour ;
	x->ele.ret.mois=x->ele.emp.mois+mois ;
	x->ele.ret.anne=x->ele.ret.anne ;
	if(x->ele.ret.jour>30){
		x->ele.ret.jour=x->ele.ret.jour-30 ;
		x->ele.ret.mois=x->ele.ret.mois+1 ;
		if(x->ele.ret.mois>12){
			x->ele.ret.mois=x->ele.ret.mois-12 ;
		    x->ele.ret.anne=x->ele.ret.anne+1 ;
		}
	}
}
void ajouterE (listeE E,listeL L){//add a borrow operation to the list
	 int x1; int x2 ; string x3 ; string x4 ; int x5 ; int x6 ; int x7 ; int x8 ;bool F;
			cout<<"enter le num de livre: "<<endl;
				cin>> x1 ;
				F=verifierILN(L , x1);
				if(F==true){
					F=verifierDEN(L , x1);
					if(F==true){
				cout<<"enter le num de l'etudiant: "<<endl;
				cin>> x2 ;
				cout<<"enter le nom de l'etudiant: "<<endl;
				cin>> x3 ;
				cout<<"enter le prenom de l'etudiant: "<<endl;
				cin>> x4 ;
				cout<<"enter la date de l'emprunte de livre: "<<endl;
				cout<<"enter le joure l'emprunte: "<<endl;
				cin>> x5 ;
				cout<<"enter le mois de l'emprunte: "<<endl;
				cin>> x6 ;
				cout<<"enter l'anne de l'emprunte: "<<endl;
				cin>> x7 ;
				cout<<"enter le periode de l'emprunte de livre: "<<endl;
				cin>> x8 ;
				listeE p;
	 p = new maillionE;
	 p->ele.Num_livE=x1;
	 p->ele.Num_E=x2;
	 p->ele.N_E=x3;
	 p->ele.P_E=x4;
	 p->ele.emp.jour=x5;
	 p->ele.emp.mois=x6;
	 p->ele.emp.anne=x7;
	 p->ele.ret.jour=x5;
	 p->ele.ret.mois=x6;
	 p->ele.ret.anne=x7;
	 retourdate(p , x8);
	 p -> suiv = E;
	 E=p;
	 downL(L,x1);
}
else{
	cout<<"le livre n'existe pas"<<endl;
}
}
else{
	cout<< "livre ne pas disponible"<<endl;
}
}

	 void afficherE(listeE E){//display list of borrows
	 	listeE courrant; 
	 	courrant = E;
	 	cout<<"les livre dans la liste de livers empruntes sont : "<<endl;
	 	while (courrant!= NULL){
	 		cout<<"   "<<"le num de livre : "  << courrant-> ele.Num_livE<<"   " <<"le num de l'etudiant : " << courrant-> ele.Num_E<<"   " <<"le nom et prenom de l'etudiant : " << courrant-> ele.N_E<<" "<< courrant-> ele.P_E<<"   " <<"la date d'emprunt : "<< courrant-> ele.emp.jour<<"/"<<courrant-> ele.emp.mois<<"/"<<courrant-> ele.emp.anne<<"   " <<"la date de retour : " << courrant-> ele.ret.jour<<"/"<<courrant-> ele.ret.mois<<"/"<<courrant-> ele.ret.anne<< endl ;
	 		cout <<endl;
			 courrant = courrant->suiv;
		 }
	}
	void retour(listeE &E,listeL L ){
	int x;
	bool F;
	cout<<"entrer le num de livre de retour"<<endl;
	cin>>x;
	F=verifierILNE(E,x);
	if(F==true)	{
			listeE temp;
	if(E->ele.Num_livE==x)//if target is in the first node
      {
          temp = E;
          E = E->suiv;
          delete temp;
          upL(L,x);
      }
      else//if target is not in the first node
      {
      	listeE courrent;
      	courrent=E;
          while(courrent->suiv!= NULL)
          {
              if(courrent->suiv->ele.Num_livE== x)
              {
                  temp= courrent->suiv;
                  courrent->suiv= courrent->suiv->suiv;
                  delete temp;
                  upL(L,x);
                  break;
              }
              else
                  courrent= courrent->suiv;
          }
      }
		
	}
	else{
		cout<<"le livre n'existe pas dans la list de livre emprunter"<<endl;
	}
	}
	void afficherLEE(listeE E,listeL L){//display books borrowed by a student
		listeE courrent;
		int x;
		cout<<"entre le num de l'etudiant pour recherche : "<<endl;
		cin>>x;
		while(courrent!=NULL){
			if(courrent->ele.Num_E==x){
			rechercheNEL(L,courrent->ele.Num_livE);
			courrent= courrent->suiv;
		}
		else{
			cout<<"l'etudiant n'exist pas dans la liste d'emprunt"<<endl;
		}
	}
}
bool verifierDNR(listeE E,date x, int x1,int x2,int x3){
	bool F;
	F=true;
	if(x.anne<x3){
		F=false;
	}
	else{
		if(x.anne=x3){
		   if(x.mois<x2){
		F=false;
	}
	else{
		if(x.mois=x2){
		    if(x.jour<x1){
		F=false;
	}
}
}
}
}
return F;
}
void afficherLNR(listeE E,listeL L){//display books borrowed by a student
		listeE courrent;
		bool F;
		F=true;
		int x1,x2,x3;
		cout<<"enter la date de ajourdhuie: "<<endl;
				cout<<"enter le joure : "<<endl;
				cin>> x1 ;
				cout<<"enter le mois : "<<endl;
				cin>> x2 ;
				cout<<"enter l'anne de : "<<endl;
				cin>> x3 ;
		while(courrent!=NULL){
			F=verifierDNR(E,courrent->ele.ret,x1,x2,x3);
			if(F=false){
			rechercheNEL(L,courrent->ele.Num_livE);
			cout<<"la date de retoure est : "<<courrent->ele.ret.jour<<"/"<<courrent->ele.ret.mois<<"/"<<courrent->ele.ret.anne<<endl;
			courrent= courrent->suiv;
		}
		courrent= courrent->suiv;
	    }
	}
int main (){
	listeE E;
	listeL L;
	L =NULL ;
	E =NULL ;
	int choix;
	do{
		affiche_menu();
		cin>>choix;
		switch (choix){
			        case 1:
					ajouterL(L);
					    system("pause"); break;
					case 2:
					afficherL(L);
						system("pause"); break;	
					case 3:
					rechercheN(L);
						system("pause"); break;	
					case 4:
					rechercheT(L);
						system("pause"); break;	
					case 5:
					verifier(L);
						system("pause"); break;	
					case 7:
					ajouterE(E , L);
					    system("pause"); break;
					case 8:
					afficherE(E);
					    system("pause"); break;
					case 9:
					retour(E,L);
					    system("pause"); break;
					case 10:
					afficherLEE(E,L);
					    system("pause"); break;
					case 11:
					afficherLNR(E,L);
					    system("pause"); break;    
		}
	}while(choix !=0);
		system("pause");	
	
	return 0;
}

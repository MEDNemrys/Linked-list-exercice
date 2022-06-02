#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct {
	char nom[10];
	char pre[10];
	int note;
}etu;
struct list{
	etu a;
	struct list *suiv;
	struct list *pre;
};
typedef struct list list;
list* head;
list*list_cree(){
	list *temp;
	temp = (list*)malloc(sizeof(list));
	printf("insert student first name :");
	scanf("%s",temp->a.nom);
	printf("insert student last name :");
	scanf("%s",temp->a.pre);
	printf("insert student grade :");
	scanf("%d",&temp->a.note);
	temp->suiv=NULL;
	temp->pre=NULL;
	return temp;
}
void list_gener( int n){
	int i;
	list* temp;
	list *nouv;
	list *nouv1;
	nouv = list_cree();
	head = nouv;
	temp = head;
	for(i=1;i<n;i++){
		nouv1 = list_cree();
		temp->suiv =nouv1;
		temp->suiv->pre = temp;
		temp = nouv1;	
		
	}
	
	
}
void affiche_deb();
void lis_av_debut(){/*------------------------------INSERT BEFORE HEAD-----------------------------*/
	list *temp;
	list *nouv;
	nouv = list_cree();
	if(head==NULL) {
	head = nouv;
	
	}else{
		head->pre = nouv;
		nouv->suiv = head; 
		head = nouv;
	}
	affiche_deb();
		
}
void lis_fin();
void lis_ap_debut(){/*------------------------------INSERTION AFTER HEAD-----------------------------*/
	list *temp;
	list *nouv;
	list *aux;
	temp = head;
	nouv = list_cree();
	aux = head->suiv;
	if(temp==NULL) {
	head = nouv;
	
	}else if(temp->suiv = NULL){
		lis_fin();
		
	}else{	
		aux->pre = nouv;
		head->suiv = nouv;
		nouv->suiv = aux;
		nouv->pre = head;
		}
		affiche_deb();
}

list* rech_fin(){ /*-----------------------------------------SEARCH LAST ONE---------------------------*/
	list *temp;
	temp = head;
	while(temp->suiv != NULL){
		temp = temp->suiv;
	}
	return temp;
}
int rech_fpos(){/*--------------------------------------LIST LENGTH----------------------*/
		list *temp;
		int k=0;
	temp = head;
	while(temp != NULL){
		temp = temp->suiv;
		k++;
	}
	return k;
}
void lis_fin(){/*----------------------------INSERT IN LAST----------------------------------------*/
	list *temp;
	list *fin;
	temp = rech_fin(head);
	fin = list_cree();
	temp->suiv = fin;
	fin->pre = temp;
}
list* rech_elem(int pos){/*---------------------------- SEARCH WITH POSITION ----------------------------------------*/
	int i;
	list* temp;
	temp=head;
	i = 1;
	while(i<pos && temp != NULL){
	temp = temp->suiv;
	i++;
	}
	return temp;
}
void lis_av_ele(int pos){/*-----------------------------------------INSERT BEFORE ELEMENT----------------------------*/
	list *temp;
	list *nouv;
	int p;
	p = rech_fpos();
	if(pos==1){
		lis_av_debut(head);
		
	}else if(pos >= p){
		lis_fin(head);
		 
	}else{
	nouv = list_cree();
	temp = rech_elem(pos);
	temp->pre->suiv = nouv;
	nouv->pre = temp->pre;
	nouv->suiv = temp;
	temp->pre = nouv;
	affiche_deb();
}

}
void lis_ap_ele(int pos){/*--------------------------------------INSERT AFTER ELEMENT------------------------*/
	list *temp;
	list *nouv;
	list *aux;
	int p;
	p = rech_fpos(head);
	if(pos==1){
	lis_ap_debut(head);
		
}else if(pos >= p){
		lis_fin(head);
		 
	}else{
	
	nouv = list_cree();
	temp = rech_elem(pos);
	aux = temp->suiv;
	aux->pre = nouv;
	temp->suiv = nouv;
	nouv->suiv = aux;
	nouv->pre = temp;
}
affiche_deb();
}
void affiche_deb(){/*------------------------------------DISPLAY FIRST-LAST-------------------------------------*/
	list *temp;
	temp = head;
	while(temp != NULL){
		printf("%s %s %d\t",temp->a.nom,temp->a.pre,temp->a.note);
		temp = temp->suiv;	
	}
	printf("\n");
}
void affiche_fin(){/*--------------------------------------------DISPLAY LAST-FIRST-----------------------------*/
	list *temp;
	temp = rech_fin(head);
	while(temp!=NULL){
		printf("%s %s %d\t",temp->a.nom,temp->a.pre,temp->a.note);
		temp = temp->pre;
	}
}
list* supp_elem(int pos){/*-------------------------------------------DELETE ELEMENT ------------------------------------------*/
	int p;
	list* temp;
	list* aux;
	list* aux1;
	p = rech_fpos();
	temp = rech_elem(pos);
	if(pos == 1 || temp->pre == NULL){
		if(temp->suiv == NULL){
			free(temp);
		}else{
			aux = temp;
			temp = temp->suiv;
			temp->pre = NULL;
			head = temp;
			free(aux);
			return head;
		}
	}
	if(pos >= p){
		if(temp->pre == NULL){
			free(head);
		}else{
			aux = temp;
			temp->pre->suiv = NULL;
			free(aux);
			
		}
	}else{
		aux = temp;
		aux1 = temp->suiv;
		temp->suiv->pre = temp->pre;
		temp->pre->suiv = temp->suiv;
		free(aux);
		return aux1;
	}
	
		
	}
int rech_val_pos(int val){
	list* temp;
	int i = 1;
	temp = head;
	while(temp->a.note != val){
		i++;
		temp = temp->suiv;	
	}
	return i;
}


list* supp_val(int val){/*--------------------------------------DELETE VALUE ---------------------------*/
	int k;
	list* temp;
	k = rech_val_pos(val);
	temp= supp_elem(k);
		return temp;
}
list* supp_infer(int val){
	int k,i;
	list* temp;
	temp = head;
	while(temp != NULL){
		if(temp->a.note <= val){
		temp = supp_val(temp->a.note);	
		}else{
			temp = temp->suiv;
		}
	}
	return head;
	
}

void inver_list(){/*----------------------------InversE LIST----------------------*/
	list *temp;
	list *aux;
	int i;
	etu k;
	int d,l;
	d = rech_fpos();
	l = d;
	temp = head;
	while(d != 1){
	for(i=1;i<d; i++){
		aux = temp->suiv;
		k = temp->a;
		temp->a = aux->a;
		aux->a = k;
		temp = temp->suiv; 
	}
	temp = head;
	d--;
 	}
	 }
void tri_bulle(){/*----------------------ORDERING LIST----------------------------*/
	list *temp;
	list *aux;
	int i;
	etu k;
	int d,l;
	d = rech_fpos();
	l = d;
	temp = head;
	while(d != 1){
	for(i=1;i<d; i++){
		aux = temp->suiv;
		if(temp->a.note > aux->a.note){
		k = temp->a;
		temp->a = aux->a;
		aux->a = k;
		}
		temp = temp->suiv; 
	}
	temp = head;
	d--;
 	}
}
void inse_croi(){/*------------------------insert elemnt and order list---------------------*/
	int pos;
	printf("which position?");
	scanf("%d",&pos);
	lis_av_ele(pos);
}
	
int main(){
	system("COLOR 61");
	int k,z;
	 int p,l;
	 int menu;
	 do{
	 system("cls");
	 printf("\t\t==================================================\n");
		printf("\t\t STUDENT INFO : FNAME-LNAME-GRADE  By:MOUTOUT\n");
		printf("\t\t==================================================\n\n");
		printf("\t\t--------------------------------------------------\n");
		printf("\t\t||\t1. create list \t\t\t\t ||\n");
		printf("\t\t||\t2. display list \t\t\t ||\n");
		printf("\t\t||\t3. Inverse List \t\t\t ||\n");
		printf("\t\t||\t4. Ordered List \t\t\t ||\n");
		printf("\t\t||\t5. Insert before 1st element\t\t ||\n");
		printf("\t\t||\t6. Insert after 1st element\t\t ||\n");
		printf("\t\t||\t7. Insert before element specified\t ||\n");
		printf("\t\t||\t8. Insert after element specified\t ||\n");
		printf("\t\t||\t9. Delete element \t\t\t ||\n");
		printf("\t\t||\t10. Exit\t\t\t\t\t ||\n");
		printf("\t\t--------------------------------------------------\n");
		printf("Enter choice: ");
		scanf("%d",&menu);
		switch(menu){
			case 1 : printf("Number of students : ");
     				 scanf("%d",&k);
     				 list_gener(k);
     				 break;
     		case 2  : printf("\n-------------List------------\n");
			 		  affiche_deb();
			 		  system("PAUSE");
			 		  break;
			case 3  : affiche_fin();
						system("PAUSE");
						break;
			case 4  :  tri_bulle();
						break;
						system("PAUSE");
			case 5   : lis_av_debut();
							system("PAUSE");
						break;
			case 6   : lis_ap_debut();
						break;
			case 7  :  printf("position?");
     					scanf("%d\n",&p);
     					lis_av_ele(p);
     					break;
     		case 8  : 	printf("which position?");
     					scanf("%d\n",&p);
     					lis_ap_ele(p+1);
     		case 9 : printf("which position?");
					scanf("%d",&l);
					supp_elem(l);
					break;
			case 10 : menu=10;
					break;
			default : printf("invalid number!!");
						break;
     					
		}}while(menu!=10);     
	 
}	
	


#include <header.h>
#include<stdio.h>
typedef struct categories{
	int category_id;
	char category_desc[80];
	char Gender[2];
	int Min_age;
	int Max_age;
	struct categories *next;
}categories;

categories *head_categories=NULL, *current_categories=NULL;
void modifycategories()
{
	int cid,found=0;
	printf("Enter Category ID to modify  : ");
        scanf("%d", &cid);
        current_categories=head_categories;
	while(current_categories!=NULL){
	if(current_categories->category_id==cid){
		printf("\nEnter new Description : ");
		scanf("%s",current_categories->category_desc);
		printf("\nEnter the Gender : ");
		scanf("%s",current_categories->Gender);
		printf("\nEnter the new minimum age : ");
		scanf("%d",&current_categories->Min_age);
		printf("\nEnter the new maximum age : ");
		scanf("%d",&current_categories->Max_age);
		found=1;
	}
	current_categories=current_categories->next;
	}
       if(found){
                printf("\n\nCategory Updated Successfully.....\n");
       }else{
       printf("\n\nRecord not found......\n");
       }system("pause");
}       


void readcategories()
{
	head_categories=NULL, current_categories=NULL;
	FILE *fp=fopen("categories.txt","r");
	categories c1, *node;
	while(fscanf(fp,"%d,%[^,],%[^,],%d,%d\n", &c1.category_id,c1.category_desc,c1.Gender,&c1.Min_age,&c1.Max_age)!=EOF)
	{
	node=(categories*)malloc(sizeof(categories));
	node->category_id=c1.category_id;
	strcpy(node->category_desc,c1.category_desc);
	strcpy(node->Gender,c1.Gender);
	node->Min_age=c1.Min_age;
	node->Max_age=c1.Max_age;
	node->next=NULL;

	if(head_categories==NULL)
{
	current_categories=head_categories=node;
}else{
	current_categories=current_categories->next=node;
}
}fclose(fp);
}


int autoIncreamentcategories(){
	int id=0;
	for(current_categories=head_categories; current_categories; current_categories=current_categories->next)
		id=current_categories->category_id;
	return id+1;
}


void addcategories(){
	categories c,*node;
	
          printf("\n\t\t\tEnter category desc  : ");
          scanf("%s",&c.category_desc);
          printf("\n\t\t\tEnter Gender  : ");
          scanf("%s",&c.Gender);
          printf("\n\t\t\tEnter minimum age  : ");
          scanf("%d",&c.Min_age);
          printf("\n\t\t\tEnter maximum age  : ");
          scanf("%d",&c.Max_age);
         
          printf("\n\t\t\t______________________________\n");
  node=(categories*)malloc(sizeof(categories));
  node->category_id=autoIncreamentcategories();
  strcpy(node->category_desc, c.category_desc);
  strcpy(node->Gender,c.Gender);
  node->Min_age=c.Min_age;
  node->Max_age=c.Max_age;
  node->next=NULL;

  if(head_categories==NULL){
	  head_categories=node;
  }else{
	  current_categories=head_categories;
	  while(current_categories->next!=NULL)
		  current_categories=current_categories->next;
	  current_categories->next=node;
  }
}


void displaycategories(){
	printf("\n%-5s%-20s%-20s%-20s%-20s%\n","ID","DESC","GEN","MIN_AGE","MAX_AGE");
	printf("\n-------------------------------------------------------------------------------------------------\n");
	for(current_categories=head_categories; current_categories; current_categories=current_categories->next)
		printf("%-5d%-20s%-20s%7d%20d\n",current_categories->category_id,current_categories->category_desc,current_categories->Gender,current_categories->Min_age,current_categories->Max_age);
        
}


void writecategories(){
	FILE *fp=fopen("categories.txt","w");
        
		for(current_categories=head_categories; current_categories; current_categories=current_categories->next)
		{
			fprintf(fp,"%d,%s,%s,%d,%d\n", current_categories->category_id,current_categories->category_desc,current_categories->Gender,current_categories->Min_age,current_categories->Max_age);}
		fclose(fp);
}

void deletecategories(){
	int cid, found=0;
	printf("Enter Category ID to delete : ");
	scanf("%d",&cid);

	current_categories =head_categories;
	if(current_categories->category_id == cid){
		head_categories = current_categories-> next;
		free(current_categories);
		found=1;
	}

	while(current_categories->next!=NULL){
		categories *tmp = current_categories-> next;
		if(tmp->category_id ==cid){
			current_categories->next=tmp->next;
			free(tmp);
			found=1;
			break;
		}
		current_categories= current_categories->next;
	}

	if(found){
		printf("\n\nCategory Deleted successfully...!");
	}
	else{
	printf("\n\nRecord Not Found\n\n");
	}
        system("pause");
}
typedef struct player{
	int player_id[8];
	char name[25];
	char address[50];
	char district[20];
	char city[20];
	char aadhar_number[13];
	char birth_date[10];
	struct player *next;

}player;

player *head_player = NULL, *current_player=NULL;

void readplayerFile(){

	head_player=NULL, current_player=NULL;
	FILE *fp =fopen("player.txt","r");
	player p1, *node;

	while(fscanf(fp,"%d,%[^,],%[^,],%[^,],%[^,],%[^,],%[^,] \n",p1.player_id,p1.name,p1.address,p1.district,p1.city,p1.aadhar_number,p1.birth_date)!=EOF){
		node =(player *)malloc(sizeof(player));
		node->player_id == p1.player_id;
		strcpy(node->name,p1.name);
		strcpy(node->address,p1.address);
		strcpy(node->district,p1.district);
		strcpy(node->city,p1.city);
		strcpy(node->aadhar_number,p1.aadhar_number);
		strcpy(node->birth_date,p1.birth_date);
		node->next = NULL;

		if(head_player == NULL){
			current_player=head_player=node;
	}else{
		current_player= current_player->next=node;
	}
	}fclose(fp);
}
int autoIncrementplayer(){
	int id =0;
	for(current_player = head_player;current_player;current_player=current_player->next)
            id=current_player->player_id;
	return id+1;
}
void modifyplayer(){
	int pid, found=0;
	printf("Enter player Id TO modify : ");
	scanf("%d",&pid);

	current_player = head_player;
	while(current_player!=NULL){
		if(current_player->player_id==pid){
			printf("Enter new name : ");
			scanf("%s",current_player->name);
			printf("Enter new address : ");
			scanf("%s",current_player->address);
			printf("Enter new district : ");
			scanf("%s",current_player->district);
			printf("Enter new city : ");
			scanf("%s",current_player->city);
			printf("Enter new adhar number : ");
			scanf("%s",current_player->aadhar_number);
			printf("Enter new birthdate :");
			scanf("%s",current_player->birth_date);
			found=1;
		}
		current_player =current_player -> next;
	}
	if(found){
		printf("\n\n Player Updated Successfully....!");
	}
	else{
		printf("\n\nRecord not Found\n\n");
	}
	system("pause");
}
void deleteplayer(){
	int pid, found=0;
	printf("Enter player ID to delete : ");
	scanf("%d",&pid);

	current_player =head_player;
	if(current_player->player_id == pid){
		head_player = current_player -> next;
		free(current_player);
		found=1;
	}

	while(current_player->next!=NULL){
		player *tmp = current_player -> next;
		if(tmp->player_id ==pid){
			current_player -> next =tmp->next;
			free(tmp);
			found=1;
			break;
		}
		current_player = current_player -> next;
	}

	if(found){
		printf("\n\nPlayer Deleted successfully...!");
	}
	else{
	printf("\n\nRecord Not Found\n\n");
	}
        system("pause");	
}


void addplayer(){
player p, *node;
	printf("\n\t\t\tEnter the  Player name :    ");
	scanf("%s",p.name);
	printf("\n\t\t\tEnter the  player address :    ");
	scanf("%s",p.address);
	printf("\n\t\t\tEnter the player district :    ");
	scanf("%s",p.district);
	printf("\n\t\t\tEnter the player city :    ");
	scanf("%s",p.city);
	printf("\n\t\t\tenter the player aadharNumber :   ");
	scanf("%s",p.aadhar_number);
	printf("\n\t\t\tEnter the player birthdate :   ");
	scanf("%s",p.birth_date);

	printf("\n\t\t\t____________________________________________\n");

node=(player *)malloc(sizeof(player));
node->player_id == autoIncrementplayer();
strcpy(node->name, p.name);
strcpy(node->address, p.address);
strcpy(node->district, p.district);
strcpy(node->city, p.city);
strcpy(node->aadhar_number, p.aadhar_number);
strcpy(node->birth_date, p.birth_date);
node->next = NULL;


	if(head_player==NULL){
		head_player =node;
	}else{
		current_player = head_player;
		while(current_player->next!=NULL)
			current_player = current_player -> next;
		current_player->next =node;

	}
	
}
void displayplayer(){
	printf("\n%-5s%-10s%-10s%-10s%-10s%-10s%-20s \n","ID","NAME","ADDRESS","DISTRICT","CITY","AADHAR_NUMBER","BIRTH_DATE");
	printf("\n-------------------------------------------------------------------------\n");
	for(current_player = head_player; current_player;current_player = current_player->next)
		printf("%-5d%-10s%-10s%-10s%-10s%-10s%-20s \n",current_player->player_id,current_player->name,current_player->address,current_player->district,current_player->city,current_player->aadhar_number,current_player->birth_date);
	
} 
void writeplayer(){
	FILE *fp=fopen("player.txt","w");
        
		for(current_player=head_player; current_player; current_player=current_player->next)
		{
			fprintf(fp,"%d,%s,%s,%s,%s,%s,%s\n", current_player->player_id,current_player->name,current_player->address,current_player->district,current_player->city,current_player->aadhar_number,current_player->birth_date);}
		fclose(fp);
}







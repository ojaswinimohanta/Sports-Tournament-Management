#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct team
{
	int team_id;
	char team_name[25];
	char owner[25];
	int noofmatches;
	struct team *next;
} team;

team *head_team = NULL, *current_team = NULL;


void modifyteam()
{
	int tid,found=0;
	printf("Enter Team ID to modify  :");
        scanf("%d", &tid);
        current_team=head_team;
	while(current_team!=NULL){
	if(current_team->team_id==tid){
		printf("\nEnter new Team Name :");
		scanf("%s",current_team->team_name);
		printf("\nEnter the new No Of Matches :");
		scanf("%d",&current_team->noofmatches);
		printf("\nEnter the new Owner  :");
		scanf("%s",current_team->owner);
	
		found=1;
	}
	current_team=current_team->next;
	}
       if(found){
                printf("\n\nTeam Updated Successfully.....\n");
       }else{
       printf("\n\nRecord not found......\n");
       }system("paused");
}       


void readteam()
{
	head_team=NULL, current_team=NULL;
	FILE *fp=fopen("team.txt","r");
	team c1, *node;
	while(fscanf(fp,"%d,%[^,],%d,%[^,]\n", &c1.team_id,c1.team_name,&c1.noofmatches,c1.owner)!=EOF)
	{
	node=(team*)malloc(sizeof(team));
	node->team_id=c1.team_id;
	strcpy(node->team_name,c1.team_name);
	node->noofmatches=c1.noofmatches;
	strcpy(node->owner,c1.owner);
	
	node->next=NULL;

	if(head_team==NULL)
{
	current_team=head_team=node=node;
}else{
	current_team=current_team->next=node;
}
}fclose(fp);
}



int autoIncreamentteam()
{
	int id = 0;
	for (current_team = head_team; current_team;current_team=current_team->next)
		id = current_team->team_id;
	return id + 1;
}
void addteam()
{
	team c, *node;

	printf("\n\t\t\tEnter team_name     : ");
	scanf("%s", &c.team_name);
	printf("\n\t\t\tEnter owner      : ");
	scanf("%s", &c.owner);
	printf("\n\t\t\tEnter no of matches : ");
	scanf("%d", &c.noofmatches);

	printf("\n\t\t\t___________________________\n");
	node = (team*)malloc(sizeof(team));
	node->team_id = autoIncreamentteam();
      strcpy(node->team_name, c.team_name);
	strcpy(node->owner, c.owner);
	node->noofmatches = c.noofmatches;
	node->next = NULL;

	if (head_team == NULL)
	{
		head_team = node;
	}
	else
	{
		current_team = head_team;
		while (current_team->next!= NULL)
			current_team = current_team->next;
		current_team->next = node;
	}
}
void displayteam()
{
	printf("\n%-5s%-25s%-20s%-20s%\n", "team_ID", "team_name", "owner", "noofmatches");
	printf("\n-------------------------------------------------------------------------------------------------\n");
	for (current_team = head_team; current_team; current_team = current_team->next)
		printf("%-5d%-25s%-20s%20d\n", current_team->team_id, current_team->team_name, current_team->owner, current_team->noofmatches);
	
}
void writeteam()
{
	FILE *fp = fopen("team.txt", "w");

	for (current_team = head_team; current_team; current_team = current_team->next)
	{
		fprintf(fp, "%d,%s,%d,%s\n", current_team->team_id, current_team->team_name, current_team->noofmatches, current_team->owner);
	}
	fclose(fp);
}
void deleteteam(){
	int tid, found=0;
	printf("Enter Team ID to delete : ");
	scanf("%d",&tid);

	current_team =head_team;
	if(current_team->team_id == tid){
		head_team = current_team-> next;
		free(current_team);
		found=1;
	}

	while(current_team->next!=NULL){
		team *tmp = current_team-> next;
		if(tmp->team_id ==tid){
			current_team->next=tmp->next;
			free(tmp);
			found=1;
			break;
		}
		current_team= current_team->next;
	}

	if(found){
		printf("\n\nTeam Deleted successfully...!");
	}
	else{
	printf("\n\nRecord Not Found\n\n");
	}
        system("pause");
}






int main()
{
	int ch;
	int returnValue = 0;
/*	char password[20];
	char p[] = "admin";
	printf("Enter Password :");
	scanf("%s", password);

	val = strcmp(p, password);
	if (val == 0)
	{
		printf("Login SucessFully");
	}
	else
		printf("\nInvalid assword");  */

	readteam();
	do
	{
		system("cls");
		printf("---------Sportz - A Sport Tournament System---------\n");
		printf("1. Manage Categories\n");
		printf("2. Manage Players\n");
		printf("3. Manage Teams\n");
		printf("4. Manage Tournaments\n");
		printf("5. Manage Matches\n");
		printf("6. Reports\n");
		printf("0. Quit\n\n");

		printf("Enter your option: ");
		returnValue = scanf("%d", &ch);
		printf("\n");
		if (returnValue == 0 || returnValue == EOF)
		{
			fflush(stdin);
			printf("Invalid input. Please enter valid input\n");
			break;
		}

		switch (ch)
		{
	/*	case 1:
		{
			int ch1;
			do
			{
				system("cls");
				printf("---------Categories Menu---------\n");
				printf("1. Add Category\n");
				printf("2. Modify Category\n");
				printf("3. Delete Category\n");
				printf("4. Display Category\n");
				printf("0. Quit\n\n");

				printf("Enter your option: ");
				returnValue = scanf("%d", &ch1);
				printf("\n");
				if (returnValue == 0 || returnValue == EOF)
				{
					fflush(stdin);
					printf("Invalid input. Please enter valid input\n");
					break;
				}

				switch (ch1)
				{
				case 1:
					// addcategories();
					// Call the Add Category Function
					break;
				case 2:
					// Call the Modify Category Function
					break;
				case 3:
					// Call the Delete Category Function
					break;
				case 4: // displaycategories();
						//       break;
				case 0:
					// printf("Exiting Categories Menu\n");
					break;
				default:
					//	printf("You have entered an Invalid Option\n");
					break;
				}
			} while (ch1 != 0);

		case 2:
		{
			int ch2;
			do
			{
				printf("---------Players Menu---------\n");
				printf("1. Add Player\n");
				printf("2. Modify Player\n");
				printf("3. Delete Player\n");
				printf("0. Quit\n\n");

				printf("Enter your option: ");
				returnValue = scanf("%d", &ch2);
				printf("\n");
				if (returnValue == 0 || returnValue == EOF)
				{
					fflush(stdin);
					printf("Invalid input. Please enter valid input\n");
					break;
				}

				switch (ch2)
				{
				case 1:
					// Call the Add Player Function
					break;
				case 2:
					// Call the Modify Player Function
					break;
				case 3:
					// Call the Delete Player Function
					break;
				case 0:
					printf("Exiting Players Menu\n");
					exit(0);
				default:
					printf("You have entered an Invalid Option\n");
					break;
				}
			} while (ch2 != 0);
		}*/

		case 3:
		  
			int ch3;
			do
			{
                     system("cls");
				printf("---------Teams Menu---------\n");
				printf("1. Add Team\n");
				printf("2. Modify Team\n");
				printf("3. Delete Team\n");
				printf("4. Display Team\n");
				printf("0. Quit\n\n");

				printf("Enter your option: ");
				returnValue = scanf("%d", &ch3);
				printf("\n");
				if (returnValue == 0 || returnValue == EOF)
				{
					fflush(stdin);
					printf("Invalid input. Please enter valid input\n");
					break;
				}

				switch (ch3)
				{
				case 1:
				    addteam();
					// Call the Add Team Function
					break;
				case 2:modifyteam();
					// Call the Modify Team Function
					break;
				case 3:deleteteam();
					// Call the Delete Team Function
					break;
				case 4:displayteam();
					break;
				case 0:
					printf("Exiting Teams Menu\n");
					break;
				default:
					printf("You have entered an Invalid Option\n");
					break;
				}
			} while (ch3 != 0);
		  
		

			/*	case 4:
			  int ch4;
			  do
			  {
				  printf("---------Tournaments Menu---------\n");
					  printf("1. Add Tournament\n");
				  printf("2. Modify Tournament\n");
				  printf("3. Delete Tournament\n");
				  printf("0. Quit\n\n");

				  printf("Enter your option: ");
				  returnValue = scanf ("%d", &ch4);
				  printf("\n");
				  if ( returnValue == 0 || returnValue ==  EOF)
				  {
					  fflush(stdin);
					  printf("Invalid input. Please enter valid input\n");
					  break;
				  }

				  switch(ch4)
				  {
					  case 1:
						  //Call the Add Tournament Function
						  break;
					  case 2:
						  //Call the Modify Tournament Function
						  break;
					  case 3:
						  //Call the Delete Tournament Function
						  break;
					  case 0:
						  printf("Exiting Tournaments Menu\n");
						  exit(0);
					  default:
							  printf("You have entered an Invalid Option\n");
						  break;
				  }
			  } while (ch4 !=0);

		  case 5:
			  int ch5;
			  do
			  {
				  printf("---------Matches Menu---------\n");
					  printf("1. Add Match\n");
				  printf("2. Modify Match\n");
				  printf("3. Delete Match\n");
				  printf("0. Quit\n\n");

				  printf("Enter your option: ");
				  returnValue = scanf ("%d", &ch5);
				  printf("\n");
				  if ( returnValue == 0 || returnValue ==  EOF)
				  {
					  fflush(stdin);
					  printf("Invalid input. Please enter valid input\n");
					  break;
				  }

				  switch(ch5)
				  {
					  case 1:
						  //Call the Add Match Function
						  break;
					  case 2:
						  //Call the Modify Match Function
						  break;
					  case 3:
						  //Call the Delete Match Function
						  break;
					  case 0:
						  printf("Exiting Matches Menu\n");
						  exit(0);
					  default:
							  printf("You have entered an Invalid Option\n");
						  break;
				  }
			  } while (ch5 !=0);

		  case 6:
			  int ch6;
			  do
			  {
				  printf("---------Reports Menu---------\n");
					  printf("1. List Results of Matches in a Tournament\n");
				  printf("2. List Matches played by a player\n");
				  printf("3. List Teams and number of matches won by them\n");
				  printf("0. Quit\n\n");

				  printf("Enter your option: ");
				  returnValue = scanf ("%d", &ch6);
				  printf("\n");
				  if ( returnValue == 0 || returnValue ==  EOF)
				  {
					  fflush(stdin);
					  printf("Invalid input. Please enter valid input\n");
					  break;
				  }

				  switch(ch6)
				  {
					  case 1:
						  //Call the Function For List Results of Matches in a Tournament
						  break;
					  case 2:
						  //Call the Function For List Matches played by a player
						  break;
					  case 3:
						  //Call the Function For List Teams and number of matches won by them
						  break;
					  case 0:
						  printf("Exiting Reports Menu\n");
						  exit(0);
					  default:
							  printf("You have entered an Invalid Option\n");
						  break;
				  }
			  } while(ch6 !=0);*/

		  case 0:
			writeteam();
			printf("\nData updated successfully into the file\n");
			
			break;
		default:
			printf("Invalid Choice\n");
			break;
		}
	} while (ch != 0);

	return EXIT_SUCCESS;
}


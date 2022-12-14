#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct tournament
{
    int tournament_id;
    char FromDate[10];
    char ToDate[10];
    char TDesc[50];
    char Manager[25];
    int NoOfMatches;
    struct tournament *next;
} tournament;

tournament *head_tournament = NULL , *current_tournament = NULL;

int  autoIncreamenttournament()
{
    int id = 0;
    for (current_tournament = head_tournament; current_tournament; current_tournament = current_tournament)
        id = current_tournament->tournament_id;
    return id + 1;
}
void modifyTournament(){
	int pid, found=0;
	printf("Enter Tournament Id  which You want to modify :");
	scanf("%d",&pid);

	current_tournament = head_tournament;
	while(current_tournament!=NULL){
		if(current_tournament->tournament_id==pid){
    printf("Enter Tournament Id");
    scanf("%d",current_tournament->tournament_id);
    printf("\n\t\t\tEnter FromDate     : ");
    scanf("%s",current_tournament->FromDate);
    printf("\n\t\t\tEnter ToDate      : ");
    scanf("%s", current_tournament->ToDate);
    printf("\n\t\t\tEnter Manager : ");
    scanf("%s",current_tournament->Manager);
    printf("\n\t\t\tEnter NoOfMatches  : ");
    scanf("%d",current_tournament->NoOfMatches);
    found=1;
		
		}
		current_tournament =current_tournament -> next;
	}
	if(found){
		printf("\n\n Tournament DEtails Updated Successfully....!");
	}
	else{
		printf("\n\n Record not Found\n\n");
	}
	system("pause");
}
void deleteTournament(){
	int pid, found=0;
	printf("Enter player ID to delete : ");
	scanf("%d",&pid);

	current_tournament =head_tournament;
	if(current_tournament->tournament_id == pid){
		head_tournament = current_tournament -> next;
		free(current_tournament);
		found=1;
	}

	while(current_tournament->next!=NULL){
		tournament *tmp = current_tournament -> next;
		if(tmp->tournament_id ==pid){
			current_tournament -> next =tmp->next;
			free(tmp);
			found=1;
			break;
		}
		current_tournament = current_tournament -> next;
	}

	if(found){
		printf("\n\n Tournament Deleted successfully...!");
	}
	else{
	printf("\n\nRecord Not Found\n\n");
	}
        system("pause");	
}


//_____________________________________________________________________________

void addtournament()
{
    tournament c, *node;
    printf("\n\t\t\tEnter Tournament ID: ");
    scanf("%d", &c.tournament_id);
    printf("\n\t\t\tEnter FromDate     : ");
    scanf("%s", &c.FromDate);
    printf("\n\t\t\tEnter ToDate      : ");
    scanf("%s", &c.ToDate);
    printf("\n\t\t\tEnter Manager : ");
    scanf("%s", &c.Manager);
    printf("\n\t\t\tEnter NoOfMatches  : ");
    scanf("%d", &c.NoOfMatches);
    printf("\n\t\t\t____________\n");

  
    node = (tournament *)malloc(sizeof(tournament));
    node->tournament_id = autoIncreamenttournament();
    strcpy(node->FromDate, c.FromDate);
    strcpy(node->ToDate, c.ToDate);
    strcpy(node->TDesc, c.TDesc);
    strcpy(node->Manager, c.Manager);
    node->NoOfMatches = c.NoOfMatches;
    node->next = NULL;

    if (head_tournament == NULL)
    {
        head_tournament = node;
    }
    else
    {
        current_tournament = head_tournament;
        while (current_tournament != NULL)
            current_tournament = current_tournament;
        current_tournament = node;
    }
}
void displaytournament()
{
    printf("\n%-5s%-20s%-20s%-20s%-20s\n", "tournament_ID", "FromDate", "ToDate", "Manager", "noofmatches");
    printf("\n-------------------------------------------------------------------------------------------------\n");
    for (current_tournament = head_tournament; current_tournament; current_tournament = current_tournament->next)
        printf("%-5d%-20s%-20s%7d%20d\n", current_tournament->tournament_id, current_tournament->FromDate, current_tournament->ToDate, current_tournament->Manager, current_tournament->NoOfMatches);
    system("pause");
}
void writetournament()
{
    FILE *fp = fopen("tournament.txt", "w");

    for (current_tournament = head_tournament; current_tournament; current_tournament = current_tournament)
    {
        fprintf(fp, "%d,%s,%s,%d,%d\n", current_tournament->tournament_id, current_tournament->ToDate, current_tournament->FromDate, current_tournament->Manager, current_tournament->NoOfMatches);
    }
    fclose(fp);
}
int main()
{
    int ch, val;
    int returnValue = 0;
    char password[20];
    char p[] = "admin";
    printf("Enter Password :");
    scanf("%s", password);

    val = strcmp(p, password);
    if (val == 0)
    {
        printf("Login SucessFully");
    }
    else
        printf("\nInvalid password");

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
            /*
        case 1:{
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
            } while (ch1 != 0);}

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
        }

        case 3:
        {
            int ch3;
            do
            {
                printf("---------Teams Menu---------\n");
                printf("1. Add Team\n");
                printf("2. Modify Team\n");
                printf("3. Delete Team\n");
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
                    //addteam();
                    // Call the Add Team Function
                    break;
                case 2:
                    // Call the Modify Team Function
                    break;
                case 3:
                    // Call the Delete Team Function
                    break;
                case 0:
                    printf("Exiting Teams Menu\n");
                    exit(0);
                default:
                    printf("You have entered an Invalid Option\n");
                    break;
                }
            } while (ch3 != 0);
        }
        */

        case 4:{
            int ch4;
            do
            {
                printf("---------Tournaments Menu---------\n");
                printf("1. Add Tournament\n");
                printf("2. Modify Tournament\n");
                printf("3. Delete Tournament\n");
                printf("4. Display Tournament");
                printf("0. Quit\n\n");

                printf("Enter your option: ");
                returnValue = scanf("%d", &ch4);
                printf("\n");
                if (returnValue == 0 || returnValue == EOF)
                {
                    fflush(stdin);
                    printf("Invalid input. Please enter valid input\n");
                    break;
                }

                switch (ch4)
                {
                case 1:
                      addtournament();
                    // Call the Add Tournament Function
                    break;
                case 2:
                     modifyTournament();
                    // Call the Modify Tournament Function
                    break;
                case 3:
                     deleteTournament();
                    // Call the Delete Tournament Function
                    break;
                case 0:
                    displaytournament();
                    printf("Exiting Tournaments Menu\n");
                    exit(0);
                default:
                    printf("You have entered an Invalid Option\n");
                    break;
                }
            } while (ch4 != 0);}

     /* case 5:{
            int ch5;
            do
            {
                printf("---------Matches Menu---------\n");
                printf("1. Add Match\n");
                printf("2. Modify Match\n");
                printf("3. Delete Match\n");
                printf("0. Quit\n\n");

                printf("Enter your option: ");
                returnValue = scanf("%d", &ch5);
                printf("\n");
                if (returnValue == 0 || returnValue == EOF)
                {
                    fflush(stdin);
                    printf("Invalid input. Please enter valid input\n");
                    break;
                }

                switch (ch5)
                {
                case 1:
                    // Call the Add Match Function
                    break;
                case 2:
                    // Call the Modify Match Function
                    break;
                case 3:
                    // Call the Delete Match Function
                    break;
                case 0:
                    printf("Exiting Matches Menu\n");
                    exit(0);
                default:
                    printf("You have entered an Invalid Option\n");
                    break;
                }
            } while (ch5 != 0);}

        case 6:{
            int ch6;
            do
            {
                printf("---------Reports Menu---------\n");
                printf("1. List Results of Matches in a Tournament\n");
                printf("2. List Matches played by a player\n");
                printf("3. List Teams and number of matches won by them\n");
                printf("0. Quit\n\n");

                printf("Enter your option: ");
                returnValue = scanf("%d", &ch6);
                printf("\n");
                if (returnValue == 0 || returnValue == EOF)
                {
                    fflush(stdin);
                    printf("Invalid input. Please enter valid input\n");
                    break;
                }

                switch (ch6)
                {
                case 1:
                    // Call the Function For List Results of Matches in a Tournament
                    break;
                case 2:
                    // Call the Function For List Matches played by a player
                    break;
                case 3:
                    // Call the Function For List Teams and number of matches won by them
                    break;
                case 0:
                    printf("Exiting Reports Menu\n");
                    exit(0);
                default:
                    printf("You have entered an Invalid Option\n");
                    break;
                }
            } while (ch6 != 0);}
*/
        case 0:
            //writeteam();
            printf("\nTopic written successfully into the file\n");
            system("pause");
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }
    } while (ch != 0);

    return EXIT_SUCCESS;
}

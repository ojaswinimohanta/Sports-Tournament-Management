#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct match
{
	int team_id;
	int match_id;
	char match_date[10];
	char team_or_player[1];
	int team1_id[4];
	int team2_id[4];
	char played[1];
	int winnerteam_id[4];
	int winnerteam_score[3];
	int otherteam_id[4];
	struct match *next;
} match;

match *head_match = NULL, *current_match = NULL;

int autoIncreamentmatch()
{
	int id = 0;
	for (current_match = head_match; current_match; current_match = current_match->next)
		id = current_match->match_id;
	return id + 1;
}
void addmatch()
{
	match c, *node;

	printf("\n\t\t\tEnter team_id    : ");
	scanf("%d", &c.team_id);
	printf("\n\t\t\tEnter match_id      : ");
	scanf("%d", &c.match_id);
	printf("\n\t\t\tEnter match_date : ");
	scanf("%s", &c.match_date);
	printf("\n\t\t\tEnter team_or_player  :");
	scanf("%s", c.team_or_player);
	printf("\n\t\t\tEnter team1_id  : ");
	scanf("%d", &c.team1_id);
	printf("\n\t\t\tEmter team2_id   :");
	scanf("%d", &c.team2_id);
	printf("\n\t\t\tEnter played  :");
	scanf("%s", c.played);
	printf("\n\t\t\tEnter winnerteam_id  :");
	scanf("%d", &c.winnerteam_id);
	printf("\n\t\t\tEnter winnerteam_score   :");
	scanf("%d", &c.winnerteam_score);
	printf("\n\t\t\tEnter otherteam_id  :");
	scanf("%d", &c.otherteam_id);

	printf("\n\t\t\t______\n");
	node = (match *)malloc(sizeof(match));
	node->team_id = c.team_id;
	node->match_id = autoIncreamentmatch();
	strcpy(node->match_date, c.match_date);
	strcpy(node->team_or_player, c.team_or_player);
	node->team1_id, c.team1_id;
	node->team2_id, c.team2_id;
	strcpy(node->played, c.played);
	node->winnerteam_id, c.winnerteam_id;
	node->winnerteam_score, c.winnerteam_score;
	node->otherteam_id, c.otherteam_id;
	node->next = NULL;

	if (head_match == NULL)
	{
		head_match = node;
	}
	else
	{
		current_match = head_match;
		while (current_match != NULL)
			current_match = current_match->next;
		current_match = node;
	}
}
void displaymatch()
{
	printf("\n%-5s%-5s%-20s%-1s%-5s%-5s%-1s%-5s%-4s%-5s\n", "team_id", "match_id", "match_date", "team_or_player", "team1_id", "team2_id", "played", "winnerteam_id", "winnerteam_score", "otherteam_id");
	printf("\n-------------------------------------------------------------------------------------------------\n");
	for (current_match = head_match; current_match; current_match = current_match)
		printf("%-5d%-5d%-20s%-20s%-5d%-5d%-20s%-7d%-7d%-7d\n", current_match->team_id, current_match->match_id, current_match->match_date, current_match->team_or_player, current_match->team1_id, current_match->team2_id, current_match->played, current_match->winnerteam_id, current_match->winnerteam_score, current_match->otherteam_id);
	system("pause");
}
void writematch()
{
	FILE *fp = fopen("matches.txt", "w");

	for (current_match = head_match; current_match; current_match = current_match)
	{
		fprintf(fp, "%d,%d,%s,%s,%d,%d,%s,%d,%d,%d\n", current_match->team_id, current_match->match_id, current_match->match_date, current_match->team_or_player, current_match->team1_id, current_match->team2_id, current_match->played, current_match->winnerteam_id, current_match->winnerteam_score, current_match->otherteam_id);
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
		printf("\nInvalid assword");

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
		case 1:
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
		}

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

					// Call the Add Team Function
					break;
				case 2:
					// modifymatch();
					//  Call the Modify Team Function
					break;
				case 3:
					// deletematch();
					//  Call the Delete Team Function
					break;
				case 4:
					displaymatch();
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
		

	case 4:
	{
		int ch4;
		do
		{
			printf("---------Tournaments Menu---------\n");
			printf("1. Add Tournament\n");
			printf("2. Modify Tournament\n");
			printf("3. Delete Tournament\n");
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

				// Call the Add Tournament Function
				break;
			case 2:
				// Call the Modify Tournament Function
				break;
			case 3:
				// Call the Delete Tournament Function
				break;
			case 0:
				printf("Exiting Tournaments Menu\n");
				exit(0);
			default:
				printf("You have entered an Invalid Option\n");
				break;
			}
		} while (ch4 != 0);
	}

	case 5:
	{
		int ch5;
		do
		{
			printf("---------Matches Menu---------\n");
			printf("1. Add Match\n");
			printf("2. Display Match\n");
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
				addmatch();
				// Call the Add Match Function
				break;
			case 2:
				displaymatch();
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
		} while (ch5 != 0);
	}

	case 6:
	{
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
		} while (ch6 != 0);
	}

	case 0:
		writematch();
		printf("\nTopic written successfully into the file\n");
		system("pause");
		break;
	default:
		's';
		printf("Invalid Choice\n");
		break;
	}
}
while (ch != 0)
	;

return EXIT_SUCCESS;
}

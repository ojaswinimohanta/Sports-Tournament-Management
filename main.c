#include<header.h>
int main()
{
	int ch,val;
	int returnValue = 0;
	/*
	char password[20];
      char p[]="admin";
      printf("Enter Password :");
      scanf("%s", password);

      val=strcmp(p,password);
      if(val==0)
       {
    printf("Login SucessFully");
       */
     
	    readcategories();
	    readplayerFile(); 
   
	do 
	{ 
		
	    	printf("---------Sportz - A Sport Tournament System---------\n");
	    	printf("1. Manage Categories\n");	
		printf("2. Manage Players\n");
		printf("3. Manage Teams\n");
		printf("4. Manage Tournaments\n");
		printf("5. Manage Matches\n");
		printf("6. Reports\n");
		printf("0. Quit\n\n");
	
		printf("Enter your option: ");
		returnValue = scanf ("%d", &ch);
		printf("\n");
		if ( returnValue == 0 || returnValue ==  EOF)
		{
			fflush(stdin);
			printf("Invalid input. Please enter valid input\n");
			break;
		}
		
		switch(ch)
		{
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
					returnValue = scanf ("%d", &ch1);
					printf("\n");
					if ( returnValue == 0 || returnValue ==  EOF)
					{
						fflush(stdin);
						printf("Invalid input. Please enter valid input\n");
						break;
					}
					
					switch(ch1)
					{
						case 1:
							addcategories();//Call the Add Category Function
							break;
						case 2:
					 	        modifycategories();//Call the Modify Category Function
							break;
						case 3:
							deletecategories();//Call the Delete Category Function
							break;
						case 4:
						       	displaycategories();//call the Display category Function
						        break;	
						case 0:
							printf("Exiting Categories Menu\n");
							break;
						default:
						    	printf("You have entered an Invalid Option\n");
							break;
					}
				} while (ch1 !=0);}
				
			case 2:{
				int ch2;
				do
				{
					printf("---------Players Menu---------\n");
				    	printf("1. Add Player\n");	
					printf("2. Modify Player\n");
					printf("3. Delete Player\n");
					printf("4. Display Player\n");
					printf("0. Quit\n\n");
	
					printf("Enter your option: ");
					returnValue = scanf ("%d", &ch2);
					printf("\n");
					if ( returnValue == 0 || returnValue ==  EOF)
					{
						fflush(stdin);
						printf("Invalid input. Please enter valid input\n");
						break;
					}
					
					switch(ch2)
					{
						case 1:
							addplayer();//Call the Add Player Function
							break;
						case 2:
							modifyplayer();//Call the Modify Player Function
							break;
						case 3:
							deleteplayer();//Call the Delete Player Function
							break;

						case 4:
					               displayplayer();
					              
						       break;	       
						case 0:
							printf("Exiting Players Menu\n");
							break;
						default:
						    	printf("You have entered an Invalid Option\n");
							break;
					}
				} while (ch2 !=0);
			       }
			
		/*	case 3:
				int ch3;
				do
				{
					printf("---------Teams Menu---------\n");
				    	printf("1. Add Team\n");	
					printf("2. Modify Team\n");
					printf("3. Delete Team\n");
					printf("0. Quit\n\n");
	
					printf("Enter your option: ");
					returnValue = scanf ("%d", &ch3);
					printf("\n");
					if ( returnValue == 0 || returnValue ==  EOF)
					{
						fflush(stdin);
						printf("Invalid input. Please enter valid input\n");
						break;
					}
					
					switch(ch3)
					{
						case 1:
							//Call the Add Team Function
							break;
						case 2:
							//Call the Modify Team Function
							break;
						case 3:
							//Call the Delete Team Function
							break;
						case 0:
							printf("Exiting Teams Menu\n");
							exit(0);
						default:
						    	printf("You have entered an Invalid Option\n");
							break;
					}
				} while (ch3 !=0);
					
			case 4:
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
				
			case 0: writeplayer();
				writecategories();
				printf("\n Data Uploaded successfully into the file\n");
	

				break;
			default:
			    	printf("Invalid Choice\n");
				break;
		}

	} while ( ch != 0);
       
	
	return EXIT_SUCCESS;
       	
}


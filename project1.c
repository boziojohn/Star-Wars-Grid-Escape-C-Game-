/*Ioannis Bozionelos
AM:2022202300157
dit23157@uop.gr

Konstantinos Velentzas
AM:2022202300243
dit23243@uop.gr
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int Rows, Columns, R, C, R1, C1, RD, CD, ar, stamina=0;
void calculateobst(int *plst, int *plemp, int ar);
void createtable(char ***gameboard, int ***troopers, char ***backup, int plemp, int plst);
void printtable(int Rows, int Columns, char **gameboard);
void moves(char ***gameboard, int ***troopers, char ***backup);
void stormtroopermoves(char ***gameboard, int ***troopers);
void darthvadermoves(char ***gameboard);
int main(void)
{
	printf("A long time ago in a galaxy far, far away...In a galaxy embroiled in war, Princess Leia Organa of the Rebel Alliance obtains plans for the Death Star, the Galactic Empire's most devastating weapon, capable of destroying entire planets. Determined to undermine the Empire's power, Leia aims to safeguard the plans by entrusting them to R2-D2, a resourceful astromech droid.\nHowever, the menacing Darth Vader, enforcer of the Emperor’s will, along with his legion of stormtroopers, relentlessly pursues Leia to recover the stolen plans. As the forces of tyranny close in, the fate of the galaxy hangs in the balance, setting the stage for an epic confrontation between the dark forces of the Empire and the heroes of the Rebellion.Let's see who will be crowned the winner of this tremendous war...\n");
 	
	printf("If you wish to start the game...give firstly a number of ROWS and secondly a number of COLUMNS\n");
	
	int p=0; 
	do
	{
		if(p!=0)
		{
			printf("Please give different numbers so that the board's size is at least 100\n");
			printf("!Remember the size is calculated by the multiplication ROWS*Columns! ;) \n");
		}
		scanf("%d%d", &Rows, &Columns);
		p++;
	}while(Rows*Columns<100); 				/*to megethos tou pinaka prepei na einai toulaxiston 100 kathws, prwton oi storm troopers prepei na einai toulaxiston 2 kai deuteron sto eukolo epipedo(dhladh sthn periptwsh pou oi storm troopers einai oi ligoteroi) gia na einai toulaxiston 2 oi troopers to sunoliko megethos tha prepei na einai 100(kathws to apotelesma ths praxhs Rows*Columns*2/100 prepei na einai >= 2)*/
	
	
	
	printf("Choose difficulty level BUT be prepared for what's coming next...Type 1 for easy, 2 for moderate, 3 for hard and 4 for impossible...Game on!\n");
	int p1=0;		
	do			
	{
		if(p1!=0)
			printf("Please give different number that belongs in [1,4]\n");
		scanf("%d", &ar);
		p1++;
	}while(ar<1 || ar>4);
	

	
	int plst, plemp;						/*to plst einai to plhthos twn storm troopers kai to plemp einai to plhthos twn empodiwn*/
	calculateobst(&plst, &plemp, ar);			
	
	int **troopers;
	char **gameboard, **backup;
	srand (time(NULL));
	createtable(&gameboard, &troopers, &backup, plemp, plst);

	int i, pllevel=0, Rnumber=Rows, Cnumber=Columns;				/*upologismos sunolikwn level bash epitreptou megethous pinaka(100)*/
	for(i = 1; i > 0; i++)		
	{
		if(Rnumber*Cnumber>=100)
		{
			pllevel ++;
			Rnumber --;
			Cnumber --;
		}
		else
			break;
	}
	
	

	for(i=1;i<=pllevel;i++)					
	{
		if(i>1)
		{
			calculateobst(&plst, &plemp, ar);
			createtable(&gameboard, &troopers, &backup, plemp, plst);
			printtable(Rows, Columns, gameboard);
		}
		printf("!Level %d! \nThink carefully and make your move or moves\n", i);
		printf("And remember...anytime you desire a helping hand to guide you towards R2D2 type guide\n");
		moves(&gameboard, &troopers, &backup);
		printf("Well done...!Level %d accomplished!\n", i);
		Rows=Rows-1;
		Columns=Columns-1;				/*Meta apo kathe level oi grammes kai oi sthles tou pinaka meiwnontai*/
	}



	for(int i = 0; i < Rows; i++)		/*apodesmeush mnhmhs pou desmeuthke apo dunamiko pinaka(gameboard)*/
		free(gameboard[i]);
	free(gameboard);

	for(int i = 0; i < Rows; i++)		/*apodesmeush mnhmhs pou desmeuthke apo dunamiko pinaka(troopers)*/
		free(troopers[i]);
	free(troopers);

	for(int i = 0; i < Rows; i++)		/*apodesmeush mnhmhs pou desmeuthke apo dunamiko pinaka(backup)*/
		free(backup[i]);
	free(backup);

	printf("The battle ends in the shadow of the Empire's stronghold. Darth Vader has escaped, but at great cost to his forces. Stormtroopers surrender under the relentless assault of Rebel fighters, their armor scorched and dented...\nPrincess Leia, alongside R2-D2, oversees the aftermath. She addresses the galaxy via hologram with R2 at her side. <<Today, we celebrate a victory for freedom, she declares, but the journey continues>>\nAs Leia's words echo, the camera pans to the defeated stormtroopers being led away. In the background, Vader's damaged lightsaber lies forgotten in the dirt, a symbol of the ongoing conflict!\nThe scene shifts to Leia on a Rebel cruiser. She gazes out into space, Vader's lightsaber in hand, a resolve in her eyes. <<We have much to do>>, she murmurs to R2-D2, who emits an affirmative beep.\nAs the cruiser joins the Rebel fleet, the iconic score crescendos. The screen fades to black, leaving a lingering sense of hope and the promise of further struggles for freedom...\n!And what's that? A thin voise sounds from a distance cheering...<<CONGRATULATIONS>>...! <<Now R2D2 has the plans of the Death Star as you passed every single level and became the SAVIOUR OF OUR UNIVERSE! We will always be grateful to have you by our side...May we meet again...MAY THE FORCE BE WITH YOU!>>\n");  
	return 0;	
}









	void calculateobst(int *plst, int *plemp, int ar)										/*sunarthsh gia upologismo arithmou empodiwn kai storm trooper bash epipedou duskolias*/
	{
		int meg;
		meg= Rows*Columns;	 
		switch(ar)
		{
			case 1:		
				*plst=(meg*2/100); 
				*plemp=(meg*13/100);
			break;
			
			case 2:
				*plst=(meg*5/100);
				*plemp=(meg*10/100);
			break;
			
			case 3:
				*plst=(meg*10/100);
				*plemp=(meg*5/100);
			break;
			
			case 4:
				*plst=(meg*15/100);
				*plemp=0;
			break;
		}
	}








	void createtable(char ***gameboard, int ***troopers, char ***backup, int plemp, int plst)						/*sunarthsh gia 1.dunamikh desmeush mnhmhs twn pinakwn, 2.gemisma pinakwn(gameboard, troopers kai backup)*/
	{
		
		*gameboard = (char**)malloc(Rows * sizeof(char*));											/*dunamikh desmeush mnhmhs gia ton didiastato pinaka gameboard*/
		if (*gameboard == NULL) 
		{
			printf("Failed to allocate memory\n");
			exit(EXIT_FAILURE);
		}
		for (int i = 0; i < Rows; i++) 
		{
			(*gameboard)[i] = malloc(Columns * sizeof(char));
			if ((*gameboard)[i] == NULL) 
			{
				printf("Failed to allocate memory");
				exit(EXIT_FAILURE);
			}
		}



		*troopers = (int**)malloc(Rows * sizeof(int*));												/*dunamikh desmeush mnhmhs gia ton didiastato pinaka troopers*/
		if (*troopers == NULL) 
		{
			printf("Failed to allocate memory\n");
			exit(EXIT_FAILURE);
		}
		for (int i = 0; i < Rows; i++) 
		{
			(*troopers)[i] = malloc(Columns * sizeof(int));
			if ((*troopers)[i] == NULL) 
			{
				printf("Failed to allocate memory");
				exit(EXIT_FAILURE);
			}
		}


		*backup = (char**)malloc(Rows * sizeof(char*));												/*dunamikh desmeush mnhmhs gia ton didiastato pinaka backup*/
		if (*backup == NULL) 
		{
			printf("Failed to allocate memory\n");
			exit(EXIT_FAILURE);
		}
		for (int i = 0; i < Rows; i++) 
		{
			(*backup)[i] = malloc(Columns * sizeof(char));
			if ((*backup)[i] == NULL) 
			{
				printf("Failed to allocate memory");
				exit(EXIT_FAILURE);
			}
		}


		int i, j, pl0=0, pl1=0, pl2=0, plt=0, s;					/*To plt einai to sunoliko plhthos teleiwn ston pinaka, to pl0 einai to plhthos twn empodiwn, to pl1 einai to plhthos twn storm troopers kai to pl2 einai to plhthos twn teleiwn*/
		plt= Rows*Columns-3-plst-plemp;	
		
		for(i=0;i<Rows;i++)											/*arxikopoihsh tou pinaka me teleies*/
			for(j=0;j<Columns;j++)
				(*gameboard)[i][j]= '.';

		
		R=rand()%Rows;												/*tuxaia topothethsh ths leia ston pinaka*/
		C=rand()%Columns;
		(*gameboard)[R][C]= 'L';

		int p2=0;													/*tuxaia topothethsh tou R2D2 ston pinaka*/
		do
		{
			R1=rand()%Rows;				
			C1=rand()%Columns;
			if((*gameboard)[R1][C1]!='L')
			{
				(*gameboard)[R1][C1]= 'R';
				p2=1;
			}
		}while(p2!=1);
		
		int p3=0;													/*tuxaia topothethsh tou darth vader ston pinaka*/
		do
		{
			s=rand()%4;
			if(s==0 && (*gameboard)[0][0]!= 'L' && (*gameboard)[0][0]!= 'R')
			{
				(*gameboard)[0][0]= 'D';
				RD=0;
				CD=0;
				p3=1;
			}
			else if(s==1 && (*gameboard)[Rows-1][0]!= 'L' && (*gameboard)[Rows-1][0]!= 'R')
			{
				(*gameboard)[Rows-1][0]= 'D';
				RD=Rows-1;
				CD=0;
				p3=1;
			}
			else if(s==2 && (*gameboard)[0][Columns-1]!= 'L' && (*gameboard)[0][Columns-1]!= 'R')
			{
				(*gameboard)[0][Columns-1]= 'D';
				RD=0;
				CD=Columns-1;
				p3=1;
			}
			else if(s==3 && (*gameboard)[Rows-1][Columns-1]!= 'L' && (*gameboard)[Rows-1][Columns-1]!= 'R')
			{
				(*gameboard)[Rows-1][Columns-1]= 'D';
				RD=Rows-1;
				CD=Columns-1;
				p3=1;
			}
		}while(p3!=1);	

		double meg=Rows*Columns;
		double percentagest=(double)plst/meg*100;
		double percentageemp=(double)plemp/meg*100;
		

		for(i=0;i<Rows;i++)												/*tuxaia topothethsh twn teleiwn, twn empodiwn kai twn storm trooper bash posostou ston pinaka*/
		{
			for(j=0;j<Columns;j++)
			{
				if((*gameboard)[i][j]!= 'D' && (*gameboard)[i][j]!= 'L' && (*gameboard)[i][j]!= 'R')
				{
					s=rand()%101;
					if(s<=percentageemp)		
					{
						if(pl0>=plemp)
						{
							j --;
							continue;
						}
						pl0 ++;
						(*gameboard)[i][j]= 'X' ;
					}
					else if(s<=percentageemp+percentagest)
					{
						if(pl1>=plst)
						{
							j --;
							continue;
						}
						pl1 ++;
						(*gameboard)[i][j]= '@';
					}
					else
					{
						if(pl2>=plt)
						{
							j --;
							continue;
						}
						pl2 ++;
						(*gameboard)[i][j]= '.';
					}
				}
			}
		}
		
		

		for(i=0;i<Rows;i++)									/*sthn thesh twn storm trooper(pou briskontai sto gameboard) bazoume tuxaia ston pinaka troopers tis times 0,1,2,3 pou tha upodeiknuoun thn kateuthunsh kai thn dieuthunsh pou tha kinountai oi troopers. Dhladh 0 gia dexia, 1 gia aristera, 2 gia katw kai 3 gia panw*/
		{
			for(j=0;j<Columns;j++)
			{
				if((*gameboard)[i][j]=='@')
					(*troopers)[i][j]=rand()%4;
				else	
					(*troopers)[i][j]=-1;
			}
		}
		
		for(i=0;i<Rows;i++)	
			for(j=0;j<Columns;j++)
				(*backup)[i][j]=(*gameboard)[i][j];
	
	}			



	


	
	void printtable(int Rows, int Columns, char **gameboard)				/*sunarthsh gia ektupwsh pinaka*/
	{
		int i,j;
		printf("      ");
		for(j=0;j<Columns;j++)												/*dhmiourgia periblhmatos tou pinaka*/
        {
			if(j<26)
				printf("%c  ", 'A' + j);
			else
				printf("%c%c ", 'A' + (j/26)-1, 'A'+(j%26));
        }

		printf("\n");
		printf("-----");
		for(j=0;j<=Columns;j++)
			if(j<Columns)
				printf("---");
		printf("\n");




		for(i=0;i<Rows;i++)
		{
			printf("%d", i+1);
			if(i+1<=9)
				printf("   | ");
			else if(i+1<=99)
				printf("  | ");
			else if(i+1<999)
				printf(" | ");
			else if(i+1>=1000)
				printf("| ");
			for(j=0;j<=Columns;j++)
			{
				if(i!=R && j!=C)
				{
					char character=gameboard[i][j];
					if( character== '.' || character=='R' || character=='@')
					{
						character='#';
						printf("%c  ", character);
					}
					else
						printf("%c  ", gameboard[i][j]);
				}
				else
					printf("%c  ", gameboard[i][j]);
			}
			printf("\n");
		}
	}















	void moves(char ***gameboard, int ***troopers, char ***backup)							/*sunarthsh gia tis kinhseis pou epilegei o paikths*/
	{
		int win=0, rounds=0;
		do
		{
			char move[100], answer;
			int len, i=0, j=0, forbidden=0; 
			fgets(move, sizeof(move), stdin); 	

			
			len=strlen(move);
			if(move[0]=='x' || move[0]=='X' && len==2)											/*bohthitikes entoles*/
			{
				printf("Are you sure you want to terminate the game(y/n)? :( \n");
				do		
				{
					answer= getchar();
				}while(answer!='y' && answer!='n' && answer!='Y' && answer!='N');
				if(answer=='y' || answer=='Y')
				{
					printf("Game over. Better luck next time!\n");
					exit(EXIT_FAILURE);
				}
				else 
				{
					printf("And the game goes on...Make your move ;) \n");
					continue;
				}
			}
			else if(move[0]=='h' || move[0]=='H' && len==2)
			{
				printf("With the help of master Yoda you may even see the board's closed cells\n");
				int i,j;
				printf("      ");
				for(j=0;j<Columns;j++)
				{
					if(j<26)
						printf("%c  ", 'A' + j);
					else
						printf("%c%c ", 'A' + (j/26)-1, 'A'+(j%26));
				}

				printf("\n");
				printf("-----");
				for(j=0;j<=Columns;j++)
					if(j<Columns)
						printf("---");
				printf("\n");




				for(i=0;i<Rows;i++)
				{
					printf("%d", i+1);
					if(i+1<=9)
						printf("   | ");
					else if(i+1<=99)
						printf("  | ");
					else if(i+1<999)
						printf(" | ");
					else if(i+1>=1000)
						printf("| ");
					for(j=0;j<=Columns;j++)
					{
						printf("%c  ", (*gameboard)[i][j]);
					}
					printf("\n");
				}
				continue;
			}
			else if(move[0]=='>' && len==2)
			{
				
				printf("Leia activates her telekinetics abilities!\n");
				int R3, R4, p3=0;
				char C3, C4, C5, C6, character;
				do
				{
					do
					{
						if(p3!=0)
							printf("Something went wrong...please try again and remember the following restrictions:\n");
						printf("Type fistly a CHARACTER that specifies the COLUMN of the obstacle you want to be moved, then type a NUMBER that specifies the ROW of that particular obstacle\n");
						printf("Then type '>', a CHARACTER of the COLUMN and a NUMBER of the ROW, where you want to move the obstacle to(!TYPE EVERYTHING WITHOUT SPACE AND THE LETTERS WITH LOWERCASE!)\n");
						printf("Also, remember that you need to check whether the cell you want to move the obstacle to is empty or not...otherwise the programm will not execute your command!\n");
						scanf("%c%d%c%c%d", &C3, &R3, &character, &C4, &R4);
						R3--;
						R4--;
						p3++;
					}while(C3<'a' || C3>'a'+Columns-1 | C4<'a' || C4>'a'+Columns-1 || R3<0 || R3>Rows-1 || R4<0 || R4>Rows-1 || character!='>');
	
					C5 = C3 -'a';
					C6 = C4 -'a';
					
				}while((*gameboard)[R3][C5]!='X' || (*gameboard)[R4][C6]!='.');
				
				(*gameboard)[R3][C5] ='.';
				(*gameboard)[R4][C6] ='X';
				
				continue;
			}
			
			
			for(i=0;i<len-1;i++)														
			{
				if(len>=5)
				{
					if(move[i]=='g' && move[i+1]=='u' && move[i+2]=='i' && move[i+3]=='d' && move[i+4]=='e')					/*bohthitikh entolh guide*/
					{
						int distanceR2, distanceC2;
						distanceR2= R1-R;											/*apostash twn grammwn kai sthlwn pou apexei h Leia apo ton R2D2*/
						distanceC2= C1-C;
						
						if(distanceR2==0 && distanceC2>0)			//dexia
						{
							if((*gameboard)[R][C+1]=='X' || (*gameboard)[R][C+1]=='@' || (*gameboard)[R][C+1]=='R')
								printf("Hint:You should search for R2D2 somewhere on your right\n");
							else
								printf("Hint:Move to your right\n");
						}
						else if(distanceR2==0 && distanceC2<0)		//aristera
						{
							if((*gameboard)[R][C-1]=='X' || (*gameboard)[R][C-1]=='@' || (*gameboard)[R][C-1]=='R')
								printf("Hint:You should search for R2D2 somewhere on your left\n");
							else
								printf("Hint:Move to your left\n");
						}
						else if(distanceR2>0 && distanceC2==0)		//katw
						{
							if((*gameboard)[R+1][C]=='X' || (*gameboard)[R+1][C]=='@' || (*gameboard)[R+1][C]=='R')
								printf("Hint:You should search for R2D2 downwards\n");
							else
								printf("Hint:Move downwards\n");
						}
						else if(distanceR2<0 && distanceC2==0)		//panw
						{
							if((*gameboard)[R-1][C]=='X' || (*gameboard)[R-1][C]=='@' || (*gameboard)[R-1][C]=='R')
								printf("Hint:You should search for R2D2 upwards\n");
							else
								printf("Hint:Move upwards\n");
						}
						else if(distanceR2>0 && distanceC2<0)			//diagwnia katw aristera
						{
							printf("Hint:Move either down or left\n");
						}
						else if(distanceR2>0 && distanceC2>0)			//diagwnia katw dexia		
						{
							printf("Hint:Move either down or right\n");
						}
						else if(distanceR2<0 && distanceC2>0)			//diagwnia panw dexia	
						{
							printf("Hint:Move either up or right\n");
						}
						else if(distanceR2<0 && distanceC2<0)				//diagwnia panw aristera	
						{
							printf("Hint:Move either up or left\n");
						}

						forbidden=1;
						break;
					}
				}
				if(len>=4)
				{
					if(move[i]=='u' && move[i+1]=='n' && move[i+2]=='d' && move[i+3]=='o')						/*bohthitikh entolh undo*/
					{
						for(i=0;i<Rows;i++)	
							for(j=0;j<Columns;j++)
								(*gameboard)[i][j]=(*backup)[i][j];
						printtable(Rows, Columns, *gameboard);
						forbidden=1;
						break;
					}
					else 
					{
						for(i=0;i<Rows;i++)	
							for(j=0;j<Columns;j++)
								(*backup)[i][j]=(*gameboard)[i][j];
					}
				}

				if(move[i]=='u' || move[i]=='U')																/*kinhseis ths Leia mesa ston gameboard*/
				{
					if(R==0)
					{
						printf("Leia can't move outside of the board...Please make a different move\n");
						break;
					}
					else if((*gameboard)[R-1][C]=='X')
					{
						printf("Leia can't move through obstacles...Please make a different move\n");
						break;
					}
					else	
					{
						if((*gameboard)[R-1][C]=='@' && stamina==0)
						{
							printf("You have just killed a storm trooper but be careful because there WILL NOT be a second time because now Leia is wounded!\n");
							(*troopers)[R-1][C]=-1;
							(*gameboard)[R][C]='.';
							(*gameboard)[R-1][C]='L';
							R--;
							stamina ++;
						}
						else if((*gameboard)[R-1][C]=='@' && stamina==1)
						{
							printf("You have been killed by a storm trooper...Game over...Better luck next time! x(\n");
							exit(EXIT_FAILURE);
						}
						else if((*gameboard)[R-1][C]=='R')
						{
							R--;
							win=1;
							break;
						}
						else if((*gameboard)[R-1][C]=='D')
						{
							printf("You were captured by DARTH VADER!...Game over! x(\n");
							exit(EXIT_FAILURE);
						}
						else
						{
							(*gameboard)[R][C]='.';
							(*gameboard)[R-1][C]='L';
							R--;
						}
					}	
				}
				else if(move[i]=='d' || move[i]=='D')
				{
					if(R==Rows-1)
					{
						printf("Leia can't move outside of the board...Please make a different move\n");
						break;
					}
					else if((*gameboard)[R+1][C]=='X')
					{
						printf("Leia can't move through obstacles...Please make a different move\n");
						break;
					}
					else	
					{
						if((*gameboard)[R+1][C]=='@' && stamina==0)
						{
							printf("You have just killed a storm trooper but be careful because there WILL NOT be a second time because now Leia is wounded!\n");
							(*troopers)[R+1][C]=-1;
							(*gameboard)[R][C]='.';
							(*gameboard)[R+1][C]='L';
							R++;
							stamina ++;
						}
						else if((*gameboard)[R+1][C]=='@' && stamina==1)
						{
							printf("You have been killed by a storm trooper...Game over...Better luck next time! x(\n");
							exit(EXIT_FAILURE);
						}
						else if((*gameboard)[R+1][C]=='R')
						{
							win=1;
							R++;
							break;
						}	
						else if((*gameboard)[R+1][C]=='D')
						{
							printf("You were captured by DARTH VADER!...Game over! x(\n");
							exit(EXIT_FAILURE);
						}
						else
						{
							(*gameboard)[R][C]='.';
							(*gameboard)[R+1][C]='L';
							R++;
						}
					}	
				}
				else if(move[i]=='r' || move[i]=='R')
				{
					if(C==Columns-1)
					{
						printf("Leia can't move outside of the board...Please make a different move\n");
						break;
					}
					else if((*gameboard)[R][C+1]=='X')
					{
						printf("Leia can't move through obstacles...Please make a different move\n");
						break;
					}
					else	
					{
						if((*gameboard)[R][C+1]=='@' && stamina==0)
						{
							printf("You have just killed a storm trooper but be careful because there WILL NOT be a second time because now Leia is wounded!\n");
							(*troopers)[R][C+1]=-1;
							(*gameboard)[R][C]='.';
							(*gameboard)[R][C+1]='L';
							C++;
							stamina ++;
						}
						else if((*gameboard)[R][C+1]=='@' && stamina==1)
						{
							printf("You have been killed by a storm trooper...Game over...Better luck next time! x(\n");
							exit(EXIT_FAILURE);
						}
						else if((*gameboard)[R][C+1]=='R')
						{
							win=1;
							C++;
							break;
						}
						else if((*gameboard)[R][C+1]=='D')
						{
							printf("You were captured by DARTH VADER!...Game over! x(\n");
							exit(EXIT_FAILURE);
						}
						else
						{
							(*gameboard)[R][C]='.';
							(*gameboard)[R][C+1]='L';
							C++;
						}
					}	
				}
				else if(move[i]=='l' || move[i]=='L')
				{
					if(C==0)
					{
						printf("Leia can't move outside of the board...Please make a different move\n");
						break;
					}
					else if((*gameboard)[R][C-1]=='X')
					{
						printf("Leia can't move through obstacles...Please make a different move\n");
						break;
					}
					else	
					{
						if((*gameboard)[R][C-1]=='@' && stamina==0)
						{
							printf("You have just killed a storm trooper but be careful because there WILL NOT be a second time because now Leia is wounded!\n");
							(*troopers)[R][C-1]=-1;
							(*gameboard)[R][C]='.';
							(*gameboard)[R][C-1]='L';
							C--;
							stamina ++;
						}
						else if((*gameboard)[R][C-1]=='@' && stamina==1)
						{
							printf("You have been killed by a storm trooper...Game over...Better luck next time! x(\n");
							exit(EXIT_FAILURE);
						}
						else if((*gameboard)[R][C-1]=='R')
						{
							win=1;
							C--;
							break;
						}	
						else if((*gameboard)[R][C-1]=='D')
						{
							printf("You were captured by DARTH VADER!...Game over! x(\n");
							exit(EXIT_FAILURE);
						}
						else
						{
							(*gameboard)[R][C]='.';
							(*gameboard)[R][C-1]='L';
							C--;
						}
					}
				}
				else if(move[i]=='x' || move[i]=='X' || move[i]=='h' || move[i]=='H' || move[i]=='>')
				{
					printf("If you want to use one of these commands x, X, h, H, >, you should execute them without any other move commands\n");
					break;
				}
				else
				{
					printf("Unacceptable command please try again\n");
					break;
				}
				
			}
			if(forbidden!=1)
			{
				if(rounds>0)
				{
					stormtroopermoves(gameboard, troopers);						/*kinhseis twn storm trooper mesa ston gameboard*/
					if(rounds%2==0)
						darthvadermoves(gameboard);								/*kinhseis tou Darth Vader mesa ston gameboard*/
				}
				printtable(Rows, Columns, *gameboard);
				rounds++;
			}
		}while(win!=1);
	}








	void stormtroopermoves(char ***gameboard, int ***troopers)							/*sunarthsh gia kinhsh twn storm trooper mesa sto gameboard*/
	{
		int i,j;
		for(i=0;i<Rows;i++)
		{
			for(j=0;j<Columns;j++)
			{
				if((*troopers)[i][j]==0) 		//dexia
				{
					if(j==0)
					{
						if((*gameboard)[i][j+1]=='X' || (*gameboard)[i][j+1]=='R' || (*gameboard)[i][j+1]=='@' || (*gameboard)[i][j+1]=='D')
							(*gameboard)[i][j]='@';
						else if((*gameboard)[i][j+1]=='L' && stamina==0)
						{
							printf("A storm trooper just stumbled across you. Don't worry...you managed to kill him, but be careful because now you are wounded!\n");
							(*gameboard)[i][j]='.';
							(*troopers)[i][j]= -1;
							stamina++;
						}
						else if((*gameboard)[i][j+1]=='L' && stamina==1)
						{
							printf("A storm trooper just stumbled across you, but sadly he managed to kill you because you were already wounded...Game over!\n");
							exit(EXIT_FAILURE);
						}
						else
						{
							(*gameboard)[i][j]='.';
							(*troopers)[i][j]= -1;
							(*gameboard)[i][j+1]='@';
							(*troopers)[i][j+1]=0;
							j++;
						}
					}
					else if(j==Columns-1) 
					{
						if((*gameboard)[i][j-1]=='X' || (*gameboard)[i][j-1]=='R' || (*gameboard)[i][j-1]=='@' || (*gameboard)[i][j-1]=='D')
							(*gameboard)[i][j]='@';
						else if((*gameboard)[i][j-1]=='L' && stamina==0)
						{
							printf("A storm trooper just stumbled across you. Don't worry...you managed to kill him, but be careful because now you are wounded!\n");
							(*gameboard)[i][j]='.';
							(*troopers)[i][j]= -1;
							stamina++;
						}
						else if((*gameboard)[i][j-1]=='L' && stamina==1)
						{
							printf("A storm trooper just stumbled across you, but sadly he managed to kill you because you were already wounded...Game over!\n");
							exit(EXIT_FAILURE);
						}
						else
						{
							(*gameboard)[i][j]='.';
							(*troopers)[i][j]= -1;
							(*gameboard)[i][j-1]='@';
							(*troopers)[i][j-1]=1;
							continue;
						}
					}
					else
					{
						if((*gameboard)[i][j+1]=='X' || (*gameboard)[i][j+1]=='R' || (*gameboard)[i][j+1]=='D' || (*gameboard)[i][j+1]=='@' && (*gameboard)[i][j-1]=='.')
						{
							(*gameboard)[i][j-1]='@';
							(*troopers)[i][j-1]=1;
							(*gameboard)[i][j]='.';
							(*troopers)[i][j]= -1;
							continue;
						}
						else if((*gameboard)[i][j+1]=='X' || (*gameboard)[i][j+1]=='R' || (*gameboard)[i][j+1]=='D' || (*gameboard)[i][j+1]=='@' && (*gameboard)[i][j-1]!='.')
							(*gameboard)[i][j]='@';
						else if((*gameboard)[i][j+1]=='L' && stamina==0)
						{
							printf("A storm trooper just stumbled across you. Don't worry...you managed to kill him, but be careful because now you are wounded!\n");
							(*gameboard)[i][j]='.';
							(*troopers)[i][j]= -1;
							stamina++;
						}
						else if((*gameboard)[i][j+1]=='L' && stamina==1)
						{
							printf("A storm trooper just stumbled across you, but sadly he managed to kill you because you were already wounded...Game over!\n");
							exit(EXIT_FAILURE);
						}
						else
						{
							(*gameboard)[i][j]='.';
							(*troopers)[i][j]= -1;
							(*gameboard)[i][j+1]='@';
							(*troopers)[i][j+1]=0;
							j++;
						}
					}
				}
				else if((*troopers)[i][j]==1)		//aristera
				{
					if(j==0)
					{
						if((*gameboard)[i][j+1]=='X' || (*gameboard)[i][j+1]=='R' || (*gameboard)[i][j+1]=='@' || (*gameboard)[i][j+1]=='D')
							(*gameboard)[i][j]='@';
						else if((*gameboard)[i][j+1]=='L' && stamina==0)
						{
							printf("A storm trooper just stumbled across you. Don't worry...you managed to kill him, but be careful because now you are wounded!\n");
							(*gameboard)[i][j]='.';
							(*troopers)[i][j]= -1;
							stamina++;
						}
						else if((*gameboard)[i][j+1]=='L' && stamina==1)
						{
							printf("A storm trooper just stumbled across you, but sadly he managed to kill you because you were already wounded...Game over!\n");
							exit(EXIT_FAILURE);
						}
						else
						{
							(*gameboard)[i][j]='.';
							(*troopers)[i][j]= -1;
							(*gameboard)[i][j+1]='@';
							(*troopers)[i][j+1]=0;
							j++;
						}
					}
					else if(j==Columns-1) 
					{
						if((*gameboard)[i][j-1]=='X' || (*gameboard)[i][j-1]=='R' || (*gameboard)[i][j-1]=='@' || (*gameboard)[i][j-1]=='D')
							(*gameboard)[i][j]='@';
						else if((*gameboard)[i][j-1]=='L' && stamina==0)
						{
							printf("A storm trooper just stumbled across you. Don't worry...you managed to kill him, but be careful because now you are wounded!\n");
							(*gameboard)[i][j]='.';
							(*troopers)[i][j]= -1;
							stamina++;
						}
						else if((*gameboard)[i][j-1]=='L' && stamina==1)
						{
							printf("A storm trooper just stumbled across you, but sadly he managed to kill you because you were already wounded...Game over!\n");
							exit(EXIT_FAILURE);
						}
						else
						{
							(*gameboard)[i][j]='.';
							(*troopers)[i][j]= -1;
							(*gameboard)[i][j-1]='@';
							(*troopers)[i][j-1]=1;
						}
					}
					else
					{
						if((*gameboard)[i][j-1]=='X' || (*gameboard)[i][j-1]=='R' || (*gameboard)[i][j-1]=='D' || (*gameboard)[i][j-1]=='@' && (*gameboard)[i][j+1]=='.')
						{
							(*gameboard)[i][j+1]='@';
							(*troopers)[i][j+1]=0;
							(*gameboard)[i][j]='.';
							(*troopers)[i][j]= -1;
						}
						else if((*gameboard)[i][j-1]=='X' || (*gameboard)[i][j-1]=='R' || (*gameboard)[i][j-1]=='D' || (*gameboard)[i][j-1]=='@' && (*gameboard)[i][j+1]!='.')
							(*gameboard)[i][j]='@';
						else if((*gameboard)[i][j-1]=='L' && stamina==0)
						{
							printf("A storm trooper just stumbled across you. Don't worry...you managed to kill him, but be careful because now you are wounded!\n");
							(*gameboard)[i][j]='.';
							(*troopers)[i][j]= -1;
							stamina++;
						}
						else if((*gameboard)[i][j-1]=='L' && stamina==1)
						{
							printf("A storm trooper just stumbled across you, but sadly he managed to kill you because you were already wounded...Game over!\n");
							exit(EXIT_FAILURE);
						}
						else
						{
							(*gameboard)[i][j-1]='@';
							(*troopers)[i][j-1]=1;
							(*gameboard)[i][j]='.';
							(*troopers)[i][j]= -1;
						}
					}
				}
			}
		}
		
		
		
		for(j=0;j<Columns;j++)
		{
			for(i=0;i<Rows;i++)
			{
				if((*troopers)[i][j]==2)		//katw
				{
					if(i==0)
					{
						if((*gameboard)[i+1][j]=='X' || (*gameboard)[i+1][j]=='R' || (*gameboard)[i+1][j]=='@' || (*gameboard)[i+1][j]=='D')
							(*gameboard)[i][j]='@';
						else if((*gameboard)[i+1][j]=='L' && stamina==0)
						{
							printf("A storm trooper just stumbled across you. Don't worry...you managed to kill him, but be careful because now you are wounded!\n");
							(*gameboard)[i][j]='.';
							(*troopers)[i][j]= -1;
							stamina++;
						}
						else if((*gameboard)[i+1][j]=='L' && stamina==1)
						{
							printf("A storm trooper just stumbled across you, but sadly he managed to kill you because you were already wounded...Game over!\n");
							exit(EXIT_FAILURE);
						}
						else
						{
							(*gameboard)[i][j]='.';
							(*troopers)[i][j]= -1;
							(*gameboard)[i+1][j]='@';
							(*troopers)[i+1][j]=2;
							i++;
						}
					}
					else if(i==Rows-1) 
					{
						if((*gameboard)[i-1][j]=='X' || (*gameboard)[i-1][j]=='R' || (*gameboard)[i-1][j]=='@' || (*gameboard)[i-1][j]=='D')
							(*gameboard)[i][j]='@';
						else if((*gameboard)[i-1][j]=='L' && stamina==0)
						{
							printf("A storm trooper just stumbled across you. Don't worry...you managed to kill him, but be careful because now you are wounded!\n");
							(*gameboard)[i][j]='.';
							(*troopers)[i][j]= -1;
							stamina++;
						}
						else if((*gameboard)[i-1][j]=='L' && stamina==1)
						{
							printf("A storm trooper just stumbled across you, but sadly he managed to kill you because you were already wounded...Game over!\n");
							exit(EXIT_FAILURE);
						}
						else
						{
							(*gameboard)[i][j]='.';
							(*troopers)[i][j]= -1;
							(*gameboard)[i-1][j]='@';
							(*troopers)[i-1][j]=3;
							continue;
						}
					}
					else
					{
						if((*gameboard)[i+1][j]=='X' || (*gameboard)[i+1][j]=='R' || (*gameboard)[i+1][j]=='D' || (*gameboard)[i+1][j]=='@' && (*gameboard)[i-1][j]=='.')
						{
							(*gameboard)[i-1][j]='@';
							(*troopers)[i-1][j]=3;
							(*gameboard)[i][j]='.';
							(*troopers)[i][j]= -1;
							continue;
						}
						else if((*gameboard)[i+1][j]=='X' || (*gameboard)[i+1][j]=='R' || (*gameboard)[i+1][j]=='D' || (*gameboard)[i+1][j]=='@' && (*gameboard)[i-1][j]!='.')
							(*gameboard)[i][j]='@';
						else if((*gameboard)[i+1][j]=='L' && stamina==0)
						{
							printf("A storm trooper just stumbled across you. Don't worry...you managed to kill him, but be careful because now you are wounded!\n");
							(*gameboard)[i][j]='.';
							(*troopers)[i][j]= -1;
							stamina++;
						}
						else if((*gameboard)[i+1][j]=='L' && stamina==1)
						{
							printf("A storm trooper just stumbled across you, but sadly he managed to kill you because you were already wounded...Game over!\n");
							exit(EXIT_FAILURE);
						}
						else
						{
							(*gameboard)[i][j]='.';
							(*troopers)[i][j]= -1;
							(*gameboard)[i+1][j]='@';
							(*troopers)[i+1][j]=2;
							i++;
						}
					}
				}
				else if((*troopers)[i][j]==3)		//panw
				{
					if(i==0)
					{
						if((*gameboard)[i+1][j]=='X' || (*gameboard)[i+1][j]=='R' || (*gameboard)[i+1][j]=='@' || (*gameboard)[i+1][j]=='D')
							(*gameboard)[i][j]='@';
						else if((*gameboard)[i+1][j]=='L' && stamina==0)
						{
							printf("A storm trooper just stumbled across you. Don't worry...you managed to kill him, but be careful because now you are wounded!\n");
							(*gameboard)[i][j]='.';
							(*troopers)[i][j]= -1;
							stamina++;
						}
						else if((*gameboard)[i+1][j]=='L' && stamina==1)
						{
							printf("A storm trooper just stumbled across you, but sadly he managed to kill you because you were already wounded...Game over!\n");
							exit(EXIT_FAILURE);
						}
						else
						{
							(*gameboard)[i][j]='.';
							(*troopers)[i][j]= -1;
							(*gameboard)[i+1][j]='@';
							(*troopers)[i+1][j]=2;
							i++;
						}
					}
					else if(i==Rows-1) 
					{
						if((*gameboard)[i-1][j]=='X' || (*gameboard)[i-1][j]=='R' || (*gameboard)[i-1][j]=='@' || (*gameboard)[i-1][j]=='D')
							(*gameboard)[i][j]='@';
						else if((*gameboard)[i-1][j]=='L' && stamina==0)
						{
							printf("A storm trooper just stumbled across you. Don't worry...you managed to kill him, but be careful because now you are wounded!\n");
							(*gameboard)[i][j]='.';
							(*troopers)[i][j]= -1;
							stamina++;
						}
						else if((*gameboard)[i-1][j]=='L' && stamina==1)
						{
							printf("A storm trooper just stumbled across you, but sadly he managed to kill you because you were already wounded...Game over!\n");
							exit(EXIT_FAILURE);
						}
						else
						{
							(*gameboard)[i][j]='.';
							(*troopers)[i][j]= -1;
							(*gameboard)[i-1][j]='@';
							(*troopers)[i-1][j]=3;
						}
					}
					else
					{
						if((*gameboard)[i-1][j]=='X' || (*gameboard)[i-1][j]=='R' || (*gameboard)[i-1][j]=='D' || (*gameboard)[i-1][j]=='@' && (*gameboard)[i+1][j]=='.')
						{
							(*gameboard)[i+1][j]='@';
							(*troopers)[i+1][j]=3;
							(*gameboard)[i][j]='.';
							(*troopers)[i][j]= -1;
							continue;
						}
						else if((*gameboard)[i-1][j]=='X' || (*gameboard)[i-1][j]=='R' || (*gameboard)[i-1][j]=='D' || (*gameboard)[i-1][j]=='@' && (*gameboard)[i+1][j]!='.')
							(*gameboard)[i][j]='@';
						else if((*gameboard)[i-1][j]=='L' && stamina==0)
						{
							printf("A storm trooper just stumbled across you. Don't worry...you managed to kill him, but be careful because now you are wounded!\n");
							(*gameboard)[i][j]='.';
							(*troopers)[i][j]= -1;
							stamina++;
						}
						else if((*gameboard)[i-1][j]=='L' && stamina==1)
						{
							printf("A storm trooper just stumbled across you, but sadly he managed to kill you because you were already wounded...Game over!\n");
							exit(EXIT_FAILURE);
						}
						else
						{
							(*gameboard)[i-1][j]='@';
							(*troopers)[i-1][j]=3;
							(*gameboard)[i][j]='.';
							(*troopers)[i][j]= -1;
						}
					}
				}
			}
		}
	}




	void darthvadermoves(char ***gameboard)							/*sunarthsh gia tis kinhseis tou darth vader mesa ston gameboard*/				
	{
		int distanceR, distanceC;
		distanceR= R-RD;											/*apostash twn grammwn kai sthlwn pou apexei o darth vader apo thn leia*/
		distanceC= C-CD;
		
		if(distanceR==0 && distanceC>0)			//dexia
		{
			if((*gameboard)[RD][CD+1]=='X' || (*gameboard)[RD][CD+1]=='@' || (*gameboard)[RD][CD+1]=='R')
				if(RD==Rows-1)
					if((*gameboard)[RD-1][CD+1]=='X' || (*gameboard)[RD-1][CD+1]=='@' || (*gameboard)[RD-1][CD+1]=='R')
						(*gameboard)[RD][CD]='D';
					else	
					{
						(*gameboard)[RD-1][CD+1]='D';
						(*gameboard)[RD][CD]='.';
						RD--;
						CD++;
					}
				else
				{
					if((*gameboard)[RD+1][CD+1]=='X' || (*gameboard)[RD+1][CD+1]=='@' || (*gameboard)[RD+1][CD+1]=='R' || CD==Columns-1)
						(*gameboard)[RD][CD]='D';
					else
					{
						(*gameboard)[RD+1][CD+1]='D';
						(*gameboard)[RD][CD]='.';
						RD++;
						CD++;
					}
				}
			else
			{
				(*gameboard)[RD][CD+1]='D';
				(*gameboard)[RD][CD]='.';
				CD++;
			}
		}
		else if(distanceR==0 && distanceC<0)		//aristera
		{
			if((*gameboard)[RD][CD-1]=='X' || (*gameboard)[RD][CD-1]=='@' || (*gameboard)[RD][CD-1]=='R')
				if(RD==Rows-1)
					if((*gameboard)[RD-1][CD-1]=='X' || (*gameboard)[RD-1][CD-1]=='@' || (*gameboard)[RD-1][CD-1]=='R' || CD==0)
						(*gameboard)[RD][CD]='D';
					else	
					{
						(*gameboard)[RD-1][CD-1]='D';
						(*gameboard)[RD][CD]='.';
						RD--;
						CD--;
					}
				else
				{
					if((*gameboard)[RD+1][CD-1]=='X' || (*gameboard)[RD+1][CD-1]=='@' || (*gameboard)[RD+1][CD-1]=='R' || CD==Columns-1)
						(*gameboard)[RD][CD]='D';
					else
					{
						(*gameboard)[RD+1][CD-1]='D';
						(*gameboard)[RD][CD]='.';
						CD--;
						RD++;
					}
				}
			else
			{
				(*gameboard)[RD][CD-1]='D';
				(*gameboard)[RD][CD]='.';
				CD--;
			}
		}
		else if(distanceR>0 && distanceC==0)		//katw
		{
			if((*gameboard)[RD+1][CD]=='X' || (*gameboard)[RD+1][CD]=='@' || (*gameboard)[RD+1][CD]=='R')
				if(CD==Columns-1)
					if((*gameboard)[RD+1][CD-1]=='X' || (*gameboard)[RD+1][CD-1]=='@' || (*gameboard)[RD+1][CD-1]=='R' || CD==0)
						(*gameboard)[RD][CD]='D';
					else	
					{
						(*gameboard)[RD+1][CD-1]='D';
						(*gameboard)[RD][CD]='.';
						RD++;
						CD--;
					}
				else
				{
					if((*gameboard)[RD+1][CD+1]=='X' || (*gameboard)[RD+1][CD+1]=='@' || (*gameboard)[RD+1][CD+1]=='R' || CD==Columns-1)
						(*gameboard)[RD][CD]='D';
					else
					{
						(*gameboard)[RD+1][CD+1]='D';
						(*gameboard)[RD][CD]='.';
						CD++;
						RD++;
					}
				}
			else
			{
				(*gameboard)[RD+1][CD]='D';
				(*gameboard)[RD][CD]='.';
				RD++;
			}
		}
		else if(distanceR<0 && distanceC==0)		//panw
		{
			if((*gameboard)[RD-1][CD]=='X' || (*gameboard)[RD-1][CD]=='@' || (*gameboard)[RD-1][CD]=='R')
				if(CD==0)
					if((*gameboard)[RD-1][CD+1]=='X' || (*gameboard)[RD-1][CD+1]=='@' || (*gameboard)[RD-1][CD+1]=='R' || CD==Columns-1)
						(*gameboard)[RD][CD]='D';
					else	
					{
						(*gameboard)[RD-1][CD+1]='D';
						(*gameboard)[RD][CD]='.';
						RD--;
						CD++;
					}
				else
				{
					if((*gameboard)[RD-1][CD-1]=='X' || (*gameboard)[RD-1][CD-1]=='@' || (*gameboard)[RD-1][CD-1]=='R' || CD==0)
						(*gameboard)[RD][CD]='D';
					else
					{
						(*gameboard)[RD-1][CD-1]='D';
						(*gameboard)[RD][CD]='.';
						CD--;
						RD--;
					}
				}
			else
			{
				(*gameboard)[RD-1][CD]='D';
				(*gameboard)[RD][CD]='.';
				RD--;
			}
		}
		else if(distanceR>0 && distanceC<0)			//diagwnia katw aristera
		{
			if((*gameboard)[RD+1][CD-1]=='X' || (*gameboard)[RD+1][CD-1]=='@' || (*gameboard)[RD+1][CD-1]=='R')
				if((*gameboard)[RD+1][CD]=='X' || (*gameboard)[RD+1][CD]=='@' || (*gameboard)[RD+1][CD]=='R')
					if((*gameboard)[RD][CD-1]=='X' || (*gameboard)[RD][CD-1]=='@' || (*gameboard)[RD][CD-1]=='R')
						(*gameboard)[RD][CD]='D';
					else
					{
						(*gameboard)[RD][CD-1]='D';
						(*gameboard)[RD][CD]='.';
						CD--;
					}
				else	
				{
					(*gameboard)[RD+1][CD]='D';
					(*gameboard)[RD][CD]='.';
					RD++;
				}
			else
			{
				(*gameboard)[RD+1][CD-1]='D';
				(*gameboard)[RD][CD]='.';
				RD++;
				CD--;
			}

		}
		else if(distanceR>0 && distanceC>0)			//diagvnia katw dexia		
		{
			if((*gameboard)[RD+1][CD+1]=='X' || (*gameboard)[RD+1][CD+1]=='@' || (*gameboard)[RD+1][CD+1]=='R')
				if((*gameboard)[RD+1][CD]=='X' || (*gameboard)[RD+1][CD]=='@' || (*gameboard)[RD+1][CD]=='R')
					if((*gameboard)[RD][CD+1]=='X' || (*gameboard)[RD][CD+1]=='@' || (*gameboard)[RD][CD+1]=='R')
						(*gameboard)[RD][CD]='D';
					else
					{
						(*gameboard)[RD][CD+1]='D';
						(*gameboard)[RD][CD]='.';
						CD++;
					}
				else	
				{
					(*gameboard)[RD+1][CD]='D';
					(*gameboard)[RD][CD]='.';
					RD++;
				}
			else
			{
				(*gameboard)[RD+1][CD+1]='D';
				(*gameboard)[RD][CD]='.';
				RD++;
				CD++;
			}
		}
		else if(distanceR<0 && distanceC>0)			//diagwnia panw dexia	
		{
			if((*gameboard)[RD-1][CD+1]=='X' || (*gameboard)[RD-1][CD+1]=='@' || (*gameboard)[RD-1][CD+1]=='R')
				if((*gameboard)[RD-1][CD]=='X' || (*gameboard)[RD-1][CD]=='@' || (*gameboard)[RD-1][CD]=='R')
					if((*gameboard)[RD][CD+1]=='X' || (*gameboard)[RD][CD+1]=='@' || (*gameboard)[RD][CD+1]=='R')
						(*gameboard)[RD][CD]='D';
					else
					{
						(*gameboard)[RD][CD+1]='D';
						(*gameboard)[RD][CD]='.';
						CD++;
					}
				else	
				{
					(*gameboard)[RD-1][CD]='D';
					(*gameboard)[RD][CD]='.';
					RD--;
				}
			else
			{
				(*gameboard)[RD-1][CD+1]='D';
				(*gameboard)[RD][CD]='.';
				RD--;
				CD++;
			}
		}
		else if(distanceR<0 && distanceC<0)				//diagwnia panw aristera	
		{
			if((*gameboard)[RD-1][CD-1]=='X' || (*gameboard)[RD-1][CD-1]=='@' || (*gameboard)[RD-1][CD-1]=='R')
				if((*gameboard)[RD][CD-1]=='X' || (*gameboard)[RD][CD-1]=='@' || (*gameboard)[RD][CD-1]=='R')
					if((*gameboard)[RD-1][CD]=='X' || (*gameboard)[RD-1][CD]=='@' || (*gameboard)[RD-1][CD]=='R')
						(*gameboard)[RD][CD]='D';
					else
					{
						(*gameboard)[RD-1][CD]='D';
						(*gameboard)[RD][CD]='.';
						RD--;
					}
				else	
				{
					(*gameboard)[RD][CD-1]='D';
					(*gameboard)[RD][CD]='.';
					CD--;
				}
			else
			{
				(*gameboard)[RD-1][CD-1]='D';
				(*gameboard)[RD][CD]='.';
				RD--;
				CD--;
			}
		}
		


		if(RD==R && CD==C)
		{
			printf("You were captured by DARTH VADER!...Game over!\n");
			exit(EXIT_FAILURE);
		}
	}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void batsmen_input(FILE*);			//function prototypes
void bowler_input(FILE*);
void batsmen_player_profile(FILE*);
void bowler_player_profile(FILE*);
float strkrate(int , int );
float batsmen_average(int, int);
float bowler_average(int,int);
float economy(int,int);
char line[1024], cricketname[17]; 


struct Batsmen_Cricketers			//batsmen data structure
{
    char format[12];
    int matches, innings, balls, runs, sixes, fours;

};
struct Batsmen_Cricketers batsmen_playerTEST, batsmen_playerODI, batsmen_playerT20;	//user variables
struct Batsmen_Cricketers vk_test,vk_odi,vk_t20, sach_test,sach_odi,sach_t20;		//preexisting player variables


struct Bowler_Cricketers		//bowlers data structure
{
    char format[12];
    int matches,balls,wickets,runs,wides,overs;

};
struct Bowler_Cricketers bowler_playerTEST, bowler_playerODI, bowler_playerT20;		//user variables
struct Bowler_Cricketers is_test,is_odi,is_t20,jb_test,jb_odi,jb_t20;			//preexisting player variables
char user_name[100];

int read_bowlman_line(FILE *fp,struct Bowler_Cricketers *bowl_stat, float *econ, float *avg ) //function to capture values from the text file into a structure
{
	fgets(line, sizeof(line), fp);
	strncpy(cricketname, line, 16);
	cricketname[16] = 0;
	strncpy(bowl_stat->format, line+17, 4);
	bowl_stat->format[4] = 0;
	sscanf(line+22, "%d %d %d %d %d %d %f %f", &bowl_stat->matches, &bowl_stat->balls, &bowl_stat->wickets, &bowl_stat->runs, &bowl_stat->wides, &bowl_stat->overs, econ, avg); 
	//printf("name=%s,type=%s,\n", name, bowl_stat->format);
	//printf("matches=%d, innings=%d, balls=%d, runs=%d, sixes=%d, fours=%d, sr=%f, avg=%f\n", bat_stat->matches, bat_stat->innings, bat_stat->balls, bat_stat->runs, bat_stat->sixes, bat_stat->fours, *strike_rate, *average);
	return(0);
}

int read_batman_line(FILE *fp, struct Batsmen_Cricketers *bat_stat, float *strike_rate, float *average) //function to capture values from the text file into a structure
{

	fgets(line, sizeof(line), fp);
	strncpy(cricketname, line, 16);
	cricketname[16] = 0;
	strncpy(bat_stat->format, line+17, 4);
	bat_stat->format[4] = 0;
	sscanf(line+22, "%d %d %d %d %d %d %f %f", &bat_stat->matches, &bat_stat->innings, &bat_stat->balls, &bat_stat->runs, &bat_stat->sixes, &bat_stat->fours, strike_rate, average); 
	//printf("name=%s,type=%s,\n", name, bat_stat->format);
	//printf("matches=%d, innings=%d, balls=%d, runs=%d, sixes=%d, fours=%d, sr=%f, avg=%f\n", bat_stat->matches, bat_stat->innings, bat_stat->balls, bat_stat->runs, bat_stat->sixes, bat_stat->fours, *strike_rate, *average);
	return(0);
}
int main()
{
	float vk_teststr,vk_odistr,vk_t20str,vk_testavg,vk_odiavg,vk_t20avg;
	float sach_teststr,sach_odistr,sach_t20str,sach_testavg,sach_odiavg,sach_t20avg;
	float is_testecon,is_odiecon,is_t20econ,is_testavg,is_odiavg,is_t20avg;
	float jb_testecon,jb_odiecon,jb_t20econ,jb_testavg,jb_odiavg,jb_t20avg;

	FILE*fp;	
	fp=fopen("input_player_stats.txt","w");		//opening a file
	if(fp==NULL)
	{
		printf("Error in opening file");
		return 0;
	}
	int choice1, comp;
	char choice2[100];

	do
	{	
	there:
	printf("\n\n\n===================================================================================================\n");
	printf("\t\t\t\tCRICKET SCORE GENERATOR\n");
	printf("===================================================================================================\n\n\n");	
	printf("\n\n\t\tPick a position\n");
	printf("\t\t\t1.Batsmen\n");
	printf("\t\t\t2.Bowlers\n");
	printf("Please enter your choice (1 or 2) : ");
	scanf("%d",&choice1);

	switch(choice1)
	{
		case 1:
			printf("\nEnter the name of the batsmen : ");
			scanf(" %s",user_name);
			batsmen_input(fp);
			fclose(fp);
			fp=fopen("input_player_stats.txt","r");
			batsmen_player_profile(fp);
            		fclose(fp);
			printf("\n\n\n=================================================================================================================\n");
			printf("\t\t\t\tPLAYER COMPARISION");
			printf("\n=================================================================================================================\n");
			here:
			printf("\n\t\tWho do you want to compare your stats with : \n\t\t\t1:Virat Kohli \n\t\t\t2:Sachin Tendulkar\n");
			printf("\t\tPlease enter your choice : ");
			scanf("%d", &comp);
			fp=fopen("batman1.txt","r");
			fgets(line, sizeof(line), fp);
			
			switch(comp)
			{
				case 1:
					read_batman_line(fp,&vk_test,&vk_teststr, &vk_testavg);
					read_batman_line(fp,&vk_odi,&vk_odistr, &vk_odiavg);
            				read_batman_line(fp,&vk_t20,&vk_t20str, &vk_t20avg);
					printf("\n=================================================================================================================\n");
					printf("\t\t\t\tSTRIKE RATE COMPARISION");
					printf("\n=================================================================================================================\n");
					printf("\nPLAYER NAME\t\tTEST\t\t\tODI\t\t\tT20I");
					printf("\n%s\t\t\t%f\t\t%f\t\t%f",user_name,strkrate(batsmen_playerTEST.runs,batsmen_playerTEST.balls),strkrate(batsmen_playerODI.runs,batsmen_playerODI.balls),strkrate(batsmen_playerT20.runs,batsmen_playerT20.balls));
					printf("\nVirat Kholi\t\t%f\t\t%f\t\t%f",vk_teststr, vk_odistr, vk_t20str);
					printf("\n\n=================================================================================================================\n");
					printf("\t\t\t\tAVERAGE COMPARISION");
					printf("\n=================================================================================================================\n");
					printf("\nPLAYER NAME\t\tTEST\t\t\tODI\t\t\tT20I");
					printf("\n%s\t\t\t%f\t\t%f\t\t%f",user_name,batsmen_average(batsmen_playerTEST.runs,batsmen_playerTEST.matches),batsmen_average(batsmen_playerODI.runs,batsmen_playerODI.matches),batsmen_average(batsmen_playerT20.runs,batsmen_playerODI.matches));
					printf("\nVirat Kholi\t\t%f\t\t%f\t\t%f",vk_testavg, vk_odiavg, vk_t20avg);

					/*printf("Your strike rates in TEST, ODI and t20 formats are: %f %f %f", strkrate(batsmen_playerTEST.runs,batsmen_playerTEST.balls),strkrate(batsmen_playerODI.runs,batsmen_playerODI.balls),strkrate(batsmen_playerT20.runs,batsmen_playerT20.balls));
					printf("Virat Kohli's strike rates in TEST, ODI and t20 are: %f %f %f", vk_teststr, vk_odistr, vk_t20str);
					printf("Your averages in TEST, ODI and t20 formats are: %f %f %f", batsmen_average(batsmen_playerTEST.runs,batsmen_playerTEST.matches),batsmen_average(batsmen_playerODI.runs,batsmen_playerODI.matches),batsmen_average(batsmen_playerT20.runs,batsmen_playerODI.matches));
					printf("Virat Kohli's averages in TEST, ODI and t20 are: %f %f %f", vk_testavg, vk_odiavg, vk_t20avg);*/
					fclose(fp);
					break;
				case 2:
					read_batman_line(fp,&sach_test,&sach_teststr, &sach_testavg);
            				read_batman_line(fp,&sach_odi,&sach_odistr, &sach_odiavg);
            				read_batman_line(fp,&sach_t20,&sach_t20str, &sach_t20avg);

					printf("\n=================================================================================================================\n");
					printf("\t\t\t\tSTRIKE RATE COMPARISION");
					printf("\n=================================================================================================================\n");
					printf("\nPLAYER NAME\t\tTEST\t\t\tODI\t\t\tT20I");
					printf("\n%s\t\t\t%f\t\t%f\t\t%f",user_name,strkrate(batsmen_playerTEST.runs,batsmen_playerTEST.balls),strkrate(batsmen_playerODI.runs,batsmen_playerODI.balls),strkrate(batsmen_playerT20.runs,batsmen_playerT20.balls));
					printf("\nSachin Tendulkar\t%f\t\t%f\t\t%f",sach_teststr, sach_odistr, sach_t20str);
					printf("\n\n=================================================================================================================\n");
					printf("\t\t\t\tAVERAGE COMPARISION");
					printf("\n=================================================================================================================\n");
					printf("\nPLAYER NAME\t\tTEST\t\t\tODI\t\t\tT20I");
					printf("\n%s\t\t\t%f\t\t%f\t\t%f",user_name,batsmen_average(batsmen_playerTEST.runs,batsmen_playerTEST.matches),batsmen_average(batsmen_playerODI.runs,batsmen_playerODI.matches),batsmen_average(batsmen_playerT20.runs,batsmen_playerODI.matches));
					printf("\nSachin Tendulkar\t%f\t\t%f\t\t%f",sach_testavg, sach_odiavg, sach_t20avg);
					/*printf("Your strike rates in TEST, ODI and t20 formats are: %f %f %f", strkrate(batsmen_playerTEST.runs,batsmen_playerTEST.balls),strkrate(batsmen_playerODI.runs,batsmen_playerODI.balls),strkrate(batsmen_playerT20.runs,batsmen_playerT20.balls));
					printf("Sachin Tendulkar's strike rates in TEST, ODI and t20 are: %f %f %f", sach_teststr, sach_odistr, sach_t20str);
					printf("Your averages in TEST, ODI and t20 formats are: %f %f %f", batsmen_average(batsmen_playerTEST.runs,batsmen_playerTEST.matches),batsmen_average(batsmen_playerODI.runs,batsmen_playerODI.matches),batsmen_average(batsmen_playerT20.runs,batsmen_playerODI.matches));
					printf("Sachin Tendulkar's averages in TEST, ODI and t20 are: %f %f %f", sach_testavg, sach_odiavg, sach_t20avg);*/
					fclose(fp);
					break;
				default:
					printf("\t\t\tEnter correct option!");
					goto here;
					
			}
			
			/*printf("\n\n\n\tTEST\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t%0.2f\t%0.2f",batsmen_playerTEST.matches,batsmen_playerTEST.runs,batsmen_playerTEST.balls,batsmen_playerTEST.sixes,batsmen_playerTEST.fours,strkrate(batsmen_playerTEST.runs,batsmen_playerTEST.balls),batsmen_average(batsmen_playerTEST.runs,batsmen_playerTEST.matches));
			printf("\n\tODI\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t%f\t%f",batsmen_playerODI.matches,batsmen_playerODI.runs,batsmen_playerODI.balls,batsmen_playerODI.sixes,batsmen_playerODI.fours,strkrate(batsmen_playerODI.runs,batsmen_playerODI.balls),batsmen_average(batsmen_playerODI.runs,batsmen_playerODI.matches));
			printf("\n\tT20I\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t%f\t%f",batsmen_playerT20.matches,batsmen_playerT20.runs,batsmen_playerT20.balls,batsmen_playerT20.sixes,batsmen_playerT20.fours,strkrate(batsmen_playerT20.runs,batsmen_playerT20.balls),batsmen_average(batsmen_playerT20.runs,batsmen_playerT20.matches));*/

			break;
		case 2:
			printf("Enter the name of the bowler : ");
			scanf(" %s",user_name);
			bowler_input(fp);
			fclose(fp);

			fp=fopen("input_player_stats.txt","r");

			bowler_player_profile(fp);
			fclose(fp);
			fp=fopen("bowlman.txt","r");
			fgets(line, sizeof(line), fp);
			printf("\n\n\n=================================================================================================================\n");
			printf("\t\t\t\tPLAYER COMPARISION");
			printf("\n=================================================================================================================\n");
			printf("\n\t\tWho do you want to compare your stats with? \n\t\t\t1:Ishant Sharma \n\t\t\t2:Jasprit Bumrah");
			printf("\nPlease enter your choice : ");
			scanf("%d", &comp);
			switch(comp)
			{
				case 1:
					read_bowlman_line(fp,&is_test,&is_testecon, &is_testavg);
					read_bowlman_line(fp,&is_odi,&is_odiecon, &is_odiavg);
            				read_bowlman_line(fp,&is_t20,&is_t20econ, &is_t20avg);
					printf("\n=================================================================================================================\n");
					printf("\t\t\t\tECONOMY COMPARISION");
					printf("\n=================================================================================================================\n");
					printf("\nPLAYER NAME\t\tTEST\t\t\tODI\t\t\tT20I");
					printf("\n%s\t\t\t%f\t\t%f\t\t%f",user_name,economy(bowler_playerTEST.runs,bowler_playerTEST.wickets),economy(bowler_playerODI.runs,bowler_playerODI.wickets),economy(bowler_playerT20.runs,bowler_playerT20.wickets));
					printf("\nIshant Sharma\t\t%f\t\t%f\t\t%f",is_testecon, is_odiecon, is_t20econ);
					printf("\n\n=================================================================================================================\n");
					printf("\t\t\t\tAVERAGE COMPARISION");
					printf("\n=================================================================================================================\n");
					printf("\nPLAYER NAME\t\tTEST\t\t\tODI\t\t\tT20I");
					printf("\n%s\t\t\t%f\t\t%f\t\t%f",user_name,bowler_average(bowler_playerTEST.runs,bowler_playerTEST.overs),bowler_average(bowler_playerODI.runs,bowler_playerODI.overs),bowler_average(bowler_playerT20.runs,bowler_playerODI.overs));
					printf("\nIshant Sharma\t\t%f\t\t%f\t\t%f",is_testavg, is_odiavg, is_t20avg);

					/*printf("\n%s's economy in TEST, ODI and t20 formats are: %f %f %f",user_name,economy(bowler_playerTEST.runs,bowler_playerTEST.wickets),economy(bowler_playerODI.runs,bowler_playerODI.wickets),economy(bowler_playerT20.runs,bowler_playerT20.wickets));
					printf("\nIshant Sharma's economy in TEST, ODI and t20 are: %f %f %f", is_testecon, is_odiecon, is_t20econ);
					printf("\n\n%s's averages in TEST, ODI and t20 formats are: %f %f %f",user_name,bowler_average(bowler_playerTEST.runs,bowler_playerTEST.overs),bowler_average(bowler_playerODI.runs,bowler_playerODI.overs),bowler_average(bowler_playerT20.runs,bowler_playerODI.overs));
					printf("\nIshant Sharma's averages in TEST, ODI and t20 are: %f %f %f", is_testavg, is_odiavg, is_t20avg);*/
					fclose(fp);
					break;
				case 2:
					read_bowlman_line(fp,&jb_test,&jb_testecon, &jb_testavg);
            				read_bowlman_line(fp,&jb_odi,&jb_odiecon, &jb_odiavg);
            				read_bowlman_line(fp,&jb_t20,&jb_t20econ, &jb_t20avg);

					printf("\n=================================================================================================================\n");
					printf("\t\t\t\tECONOMY COMPARISION");
					printf("\n=================================================================================================================\n");
					printf("\nPLAYER NAME\t\tTEST\t\t\tODI\t\t\tT20I");
					printf("\n%s\t\t\t%f\t\t%f\t\t%f",user_name,economy(bowler_playerTEST.runs,bowler_playerTEST.wickets),economy(bowler_playerODI.runs,bowler_playerODI.wickets),economy(bowler_playerT20.runs,bowler_playerT20.wickets));
					printf("\nJasprit Bumrah\t\t%f\t\t%f\t\t%f",jb_testecon, jb_odiecon, jb_t20econ);
					printf("\n\n=================================================================================================================\n");
					printf("\t\t\t\tAVERAGE COMPARISION");
					printf("\n=================================================================================================================\n");
					printf("\nPLAYER NAME\t\tTEST\t\t\tODI\t\t\tT20I");
					printf("\n%s\t\t\t%f\t\t%f\t\t%f",user_name,bowler_average(bowler_playerTEST.runs,bowler_playerTEST.overs),bowler_average(bowler_playerODI.runs,bowler_playerODI.overs),bowler_average(bowler_playerT20.runs,bowler_playerODI.overs));
					printf("\nJasprit Bumrah\t\t%f\t\t%f\t\t%f",jb_testavg, jb_odiavg, jb_t20avg);
					/*printf("Your economy in TEST, ODI and t20 formats are: %f %f %f", economy(bowler_playerTEST.runs,bowler_playerTEST.wickets),economy(bowler_playerODI.runs,bowler_playerODI.wickets),economy(bowler_playerT20.runs,bowler_playerT20.wickets));						
					printf("Jasprit Bumrah's economy in TEST, ODI and t20 are: %f %f %f", jb_testecon, jb_odiecon, jb_t20econ);
					printf("Your averages in TEST, ODI and t20 formats are: %f %f %f", bowler_average(bowler_playerTEST.runs,bowler_playerTEST.overs),bowler_average(bowler_playerODI.runs,bowler_playerODI.overs),bowler_average(bowler_playerT20.runs,bowler_playerODI.overs));
					printf("Jasprit Bumrah's averages in TEST, ODI and t20 are: %f %f %f", jb_testavg, jb_odiavg, jb_t20avg);*/
					fclose(fp);
					break;
				default:
					printf("Enter correct option");
					
			}
           
            


	
			/*printf("\n\tTEST\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t%f\t%f",bowler_playerTEST.matches,bowler_playerTEST.balls,bowler_playerTEST.runs,bowler_playerTEST.wickets,bowler_playerTEST.wides,bowler_playerTEST.overs,economy(bowler_playerTEST.runs,bowler_playerTEST.wickets),bowler_average(bowler_playerTEST.runs,bowler_playerTEST.overs));
			printf("\n\tODI\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t%f\t%f",bowler_playerODI.matches,bowler_playerODI.balls,bowler_playerODI.runs,bowler_playerODI.wickets,bowler_playerODI.wides,bowler_playerODI.overs,economy(bowler_playerODI.runs,bowler_playerODI.wickets),bowler_average(bowler_playerODI.runs,bowler_playerODI.overs));
			printf("\n\tT20I\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t%f\t%f",bowler_playerT20.matches,bowler_playerT20.balls,bowler_playerT20.runs,bowler_playerT20.wickets,bowler_playerT20.wides,bowler_playerT20.overs,economy(bowler_playerT20.runs,bowler_playerT20.balls),bowler_average(bowler_playerT20.runs,bowler_playerT20.overs));*/
			break;
		default : 
			printf("Please enter the correct option\n");
			goto there;
	}
	printf("\n\nScore generation and statistic comparision completed sucessfully!\nWould you like to try score generation again(yes/no) : ");
	scanf("%s",choice2);
	if(strcmp(choice2,"yes")!=0)
	{
		printf("\n\t\t\t\t\t\t\t\tTHANK YOU!");
	}
	}
	while(strcmp(choice2,"yes")==0);
	
	return 0;
}
void batsmen_input(FILE *fp)
{
	printf("\n\t\tTEST FORMAT\n");
	strcpy(batsmen_playerTEST.format,"TEST");			
    	printf("Enter the number of matches played : ");
    	scanf("%d", &batsmen_playerTEST.matches);
    	printf("Enter number of runs scored : ");
    	scanf("%d", &batsmen_playerTEST.runs);
    	printf("Enter number of balls faced : ");
    	scanf("%d", &batsmen_playerTEST.balls);
	here1:
    	printf("Enter number of sixes scored : ");
    	scanf("%d", &batsmen_playerTEST.sixes);
    	printf("Enter number of fours scored : ");
    	scanf("%d", &batsmen_playerTEST.fours);
	if(batsmen_playerTEST.runs<(4*batsmen_playerTEST.fours+6*batsmen_playerTEST.sixes))
	{
		printf("\nThere is an ambiguity in the number of runs entered!(runs generated by 4s and 6s is greater than the number of runs entered)\n");
		printf("\nPlease enter number of fours and sixes correctly!\n\n");
		goto here1;
	}
	fwrite(&batsmen_playerTEST,sizeof(batsmen_playerTEST),1,fp);

	printf("\t\tODI FORMAT\n");	
	strcpy(batsmen_playerODI.format,"ODI");				
	printf("Enter the number of matches played : ");
	scanf("%d", &batsmen_playerODI.matches);
	printf("Enter number of runs scored : ");
	scanf("%d",&batsmen_playerODI.runs);
	printf("Enter number of balls faced : ");
	scanf("%d",&batsmen_playerODI.balls);
	here2:
	printf("Enter number of sixes scored : ");
	scanf("%d",&batsmen_playerODI.sixes);
	printf("Enter number of fours scored : ");
	scanf("%d",&batsmen_playerODI.fours);
	if(batsmen_playerODI.runs<(4*batsmen_playerODI.fours+6*batsmen_playerODI.sixes))
	{
		printf("\nThere is an ambiguity in the number of runs entered!(runs generated by 4s and 6s is greater than the number of runs entered)\n");
		printf("\nPlease enter number of fours and sixes correctly!\n\n");
		goto here2;
	}
	fwrite(&batsmen_playerODI,sizeof(batsmen_playerODI),1,fp);
	
	printf("\t\tT20I FORMAT\n");
	strcpy(batsmen_playerT20.format,"T20I");					
	printf("Enter the number of matches played : ");
	scanf("%d",&batsmen_playerT20.matches);
	printf("Enter number of runs scored : ");	
	scanf("%d",&batsmen_playerT20.runs);
	printf("Enter number of balls faced : ");
	scanf("%d",&batsmen_playerT20.balls);
	here3:
	printf("Enter number of sixes scored : ");
	scanf("%d",&batsmen_playerT20.sixes);
	printf("Enter number of fours scored : ");
	scanf("%d",&batsmen_playerT20.fours);
	if(batsmen_playerT20.runs<(4*batsmen_playerT20.fours+6*batsmen_playerT20.sixes))
	{
		printf("\nThere is an ambiguity in the number of runs entered!(runs generated by 4s and 6s is greater than the number of runs entered)\n");
		printf("\nPlease enter number of fours and sixes correctly!\n\n");
		goto here3;
	}
	fwrite(&batsmen_playerT20,sizeof(batsmen_playerT20),1,fp);
	
	
}

void bowler_input(FILE *fp)
{

	printf("\t\tTEST FORMAT\n");				//test
	strcpy(bowler_playerTEST.format,"TEST");    	
	printf("Enter the number of matches played : ");
    	scanf("%d",&bowler_playerTEST.matches);
    	printf("Enter number of balls bowled : ");
    	scanf("%d",&bowler_playerTEST.balls);
	there1:
    	printf("Enter number of wickets taken : ");
    	scanf("%d",&bowler_playerTEST.wickets);
	if(bowler_playerTEST.wickets>bowler_playerTEST.matches*11)
	{
		printf("\nThere is an ambiguity in the number of wickets taken entered!");
		printf("\nPlease enter number of wickets taken correcty!\n");
		goto there1;
	}
    	printf("Enter number of runs given: ");
    	scanf("%d",&bowler_playerTEST.runs);
    	printf("Enter number of wides given : ");
    	scanf("%d",&bowler_playerTEST.wides);
        printf("Enter number of overs bowled : ");
    	scanf("%d",&bowler_playerTEST.overs);
	fwrite(&bowler_playerTEST,sizeof(bowler_playerTEST),1,fp);

	printf("\t\tODI FORMAT\n");				//ODI
	strcpy(bowler_playerODI.format,"ODI");  
	printf("Enter the number of matches played : ");
    	scanf("%d",&bowler_playerODI.matches);
    	printf("Enter number of balls bowled : ");
    	scanf("%d",&bowler_playerODI.balls);
	there2:
    	printf("Enter number of wickets taken : ");
    	scanf("%d",&bowler_playerODI.wickets);
	if(bowler_playerODI.wickets>bowler_playerODI.matches*11)
	{
		printf("\nThere is an ambiguity in the number of wickets taken entered!");
		printf("\nPlease enter number of wickets taken correcty!\n");
		goto there2;
	}
    	printf("Enter number of runs given: ");
    	scanf("%d",&bowler_playerODI.runs);
    	printf("Enter number of wides given : ");
    	scanf("%d",&bowler_playerODI.wides);
        printf("Enter number of overs bowled : ");
    	scanf("%d",&bowler_playerODI.overs);
	fwrite(&bowler_playerODI,sizeof(bowler_playerODI),1,fp);

	printf("\t\tT20I FORMAT\n");				//T20
	strcpy(bowler_playerT20.format,"T20"); 
	printf("Enter the number of matches played : ");
    	scanf("%d",&bowler_playerT20.matches);
    	printf("Enter number of balls bowled : ");
    	scanf("%d",&bowler_playerT20.balls);
	there3:
    	printf("Enter number of wickets taken : ");
    	scanf("%d",&bowler_playerT20.wickets);
	if(bowler_playerT20.wickets>bowler_playerT20.matches*11)
	{
		printf("\nThere is an ambiguity in the number of wickets taken entered!");
		printf("\nPlease enter number of wickets taken correcty!\n");
		goto there3;
	}
    	printf("Enter number of runs given: ");
    	scanf("%d",&bowler_playerT20.runs);
    	printf("Enter number of wides given : ");
    	scanf("%d",&bowler_playerT20.wides);
        printf("Enter number of overs bowled : ");
    	scanf("%d",&bowler_playerT20.overs);
	fwrite(&bowler_playerT20,sizeof(bowler_playerT20),1,fp);
}



void batsmen_player_profile(FILE *fp)
{
	printf("\n=================================================================================================================\n");
	printf("\t\t\t\t\t\tPLAYER PROFILE\n");
	printf("=================================================================================================================\n");
	printf("\n\n\t\t\t\t\t\tPLAYER NAME : %s\n\n\n\n",user_name);
	printf("=================================================================================================================\n");
	printf("\tFORMAT\tMATCHES\t\tRUNS\tBALLS FACED\t\tSIXES\t\tFOURS\tSTRIKE RATE\tAVERAGE\n");
	printf("=================================================================================================================\n");


	struct Batsmen_Cricketers *object=malloc(sizeof(struct Batsmen_Cricketers));


	while(fread(object,sizeof(struct Batsmen_Cricketers),1,fp)>0)
	{
		
		printf("\n\t%s\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t%f\t%f",object->format,object->matches,object->runs,object->balls,object->sixes,object->fours,strkrate(object->runs,object->balls),batsmen_average(object->runs,object->matches));
		//printf("\n%d",ftell(fp));
	}
	printf("\n=================================================================================================================\n");

}
void bowler_player_profile(FILE *fp)
{
	printf("\n=================================================================================================================\n");
	printf("\t\t\t\t\t\tPLAYER PROFILE\n");
	printf("=================================================================================================================\n");
	printf("\n\n\t\t\t\t\t\tPLAYER NAME : %s\n\n\n\n",user_name);
	printf("======================================================================================================================\n");
	printf("\tFORMAT\t\tMATCHES\t\tWICKETS\t\tRUNS GIVEN\tWIDES\t\tOVERS\tECONOMY\t\tAVERAGE\n");
	printf("======================================================================================================================\n");
	struct Bowler_Cricketers *object=malloc(sizeof(struct Bowler_Cricketers));
	while(fread(object,sizeof(struct Bowler_Cricketers),1,fp)>0)
	{
		
		printf("\n\t%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t%f\t%f",object->format,object->matches,object->wickets,object->runs,object->wides,object->overs,economy(object->runs,object->overs),bowler_average(object->runs,object->wickets));
		//printf("\n%d",ftell(fp));
	}
	printf("\n=================================================================================================================\n");
}
float strkrate(int r, int b)
{
	if(b!=0)
	{
    		return (float)r*(float)100/(float)b;
	}
	else
	{
		return 0;
	}
}
float batsmen_average(int run, int m)
{
	if(m!=0)
	{
    		return (float)run/(float)m;
	}
	else
	{
		return 0;
	}
}
float bowler_average(int run, int wickets)
{
	if(wickets!=0)
	{
   		return (float)run/(float)wickets;
	}
	else
	{
		return 0;
	}
} 

float economy(int run, int overs)
{
	if(overs!=0)
	{
  		return (float)run/(float)overs;
	}
	else
	{
		return 0;
	}
}

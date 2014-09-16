/*Author:Shivkumar 1PI12IS103
	 Madhusudhan 1PI12IS4
Question:Updating the company's share cost 
	
SIR ITS WORKING SAME LENGTH OF THE DIGITS OF THE SHARE_COST I TRIED FOR THE OTHER LENGTHS BUT IT'S NOT WORKING
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
 {
  int lineCount=0,p=0,x=0,flag=1,len1=0,len2=0;
  FILE *file;
  file=fopen("data4.csv","r+");
   if(file==NULL)
     {
       printf("file is not opened properly\n");
       return -1;
     }
    char line[100];
    char companyname[30];
    char sharecost[30];

  while ((fgets(line,sizeof(line),file)) != NULL) 
    {
     lineCount++;
    }

  char *lineArray[lineCount-1];
  char *token;
  char ans[100];
  const char *j=",";
  rewind(file);
  char *company_name[lineCount];
  char *share_cost[lineCount];
  while ((fgets(line,sizeof(line),file)) != NULL) 
   {
      lineArray[p]=(char *)malloc(strlen(line));//1st bunch of memory allocated
      strcpy(lineArray[p],line);
      token = strtok(lineArray[p],j);
      x=1;
    
      while( token != NULL) 
        {
            if((x%3)==1)
              {
                company_name[p]=malloc(strlen(token));
                strcpy(company_name[p],token);
              }
           else if((x%3)==2)
              {

                share_cost[p] = malloc(strlen(token));
                strcpy(share_cost[p],token);
              }
           token = strtok(NULL, j);
           x++;
        }   //end of inner while
    p++;
 
  }//end of outer while

	    rewind(file);
	    printf("Enter Company name\n");
	    scanf("%s",companyname);

	    printf("Enter share cost\n");
		
           scanf("%s",sharecost);
      
		for(x=0;x<lineCount;x++)
		  {
			                    
		    if(strcmp(companyname,company_name[x])==0)
                       break;
		   }
	       rewind(file);
               for(p=0;p<x;p++)
		{
		   fgets(line,sizeof(line),file);
		}
           // fputs(char3,file);
      lineArray[0]=(char *)malloc(strlen(line));//1st bunch of memory allocated
      strcpy(lineArray[0],line);
      token = strtok(lineArray[0],j);
      x=1;
    
      while( token != NULL) 
        {
           
            if((x%3)==2)
              {
                fprintf(file,"%s,%s",companyname,sharecost);    
              }
           token = strtok(NULL, j);
           x++;
        }   //end of inner while

fclose(file);
return 0;
}

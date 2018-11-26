#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct date {
	int d;
	int m;
	int y;
}date;


typedef struct student {
	char fname[20];
	char lname[20];
	struct date dob;
	char gender[1];
	
}student;


int main(){
	
	/* Pripojenie suboru a naèitanie obsahu */
	FILE*f;
	struct student School[20];
	int index=0;
	f=fopen("text.txt","r");
	
	if(f==NULL){
		printf("Error");
	}
	
	while(fscanf(f,"%s",&School[index].fname) !=EOF)
	{
		
		fscanf(f,"%s",&School[index].lname);
		/*struct dob*/
		fscanf(f,"%d",&School[index].dob.d);
		fscanf(f,"%d",&School[index].dob.m);
		fscanf(f,"%d",&School[index].dob.y);
		fscanf(f,"%s",&School[index].gender);
		
		index++;
	}

	
	/* Vypisanie zien */
	int i;
	printf("Females:");
	for(i=0;i<index;i++)
	{
		School[i].gender;
		if(School[i].gender[0]=='F'){
		printf("\n%s %s",School[i].fname,School[i].lname);	
		}
	}
	
	/* Vypisanie tych ktorí sa narodili v decembri */
	printf("\n\nDecember month:");
	for(i=0;i<index;i++)
	{

		if(School[i].dob.m==12)
		{
		printf("\n%s %s",School[i].fname,School[i].lname);
		}
	}
	
	/* Vypisanie tych ktorych vek je len po 18 rokov*/
	printf("\n\nYounger than 18:");
    for (i=0; i<index; i++){
        if ((School[i].dob.y==2000 && School[i].dob.m==11 && School[i].dob.d>=24) || (School[i].dob.y==2000 && School[i].dob.m==12) || School[i].dob.y>=2001)
		{
            printf("\t \n%s %s", School[i].fname, School[i].lname);
   		}
	}
	
	/* Vypisanie pod¾a znamenia panna */
	printf("\n\nVirgo sign:");
	for(i=0;i<index;i++)
	{
		
		School[i].dob.d;
		School[i].dob.m;
		if( (School[i].dob.m == 8 && (School[i].dob.d>=24 && School[i].dob.d<=31)) || (School[i].dob.m == 9 && (School[i].dob.d>=1 && School[i].dob.d<=23)))
		{
		printf("\n%s %s",School[i].fname,School[i].lname);
		}
	}
	
	/* Usporiadanie pod¾a veku */

	int temp,j;
	printf("\n\nSorted by age:");
    for (i=0;i<index-1;i++)
	{
		for (j = 0;j<index-i-1;j++)
		{
			if (School[j].dob.d > School[j+1].dob.d)
			{
				struct student temp = School[j];
				School[j] = School[j+1];
				School[j+1] = temp;
			}
		}
	}
	
	for (i=0;i<index-1;i++)
	{
		for (j = 0;j<index-i-1;j++)
		{
			if (School[j].dob.m > School[j+1].dob.m)
			{
				struct student temp = School[j];
				School[j] = School[j+1];
				School[j+1] = temp;
			}
		}
	}
	
	for (i=0;i<index-1;i++)
	{
		for (j = 0;j<index-i-1;j++)
		{
			if (School[j].dob.y > School[j+1].dob.y)
			{
				struct student temp = School[j];
				School[j] = School[j+1];
				School[j+1] = temp;
			}
		}
	}
	
    for(i=0;i<index;i++)
	{
    	printf("\n %d %d %d %s %s",School[i].dob.d,School[i].dob.m,School[i].dob.y,School[i].fname,School[i].lname);
	}
    
    fclose(f);
    
	
	

	
}

#include <stdio.h> 
#include <stdlib.h> 
#include "STD_Types.h"
#include "List.h"

void scanINFO(Patient* p) //function for scaning patient information
{
	getchar();
	printf("please enter patient's name:");
	scanf("%[^\n]%*c",&(p -> NAME));
	printf("please enter patient's age:");
	scanf("%d",&(p -> AGE));
	getchar();
	printf("please enter patient's gender:");
	scanf("%[^\n]%*c",&(p -> GENDER));
}

void patientINFO(Patient* start) //function to print the patient information
{
	printf("\n\n-------------------------------\n");
	printf("patient's info\nID is : %d\nName : %s\n",start -> ID,start -> NAME);
	printf("age : %d\nID : %s\n" ,start -> AGE,start -> GENDER);
	printf("\n-------------------------------\n");
}

Patient* AddPatient(Patient* start) // function to add new patient 
{
	Patient* c= start; Patient* pk= start; u32 id; 
	
	/*
	do
	{
		
		i=1;
		scanf("%d",&(temp -> ID ));
		while((temp->ID != c->ID)&&(c!=NULL)) 
		{
			c=c->link;	
		}
		if(c!=NULL)
		{
			i=0; c=start;
			printf("\nthis ID is already exist!\nplease enter another one: ");
			
		}
		else
			break;
	}while((c!=NULL)&&(i==0));
	*/
		
		printf("please enter Patient's ID:"); 
		scanf("%d",&(id ));
		while((id != c->ID)&&(c->link!=NULL)) 
		{
			c=c->link;	
		}
		if(c->ID==id)
		{
			printf("\n-------------------------------\n");
			printf("\nthis ID is already exist!\n");
			printf("\n-------------------------------\n");
			return c;
			
		}
		else
		{
			
			Patient* temp  =(Patient *)malloc(sizeof(Patient));
			temp -> ID=id;
			scanINFO(temp);
			temp -> link =NULL;
			
			while( pk -> link != NULL)
				pk = pk -> link;
	
			pk -> link= temp  ; 
			
			return temp;
		}
}

Patient* EditPatient(Patient* start) // function to edit patient record
{
	Patient* c= start; Patient* pk= start; u32 sel, id; 
	
	printf("please enter Patient's ID:"); 
	scanf("%d",&(id ));
	while((id != c->ID)&&(c->link!=NULL)) 
	{
		c=c->link;	
	}
	if(c->ID==id)
	{
		
		patientINFO(c);
		
		printf("to edit the Name enter 1\n");
		printf("to edit the age enter 2\n");
		printf("to edit the gender enter 3\n");
		printf("to edit the whole info 4\n");
		printf("your selection : ");
		scanf("%d",&sel);
		switch (sel)
		{
			case 1: 
				getchar();
				printf("please enter patient's Name:");
				scanf("%[^\n]%*c",&(c -> NAME)); 
				patientINFO(c); break;
				
			case 2:
				printf("please enter patient's age:");
				scanf("%d",&(c -> AGE));
				patientINFO(c); break;
			
			case 3:
				getchar();
				printf("please enter patient's gender:");
				scanf("%[^\n]%*c",&(c -> GENDER));
				patientINFO(c); break;
				
			case 4: 
				scanINFO(c);
				patientINFO(c); break;
				
			default : printf("\ninvalide selection \n");
				
		}
	}
	else
	{
		printf("\n-------------------------------\n");
		printf("\nthis ID is not exist!\n");
		printf("\n-------------------------------\n");
	}
	return start;
}

Patient* patientID( Patient* start , u32 id) // to search about patient by id
{
	Patient* p= start;
	
	while ((p-> ID != id )&&(p->link!=NULL))
		p= p -> link;
	if(p->ID==id)
		return p;
	else
	{
		printf("\n-------------------------------\n");
		printf("\nthis ID is not exist!\n");
		printf("\n-------------------------------\n");
		return NULL;
	}
}


void PrintList(Patient* start) //function to print the whole list of patients
{
	Patient *last = start;
	u32 i =1;
	
	printf("Patient Number %d\n", i);
	patientINFO(last);
	
	while ((last -> link)!=NULL)
	{
		last = last ->link;
		i++;
		printf("Patient Number %d\n", i);
		patientINFO(last);
	}
	
}

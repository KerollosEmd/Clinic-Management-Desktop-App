#include <stdio.h> 
#include <stdlib.h> 
#include "STD_Types.h"
#include "List.h"
/*
slot slots[5]={
	[0].TIME = "2PM TO 2:30PM" ,
	[1].TIME = "2:30 PM TO 3:00 PM",
	[2].TIME = "3:00 PM TO 3:30 PM",
	[3].TIME = "3:30 PM TO 4:00 PM",
	[4].TIME = "4:00 PM TO 4:30 PM"
}
*/
void  main()
{
	u32 sel;
	Patient* Pat=NULL;
	while(1)
	{
	printf("\nadmin mode (1) \nuser mode (2)\nyour selection :");
	scanf("%d",&sel);
	
	
	
	switch (sel)
	{
		case 1 : Pat=adminMode(); break;
		case 2 : userMode(Pat); break;
		default : printf("\nunvalide choice \n");
	}
	}
	
}
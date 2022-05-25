#include <stdio.h>
#include <stdlib.h>
#include "STD_Types.h"
#include "List.h"

slot slots[5] = { // making slotes to be reserved

	{"2:00 PM TO 2:30 PM", NULL},
	{"2:30 PM TO 3:00 PM", NULL},
	{"3:00 PM TO 3:30 PM", NULL},
	{"3:30 PM TO 4:00 PM", NULL},
	{"4:00 PM TO 4:30 PM", NULL}

};

Patient *adminMode(void)
{
	u32 password = 1234, tries = 0, pw, exit = 1;
	u32 selection;

	Patient *ptr = (Patient *)malloc(sizeof(Patient));
	Patient *p = NULL;

	printf("welcome to admin mode\n");

	do
	{
		if (tries == 0)
		{
			printf("\nplease enter the password: ");
			scanf("%d", &pw);
		}
		else
		{
			printf("wrong password\nplease try again: ");
			scanf("%d", &pw);
		}
		tries++;

	} while ((pw != password) && (tries < 3));

	if (tries < 3)
	{
		while (exit != 0)
		{
			printf("To add new patient enter: 1\n");
			printf("To edit patient record enter: 2\n");
			printf("To reserve a slot with a doctor enter: 3\n");
			printf("To cancel reservation enter 4\n");
			printf("To exit admin mode enter 5\n");
			printf("your selection: ");
			scanf("%d", &selection);

			switch (selection)
			{
			case 1: // add patient info
			{
				if (p == NULL)
				{
					p = ptr;
					printf("please enter patient's ID:");
					scanf("%d", &(ptr->ID));
					scanINFO(ptr);
					ptr->link = NULL;
					patientINFO(ptr);
				}
				else
				{
					p = AddPatient(ptr);

					patientINFO(p);
				}
				break;
			}

			case 2: // edit patient record
			{
				p = EditPatient(ptr);
				break;
			}

			case 3: // reserve a slot with a doctor
			{
				u32 i, j, id;
				while (1)
				{
					printf("to exit enter 5\n");
					printf("--------------------------------\n");
					for (j = 0; j < 5; j++)
					{
						if (slots[j].PATIENT == NULL)
							printf("%d) Doctor is available from %s \n", j, slots[j].TIME);
					}
					printf("--------------------------------\n");
					printf("choose the available slot: ");
					scanf("%d", &i);
					printf("enter the patient ID : ");
					scanf("%d", &id);
					if (i == 5)
						break;

					slots[i].PATIENT = patientID(ptr, id);
				}
				printf("so the reserved slots are :");
				printf("--------------------------------\n");
				for (j = 0; j < 5; j++)
				{
					if (slots[j].PATIENT != NULL)
						printf("%d) slot reseved : %s to patient :%s ID: %d\n", j, slots[j].TIME, (slots[j].PATIENT)->NAME, (slots[j].PATIENT)->ID);
				}
				printf("--------------------------------\n");
				break;
			}

			case 4: // cancel reservation
			{
				u32 i, j = 0, id;
				printf("the reserved slots are :");
				printf("--------------------------------\n");
				for (j = 0; j < 5; j++)
				{
					if (slots[j].PATIENT != NULL)
						printf("%d) slot reseved : %s to patient :%s ID: %d\n", j, slots[j].TIME, (slots[j].PATIENT)->NAME, (slots[j].PATIENT)->ID);
				}
				printf("--------------------------------\n");

				printf("enter the patient's id to be canceled : ");
				scanf("%d", &id);

				Patient *c = patientID(ptr, id);

				if (c->ID == id)
				{
					for (j = 0; (j < 5) && (slots[j].PATIENT != c); j++)
						;
					if (slots[j].PATIENT == c)
						slots[j].PATIENT = NULL;
				}

				break;
			}

			case 5: // exit admin mode
			{
				exit = 0;
				return ptr;
				break;
			}
			default:
				printf("\nunavailable selection!\n");
			}
		}
	}
	else
		printf("system failer");
}

void userMode(Patient *start)
{
	u32 selection, id, j;
	if (start != NULL)
	{
		printf("welcome to user mode \n");
		printf("to view patient's record enter (1)\n");
		printf("to view today's reservations enter (2)\n");
		printf("your selection : ");
		scanf("%d", &selection);

		switch (selection)
		{
		case 1: // view patient's record
		{
			printf("please enter patient's id :");
			scanf("%d", &id);
			patientINFO(patientID(start, id));
			break;
		}

		case 2: // to view reservations
		{
			printf("the reserved slots are :");
			printf("--------------------------------\n");
			for (j = 0; j < 5; j++)
			{
				if (slots[j].PATIENT != NULL)
					printf("%d) slot reseved : %s to patient :%s ID: %d\n", j, slots[j].TIME, (slots[j].PATIENT)->NAME, (slots[j].PATIENT)->ID);
			}
			printf("--------------------------------\n");
			break;
		}
		default:
			printf("\nunavailable selection!\n");
		}
	}
	else
		printf("there is no info can display for now please access admin mode first and enter some data ");
}
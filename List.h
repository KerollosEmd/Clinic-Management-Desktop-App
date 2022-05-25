#ifndef List_h
#define List_h 

typedef struct N Patient;

struct N{
	
	
	u32 ID; 
	u32 AGE;
	u8 NAME[20];
	u8 GENDER[10];
	
	Patient* link;
};

typedef struct SLOT slot;

struct SLOT {
	
	//u32 IsReseved; //if equals 0 indecates that it's not reserved
	u8  TIME[20];	// tells the slot time 
	Patient* PATIENT;	// pointing to the patient who reserved the slot
};

void PrintList(Patient* start);

void patientINFO(Patient* start);

void scanINFO(Patient* p);

Patient* adminMode(void);
void userMode(Patient* start);

Patient* EditPatient(Patient* start);

Patient* AddPatient(Patient* start);

Patient* patientID( Patient* start , u32 id);

#endif
//
// Created by zas on 9/11/2022.
//

#ifndef UNTITLED_ADMIN_H
#define UNTITLED_ADMIN_H
#define password 1234

#define slot1 1
#define slot2 2
#define slot3 3
#define slot4 4
#define slot5 5
#define slot_number 5
#define NUMBER_OF_PATIENTS 20
typedef struct
{
    uint8 name[20];
    uint8 age;
    uint8 gender[10];
    uint8 ID;
    uint8 slot;

}TStrPatient;
extern TStrPatient aSTrPatients[NUMBER_OF_PATIENTS];
extern  uint8 slot[slot_number];
void admin_mode_logain(void );

void admin_mode_options(void );

void Add_New_Patient(void );

void Edit_patient_record(void );

void Reserve_a_slot_with_the_doctor(void );

void Cancel_reservation(void );
#endif //UNTITLED_ADMIN_H

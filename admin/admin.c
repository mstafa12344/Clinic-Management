#include "STD_Types.h"
#include <stdio.h>
#include "admin.h"

 uint8 slot[5]={slot1,slot2,slot3,slot4,slot5};
 TStrPatient aSTrPatients[NUMBER_OF_PATIENTS]=
        {
        {
                {'m','u','s','t','a','f','a'},
                20,
                {'m','a','l','e'},
                12,
                slot1
            },
        {
                {'o','m','a','r'},
                21,
                {'m','a','l','e'},
                20,
                slot2
            },
        {
                {'m','a','i'},
                18,
                {'f','e','m','a','l','e'},
                13,
                slot3
            },

        };

void admin_mode_options(void )
{

    uint8 u8ChoosVar1;
    printf("\nplease select what do you want\n");
    printf("1-Add new patient record\n\n2-Edit patient record\n\n3- Reserve a slot with the doctor\n\n4-Cancel reservation\n\n");
    scanf("%d",&u8ChoosVar1);
    switch (u8ChoosVar1)
    {
        case 1:
            Add_New_Patient();
            break;
        case 2:
            Edit_patient_record();
            break;
        case 3:
            Reserve_a_slot_with_the_doctor();
            break;
        case 4:
            Cancel_reservation();
            break;



    }
}



void admin_mode_logain(void )
{
    uint8 counter=0;
    uint32 pass;
    printf("please enter the password:   ");
    scanf("%d",&pass);

    while (pass!=password&&counter<3)
    {
        printf("wrong try again.....\n ");
        printf("please enter the new password:   ");
        scanf("%d",&pass);
        counter++;

    }

    if(pass==password)
    {
        admin_mode_options();
    }
    else
    {

    }
}

void Add_New_Patient(void )
{
    uint8 index,i;
    uint8 tempID;
    printf("please enter the patient number:  ");
    scanf("%d",&index);

    if(aSTrPatients[index].ID!=0)
    {
        printf("this position is full!!!!!!!!");
    } else

    {
        printf("enter the ID :    ");
        scanf("%d",&tempID);
        for ( i = 0; i < NUMBER_OF_PATIENTS; i++)
        {
            if(tempID==aSTrPatients[i].ID)
            {
                printf("the ID already existed");
                break;
            }
            else
            {
                printf("enter the name  :");
                scanf("%s", &aSTrPatients[index].name);

                printf("enter your age   :");
                scanf("%d", &aSTrPatients[index].age);

                printf("enter the gender : ");
                scanf("%s",&aSTrPatients[index].gender);

                printf("enter your ID :  ");
                scanf("%d",&aSTrPatients[index].ID);

                break;

            }

        }
    }
}

void Edit_patient_record(void )
{
    uint8 u8CheckID,j;
    printf("please enter the ID: ");
    scanf("%d",&u8CheckID);

    for(j=0;j<NUMBER_OF_PATIENTS;j++)
    {
        if(u8CheckID==aSTrPatients[j].ID)
        {
            printf("you can edit\n");
            printf("old data are \n");
            printf("name: %s\n", aSTrPatients[j].name);
            printf("age: %d\n", aSTrPatients[j].age);
            printf("gender: %s\n",aSTrPatients[j].gender);
            printf("ID: %d\n",aSTrPatients[j].ID);

            printf("new data\n");
            printf("enter the name  :");
            scanf("%s", &aSTrPatients[j].name);

            printf("enter your age   :");
            scanf("%d", &aSTrPatients[j].age);

            printf("enter the gender : ");
            scanf("%s",&aSTrPatients[j].gender);

            printf("enter your ID :  ");
            scanf("%d",&aSTrPatients[j].ID);
            break;
        }
        else
        {
            printf("incorrect ID!!!!");
            break;
        }
    }
}

void Reserve_a_slot_with_the_doctor(void )
{
    uint8 patientNum;
    uint8 counter1,counter2=0;
    for(counter1=0;counter1<NUMBER_OF_PATIENTS;counter1++)
    {
        if(counter2<5)
        {
            if (aSTrPatients[counter1].slot == slot[counter2])
            {
                slot[counter2] = 0;
            }
            counter2++;
        }
    }
    printf(" available slots are:\n");
    for(uint8 j=0;j<slot_number;j++)
    {
        if(slot[j]!=0)
        {
            if(j==0)
            {
                printf("slot from 2pm to 2:30pm\n");
            }
            if(j==1)
            {
                printf("slot from  2:30pm to 3pm\n");
            }
            if(j==2)
            {
                printf("slot from  3pm to 3:30pm\n");
            }
            if(j==3)
            {
                printf("slot from 4pm to 4:30pm\n");
            }
            if(j==4)
            {
                printf("slot from  4:30pm to 5pm\n");
            }

        }

    }
    printf("please enter the patient number: ");
    scanf("%d",&patientNum);

    if((aSTrPatients[patientNum-1].ID==0))
    {
        printf("this ID dose not existed\n");
    }

    else
    {
        if(aSTrPatients[patientNum-1].slot!=0)
        {
            printf("this ID has a slot\n");

        }
        else
        {
            printf("please enter the ID:    ");
            scanf("%d", &aSTrPatients[patientNum].ID);
            printf("please enter desired slot:   ");
            scanf("%d", &aSTrPatients[patientNum].slot);

        }

    }

}

void Cancel_reservation(void )
{
    uint8 patient_ID;
    uint8 counter;
    printf("please enter the ID:  ");
    scanf("%d",&patient_ID);

    for(counter=0;counter<NUMBER_OF_PATIENTS;counter++)
    {
        if(patient_ID==aSTrPatients[counter].ID)
        {
          slot[aSTrPatients[counter].slot-1] =0;
            break;
        }

    }
    printf(" available slots are:\n");
    for(uint8 j=0;j<slot_number;j++)
    {
        if(slot[j]!=0)
        {
            if(j==0)
            {
                printf("slot from 2pm to 2:30pm\n");
            }
            if(j==1)
            {
                printf("slot from  2:30pm to 3pm\n");
            }
            if(j==2)
            {
                printf("slot from  3pm to 3:30pm\n");
            }
            if(j==3)
            {
                printf("slot from 4pm to 4:30pm\n");
            }
            if(j==4)
            {
                printf("slot from  4:30pm to 5pm\n");
            }

        }

    }

}
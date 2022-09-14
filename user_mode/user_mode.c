#include "../STD_Types.h"
#include "user_mode.h"
#include "../admin/admin.h"
#include <stdio.h>

void user_mode_logain(void )
{
    uint8 switchNum;
    printf("select what do you want\n1-View patient record\n2- View today s reservations\n");
    scanf("%d",& switchNum);
    switch ( switchNum)
    {
        case 1:
            View_patient_record() ;
            break;
        case 2:
            View_today_reservations();
            break;
    }
}


void View_patient_record(void )
{
    uint8 tempID;
    uint8 count;
    printf("please enter the ID:   ");
    scanf("%d",&tempID);
    for(count=0;count<NUMBER_OF_PATIENTS;count++)
    {
        if(tempID==aSTrPatients[count].ID)
        {
            printf("name: %s\n",aSTrPatients[count].name);
            printf("age : %d\n",aSTrPatients[count].age);
            printf("gender :%s\n",aSTrPatients[count].gender);
            printf("ID : %d\n",aSTrPatients[count].ID);

        }
    }
}


void View_today_reservations(void )
{
    uint8 count;
    for (count=0;count<NUMBER_OF_PATIENTS;count++)
    {
        /*
        if(aSTrPatients[count].ID!=0)
        {
            printf("ID: %d\n",aSTrPatients[count].ID);
        }
        */
        if((aSTrPatients[count].slot!=0)&&(aSTrPatients[count].ID!=0))
        {
            printf("ID: %d\t--> ",aSTrPatients[count].ID);
           if( aSTrPatients[count].slot==slot1)
           {
               printf("slot from 2pm to 2:30pm\n");
           }
           else if( aSTrPatients[count].slot==slot2)
            {
                printf("slot from 2:30pm to 3pm\n");
            }
            else if( aSTrPatients[count].slot==slot3)
            {
                printf("slot from 3pm to 3:30pm\n");
            }
            else if( aSTrPatients[count].slot==slot4)
            {
                printf("slot from 4pm to 4:30pm\n");
            }
            else if( aSTrPatients[count].slot==slot5)
            {
                printf("slot from 4:30pm to 5pm\n");
            }
            else
           {
               printf("no slots reserved\n");
           }
        }
    }
}
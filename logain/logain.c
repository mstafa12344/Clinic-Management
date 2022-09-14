
#include "STD_Types.h"
#include "../admin/admin.h"
#include "../user_mode/user_mode.h"
#include <stdio.h>
void logain(void )
{
    uint8 U8ChoosVar;
    printf("/**********************/\n");
    printf("/*welcom to the clinic*/\n");
    printf("/**********************/\n");
    printf("admin or user!!!\n1-amin\n2-user\n");
    scanf("%d",&U8ChoosVar);

    switch (U8ChoosVar)
    {
        case 1:
            admin_mode_logain();
            break;
        case 2:
            user_mode_logain();
            break;
    }


}
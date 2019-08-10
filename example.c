#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList_ByteArray.h"


LinkedList_ByteArray* processList(LinkedList_ByteArray* list);

////////////////////////////////////////////////////////////////////////////////
int main()
{
    printf("App start.........\n");

    /* create the list */
    LinkedList_ByteArray* stack = NULL;

    for(int repeat = 0; repeat < 3; repeat++)
    {
        /* add some elements to the list */
        uint8_t a[3][4] = {
           {0, 1, 2, 3},
           {4, 5, 6, 7},
           {8, 9, 10, 11},
        };
        for(int i = 0; i < 3; i++){
        	stack = ba_append(stack, a[i], sizeof(a[i]));
        }
        uint8_t c[] = {12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22};
        stack = ba_prepend(stack, c, sizeof(c));

        /* print the content */
         ba_print(stack);
         stack = processList(stack);
     }
	printf("END\n");
    return 0;
}
////////////////////////////////////////////////////////////////////////////////
LinkedList_ByteArray* processList(LinkedList_ByteArray* list)
{
    for(int i = 0; list != NULL; i++){
         printf("Processing: %d, data:", i);
         pHex_nl(list->data, list->length);
         list = ba_removeFirst(list);
     }
     return list;
}


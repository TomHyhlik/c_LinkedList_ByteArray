#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList_ByteArray.h"


LinkedList_ByteArray* processList(LinkedList_ByteArray* list);

////////////////////////////////////////////////////////////////////////////////
int main()
{
    printf("AppStart.......................................\n");

    /* create the list */
    LinkedList_ByteArray* list = NULL;

    /* append some data */
    for (int i = 1; i <= 5; i++) {
        /* create array to append and fill it with data */
        size_t array_len = i;
        uint8_t* array = malloc(array_len);
        for (int j = 0; j < array_len; j++) {
            array[j] = i + j;
        }
        /* append the anew array to the list */
        list = ba_append(list, array, array_len);
    }

    printf("\nPrint the whole list content:\n");
    ba_print(list);

    list = processList(list);

	printf("AppEnd........................................\n");
    return 0;
}
////////////////////////////////////////////////////////////////////////////////
LinkedList_ByteArray* processList(LinkedList_ByteArray* list)
{
    printf("\nProcess the list:\n");

    for (int i = 0; list != NULL; i++) {
         printf("Processing: %d, data:", i);
         pHex_nl(list->data, list->length);
         list = ba_removeFirst(list);
     }
     return list;
}
////////////////////////////////////////////////////////////////////////////////

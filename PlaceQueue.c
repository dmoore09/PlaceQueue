//Daniel Moore
////905614004
////
////On my honor:
////
////I have not discussed the C language code in my program with
////anyone other than my instructor or the teaching assistants assigned to this course.
////
////I have not used C language code obtained from another student, or
////any other unauthorized source, either modified or unmodified.
////If any C language code or documentation used in my program
////was obtained from another source, such as a text book or course
////notes, that has been clearly noted with a proper citation in the comments of my program.
////
////<Daniel Moore>
//

#include <stdio.h>
#include <stdbool.h>
#include "Place.h"
#include "Queue.h"
#include "PlaceQueue.h"
#include <stdlib.h>

bool PlaceDT_Set(PlaceDT* const pPlaceDT, Place* pPlace){
	pPlaceDT->pItem = &(*pPlace);
	QNode_Init(&(pPlaceDT->Node));
	return true;
}

bool PlaceQueue_Init(PlaceQueue* const pPQ){
	Queue_Init(&(pPQ->Q));
	return true;
}

bool   PlaceQueue_Schedule(PlaceQueue* const pPQ, Place* const pPlace){
	PlaceDT *wrapper = malloc(sizeof(PlaceDT));
	PlaceDT_Set(wrapper, pPlace);
	Queue_Push(&(pPQ->Q), &(wrapper->Node));
	return true;
}

Place* PlaceQueue_Visit(PlaceQueue* const pPQ){
	if (!PlaceQueue_Empty(pPQ))
	{
		QNode* node = Queue_Pop(&(pPQ->Q));
		PlaceDT *p = Queue_Entry(node, PlaceDT, Node);
		Place *payload = p->pItem;
		free(p);
		return payload;
	}
	else
	{
		return NULL;
	}
}

bool   PlaceQueue_Contains(const PlaceQueue* const pPQ, const Place* const pPlace){
	//temporary place queue
	PlaceQueue temp;
	PlaceQueue_Init(&temp);
	bool contains = false;
	while(!Queue_Empty(&(pPQ->Q))){
		//Place_Print(*pPlace);
		//Place_Print(Queue_Front(&(pPQ->Q)));
		Place* tempPlace = PlaceQueue_Visit(pPQ);
		if (Place_Equals(tempPlace, pPlace)){
			contains = true;
		}
		PlaceQueue_Schedule(&temp, tempPlace);
	}
	printf("first loop ok \n");
	while (!Queue_Empty(&(temp.Q)))
	{
		PlaceQueue_Schedule(pPQ, PlaceQueue_Visit(&temp));
	}
	printf("second loop ok \n");
	return contains;	
	
}

bool   PlaceQueue_Empty(const PlaceQueue* const pPQ){
	return Queue_Empty(&(pPQ->Q));
}


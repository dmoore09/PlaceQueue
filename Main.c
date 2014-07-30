#include "PlaceQueue.h"
#include <stdio.h>
#include "Place.h"

int main(int argc, char **argv){
	PlaceQueue q;
	PlaceQueue_Init(&q);
	printf("PlaceQueue initialized correctly \n");

	Place p;
	Place d;
	char name[6];
	name[0] = 'a';
	//name[1] = 'b';
	//name[2] = 'c';
	//name[3] = 'd';
	//name[4] = 'e';
  		
	Place_Set(&p, 2110652, "dsoij", "17654", "1");
	Place_Set(&d, 10, "a", "1", "1");
	printf("Place initialized correctly \n");

	Place_Print(&p);

	if (Place_Equals(&p, &d)){
		printf("equals correct \n");
	}
	else{
		printf("equals incorrect\n");
	}

	PlaceQueue_Schedule(&q, &p);
	printf("push crrectly \n");

	if (PlaceQueue_Contains(&q, &d))
	{
		printf("contains correct \n");
	}
	else{
		printf("contains false \n");
	}

	PlaceQueue_Visit(&q);
	printf("pop correctly \n");

	

	 
}

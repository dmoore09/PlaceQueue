#include "Place.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
bool Place_Set(Place* const pPlace, uint32_t FID, char* Name, char* Lat, char* Long){

		pPlace->FID = FID;
		
		//copy name
		pPlace->Name = malloc( sizeof(char) * (MAXNAMELENGTH + 1) );
		for (int i = 0; i < MAXNAMELENGTH; i++){
			pPlace->Name[i] = Name[i];
		}

                pPlace->Latitude = malloc( sizeof(char) * (LATITUDELENGTH + 1 ) );
                for (int i = 0; i < LATITUDELENGTH; i++){
                        pPlace->Latitude[i] = Lat[i];
                }

                pPlace->Longitude = malloc( sizeof(char) * ( LONGITUDELENGTH + 1 ) );
                for (int i = 0; i < LONGITUDELENGTH; i++){
                        pPlace->Longitude[i] = Long[i];
                }

		return true;
	
	
	
		//return false;
	
}

void Place_Print(Place * p){
	printf("%d \n" ,p->FID);
	printf("%c \n", p->Name[0]);
	printf("%c \n", p->Latitude[0]);
	printf("%c \n", p->Longitude[0]);
}

bool  Place_Equals(const Place* const pLeft, const Place* const pRight){
//	int rName = sizeof(pRight->Name) / sizeof(char); 
//	int lName = sizeof(pLeft->Name) / sizeof(char);
//	int rLat = sizeof(pRight->Latitude) / sizeof(char);
//	int lLat = sizeof(pLeft->Latitude) / sizeof(char);
//	int rLon = sizeof(pRight->Longitude) / sizeof(char);
//	int lLon = sizeof(pLeft->Longitude) / sizeof(char);

	if (pLeft->FID == pRight->FID){
	
		for (int i = 0; i < MAXNAMELENGTH; i++)
		{
			if (pRight->Name[i] != pLeft->Name[i])
			{
				return false;
			}
		}
		for (int j = 0; j < LATITUDELENGTH; j++)
		{
			if (pRight->Latitude[j] != pLeft->Latitude[j])
			{
				return false;		
			}
		}
		for (int k = 0; k < LONGITUDELENGTH; k++)
		{
			if (pRight->Longitude[k] != pLeft->Longitude[k])
			{
				return false;
			}
		}
		
		return true;
	}
	return false;
}

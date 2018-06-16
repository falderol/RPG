#include <stdio.h>
#include <stdint.h>

void convertFromCp(uint32_t cp, FILE * storeHere){
	if(cp%10 == 0){ // can convert to sp
		if(cp%100 == 0){ // can convert to gp
			if (cp%1000 == 0){// can convert to pp
				fprintf(storeHere,"%6u pp", cp/1000);
			}
			else{// print in gp
				fprintf(storeHere,"%6u gp", cp/100);
			}
		}
		else{ // print in sp
			fprintf(storeHere,"%6u sp", cp/10);
		}
	}
	else{
		fprintf(storeHere,"%6u cp", cp);
	}
}
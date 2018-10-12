#include "simpleCSVsorter.h"
#include "mergesort.h"
//------------Functions-----------------------//
int commaCounter(char* firstLine, char* catCheck, int bigLineCount){
	int functionCommaCount=0;
	char *token;
	token = strtok(firstLine, ",");
	while(token!=NULL){
		if(strcmp(token,catCheck)==0){
			return functionCommaCount;
		}
		token = strtok(NULL, ",");	
		functionCommaCount++;
	}	
	return -1;
}
int simpleCSVsorter(
//------------Main-----------------------------//
int main(int argc, char** argv){
	DIR *startDir;
	DIR *outputDir;
	char* univCategory;
	if(argc < 3){
		printf("not enough arguments error\n");
		return -1;	
	}
	else{
		//asst0 case
		if(argc == 3){
			if((strcmp(argv[1], "-c")) != 0){
				printf("argument -c error\n");
				return -1;			
			}
			univCategory = argv[2];
			//start directory is current directory
			//must output to current directory		
		}
		//only given category and start directory or target directory
		else if(argc == 5){
			if(((strcmp(argv[1], "-c")) != 0) || ((strcmp(argv[3], "-d")) != 0)){
				printf("argument -c or -d error\n");
				return -1;
			}
			else if((strcmp(argv[3], "-d")) == 0){
				univCategory = argv[2];
				startDir = argv[4];   //make start directory, dont know if correct
			}
			else if((strcmp(argv[3], "-o")) == 0){
				univCategory = argv[2];
				//make argv[4] the output directory 			
			}
	
		}
		// given category, start directory, and target directory
		else if(argc == 7){
			if(((strcmp(argv[1], "-c")) != 0) || ((strcmp(argv[3], "-d")) != 0) || ((strcmp(argv[5], "-o")) != 0)){
				printf("argument -c or -d or -o error\n");
				return -1;
			}
			univCategory = argv[2];
			startDir = argv[4];   //make start directory, dont know if correct
			outputDir = argv[6];   //idk if i'm dumb			
		}
		else{
			printf("number of arguments error\n");
			return -1;		
		}	
	}
}

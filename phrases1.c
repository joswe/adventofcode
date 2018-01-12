/*
 * phrases1.c
 *
 *  Created on: 29 dec. 2017
 *      Author: JW
 */
#include <stdio.h>
#include <string.h>


int compare(char word1[], char word2[]){
	int lengthword1 = strlen(word1);
	int lengthword2 = strlen(word2);
	char temp;


	if(lengthword1 == lengthword2){

		//----------sort word 1------------
		qsort(word1, lengthword1, sizeof(char), strcmp);

		//printf("word1: %s\n", word1);
		//----------sort word 2------------
		qsort(word2, lengthword2, sizeof(char), strcmp);
		//printf("word2: %s\n", word2);

		//-----check if it is equal------------------
		for(int b = 0; b<lengthword1; b++){
			if(word1[b]!=word2[b]){
				return 0;
			}
		}
		//if it didn't exit before it is anagrams
		return 1;
	}
	else
	return 0;
}



int phrases1(void){
	FILE *fp  = fopen("phrases.txt", "r");

	char currentc;
	char array[500][500]; //array[i][j]
	int i = 0;
	int j = 0;
	int numberOfWords = 0;
	int numberOfChars = 0;
	int counter = 0;
	int numberofphrases = 0;
	int result = 0;


	while((currentc = getc(fp)) != EOF){

		if((currentc >= 'a') && (currentc <= 'z')) {		// if it is letter
			array[i][j]= currentc;
			j = j + 1;										// array index j +1
		}

		else if(currentc == ' '){
				array[i][j] = 0;							//if it is a space, write a 0 into array, set index back to 0
				j = 0;
				i = i + 1;									//next row
		}


		else if((currentc == '\n') || (currentc == '\r')) {		//if you come to the end of a line
			//printf("end of line\n");

			numberofphrases = numberofphrases + 1;
			numberOfWords = i+1;

			for(int x =0; x<numberOfWords; x++){
				for(int y = x+1; y<numberOfWords; y++){
					if(compare(array[x], array[y])>0){
						result++;
					}
				}

			}
			printf("Satznr: %d, Anzahl gleicher Worte: %d\n", numberofphrases, result);
			if(result > 0){
					counter = counter+1;
			}
			result = 0;
			i = 0;
			j = 0;
			memset(array, 0, sizeof(char)*500*500);
			numberOfWords = 0;
		}
	//break;
	}

	/*
	printf("%d\n", numberOfWords);
	for(int t=0; t<numberOfWords; t++){
		numberOfChars = strlen(array[j]);
		printf("%d\n", numberOfChars);
		for(int u = 0; u < numberOfChars; u++){
			printf("%c", array[t][u]);
			fflush(stdout);
		}
		printf("\n");
	}
*/
	printf("Anzahl der Sätze: %d\n", numberofphrases);
	printf("Anzahl der ungültigen Sätze: %d\n", counter);
	printf("Anzahl der gültigen Sätze: %d\n", (numberofphrases-counter));
	return 0;
}




int main(void){
	phrases1();
	//char worda[5] = "lhal";
	//char wordb[5] = "xhil";
	//compare(worda, wordb);
	//int result = compare("what", "whain");
	//printf("%d\n", result);
	return 0;

}


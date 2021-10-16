//  Class: Math 230, Meeting time: 10:10 am

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
# define MAXN 10000

void calcSums(int *topog, int *sums, int rows, int cols );

int main()
{
	char lineRead [ MAXN ];
	FILE *inFile = fopen("topo5by6.txt", "r");
	fscanf(inFile, "%s", lineRead);
	int rows = atoi(lineRead);
	fscanf(inFile, "%s", lineRead);
	int cols = atoi(lineRead);
	int *topography = malloc(rows*cols*sizeof(int));
	int i = 0;
	while(!feof(inFile)) {
		fscanf(inFile, "%s", lineRead);
		*(topography+i/rows*cols + i%cols) = atoi(lineRead);
		i++;
	}

int *sumList = malloc(rows*sizeof(int));
for (int i=0; i < rows; i++) {
	*(sumList+i) = 0;
}

int r, c;

calcSums(topography, sumList, rows, cols); 

for(r = 0; r < rows; r++)

//Print results
printf("%8d, %8d \n", r , sumList[r]);
return 0;

}


void calcSums(int *topog, int *sums, int rows, int cols) {

int i , j , x, bounds = 99999999;

int sum,sum2,sum3;

    for( i=0; i<rows; i++){

        x = i;

        for (j=0; j< cols-1; j++){

            //Calculate sums
            sum = abs(*(topog + x*cols +j) - *(topog + x*cols + j+1));

            if(x-1 < 0)

            { 
                sum2 = bounds; 
            }

            else
            {
                sum2 = abs(*(topog + x*cols + j) - *(topog + (x-1)*cols + j+1));
            }

            if(x + 1 >= rows)
            {
                sum3 = bounds;
            }

            else
            {
                sum3 = abs(*(topog + x*cols + j) - *(topog +(x+1)*cols + j+1));
            }

            //if sum equals, go straight
            if (sum <= sum2 && sum<= sum3)
            { 
                *(sums+i) += sum;
            }

            else if (sum2 < sum && sum2 < sum3)
            {
                *(sums+i) += sum2;
                x--;
            }

            else if (sum3 < sum && sum3< sum2)
            {
                *(sums+i) += sum3;

                x++;
            }

            //random number generator that breaks tie
            else if(sum2==sum3){

                *(sums+i) += sum3;

                srand(time(0));

                int randomNumber = rand()%2;

                if(randomNumber == 0){

                x--;

            }

            else{

                x++;

            }
        }
    }
}


}

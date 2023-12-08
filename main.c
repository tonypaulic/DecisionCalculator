#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{

   // define variables
   int decisions_required = 0;
   float oic_ratio = 0;
   int numFT = 0;
   int numPT = 0;
   float FTperformance = 0;
   float PTperformance = 0;

   // ensure proper number of parameters are passed
   if ( argc != 5 ) {
      printf("Number of parameters:%d\n", argc); 
      printf("Required paramters: DecisionsRequired OIC-PTFT-Ratio FTperformance PTperformance\n");
      exit(1);
   }

   // get parameters into varialbes for processing
   decisions_required = atoi(argv[1]);
   oic_ratio = atof(argv[2]);
   FTperformance = atof(argv[3]);
   PTperformance = atof(argv[4]);

   // set starting number at 1
   numFT = 1;
   numPT = numFT * oic_ratio;

   // repeat the calculation until we surpass the required decisions - maintaining ratio of PT to FT
   while ( (numFT * FTperformance) + (numPT * PTperformance) < decisions_required) {
      numFT++;
      numPT = numFT * oic_ratio;
   }

   // output results
   printf("\nDecisions Required = %d\n", decisions_required);
   printf("Number of FT OICs = %d\n", numFT);
   printf("Number of PT OICs = %d\n", numPT);

}
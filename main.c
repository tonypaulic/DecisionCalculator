#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ( int argc, char *argv[] )
{

   // ensure proper number of parameters are passed
   //    1 = number of decisions to model for
   //    2 = FT/PT ratio to use
   //    3 = FT OIC performance
   //    4 = PT OIC performance
   if ( argc != 5 ) {
      printf("Number of parameters:%d\n", argc); 
      printf("Required parameters: DecisionsRequired OIC-PTFT-Ratio FTperformance PTperformance\n");
      exit(1);
   }

   // define variables
   int decisions_required = atoi(argv[1]);   // how many total decisions to model for
   float oic_ratio = atof(argv[2]);          // the ratio of FT to PT OICs
   float FTperformance = atof(argv[3]);      // FT OIC performance value as decisions/year
   float PTperformance = atof(argv[4]);      // PT OIC performance value as decisions/year
   int numFT = 1;                            // number of FT OICs to meet decision requirements
   int numPT = numFT * oic_ratio;            // number of PT OICs required, based on ratio
   int prev_numFT = 0;                       // holder for undershoot value of required number of FT OICs
   int prev_numPT = 0;                       // holder for undershoot value of required number of PT OICs

   // repeat the calculation until we surpass the required decisions - maintaining ratio of PT to FT
   // save the previous value before goign over and use that
   while ( (( numFT * FTperformance ) + ( numPT * PTperformance )) < decisions_required ) {
      prev_numFT = numFT++;
      prev_numPT = numPT;
      numPT = numFT * oic_ratio;
   }

   // output results
   printf("\nRequested Decisions Total = %d\n", decisions_required);
   printf("PT to FT Ratio to be used = %.2f\n", oic_ratio);
   printf("FT Performance Trend Value = %.5f\n", FTperformance);
   printf("PT Performance Trend Value = %.5f\n", PTperformance);
   printf("-----------------------------------------\n");
   printf("Predicted Number of required FT OICs = %d\n", prev_numFT);
   printf("Predicted Number of required PT OICs = %d\n", prev_numPT);

   // success
   return (0);

}
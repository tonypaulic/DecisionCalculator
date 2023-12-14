#include <stdio.h>
#include <stdlib.h>

int main ( int argc, char *argv[] )
{

   // ensure proper number of parameters are passed
   //    1 = number of decisions to model for
   //    2 = PT/FT ratio to use
   if ( argc != 5 ) {
      printf("Required parameters: Decisions_Required PT-FT_Ratio FT-Trend PT-Trend\n\n");
      exit(1);
   }

   // define variables
   int decisions_required = atoi(argv[1]);   // how many total decisions to model for
   float oic_ratio = atof(argv[2]);          // the ratio of FT to PT OICs
   float FTperformance = atof(argv[3]);      // FT OIC performance value as decisions/year via trend
   float PTperformance = atof(argv[4]);      // PT OIC performance value as decisions/year via trend
   int numFT = 1;                            // number of FT OICs to meet decision requirements
   int numPT = numFT * oic_ratio;            // number of PT OICs required, based on ratio
   int prev_numFT = 0;                       // holder for undershoot value of required number of FT OICs
   int prev_numPT = 0;                       // holder for undershoot value of required number of PT OICs

   // repeat the calculation until we surpass the required decisions - maintaining ratio of PT to FT
   // save the previous value before goign over and use that
   while ( (( numFT * FTperformance ) + ( numPT * PTperformance )) < decisions_required ) {
      numFT++;
      numPT = numFT * oic_ratio;
   }

   // output results
   printf("\nRequested Decisions Total = %d\n", decisions_required);
   printf("PT to FT Ratio to be used = %.2f\n", oic_ratio);
   printf("FT Performance Trend Value = %.5f\n", FTperformance);
   printf("PT Performance Trend Value = %.5f\n", PTperformance);
   printf("-----------------------------------------\n");
   printf("Predicted Number of required FT OICs = %d\n", numFT);
   printf("Predicted Number of required PT OICs = %d\n", numPT);

   // success
   return (0);

}
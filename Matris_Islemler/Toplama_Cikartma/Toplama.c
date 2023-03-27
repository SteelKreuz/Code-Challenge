#include <stdio.h>

#define SAT 2
#define SUT 2

void main(){

    int m1[SAT][SUT] = {  5, 3,
                          4, 1
                       };
    int  m2[SAT][SUT] = {
                          1, 4,
                          2, 6
                        };

    int TopMat[SAT][SUT];

    puts("\n\n1. matris:");
    for(int satir = 0; satir < SAT; satir++)
    {
        for(int sutun = 0; sutun < SUT; sutun++)
        {
            /*  _                                           _
             * |  1. satir, 1. sutun  -  1. satir, 2. sutun  |
             * |_ 2. satir, 1. sutun  -  2. satir, 2. sutun _|
             *  
             * [ (0, 0)  (0, 1)]
             * [ (1, 0)  (1, 1)] 2x2                                        
             */
            printf("%4d", m1[satir][sutun]);
        }
        printf("\n"); // Her satir sonunda, bir alt satira gecer.
    }

    puts("\n\n2. matris:");
    for(int satir = 0; satir < SAT; satir++)
    {
        for(int sutun = 0; sutun < SUT; sutun++){
            printf("%4d", m2[satir][sutun]);
        }
        printf("\n");
    }

    puts("\n\nIki matrisin toplami: ");

    for(int satir = 0; satir < SAT; satir++)
    {
        for(int sutun = 0; sutun < SUT; sutun++)
        {
            /*
             * TopMat = [ a  b ] =  [ a = (m1(0,0) + m2(0,0))  b = (m1(0,1) + m2(0,1)) ]
             *          [ c  d ]    [ c = (m1(1,0) + m2(1,0))  b = (m1(1,1) + m2(1,1)) ]
             */
            TopMat[satir][sutun] = m1[satir][sutun] + m2[satir][sutun];
            printf("%4d", TopMat[satir][sutun]);
        }
        printf("\n");
    }
    printf("\n\n");
}
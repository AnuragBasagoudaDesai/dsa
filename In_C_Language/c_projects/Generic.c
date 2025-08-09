#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

enum VariantType { INT , FLOAT , STRING};

typedef struct 
{
    enum VariantType type;
    union 
    {
        int i ;
        float f;
        char* s;
    }value;
    
}variant;


int main()
{

    variant var1;
    var1.type = INT;
    var1.value.i = 10;
    variant var2;
    var2.type = FLOAT;
    var2.value.f = 10.00232232;
    
    printf(" %d ",var1.value.i);
    printf("%.10f",var2.value.f);
}
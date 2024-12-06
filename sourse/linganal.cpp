#include <string.h>
#include <strings.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#include "..\headers\tree_types.h"
#include "..\headers\tree_funck.h"
#include "..\headers\tree_data_base_funk.h"
#include "..\headers\tree_const.h"
#include "..\headers\calculator.h"
#include "..\headers\comporator.h"

const int START_ARR = 16;
char      string[100] = "x = 5y - sin(2);";
int        p = 0;

enum element_types
{
    CONST,
    VARIABLE,
    FUNC,
    OPER, 
    EQUAL,
    END_COMMAND,
    ERROR_EL
};

int element_type(char currEl)
{
    if ( currEl == '+' || currEl == '-' || currEl == '*' ||  
         currEl == '/' || currEl == '^' ||                  ) return OPER;
    if (isalpha(currEl))                                      return VAL_FUNC;
    if (isalnum(currEl))                                      return CONST;
    if (currEl == '=')                                        return EQUAL;
    if (currEl == ';')                                        return END_COMMAND;
}

node_t *startLing(node_t *sartTree)
{
    node_t *nodeArr  D= (node_t *)calloc(START_ARR, sizeof(node_t));
    int     currEL   = 0;
    int     currType = ERROR_EL;

    while (string                          [p] != '\0') 
    {
        while ( isspace(string[p]) ) p++;

        currType = element_type(string[p]);
        nodeArr[currEL].data.nodeType = currType;

        switch (currType)
        {
            case CNST:
                nodeArr[currEL].data.nodeData.cnst = scanDouble(&string, &p);
                break;
            case OPER:
                nodeArr[currEL].data.nodeData.func = scanOperation(&string, &p);
                break;
            case FUNC:
                nodeArr[currEL].data.nodeData.func = scanFunc(&string, &p);
            case VAL:
                nodeArr[currEL].data.nodeData.func = scanFunc(&string, &p);
        }
         
    }
}


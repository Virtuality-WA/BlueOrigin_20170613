/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jose
 *
 * Created on June 16, 2017, 11:12 PM
 */

#include <cstdlib>
#include <cstdio>
#include <cstring>

#include <iostream>
#include <string.h>


using namespace std;

#define INPSTRING "Hello World"
//#define DISPLAY_WIDTH   2
//#define DISPLAY_WIDTH   5
//#define DISPLAY_WIDTH   strlen(INPSTRING)
//#define DISPLAY_WIDTH   strlen(INPSTRING)+1
#define DISPLAY_WIDTH   strlen(INPSTRING)-1



int
createDisplay(char *iStr, int blockSize, char **disp, int *nRows)
{
    int ret = 0;
    
    if ( (0 == blockSize) ||
         (NULL == iStr) ||
         (NULL == nRows)
       )
    {
        ret = -2;
    }
    else
    {
        int iStrSize = strlen(iStr);
        int copySize = iStrSize;
        int memSize = blockSize;

        *nRows = 1;

        if (iStrSize > blockSize)
        {
            copySize = blockSize;
            *nRows += iStrSize - blockSize;
            memSize *= (*nRows);
        }

        if ( NULL == (*disp = (char *)malloc(memSize)))
        {
            ret = -1;
        }
        else
        {
            memset(*disp, ' ', memSize);
            for (int i = 0; (ret==0) && (i<(*nRows)); i++)
            {
                memcpy(&(*disp)[i*blockSize], &iStr[i], copySize);
            }
        }
    }
    
    return ret;
}

/*
 * 
 *
 * 
 */
int main(int argc, char** argv) {

    int width = 0;
    int displayRows = 0;
    char *displayData = NULL;

    cout << "Strng: " << INPSTRING << endl;

    int ret = createDisplay((char *)INPSTRING, DISPLAY_WIDTH, &displayData, &displayRows);

    return 0;
}


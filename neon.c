//NEON
//Copyright 2021 - Daniel Blevins

#include <stdio.h>
#include <peekpoke.h>
#include <string.h>
//#include <stdlib.h>

#include "memmap.h"

#include "ciofunc.h"
//#include "parse.h"
//#include "docfunc.h"
#include "buffers.h"
//#include "processdata.h"
//#include "attribute.h"
#include "debug.h"

#include "browse.h"
//#include "save.h"
#include "load.h"

//char testbuffer[128];
//char status[5];
char* p;


void main()
{
	int s;
	//char test;
	//int big;
	
	POKE(702,64); //Set input to upper case
	(int)ConsoleDL = PEEKW(SDLSTL);
	WriteLine("\n NEON \n Daniel Blevins - MMXXI \n");
	FullPath(DEFAULT_DRIVE);	
	
	while(1)
	{
		
		WriteLine("\n Read - Enter filespec");
		
		
		PageName = "";
		ShowConsole();
		WriteLine("\n>");
		input(0,OutputBuffer,255);
		if(OutputBuffer[0] == 155)	
		{				
			FileSpec = "INDEX.DOC";				
			Browse();
		}
		else
		{
			FileSpec = (char*)OutputBuffer;		
			Browse();
							
			//s = LoadADX(FileSpec);
			//bytetohex(s,Debug,4);
			//WriteLine(Debug);
			
		}

	};
	return;

}


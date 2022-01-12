#include "config.h"

#ifndef DOCDATA_H
#define DOCDATA_H
typedef struct Link Link;
struct Link
{
	Link *NextLink;
	Link *PreviousLink;
	char *DisplayLine;
	char Start;
	char End;	
	char PageName[PAGENAME_LEN]; //Name of page in document to link to
	char FileSpec[1]; 
};

typedef struct Page Page;
struct Page
{
	Page *NextPage;
	char PageStyle[HWR_COUNT];
	char Name[PAGENAME_LEN];
	Link *LinkList;
	char *DisplayList;	
	char *DLInterrupt;
};

typedef struct LoadFile LoadFile;
struct LoadFile
{
	LoadFile *NextFile;
	int StartAddr;
	int Size;
	char FileSpec[1]; //this need to be dynamically sized
};
#endif


extern Page *FirstPage;
//extern Page *CurrentPage;

extern LoadFile* FileCursor;
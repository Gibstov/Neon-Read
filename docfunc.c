#include <atari.h>
#include <peekpoke.h>

#include "ciofunc.h"
#include "docfunc.h"




char recordlen(char* message)
{
	char i=0;
	
	while((i<255) && (message[i] != CH_EOL))
	{
		++i;
	}

	return i;
}

void strcopy(char* source, char* target, char len)
{
	//Copies [len] characters from [source] into [target] and then appends a [0] at the end of target.  target size should be at least [len + 1]
	
	char i;
	for(i=0;i<len;i++)
	{
		target[i] = source[i];
	}
	target[len] = 0;
	
}

char strcompare(char *string1, char *string2)
{
	char Result;
	int i=0;
	char c;
	
	Result = 1;
	
	do
	{
		c=string1[i];			
		if(c != string2[i])
		{
			Result = 0;
		}
		++i;
	}while(c != 0);;
	
	return Result;
	
}

char hextobyte(char* hexString, int* value, char len)
{
	char digit,i;
	char tmp = 0;
	char size = 0; //number of digits of number
	
	*value = 0;
	
	for(i=0; i < len; i++)
	{		
		digit = hexString[i];
		
		if((digit == ' ') || (digit == CH_EOL))
		{
			return size;	//Space/EOL is fine - number of digits found
		}
	

		if(digit > 96)
		{
			digit -= 32;
		}
		
		if((digit < '0') || (((digit > '9') && (digit < 'A'))) || (digit > 'F'))
		{			
			return 0; //Fail
		}
		
		*value = *value * 16;
		
		if((digit > 47) && (digit < 58))
		{ 
			tmp = digit - 48;
		}
		else
		{
			tmp = digit - 55;
		}
	
		*value += tmp;
		++size;		//add one to the number of valid digits
	}
	
	return size;	//number of digits found
}

void bytetohex(int value, char* hexString, char len)
{
	char digit,i;
	char tmp = 0;
	char size = 0; //number of digits of number
	
	hexString[len] = 0;	
	for(i=len; i > 0; --i)
	{		
		digit = value;
		digit = digit % 16;		
		
		if((digit < 0x0A))
		{			
			hexString[i-1] = digit + 48;
		}
		else
		{
			hexString[i-1] = digit + 55;
		}
		
		value = value / 16;	
	}
	
	
	
}

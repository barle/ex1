#include <stdio.h>
#include "InputHandler.h"
#include "HammingUtil.h"
#include "OutputFileHandler.h"

#define WORD_COUNT 8

void decodeBuffer(char *buffer)
{
	int current_position = 0;
	int i;
	char decodedMessage[CODE_DATA_SIZE + 1] = { '/0' };
	
	for (i = 0; i < BITS_IN_BYTE; i++, current_position += CODE_WORD_SIZE)
		hammingDecoder(current_position, buffer); //Correct errors

	//Print decoded buffer to file
	//We are handling everytime 8 words at a time
	for (i = 0; i < WORD_COUNT; i++)
	{
		//Convert 63 bits into 57 bits
		removeCheckBits(buffer, decodedMessage, i);
	}

	decodedMessage[CODE_DATA_SIZE] = '\0';
		
	writeToFile(decodedMessage);	
}
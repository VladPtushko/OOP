#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "Header.h"
#include <iostream>

int main()
{
	Tractrisa t = {1, 1, 1, 1};
	int rc;
	const char* msgs[] = { "0 - exit", "1 - SetLine", "2 - SetHigh", "3 - GetLine", "4 - Gethigh", "5 - GetPoint", "6 - GetLengthOfArc", "7 - GetCurvature", "8 - GetSquare" };
	const int NMsgs = sizeof(msgs) / sizeof(msgs[0]);
	int(*fptr[])(Tractrisa &t) = { NULL, SLine, SHight, GLine, GHight, GPoint, GLength, GCurvature, GSquare};
	while (rc = dialog(msgs, NMsgs))
	{
		fptr[rc](t);
	}

		printf("That's all. Bye!\n");
	_CrtDumpMemoryLeaks();
}
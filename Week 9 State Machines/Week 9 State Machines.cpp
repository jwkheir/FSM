// Week 9 State Machines.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Bulb.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Bulb * bulb = new Bulb();
	bulb->Update();
	bulb->voltage = 0;
	bulb->Update();
	bulb->voltage = 240;
	bulb->Update();
	bulb->voltage = 500;
	bulb->Update();
	system("pause");

	return 0;
}


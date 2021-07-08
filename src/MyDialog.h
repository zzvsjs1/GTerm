#pragma once
#ifndef MY_DIALOG
#define MY_DIALOG

#include <QPair>

#include "SetXYDialog.h"

class MyDialog
{
public:
	static QPair<int, int> getXY();

	enum GetXYFlag
	{
		CANCEL = -2,
		ERROR,
		SUCCESS
	};


};
#endif // !MY_DIALOG

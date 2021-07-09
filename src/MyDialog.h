#pragma once
#ifndef MY_DIALOG
#define MY_DIALOG

#include <QPair>
#include <tuple>

#include "SetXYDialog.h"
#include "GTRGBChooser.h"

class MyDialog
{
public:
	static QPair<int, int> getXY();
	
	static std::tuple<int, int, int> getRGB();

	enum Status
	{
		CANCEL = -2,
		ERROR,
		SUCCESS
	};

	enum ColorPos
	{
		R,
		G,
		B
	};

};
#endif // !MY_DIALOG

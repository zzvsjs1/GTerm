#pragma once
#ifndef MY_DIALOG
#define MY_DIALOG

#include <QPair>
#include <tuple>

#include <optional>

#include "SetXYDialog.h"
#include "GTRGBChooser.h"

class MyDialog
{
private:

	MyDialog() noexcept { };

public:

	[[nodiscard]] static ::std::optional<QPair<int, int>> getXY();
	
	[[nodiscard]] static ::std::optional < std::tuple<int, int, int>> getRGB();

	enum class Status
	{
		CANCEL,
		ERROR,
		SUCCESS
	};

	enum class ColorPos
	{
		R,
		G,
		B
	};
};
#endif // !MY_DIALOG

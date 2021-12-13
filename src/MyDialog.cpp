#include "MyDialog.h"

QPair<int, int> MyDialog::getXY()
{
	const auto dialog = ::std::make_unique<SetXYDialog>();
	const int ret = dialog->exec();
	if (ret)
	{
		return dialog->getXY();
	}

	if (ret == ERROR)
	{
		return {ERROR, ERROR};
	}

	return {CANCEL, CANCEL};
}

std::tuple<int, int, int> MyDialog::getRGB()
{
	const auto dialog = ::std::make_unique<GTRGBChooser>();
	const auto ret = dialog->exec();
	if (ret)
	{
		return dialog->getRGB();
	}

	if (ret == ERROR)
	{
		return {ERROR, ERROR, ERROR};
	}

	return {CANCEL, CANCEL, CANCEL};
}

#include "MyDialog.h"

QPair<int, int> MyDialog::getXY()
{
	std::unique_ptr<SetXYDialog> dialog(new SetXYDialog);
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
	std::unique_ptr<GTRGBChooser> dialog(new GTRGBChooser);
	const int ret = dialog->exec();
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

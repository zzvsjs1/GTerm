#include "MyDialog.h"

QPair<int, int> MyDialog::getXY()
{
	std::unique_ptr<SetXYDialog> dialog(new SetXYDialog);
	const int ret = dialog->exec();
	if (ret)
	{
		return dialog->getXY();
	}

	if (ret == -1)
	{
		return { -1, -1 };
	}

	return { -2, -2 };
}

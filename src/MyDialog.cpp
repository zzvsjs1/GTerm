#include "MyDialog.h"

QPair<int, int> MyDialog::getXY()
{
	std::unique_ptr<SetXYDialog> dialog(new SetXYDialog);
	const int ret = dialog->exec();
	if (ret)
	{
		return dialog->getXY();
	}

	if (ret == Status::ERROR)
	{
		return { Status::ERROR, Status::ERROR };
	}

	return { Status::CANCEL, Status::CANCEL };
}

std::tuple<int, int, int> MyDialog::getRGB()
{
	std::unique_ptr<GTRGBChooser> dialog(new GTRGBChooser);
	const int ret = dialog->exec();
	if (ret)
	{
		return dialog->getRGB();
	}

	if (ret == Status::ERROR)
	{
		return { Status::ERROR, Status::ERROR, Status::ERROR };
	}

	return { Status::CANCEL, Status::CANCEL, Status::CANCEL };
}

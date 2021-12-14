#include "MyDialog.h"

::std::optional<QPair<int, int>> MyDialog::getXY()
{
	const auto dialog = ::std::make_unique<SetXYDialog>();
	if (const int ret = dialog->exec(); ret > 0)
	{
		return dialog->getXY();
	}

	return ::std::nullopt;
}

::std::optional<std::tuple<int, int, int>> MyDialog::getRGB()
{
	const auto dialog = ::std::make_unique<GTRGBChooser>();
	if (const auto ret = dialog->exec(); ret > 0)
	{
		return dialog->getRGB();
	}

	return ::std::nullopt;
}

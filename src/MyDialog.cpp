#include "MyDialog.h"

::std::optional<QPair<int, int>> MyDialog::getXY()
{
	return getXY(0, 0);
}

::std::optional<QPair<int, int>> MyDialog::getXY(const int x, const int y)
{
	const auto dialog = ::std::make_unique<SetXYDialog>(Q_NULLPTR, x, y);
	if (const int ret = dialog->exec(); ret > 0)
	{
		return dialog->getXY();
	}

	return ::std::nullopt;
}

::std::optional<std::tuple<int, int, int>> MyDialog::getRGB()
{
	return getRGB(0, 0, 0);
}

::std::optional<std::tuple<int, int, int>> MyDialog::getRGB(const int r, const int g, const int b)
{
	const auto dialog = ::std::make_unique<GTRGBChooser>(Q_NULLPTR, r, g, b);
	if (const auto ret = dialog->exec(); ret > 0)
	{
		return dialog->getRGB();
	}

	return ::std::nullopt;
}

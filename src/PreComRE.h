#pragma once
#ifndef MYRE
#define MYRE

#include <QRegularExpression>

namespace GTRE
{
	const QRegularExpression findSlasht(QString("\\\\t"));
	const QRegularExpression findSlashn("\\\\n");
}

namespace GTSPE
{
	const QString tab("    ");
	const QChar dslasht('\\t');
	const QChar newline(u'\n');
	const QChar dslashn('\\n');
	const QChar slash(u'\\');
	const QChar n(u'n');
	const QChar t(u't');
}

#endif // !MYRE

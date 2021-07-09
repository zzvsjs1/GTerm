#pragma once
#ifndef MYRE
#define MYRE

#include <QRegularExpression>

namespace GTRE
{
	static const QRegularExpression findSlasht(QString("\\\\t"));
	static const QRegularExpression findSlashn(QString("\\\\n"));
}

namespace GTSPE
{
	static const QChar dslasht('\\t');
	static const QChar newline(u'\n');
	static const QChar dslashn('\\n');
	static const QChar slash(u'\\');
	static const QChar n(u'n');
	static const QChar t(u't');
	static const QChar space(u' ');
}

#endif // !MYRE

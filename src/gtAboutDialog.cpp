// Copyright 2021 GTerm Project
// Licensed under GPL-3.0 License

#include <QLabel>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QtGlobal>
#include <QStringBuilder>

#include "GTAboutDialog.h"

#define STR_HELPER(x) #x
#define NUM_TO_STR(x) STR_HELPER(x)

GTAboutDialog::GTAboutDialog(QWidget* parent)
	: QDialog(parent)
{
    setUp();
}

void GTAboutDialog::setUp()
{
    setWindowTitle(QStringLiteral("About GTerm"));
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    const QString text =
        QStringLiteral(R"(
<p style='font-size:38pt; font-weight:400;'>GTerm</p>

<p style='font-size: small;'>
%QT_VERSION%
</p>

<p>
Check for update: <a href='https://jupiter.csit.rmit.edu.au/~e58140/GTerm/'>https://jupiter.csit.rmit.edu.au/~e58140/GTerm/</a>
</p>

<p>
%ABOUT_GTERM%
</p>

<p>
If you need an older version of GTerm, please <a href='mailto: gayan.wijesinghe@rmit.edu.au'>contact Gayan</a> .
</p>
)").replace(QStringLiteral("%QT_VERSION%"),
    tr("Using Qt %1. Build by %2 on %3").arg(QStringLiteral(QT_VERSION_STR),
#if defined(__clang__)
        tr(" Build By Clang on: ")
#elif defined(__GNUC__) || defined(__GNUG__)
        tr(" Build By GCC on: ")
#elif defined(_MSC_VER)        
        tr(" MSVC ") % QStringLiteral(NUM_TO_STR(_MSC_VER))
#endif
        , QStringLiteral(__DATE__) % QStringLiteral(" ") % QStringLiteral(__TIME__)))
        .replace(QStringLiteral("%ABOUT_GTERM%"),
            QStringLiteral("GTerm allows you to create a GUI application using ::std::cout-like statements."));

    // TODO: Memory leak.

    const auto textLabel = new QLabel(text);
    textLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);
    textLabel->setOpenExternalLinks(true);

    const auto gtCopyright = new QLabel(QStringLiteral("<small>%1</small>").arg(
        QStringLiteral("\u00A9 2021-2022. Gayan Wijesinghe")));

    const auto gtLogo = new QLabel();
    gtLogo->setPixmap(QPixmap(QStringLiteral(":/gtres/resources/logo/gw.png")));
    gtLogo->setContentsMargins(30, 0, 30, 0);

    const auto gtMainLayout = new QVBoxLayout;
    const auto gtHLayout = new QHBoxLayout;

    setLayout(gtMainLayout);
    gtMainLayout->addLayout(gtHLayout);
    gtMainLayout->addWidget(gtCopyright);
    gtCopyright->setAlignment(Qt::AlignCenter);
    gtCopyright->setContentsMargins(0, 15, 0, 0);

    gtHLayout->setAlignment(Qt::AlignLeft);
    gtHLayout->addWidget(gtLogo);
    gtHLayout->addWidget(textLabel);
}

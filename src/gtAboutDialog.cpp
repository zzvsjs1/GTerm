#include "gtAboutDialog.h"

#include <QLabel>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QtGlobal>

GtAboutDialog::GtAboutDialog(QWidget* parent) : QDialog(parent)
{
	setWindowTitle(tr("About GTerm"));
	setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    const QString text =
        QStringLiteral(R"(
<p style='font-size:38pt; font-weight:400;'>GTerm</p>

<p style='font-size: small;'>
Qt_Version: 6.02
</p>

<p>
Check for update: <a href='https://jupiter.csit.rmit.edu.au/~e58140/GTerm/'>https://jupiter.csit.rmit.edu.au/~e58140/GTerm/</a>
</p>

<p>
If you need an older version of GTerm, please contact Gayan.
</p>

<p>
<a href='mailto: gayan.wijesinghe@rmit.edu.au'>Send Email</a>
</p>

)");

    QLabel* textLabel = new QLabel(text);
    textLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);
    textLabel->setOpenExternalLinks(true);

    QLabel* gtCopyright = new QLabel(QStringLiteral("<small>%1</small>").arg(tr("\u00A9 2020-2021. Gayan Wijesinghe")));

    QLabel* gtLogo = new QLabel();
    //gtLogo->setPixmap(QPixmap(QString(".\\resource\\logo\\logo.png")));
    gtLogo->setContentsMargins(30, 0, 30, 0);

    QVBoxLayout* gtMainLayout = new QVBoxLayout;
    QHBoxLayout* gtHLayout = new QHBoxLayout;

    setLayout(gtMainLayout);
    gtMainLayout->addLayout(gtHLayout);
    gtMainLayout->addWidget(gtCopyright);
    gtCopyright->setAlignment(Qt::AlignCenter);
    gtCopyright->setContentsMargins(0, 15, 0, 0);

    gtHLayout->setAlignment(Qt::AlignLeft);
    gtHLayout->addWidget(gtLogo);
    gtHLayout->addWidget(textLabel);
}
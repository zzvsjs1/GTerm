# GTerm

## Class GTerm

java.lang.Object  
>java.awt.Component  
>>java.awt.Container  
>>>java.awt.Window  
>>>>java.awt.Frame  
>>>>>GTerm  

# public final class GTerm

### This Version:

2021.03.01
GTerm allows you to create a GUI application using System.out.println-like statements.

Version History:

2020.02.29: Original version

2020.03.06: Added \n support for print and println. Added clear.

2020.03.10: Added textField, textArea, setTextInField, getTextInField, addButton support, repaint in clear.

2020.03.15: Does not exit on close; added close, addPasswordField, addList, addElementToList, removeElementFromList, getSelectedElementFromList

2020.03.21: Fixed non-removal in removeElementFromList, addList and addTextArea now has auto-scrollbars

2020.06.01: Lists of String type

2020.07.06: getElementFromList returns value of consistent type. Added getSelectedElementIndexFromList, setFilePath

2020.08.25: Lists replaced with tables (\t formats data in to columns. Supports optional header row.). Added addTable, addRowToTable, clearRowsOfTable, getSelectedRowIndexFromTable, getSelectedRowFromTable. Exceptions thrown from invoked supplied methods are more readable. Added addImageIcon(BufferedImage), showErrorDialog(String), showWarningDialog(String). Title of showMessageDialog(String) says "information" instead of "message" (to match icon). addPasswordField, addTextArea and addTextField now return the text field index.

2021.03.01: Images added in a terminal fashion. addTable uses background set by setBackgroundColor.

### Author:
Gayan Wijesinghe

# Q&A

### Q: How do I install GTerm?

A: Refer to Lecture 1 recording from the 13:59 point on the clock in the shared screen:

https://rmit.instructure.com/courses/67194/discussion_topics/802227

 

###  Q: What are GTerm methods and how do I use the documentation?

A: More examples of how to use GTerm methods and documentation have been shown in Tutorial 1 recording (same link as above). More examples will be given over the coming weeks also.

 

###  Q: What's this forum?

A: Use this forum for all questions relating to GTerm

### Klemens Chung

Hello,

I was wondering if this command:" zt.addButton(); " to be explained how it works?

### Gayan Wijesinghe

Hi Klemens,

Please note that you must not use this for A1 because it requires the creation of methods. For your future understanding, here's a simple program that does the job.


```C++
#include <iostream>
#include <QPushButton>
#include <QWidget>

Class MyClass :: public QWidget
{
  Q_OBJECT;
public:
  MyClass(QWidget* parent = nullptr);
  ~MyClass();
  void doSomething();

private:
  QPushButton* gtButton;
  QWidget* gtCentralWidget;
}

MyClass::MyClass()
{
  gtCentralWidget = new QWidget(this);
  gtCentralWidget->resize(QSize(1024, 768));
  gtCentralWidget->setMaximumSize(QSize(1024, 768));
  
  gtButton = new QPushButton(gtCentralWidget);
  connect(gtButton, &QPushButton::clicked, this, qOverload<>(&MyClass::doSomething));
}

MyClass::~MyClass()
{
  delete gtButton;
}

void MyClass::doSomething()
{
  std::cout << "Hello GTerm, you clicked me." << std::endl;
}
```

Remember to come to pracs and I can give you more help on such features.

Regards,

Gayan

# C GTerm, C++ GTerm, QT GTerm

public QObject, public QPaintDevice
>public QWidget
>>public QMainWindow
>>>GtMain::GtMain

# GtMain::GtMain(QWidget* parent = nullptr): QMainWindow(parent)

### This Version:

2021.03.28
GTerm allows you to create a GUI application using std::cout-like statements.

Version History:

2021.03.25: Original version

2021.03.28: Sub GTerm window replace function in main GTerm window. Add GTerm gt = new GTerm(1024, 768); function.

2021.04.03: QResource replace hard coding path in icon and image. Add addImageIcon function. Fix QFon issue.

### Author:
Gayan Wijesinghe

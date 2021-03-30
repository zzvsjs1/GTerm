#pragma once

#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QLineEdit>
#include <QGroupBox>
#include <QTableView>

class GtSubWindow : public QWidget
{
public:
	GtSubWindow(QWidget* parent = nullptr);
	~GtSubWindow();
    void getInputString();
    void showMessageDialog();
    void showErrorDialog();
    void addImageIcon();
    void addTable();
    void addRowToTable();
    void getSelectRowFromTable();
    void getRowIndexFromSelectTable();
    void addButton();
    void print();
    void println();
    void setFont();
    void setFontSize();
    void setBackgroundColor();
    void setXY();
    void setFilePath();
    void clear();
    void addTextArea();
    void addTextField();
    void clearRowsOfTable();
    void getColorFromDialog();
    void getPasswordFromDialog();
    void getTextFromEntry();
    void setTextInEntry();
    void showWarningDialog();
    QString getFilePath();

private:
    void retranslateUi();
    inline void setupUi();
	QTableView* gtTable;
	QFont* gtFont;
	QWidget* gtCentralWidget;
	QGroupBox* gtGroupBox;
};
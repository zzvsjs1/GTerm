#pragma once

#include <QVector>
#include <QWidget>
#include <QMainWindow>
#include <QLabel>
#include <QTextEdit>
#include <QLineEdit>
#include <QGroupBox>
#include <QTableView>
#include <QMessageBox>
#include <QInputDialog>
#include <QDesktopServices>
#include <QUrl>
#include <QFileDialog>
#include <QPalette>
#include <QPixmap>
#include <QStandardPaths>
#include <QGraphicsView>
#include <QImage>
#include <QGuiApplication>
#include <QLayout>

QT_BEGIN_NAMESPACE
class QAction;
class QLabel;
class QMenu;
class QScrollArea;
class QScrollBar;
QT_END_NAMESPACE

class GtSubWindow : public QMainWindow
{
    Q_OBJECT;

public:
    GtSubWindow(QWidget* parent = nullptr);
	~GtSubWindow();
    void showHelp();
    void getInputString();
    void showMessageDialog(QString& inputString);
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
    int x;
    int y;
    void retranslateUi();
    inline void setupUi();
    
    QLabel* gtLabel;
    QScrollArea* gtScrollArea;
	QTableView* gtTable1;
	QFont* gtFont;
	QGroupBox* gtGroupBox;
    QVector<QTableView*> gtTable;
    
    void showDialog();
};
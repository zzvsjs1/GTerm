#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QMainWindow>
#include <QImage>

QT_BEGIN_NAMESPACE
class QAction;
class QLabel;
class QMenu;
class QScrollArea;
class QScrollBar;
QT_END_NAMESPACE

class GtImageViewer : public QMainWindow
{
    Q_OBJECT

public:
    GtImageViewer(QWidget* parent = nullptr);
    bool loadFile(const QString&);

private slots:
    void open();
    void saveAs();
    void copy();
    void paste();
    void zoomIn();
    void zoomOut();
    void normalSize();
    void fitToWindow();
    void about();

private:
    void createActions();
    void updateActions();
    bool saveFile(const QString& fileName);
    void setImage(const QImage& newImage);
    void scaleImage(double factor);
    static void adjustScrollBar(QScrollBar* scrollBar, double factor);

    QImage image;
    QLabel* imageLabel;
    QScrollArea* scrollArea;
    double scaleFactor = 1;

    QAction* saveAsAct;
    QAction* printAct;
    QAction* copyAct;
    QAction* zoomInAct;
    QAction* zoomOutAct;
    QAction* normalSizeAct;
    QAction* fitToWindowAct;
};
#endif

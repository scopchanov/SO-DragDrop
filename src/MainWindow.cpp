#include "MainWindow.h"
#include "List.h"
#include "OpenGlWidget.h"
#include <QGridLayout>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent)
{
	auto *widget = new QWidget(this);
	auto *layoutMain = new QHBoxLayout(widget);
	auto *list = new List(this);
	auto *viewTopLeft = new OpenGlWidget(this);
	auto *viewTopRight = new OpenGlWidget(this);
	auto *viewBottomLeft = new OpenGlWidget(this);
	auto *viewBottomRight = new OpenGlWidget(this);
	auto *layoutGrid = new QGridLayout();

	list->addItem(new QListWidgetItem(QIcon(":/pix/images/error.png"), tr("Item 1")));
	list->addItem(new QListWidgetItem(QIcon(":/pix/images/warning.png"), tr("Item 2")));
	list->addItem(new QListWidgetItem(QIcon(":/pix/images/information.png"), tr("Item 3")));
	list->setViewMode(QListWidget::IconMode);
	list->setIconSize(QSize(64, 64));
	list->setGridSize(QSize(64, 64));
	list->setMaximumWidth(100);

	layoutGrid->addWidget(viewTopLeft, 0, 0);
	layoutGrid->addWidget(viewTopRight, 0, 1);
	layoutGrid->addWidget(viewBottomLeft, 1, 0);
	layoutGrid->addWidget(viewBottomRight, 1, 1);

	layoutMain->addWidget(list);
	layoutMain->addLayout(layoutGrid);

	setCentralWidget(widget);
	resize(640, 480);
}

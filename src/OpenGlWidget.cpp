#include "OpenGlWidget.h"
#include <QDragEnterEvent>
#include <QMimeData>
#include <QPainter>
#include <QIcon>

OpenGlWidget::OpenGlWidget(QWidget *parent) :
	QOpenGLWidget(parent)
{
	setAcceptDrops(true);
}

void OpenGlWidget::dragEnterEvent(QDragEnterEvent *event)
{
	QOpenGLWidget::dragEnterEvent(event);
	event->accept();
}

void OpenGlWidget::dropEvent(QDropEvent *event)
{
	const QMimeData *mimeData = event->mimeData();

	if (mimeData->hasFormat("application/x-qabstractitemmodeldatalist")) {
		QByteArray encoded = mimeData->data("application/x-qabstractitemmodeldatalist");
		QDataStream stream(&encoded, QIODevice::ReadOnly);

		while (!stream.atEnd()) {
			int row;
			int col;
			QMap<int,  QVariant> roleDataMap;


			stream >> row >> col >> roleDataMap;

			// QString name = roleDataMap.value(0).toString();
			QIcon icon = roleDataMap.value(1).value<QIcon>();

			m_pixmap = icon.pixmap(icon.availableSizes().first());

			update();
		}
	} else {
		event->ignore();
	}
}

void OpenGlWidget::paintGL()
{
	QPainter painter(this);

	painter.drawPixmap(0, 0, m_pixmap);
}

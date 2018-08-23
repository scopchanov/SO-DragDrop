#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QOpenGLWidget>

class OpenGlWidget : public QOpenGLWidget
{
	Q_OBJECT
public:
	explicit OpenGlWidget(QWidget *parent = nullptr);

protected:
	void dropEvent(QDropEvent *event) override;
	void dragEnterEvent(QDragEnterEvent *event) override;
	void paintGL() override;

private:
	QPixmap m_pixmap;
};

#endif // OPENGLWIDGET_H

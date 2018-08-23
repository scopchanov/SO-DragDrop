#ifndef LIST_H
#define LIST_H

#include <QListWidget>

class List : public QListWidget
{
	Q_OBJECT
public:
	explicit List(QWidget *parent = nullptr);

protected:
	void dropEvent(QDropEvent *) override;
};

#endif // LIST_H

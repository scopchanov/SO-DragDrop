#include "List.h"

List::List(QWidget *parent) :
	QListWidget(parent)
{
	setAcceptDrops(false);
}

void List::dropEvent(QDropEvent * /*event*/)
{

}

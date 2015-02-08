#include "AddNewCodePageViewModel.h"

#include "CodeViewModel.h"

AddNewCodePageViewModel::AddNewCodePageViewModel(QObject *parent) :
	QObject(parent)
{
	m_current = new CodeViewModel();
}

QObject *AddNewCodePageViewModel::current() const
{
	return m_current;
}

void AddNewCodePageViewModel::setCurrent(QObject *arg)
{
	if (m_current != arg)
	{
		m_current = arg;
		emit currentChanged(arg);
	}
}

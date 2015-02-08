#include "EditCodePageViewModel.h"


EditCodePageViewModel::EditCodePageViewModel(QObject *parent) :
	QObject(parent)
{
	m_new = 0;
}

QObject *EditCodePageViewModel::current() const
{
	return m_current;
}

QObject *EditCodePageViewModel::clone() const
{
	return m_new;
}

void EditCodePageViewModel::setCurrent(QObject *arg)
{
	if (m_current != arg) {
		m_current = (CodeViewModel*)arg;
		m_new = m_current->clone();
		emit currentChanged(arg);
	}
}

void EditCodePageViewModel::save()
{
	m_current->update(m_new);
}

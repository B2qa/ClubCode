#ifndef EDITCODEPAGEVIEWMODEL_H
#define EDITCODEPAGEVIEWMODEL_H

#include <QObject>

#include "CodeViewModel.h"

class EditCodePageViewModel : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QObject* current READ current WRITE setCurrent NOTIFY currentChanged)
	Q_PROPERTY(QObject* clone READ clone NOTIFY cloneChanged)

	public:
		explicit EditCodePageViewModel(QObject *parent = 0);

		QObject* current() const;
		QObject* clone() const;

	signals:
		void currentChanged(QObject* arg);

		void cloneChanged(QObject* arg);

	public slots:
		void setCurrent(QObject* arg);
		void save();

	private:
		CodeViewModel* m_new;
		CodeViewModel* m_current;
};

#endif // EDITCODEPAGEVIEWMODEL_H

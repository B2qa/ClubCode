#ifndef ADDNEWCODEPAGEVIEWMODEL_H
#define ADDNEWCODEPAGEVIEWMODEL_H

#include <QObject>

class AddNewCodePageViewModel : public QObject
{
		Q_OBJECT

		Q_PROPERTY(QObject* current READ current WRITE setCurrent NOTIFY currentChanged)

	public:
		explicit AddNewCodePageViewModel(QObject *parent = 0);

		QObject* current() const;

	signals:
		void currentChanged(QObject* arg);

	private:
		QObject* m_current;

	public slots:
		void setCurrent(QObject* arg);
};

#endif // ADDNEWCODEPAGEVIEWMODEL_H

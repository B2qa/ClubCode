#ifndef MAINVIEWMODEL_H
#define MAINVIEWMODEL_H

#include <QObject>

#include "CodeViewModel.h"


class MainViewModel : public QObject
{
		Q_OBJECT

		Q_PROPERTY(QList<QObject*> codes READ codes WRITE setCodes NOTIFY codesChanged)

	public:
		MainViewModel();

		QList<QObject*> codes() const;

	public slots:
		void setCodes(QList<QObject*> arg);
		void createCode(CodeViewModel* code);
		void removeCode(CodeViewModel* code);
		void load();
		void save();

	signals:
		void codesChanged(QList<QObject*> arg);

	private:
		QList<QObject*> m_codes;
};

#endif // MAINVIEWMODEL_H

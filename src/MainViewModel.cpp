#include "CodeViewModel.h"
#include "MainViewModel.h"

#include <QFile>
#include <QtQml>

MainViewModel::MainViewModel()
{
	load();
}

QList<QObject *> MainViewModel::codes() const
{
	return m_codes;
}

void MainViewModel::setCodes(QList<QObject *> arg)
{
	if (m_codes != arg) {
		m_codes = arg;
		emit codesChanged(arg);
	}
}

void MainViewModel::createCode(CodeViewModel* code)
{
	m_codes << code;

	emit codesChanged(m_codes);

	save();
}

void MainViewModel::removeCode(CodeViewModel *code)
{
	m_codes.removeAll(code);

	emit codesChanged(m_codes);

	save();
}

void MainViewModel::load()
{
        QFile file("nemo/home/.local/share/harbour-clubcode/database");

	if (file.open(QIODevice::ReadOnly))
	{
		QDataStream stream(&file);

		while (!stream.atEnd())
		{
			CodeViewModel* item = new CodeViewModel();
			stream >> *item;

			m_codes << item;
		}
	}
}

void MainViewModel::save()
{
        QDir::current().mkpath("nemo/home/.local/share/harbour-clubcode");

        QFile file("nemo/home/.local/share/harbour-clubcode/database");

	if (file.open(QIODevice::WriteOnly))
	{
		QDataStream stream(&file);

		foreach (QObject*item, m_codes)
		{
			stream << *(CodeViewModel*)item;
		}
	}
}

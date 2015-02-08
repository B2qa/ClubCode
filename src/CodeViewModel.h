#ifndef CODEVIEWMODEL_H
#define CODEVIEWMODEL_H

#define CODE128_B_START 104
#define CODE128_STOP 106

#include <QObject>

class CodeViewModel : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
	Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)
	Q_PROPERTY(QString code READ code WRITE setCode NOTIFY codeChanged)

	friend QDataStream &operator <<(QDataStream &stream, const CodeViewModel &code);
	friend QDataStream &operator >>(QDataStream &stream, CodeViewModel &code);

	public:
		CodeViewModel();

		QString name() const;
		QString description() const;
		QString code() const;

		void update(CodeViewModel* other);

		CodeViewModel* clone();

	public slots:
		void setName(QString arg);
		void setDescription(QString arg);
		void setCode(QString arg);
		QString generateCode(QString code);

	private:
		QString m_name;
		QString m_description;
		QString m_code;

		int codeToChar(int code);
		int charToCode(int ch);
		int calculateCheckCharacter(QString code);
	signals:
		void nameChanged(QString arg);
		void descriptionChanged(QString arg);
		void codeChanged(QString arg);
};

#endif // CODEVIEWMODEL_H

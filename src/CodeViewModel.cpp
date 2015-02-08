#include "CodeViewModel.h"

CodeViewModel::CodeViewModel()
{
}

QString CodeViewModel::name() const
{
	return m_name;
}

QString CodeViewModel::description() const
{
	return m_description;
}

QString CodeViewModel::code() const
{
	return m_code;
}

void CodeViewModel::update(CodeViewModel *other)
{
	m_name = other->name();
	m_description = other->description();
	m_code = other->code();

	emit nameChanged(m_name);
	emit descriptionChanged(m_description);
	emit codeChanged(m_code);
}

CodeViewModel *CodeViewModel::clone()
{
	CodeViewModel* clone = new CodeViewModel();
	clone->setName(m_name);
	clone->setDescription(m_description);
	clone->setCode(m_code);

	return clone;
}

void CodeViewModel::setName(QString arg)
{
	if (m_name != arg) {
		m_name = arg;
		emit nameChanged(arg);
	}
}

void CodeViewModel::setDescription(QString arg)
{
	if (m_description != arg) {
		m_description = arg;
		emit descriptionChanged(arg);
	}
}

void CodeViewModel::setCode(QString arg)
{
	if (m_code != arg) {
		m_code = arg;
		emit codeChanged(arg);
	}
}

QString CodeViewModel::generateCode(QString code)
{
	QString encoded;

	encoded.prepend(QChar(codeToChar(CODE128_B_START))); //Start set with B Code 104
	encoded.append(code);
	encoded.append(QChar(calculateCheckCharacter(code)));
	encoded.append(QChar(codeToChar(CODE128_STOP))); //End set with Stop Code 106

	return encoded;
}

int CodeViewModel::codeToChar(int code)
{
	return code + 105;
}

int CodeViewModel::charToCode(int ch)
{
	return ch - 32;
}

int CodeViewModel::calculateCheckCharacter(QString code)
{
	QByteArray encapBarcode(code.toUtf8()); //Convert code to utf8

	//Calculate check character
	long long sum = CODE128_B_START; //The sum starts with the B Code start character value
	int weight = 1; //Initial weight is 1

	foreach(char ch, encapBarcode) {
		int code_char = charToCode((int)ch); //Calculate character code
		sum += code_char*weight; //add weighted code to sum
		weight++; //increment weight
	}

	int remain = sum%103; //The check character is the modulo 103 of the sum

	//Calculate the font integer from the code integer
	if(remain >= 95)
		remain += 105;
	else
		remain += 32;

	return remain;
}

QDataStream &operator <<(QDataStream &stream, const CodeViewModel &code)
{
	stream << code.m_name;
	stream << code.m_description;
	stream << code.m_code;

	return stream;
}

QDataStream &operator >>(QDataStream &stream, CodeViewModel &code)
{
	stream >> code.m_name;
	stream >> code.m_description;
	stream >> code.m_code;

	return stream;
}

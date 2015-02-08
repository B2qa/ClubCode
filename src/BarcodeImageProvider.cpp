#include <QPainter>
#include <QImage>

#include "BarcodeImageProvider.h"

BarcodeImageProvider::BarcodeImageProvider()
	: QQuickImageProvider(QQuickImageProvider::Image)
{
}



QImage BarcodeImageProvider::requestImage(const QString &id, QSize *size, const QSize &requestedSize)
{
	QImage image(requestedSize, QImage::Format_ARGB32);
	QPainter painter(&image);
	QFont barcodefont = QFont("Code 128", 46, QFont::Normal);
	barcodefont.setLetterSpacing(QFont::AbsoluteSpacing,0.0);
	painter.setFont(barcodefont);

	QString arr = generateCode(id);
	QRect barcodeRect(0, 0, image.width(), image.height());
	painter.drawText(barcodeRect, Qt::AlignCenter, arr);

	return image;
}

QString BarcodeImageProvider::generateCode(QString code)
{
	QString encoded;

	encoded.prepend(QChar(codeToChar(CODE128_B_START))); //Start set with B Code 104
	encoded.append(code);
	encoded.append(QChar(calculateCheckCharacter(code)));
	encoded.append(QChar(codeToChar(CODE128_STOP))); //End set with Stop Code 106

	return encoded;
}

int BarcodeImageProvider::codeToChar(int code)
{
	return code + 105;
}

int BarcodeImageProvider::charToCode(int ch)
{
	return ch - 32;
}

int BarcodeImageProvider::calculateCheckCharacter(QString code)
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

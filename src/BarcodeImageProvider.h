#ifndef BARCODEIMAGEPROVIDER_H
#define BARCODEIMAGEPROVIDER_H

#include <QQuickImageProvider>
#define CODE128_B_START 104
#define CODE128_STOP 106


class BarcodeImageProvider : public QQuickImageProvider
{
	public:
		BarcodeImageProvider();

		// QQuickImageProvider interface
	public:
		QImage requestImage(const QString &id, QSize *size, const QSize &requestedSize);
	private:
		QString generateCode(QString code);
		int codeToChar(int code);
		int charToCode(int ch);
		int calculateCheckCharacter(QString code);
};

#endif // BARCODEIMAGEPROVIDER_H

import QtQuick 2.0
import Sailfish.Silica 1.0

Page
{
	property variant current

	id: page

	PageHeader
	{
		title: current.name
		id: header
	}

	Rectangle
	{
		color: "white"
		anchors.left: parent.left
		anchors.right: parent.right
		anchors.bottom: parent.bottom
		anchors.top: header.bottom
		id: background

		Column
		{
			anchors.centerIn: parent
			rotation: 90

			Label
			{
				color: "black"
				font.family: "Code 128"
				fontSizeMode: Text.Fit
				font.pixelSize: 300
				width: background.height - 20
				height: background.width - 150
				horizontalAlignment: Qt.AlignHCenter
				verticalAlignment: Qt.AlignVCenter
				text: current.generateCode(current.code)
				font.letterSpacing: 0
				anchors.horizontalCenter: parent.horizontalCenter
			}

			Label
			{
				anchors.horizontalCenter: parent.horizontalCenter
				text: current.code
				color: "black"
			}
		}
	}
}


import QtQuick 2.0
import Sailfish.Silica 1.0

import harbour.clubcode 0.1
import ".."

Dialog
{
	onAccepted: main.createCode(context.current)

	AddNewCodePageViewModel
	{
		id: context
	}

	SilicaFlickable
	{
		anchors.fill: parent

		DialogHeader
		{
			id: header
			acceptText: "Create code"
		}

		EditCodeTemplate
		{
			context: context.current
			anchors.top: header.bottom
		}
	}
}






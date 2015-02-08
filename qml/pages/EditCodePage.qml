import QtQuick 2.0
import Sailfish.Silica 1.0

import ".."
import harbour.clubcode 0.1

Dialog
{
	property alias current : context.current

	onAccepted:
	{
		context.save();
		main.save();
	}

	EditCodePageViewModel
	{
		id: context

	}

	DialogHeader
	{
		id: header
	}

	EditCodeTemplate
	{
		context: context.clone
		anchors.top: header.bottom
	}
}

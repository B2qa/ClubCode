import QtQuick 2.0
import Sailfish.Silica 1.0
import harbour.clubcode 0.1
import "pages"

ApplicationWindow
{
	MainViewModel
	{
		id: main
	}

	allowedOrientations: Orientation.Portrait

	initialPage: Component { HomePage { } }
    cover: Qt.resolvedUrl("cover/CoverPage.qml")
}



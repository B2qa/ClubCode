import QtQuick 2.0
import Sailfish.Silica 1.0


Page
{
    id: page

	SilicaFlickable
	{
        anchors.fill: parent

		PullDownMenu
		{
			MenuItem
			{
				text: qsTr("Add a new Code")
				onClicked: pageStack.push(Qt.resolvedUrl("AddNewCodePage.qml"))
            }
        }

		SilicaListView
		{
			anchors.fill: parent
			model: main.codes
			spacing: 10
			header: PageHeader
			{
				title: "Codes"
			}

            delegate: ListItem {

                id: item
                width: ListView.view.width
               // height: menu.active? contentHeight + menu.height : contentHeight
                contentHeight: Theme.itemSizeMedium // two line delegate

                onClicked: {
                    pageStack.push(Qt.resolvedUrl("ViewCodePage.qml"), { current: modelData })
                }

                onPressAndHold: menu.active? menu.hide() : menu.show(item)

                menu: ContextMenu
                        {
                            id: menu

                            MenuItem
                            {
                                text: "Edit"
                                onClicked: pageStack.push(Qt.resolvedUrl("EditCodePage.qml"), { current: modelData })
                            }
                            MenuItem
                            {
                                text: "Remove"
                                onClicked: main.removeCode(modelData)
                            }
                        }

				Rectangle
				{
                    height: Theme.itemSizeMedium
					width: parent.width
					color: "white"


					Label
					{
						color: "gray"
						font.family: "Code 128"
						anchors.centerIn: parent
                        font.pixelSize: parent.height
						text: modelData.generateCode(modelData.code)
						font.letterSpacing: 0
						opacity: 0.5
						anchors.verticalCenterOffset: -6
					}

					Column
					{
						anchors.centerIn: parent

						Label
						{
							text: modelData.name
							color: "black"
							font.bold: true
							anchors.horizontalCenter: parent.horizontalCenter
						}

						Label
						{
							text: modelData.description
							color: "black"
							anchors.horizontalCenter: parent.horizontalCenter
						}
					}
				}
			}
		}
    }
}



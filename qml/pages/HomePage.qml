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

			delegate: Item
			{

				width: page.width
				height: menu.active ? menu.height + 160 : 160
				id: item

				ContextMenu
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
					height: 160
					width: parent.width
					color: "white"


					Label
					{
						color: "gray"
						font.family: "Code 128"
						anchors.centerIn: parent
						font.pixelSize: 140
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

					BackgroundItem
					{
						width: parent.width
						height: parent.height
						onClicked: pageStack.push(Qt.resolvedUrl("ViewCodePage.qml"), { current: modelData })
						onPressAndHold: menu.show(item)
					}
				}
			}
		}
    }
}



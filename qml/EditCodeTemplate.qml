import QtQuick 2.0
import Sailfish.Silica 1.0


Column
{
	property variant context

	width: parent.width

    TextField
	{
		focus: true
		placeholderText: "Name"
		label: placeholderText
		width: parent.width
		id: name
        text: context.name

        // Show 'next' icon to indicate pressing Enter will move the
        // keyboard focus to the next text field in the page
        EnterKey.iconSource: "image://theme/icon-m-enter-next"

        // When Enter key is pressed, move the keyboard focus to the
        // next field
        EnterKey.onClicked: description.focus = true


		Binding
		{
			target: context
			property: "name"
			value: name.text
		}

	}

	TextField
    {
        id: description

        placeholderText: "Description"
		label: placeholderText
		width: parent.width
        text: context.description

        // Show 'next' icon to indicate pressing Enter will move the
        // keyboard focus to the next text field in the page
        EnterKey.iconSource: "image://theme/icon-m-enter-next"

        // When Enter key is pressed, move the keyboard focus to the
        // next field
        EnterKey.onClicked: code.focus = true

		Binding
		{
			target: context
			property: "description"
			value: description.text
		}
	}

    TextField {
        id: code
        placeholderText: "Code"
		label: placeholderText
		width: parent.width
        text: context.code

        // When Enter key is pressed, move the keyboard focus to the
        // next field
        EnterKey.onClicked: accept()


		Binding
		{
			target: context
			property: "code"
			value: code.text
		}
	}
}

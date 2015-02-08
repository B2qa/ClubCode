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

		Binding
		{
			target: context
			property: "name"
			value: name.text
		}

	}

	TextField
	{
		placeholderText: "Description"
		label: placeholderText
		width: parent.width
		id: description
		text: context.description

		Binding
		{
			target: context
			property: "description"
			value: description.text
		}
	}

	TextField
	{
		placeholderText: "Code"
		label: placeholderText
		width: parent.width
		id: code
		text: context.code

		Binding
		{
			target: context
			property: "code"
			value: code.text
		}
	}
}

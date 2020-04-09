#include "message.h"

Message::Message()
{
	font.setBold(true);
	font.setPointSize(30);
	font.setFamily("SansSerif");
	setFont(font);
	//boundingRect();
	//adjustSize();
}

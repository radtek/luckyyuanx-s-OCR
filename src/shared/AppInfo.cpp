#include "AppInfo.h"
#include <QtCore/QtCore>

AppInfo* AppInfo::mInstance = 0;

AppInfo* AppInfo::instance()
{
	if(mInstance == 0)
	{
		mInstance = new AppInfo;
	}
	return mInstance;
}

AppInfo::AppInfo()
{

}

void AppInfo::setAppPath(const std::string& appPath)
{
	mAppPath = appPath;
}

const std::string& AppInfo::appPath()
{
	return mAppPath;
}

std::string AppInfo::appDir()
{
	QFileInfo fileInfo(QString::fromStdString(mAppPath));
	return fileInfo.dir().absolutePath().toStdString();
}

std::string AppInfo::toUnicode(std::string text )
{
	QString locatText = QString::fromLocal8Bit(text.c_str());
	return std::string(locatText.toAscii().constData());
}

#include "test.h"


void getTime(time_t& creationTime)
{
	time_t epochSeconds = std::time(nullptr);
	struct tm timeInfo;
	localtime_s(&timeInfo, &epochSeconds);


	timeInfo.tm_mday = 1;
	timeInfo.tm_hour = 0;
	timeInfo.tm_min = 0;
	timeInfo.tm_sec = 0;

	creationTime = std::mktime(&timeInfo);

}
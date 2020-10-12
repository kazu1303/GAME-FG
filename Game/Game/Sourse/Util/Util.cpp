#include "Util.h"
#include <math.h>



//Šp“x‚ğƒ‰ƒWƒAƒ“‚É
float Util::AngleToRadian(float angel)
{
	//‰~ü—¦
	const float PI = (float)acos(-1);
	return angel * PI / 180.0f;
}

//ƒ‰ƒWƒAƒ“‚ğŠp“x‚É
float Util::RadianToAngle(float radian)
{
	//‰~ü—¦
	const float PI = (float)acos(-1);
	return radian * 180.0f / PI;
}

//Šp“x‚ğ0`360“à‚É•ÏX
float Util::Angle0To360(float angle)
{
	//Šp“x‚ğ‚O‚©‚ç‚R‚U‚O“à‚Éû‚ß‚é
	float currentAngle = (float)(fabs(angle - ((int)angle / 360) * 360));
	//Šp“x‚ª0ˆÈ‰º‚Ìê‡‚Í360“x‚©‚çˆø‚«‹‚ß‚é
	if (angle < 0)currentAngle = 360 - currentAngle;
	return currentAngle;
}



//O•½•û‚Ì’è—‚æ‚èÎüˆÈŠO‚Ìü‚Ì’·‚³‚ğæ“¾
float Util::LengthTry(float length1, float length2)
{
	//O•½•û‚Ì’è—‚æ‚è‚Qü‚©‚ç‚à‚¤ˆê‚Â‚Ìü(Î‚ß‚Å‚Í‚È‚¢•û)‚Ì’·‚³‚ğ‹‚ß‚é
	float length = (float)(sqrt(length1 * length1 - length2 * length2));
	//length2‚ªlength1‚æ‚è’·‚­‚È‚é‚Ælength‚Í0
	if (length2 >= length1)	length = 0;
	return length;
}

//”ä—¦‚ÌŠ“¾
float Util::Ratio(float value1, float value2)
{
	//1‚Ì•û‚Ì”ä—¦‚ğ‹‚ß‚é
	return value1 / (value1 + value2);
}

#include "Vout.h"

Vout Vout::lerp(Vout v1, Vout v2, float weight)
{
	Vout v;
	v.color		= Lerp(v1.color, v2.color, weight);
	//v.normal	= Lerp(v1.normal, v2.normal, weight);
	v.position	= Lerp(v1.position, v2.position, weight);
	//v.Texcoord	= Lerp(v1.Texcoord, v2.Texcoord, weight);
	v.windowPos	= Lerp(v1.windowPos, v2.windowPos, weight);

	return v;
}

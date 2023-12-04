#include "DomainExpension.h"
#include <iostream>
#include <Windows.h>
#include <mmsystem.h>

EDomains DomainExpension::getDomains()
{
    return characterDomains;
}

void DomainExpension::setDomains(EDomains CharDomain)
{
	switch (CharDomain)
	{
	case None:
		
		std::cout << "Mort ou vie <= à 0" << std::endl;
		break;
	case Gojo:
		break;
	case Jogo:
		break;
	case Mahito:
		break;
	case Sukuna:
		break;
	default:
		break;
	}
}

void DomainExpension::getDomainStat()
{
}

void DomainExpension::setDomainStat()
{
}

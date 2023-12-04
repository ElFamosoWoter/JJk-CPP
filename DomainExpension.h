#pragma once

enum EDomains
{
	None,
	Gojo,
	Jogo,
	Mahito,
	Sukuna,
};


class DomainExpension
{
	
private:
	EDomains characterDomains;

public :
	EDomains getDomains();
	void setDomains(EDomains CharDomain);

	void getDomainStat();
	void setDomainStat();




};


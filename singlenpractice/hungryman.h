#pragma once
#ifndef HUNGRYMAN
#define HUNGRYMAN


class hungryman
{
public:
	hungryman();
	~hungryman();
	hungryman& getinstance();
	hungryman(hungryman&) = delete;

private:
	static hungryman tmp;
};
#endif

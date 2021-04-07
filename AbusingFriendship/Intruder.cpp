#include "Intruder.h"
#include "Authorizer.h"
#include <iostream>

// defined locally in this component
class Cert
{
public:
	Cert(Authorizer& auth)
	{
		std::cout << "Authorize from Intruder!!\n";
		auth.Authorize();
	}
};

Intruder::Intruder(Authorizer& auth)
{
	Cert cert(auth);
}

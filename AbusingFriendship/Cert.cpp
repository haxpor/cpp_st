#include "Cert.h"
#include "Authorizer.h"
#include <iostream>

Cert::Cert(Authorizer& auth)
{
	std::cout << "Authorize from normal flow via Cert\n";
	auth.Authorize();
}

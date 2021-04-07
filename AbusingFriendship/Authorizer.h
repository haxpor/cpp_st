#pragma once

class Cert;

class Authorizer
{
	friend Cert;
	// authorize to gain access to priviledged area
	void Authorize();
};

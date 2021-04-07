/**
 * Inspired by example of Abusing Friendship in chapter 3 of Large Scale C++ Software Design by John Lakos.
 * Here we demonstrate the similar setup by having
 *	- "Authorizer" component to hold the privilledge giver to consumer which utilize Cert
 *	- "Cert" component is somewhat kind of a key to get access into privilleged area
 *	- "Intruder" component is and intrution attempt to gain access to privilledged area gated by Authorizer
 *
 *	This pinpoints to the risk if we declare and utilize long-distance friend accessibility.
 *	If we utilize friend locally in the same header file, nested in the class that declares it, then
 *	it eliminates this issue.
 *
 * If not link against Cert component (object file), then we will get the following output
 *
 * $ .af
 * Authorize from Intruder!!
 * Called Authorizer::Authorize()
 * Authorize from Intruder!!
 * Called Authorizer::Authorize()
 *
 * Otherwise, we will get
 *
 * $ ./af
 * Authorize from normal flow via Cert
 * Called Authorizer::Authorize()
 * Authorize from normal flow via Cert
 * Called Authorizer::Authorize()
 */

#include "Authorizer.h"
#include "Cert.h"
#include "Intruder.h"

int main()
{
	Authorizer auth;
	Cert cert(auth);
	Intruder intruder(auth);

	return 0;
}

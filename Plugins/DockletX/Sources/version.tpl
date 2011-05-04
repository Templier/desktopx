// This file is used as a template for build versioning
//
// DO NOT MODIFY VERSION.H, IT WILL BE OVERWRITTEN AT BUILD TIME
// MAKE MODIFICATIONS TO VERSION.TPL

#define VERSION_MAJOR 1
#define VERSION_MINOR 2
#define VERSION_BUILD $REVNUM$
#define VERSION_DIRTY $DIRTY$

//////////////////////////////////////////////////////////////////////////
// Expiration
#ifdef DEBUG
#define EXPIRATION_YEAR 2011
#define EXPIRATION_MONTH 12
#define EXPIRATION_DAY 1
#endif
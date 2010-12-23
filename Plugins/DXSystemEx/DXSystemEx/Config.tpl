///////////////////////////////////////////////////////////////////////////////////////////////
// This file is used as a template by SubWCRev
//
// DO NOT MODIFY, IT WILL BE OVERWRITTEN AT BUILD TIME
// MAKE MODIFICATIONS TO .tpl file
//
///////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#define PLUGIN_NAME			"Extended System Control"
#define PLUGIN_AUTHOR		"Julien Templier"
#define PLUGIN_CAPABILITY	"Extended System Control"
#define PLUGIN_PLATFORM		SD_OS_XP
#define PLUGIN_HOSTS		SD_HOST_DESKTOPX

#define PLUGIN_PREFIX 		"SystemEx_"
// Compile zip fallback in case 7z.dll is not included
#define ENABLE_ZIP_FALLBACK		1

#define VERSION_MAJOR 		1
#define VERSION_MINOR 		2
#define VERSION_BUILD 		${Revision}

#ifdef DEBUG
#define EXPIRATION_YEAR 	2011
#define EXPIRATION_MONTH 	10
#define EXPIRATION_DAY 		5
#endif
//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2013 Martin Slater
// Created : Thursday, 31 October 2013 11:42:29 AM
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "core/pc/safe_windows.h"

#ifdef _MANAGED
#pragma managed(push, off)
#endif

BOOL APIENTRY DllMain( HMODULE /*hModule*/,
                       DWORD  /*ul_reason_for_call*/,
                       LPVOID /*lpReserved*/
					 )
{
    return TRUE;
}

#ifdef _MANAGED
#pragma managed(pop)
#endif



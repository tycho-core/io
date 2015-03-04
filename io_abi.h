//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2013 Martin Slater
// Created : Thursday, 31 October 2013 11:42:29 AM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef _TEMPLATE_ABI_H_1DF17126_B0C3_491A_B852_4E0149317995
#define _TEMPLATE_ABI_H_1DF17126_B0C3_491A_B852_4E0149317995

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "io/io_abi.h"

#if TYCHO_PC

// DLL interface
#ifdef TYCHO_IO_EXPORTS
#define TYCHO_IO_ABI __declspec(dllexport)
#else
#define TYCHO_IO_ABI __declspec(dllimport)
#endif 

// disable a few warnings globally. should move these into specific cpp's to avoid polluting
// user header files
#pragma warning(disable : 4251) // class needs to have dll-interface to be used by clients of class ''
#pragma warning(disable : 4355) // 'this' : used in base member initializer list

#else // TYCHO_PC

#define TYCHO_IO_ABI

#endif // TYCHO_GC

#ifdef __cplusplus
#include "core/memory/new.h"
#include "core/memory.h"
#include "core/debug/assert.h"
#endif 

#endif // _TEMPLATE_ABI_H_1DF17126_B0C3_491A_B852_4E0149317995

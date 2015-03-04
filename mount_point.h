//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Monday, 26 May 2008 10:50:17 PM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __MOUNT_POINT_H_5F8FEBAE_651A_4A82_A37A_DB709623B412_
#define __MOUNT_POINT_H_5F8FEBAE_651A_4A82_A37A_DB709623B412_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "io/io_abi.h"

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace io
{

	/// Base class of all mount points. This is specialised by devices to store
	/// custom information they need per mount point.
    class TYCHO_IO_ABI mount_point
    {	
    public:
		/// constructor.
		/// \param d device that owns this mount point.
		mount_point(device* d) : m_device(d) {}
				
		/// destructor
		virtual ~mount_point()
			{ m_device = 0; }
		
		/// get the device that owns this mount point.
		device* get_device() { return m_device; }
		
	private:    
		device* m_device; ///< device that owns this mount point.
    };

} // end namespace
} // end namespace

#endif // __MOUNT_POINT_H_5F8FEBAE_651A_4A82_A37A_DB709623B412_

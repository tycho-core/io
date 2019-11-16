//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Friday, 2 May 2008 12:35:31 AM
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "interface.h"
#include "io/file.h"
#include "io/mount_point.h"
#include "core/debug/assert.h"
#include <algorithm>

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////
namespace tycho
{
namespace io
{

	//------------------------------------------------------------------------------------

	interface::~interface()
	{
		clear();
	}
	
	//------------------------------------------------------------------------------------

	void interface::add_device(device_ptr d)
	{
		m_devices.push_back(d);
	}
		
	//------------------------------------------------------------------------------------

	bool interface::mount(const io::path& dir, mount_point_ptr mp)	
	{		
		mount_point_entry mpe;
		mpe.dir = dir;
		mpe.device_mp = mp;
		m_mount_points.push_back(mpe);
		return true;
	}
	
	//------------------------------------------------------------------------------------

	bool interface::unmount(const io::path& dir)
	{
		mount_points::iterator it = std::find(m_mount_points.begin(), m_mount_points.end(), dir);
		if(it == m_mount_points.end())
			return false;
		m_mount_points.erase(it);
		return true;		
	}
		
	//------------------------------------------------------------------------------------

	stream_ptr interface::open_stream(const io::path& p, int flags)
	{
		mount_point_entry* mp = find_mount_point(p);
		if(!mp)
			return stream_ptr();
		io::path mount_relative_path = mp->dir.make_relative(p);
		return mp->device_mp->get_device()->open_stream(mp->device_mp, mount_relative_path, flags);
	}
	
	//------------------------------------------------------------------------------------

	bool interface::create_directories(const io::path& p)
	{
		mount_point_entry* mp = find_mount_point(p);
		if(!mp)
			return false;
		io::path mount_relative_path = mp->dir.make_relative(p);
		return mp->device_mp->get_device()->create_directories(mp->device_mp, mount_relative_path);
	}

	//------------------------------------------------------------------------------------

	/// \todo O(N) in number of mount points, make faster
	interface::mount_point_entry* interface::find_mount_point(const io::path& path)
	{
		mount_point_entry* best = 0;
		int best_len = 0;
		for(size_t i = 0; i < m_mount_points.size(); ++i)
		{
			mount_point_entry& mp = m_mount_points[i];
			if(path.starts_with(mp.dir))
			{
				int len = mp.dir.length();
				if(len > best_len)
				{
					best = &mp;
					best_len = len;
				}
			}
		}
		TYCHO_ASSERT(best);
		return best;
	}
	
	//------------------------------------------------------------------------------------

	void interface::clear()
	{
		mount_points tmp_mp;
		m_mount_points.swap(tmp_mp);		
		devices tmp_d;
		m_devices.swap(tmp_d);
	}

	//------------------------------------------------------------------------------------

} // end namespace
} // end namespace
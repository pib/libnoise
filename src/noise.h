// noise.h
//
// Version 0.1.3 - 2004-06-03
//
// Copyright (C) 2003, 2004 by Jason Bevins    
//
// This library is free software; you can redistribute it and/or modify it
// under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation; either version 2.1 of the License, or (at
// your option) any later version.
//
// This library is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
// License (COPYING.txt) for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this library; if not, write to the Free Software Foundation,
// Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
// The developer's email is zigjas@greymartinzig.com (for great email, take
// off every 'zig'.)
//

#ifndef NOISE_H
#define NOISE_H

/// @mainpage libnoise
///
/// @section intro Introduction
///
/// This library generates 3-dimensional coherent noise.
///
/// libnoise is known to compile under Windows 9X/ME/2K/XP (using Microsoft
/// Visual C++ 5.0) and under Linux (using gcc).  It should be portable across
/// many platforms, although you may need to modify basictypes.h before it
/// works on your platform.
///
/// @section uses Uses of Coherent Noise
///
/// Coherent noise is often used to generate synthetic terrain and textures,
/// and can also be used to realistically move critters and such.
///
/// @section noise Noise Modules
///
/// A <i>noise module</i> receives a 3-dimensional input point from the
/// application, computes the noise value that is located at that point, and
/// returns the resulting value back to the application.  Noise modules may
/// be combined together in various ways to generate more complex noise.
///
/// If the application passes the same input point to a noise module, the
/// noise module returns the same value.
///
/// All noise modules are derived from the Module abstract base class.
///
/// @section contact Contact
///
/// Contact jas for questions about libnoise.  The spam-resistant email
/// address is jazigs@greyzigmartin.com (For great email, take off every
/// <a href=http://www.planettribes.com/allyourbase/story.shtml>zig</a>.)

#include "module/module.h"
#include "model/model.h"
#include "misc.h"

#endif

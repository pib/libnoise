// cylinder.h
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

#ifndef NOISE_MODEL_CYLINDER_H
#define NOISE_MODEL_CYLINDER_H

#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include "../module/modulebase.h"

namespace noise
{

  namespace model {

    /// @addtogroup libnoise
    /// @{

    /// @defgroup models Models
    /// @addtogroup models
    /// @{

    /// Model that defines the surface of a cylinder.
    ///
    /// @image html modelcylinder.png
    ///
    /// Using a noise module, this class returns values that lie on the surface
    /// of a cylinder.
    ///
    /// To return a noise value from a point on the cylinder, pass an angle and
    /// a height to the GetValue() method.
    ///
    /// The cylinder has a radius of @b 1.0 unit and has infinite height.  The
    /// cylinder is oriented along the @a y axis.  The center of the cylinder is
    /// located at ( @b 0.0, @b 0.0, @b 0.0 ).
    class Cylinder
      {
	
      public:
	
	/// Constructor.
	Cylinder ();
	
	/// Returns the noise module used to generate the values on the surface
	/// of the cylinder.
	///
	/// @returns A reference to the noise module.
	///
	/// @pre A noise module was passed to the SetModule() method.
	const module::Module& GetModule () const
	  {
	    assert (m_pModule != NULL);
	    return *m_pModule;
	  }

	/// Returns the noise value at the given position on the cylinder.
	///
	/// @param angle The angle around the cylinder's center, in degrees.
	/// @param height The height of the point along the @a y axis.
	///
	/// @returns The noise value.
	///
	/// @pre A noise module was passed to the SetModule() method.
	///
	/// The noise value is generated by the module passed to the SetModule()
	/// method.
	///
	/// The cylinder has a radius of @b 1.0 unit and has infinite height.
	/// The cylinder is oriented along the @a y axis.  The center of the
	/// cylinder is located at ( @b 0.0, @b 0.0, @b 0.0 ).
	double GetValue (double angle, double height) const;
	
	/// Sets the noise module used to generate the values on surface of the
	/// cylinder.
	///
	/// @param module The noise module.
	///
	/// The noise module must exist for the lifetime of this object, unless
	/// you pass a new module to this method.
	void SetModule (const module::Module& module)
	  {
	    m_pModule = &module;
	  }
	
      private:
	
	/// A pointer to the module used to generate the noise values.
	const module::Module* m_pModule;
	
      };
    
    /// @}
    
    /// @}

  } /* model:: */
} /* noise:: */

#endif

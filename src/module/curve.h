// curve.h
//
// Version 0.1.1 - 2004-03-04
// - Changed GetNumControlPoints() to GetControlPointCount() for consistency.
// - Changed GetNumSourceModules() to GetSourceModuleCount() for consistency.
// - Changed m_numControlPoints to m_controlPointCount for consistency.
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

#ifndef NOISE_MODULE_CURVE_H
#define NOISE_MODULE_CURVE_H

#include "modulebase.h"

namespace noise
{

  namespace module {

    /// @addtogroup libnoise
    /// @{
    
    /// This structure defines a control point.
    ///
    /// Control points are used for defining splines.
    struct ControlPoint
    {
      
      /// The input value.
      double m_inputValue;
      
      /// The output value that is mapped from the input value.
      double m_outputValue;
      
    };
    
    /// @addtogroup modules
    /// @{
    
    /// @addtogroup modifiermodules
    /// @{
    
    /// Noise module that maps the value from the source module onto an
    /// arbitrary curve.
    ///
    /// @image html modulecurve.png
    ///
    /// The mapping curve is a spline defined by a number of <i>control
    /// points</i>. Each control point has an <i>input value</i> and an
    /// <i>output value</i>.  To add the control points to this module, call the
    /// AddControlPoint() method.
    ///
    /// There is no limit to the number of control points that can be added to
    /// the curve.  There must be a minimum of four control points on the curve
    /// before an application can call the GetValue() method. The control points
    /// can have any input and output value, although no two control points can
    /// have the same input value.
    ///
    /// This noise module requires one source module.
    class Curve: public Module
      {
	
      public:
	
	/// Constructor.
	Curve ();

	/// Destructor.
	~Curve ();

	/// Adds a control point onto the mapping curve.
	///
	/// @param inputValue The input value stored in the control point.
	/// @param outputValue The output value stored in the control point.
	///
	/// @pre No two control points have the same input value.
	///
	/// @throw NoiseEx
	/// - @a EX_INVALID_PARAM: An invalid parameter was specified; see the
	///   preconditions for more information.
	///
	/// The mapping curve is a spline defined by a number of <i>control
	/// points</i>. Each control point has an <i>input value</i> and an
	/// <i>output value</i>.
	///
	/// It does not matter which order these points are added.
	void AddControlPoint (double inputValue, double outputValue);
	
	/// Deletes all the control points from the mapping curve.
	///
	/// @post All points on the mapping curve are deleted.
	void ClearAllControlPoints ();
	
	/// Returns a pointer to the array of control points on the mapping
	/// curve.
	///
	/// @returns A pointer to the array of control points.
	///
	/// Before calling this method, call GetControlPointCount() to determine
	/// the number of control points in this array.
	///
	/// It is recommended that an application does not store this pointer
	/// for later use since the pointer to the array may change if the
	/// application calls another method of this object.
	const ControlPoint* GetControlPointArray () const
	  {
	    return m_pControlPoints;
	  }
	
	/// Returns the number of control points on the mapping curve.
	///
	/// @returns The number of control points on the mapping curve.
	int GetControlPointCount () const
	  {
	    return m_controlPointCount;
	  }
	
	virtual int GetSourceModuleCount () const
	  {
	    return 1;
	  }
	
	virtual double GetValue (double x, double y, double z) const;
	
      protected:
	
	/// Determines the array index in which to insert the control point into
	/// the internal control point array.
	///
	/// @param inputValue The input value of the control point.
	///
	/// @returns The array index in which to insert the control point.
	///
	/// @pre No two control points have the same input value.
	///
	/// @throw NoiseEx
	/// - @a EX_INVALID_PARAM: An invalid parameter was specified; see the
	///   preconditions for more information.
	///
	/// By inserting the control point at the returned array index, this
	/// class ensures that the control point array is sorted by input value.
	/// The code that maps a value onto the curve requires a sorted control
	/// point array.
	int FindInsertionPos (double inputValue);
	
	/// Inserts the control point at the specified position in the internal
	/// control point array.
	///
	/// @param insertionPos The zero-based array position in which to insert
	/// the control point.
	/// @param inputValue The input value stored in the control point.
	/// @param outputValue The output value stored in the control point.
	///
	/// To make room for this new control point, this method reallocates the
	/// control point array and shifts all control points occurring after
	/// the insertion position up by one.
	///
	/// Because the curve mapping algorithm in this module requires that all
	/// control points in the array must be sorted by input value, the new
	/// control point should be inserted at the position in which the order
	/// is still preserved.
	void InsertAtPos (int insertionPos, double inputValue,
			  double outputValue);
	
	/// Number of control points on the curve.
	int m_controlPointCount;
	
	/// Array that stores the control points.
	ControlPoint* m_pControlPoints;
	
      };
    
    /// @}
    
    /// @}
    
    /// @}
    
  }
}

#endif

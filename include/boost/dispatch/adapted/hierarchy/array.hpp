//==================================================================================================
/*!
  @file

  Defines the arithmetic_ hierarchy

  @copyright 2009 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_ADAPTED_HIERARCHY_ARRAY_HPP_INCLUDED
#define BOOST_DISPATCH_ADAPTED_HIERARCHY_ARRAY_HPP_INCLUDED

#include <boost/dispatch/hierarchy/unspecified.hpp>
#include <boost/dispatch/adapted/hierarchy/tuple.hpp>
#include <boost/dispatch/hierarchy_of.hpp>
#include <boost/dispatch/property_of.hpp>

namespace boost { namespace dispatch
{
  /*!
    @ingroup group-hierarchy
    @brief Array type hierarchy tag

    Types are classified as array_ if they represent a compound type with a static size,
    an operator[] and a value_type.

    @tparam T Base hierarchy
    @tparam N Size of the classified array
  **/
  template<typename T, typename N> struct array_ : array_<typename T::parent, N>
  {
    /// Parent hierarchy of array_
    using parent = array_<typename T::parent, N>;
  };

  template<typename T, typename N>
  struct  array_<unspecified_<T>,N> : bag_<property_of_t<T>, N>
  {
    using parent = bag_<property_of_t<T>, N>;
  };
} }

#endif

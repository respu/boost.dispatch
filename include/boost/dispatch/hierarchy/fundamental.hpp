//==================================================================================================
/*!
  @file

  Defines the fundamental_ hierarchy

  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_HIERARCHY_FUNDAMENTAL_HPP_INCLUDED
#define BOOST_DISPATCH_HIERARCHY_FUNDAMENTAL_HPP_INCLUDED

#include <boost/dispatch/hierarchy/unspecified.hpp>

namespace boost { namespace dispatch
{
  /*!
    @ingroup group-hierarchy
    @brief Fundamental type hierarchy tag

    Types classified as fundamental_ have similar properties to Fundamental C++ types, i.e
    being a floating point, an integer, a boolean type or void.

    @tparam T Base hierarchy
  **/
  template<typename T> struct fundamental_ : unspecified_<T>
  {
    using parent = unspecified_<T>;
  };
} }

#endif

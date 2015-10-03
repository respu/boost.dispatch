//==================================================================================================
/*!
  @file

  Defines the bool_ hierarchy

  @copyright 2009 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_HIERARCHY_BOOL_HPP_INCLUDED
#define BOOST_DISPATCH_HIERARCHY_BOOL_HPP_INCLUDED

#include <boost/dispatch/hierarchy/fundamental.hpp>

namespace boost { namespace dispatch
{
  /*!
    @ingroup group-hierarchy
    @brief Boolean type hierarchy tag

    Types classified as bool_ have properties similar to bool

    @tparam T Base hierarchy
  **/
  template<typename T> struct bool_ : fundamental_<T>
  {
    using parent = fundamental_<T>;
  };
} }

#endif

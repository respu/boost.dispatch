//==================================================================================================
/*!
  @file

  Defines the void_ hierarchy

  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_HIERARCHY_VOID_HPP_INCLUDED
#define BOOST_DISPATCH_HIERARCHY_VOID_HPP_INCLUDED

#include <boost/dispatch/hierarchy/fundamental.hpp>

namespace boost { namespace dispatch
{
  /*!
    @ingroup group-hierarchy
    @brief void type hierarchy tag

    Types classified as void_ have properties similar to void

    @tparam T Base hierarchy
  **/
  template<typename T> struct void_ : fundamental_<T>
  {
    using parent = fundamental_<T>;
  };
} }

#endif

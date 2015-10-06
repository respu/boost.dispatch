//==================================================================================================
/*!
  @file

  Defines the floating_ hierarchy

  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_HIERARCHY_FLOATING_HPP_INCLUDED
#define BOOST_DISPATCH_HIERARCHY_FLOATING_HPP_INCLUDED

#include <boost/dispatch/hierarchy/signed_types.hpp>

namespace boost { namespace dispatch
{
  /*!
    @ingroup group-hierarchy
    @brief floating type hierarchy tag

    Types are classified as floating_ if they behaves as one of the basic floating point types.

    @tparam T Base hierarchy
  **/
  template<typename T> struct floating_ : signed_<T>
  {
    using parent = signed_<T>;
  };
} }

#endif

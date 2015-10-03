//==================================================================================================
/*!
  @file

  Provides a hierarchy for integral constant types

  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_ADAPTED_HIERARCHY_INTEGRAL_CONSTANT_HPP_INCLUDED
#define BOOST_DISPATCH_ADAPTED_HIERARCHY_INTEGRAL_CONSTANT_HPP_INCLUDED

#include <boost/dispatch/hierarchy/unspecified.hpp>
#include <boost/dispatch/hierarchy_of.hpp>

namespace boost { namespace dispatch
{
  /*!
    @ingroup group-hierarchy
    @brief integral constant type hierarchy tag

    Types are classified as constant_ if they are type embedding a integral constant.

    @note When reaching @c constant_<unspecified_<T>> , the hierarchy turns into
    @c scalar_<integral_<T>> and evolves accordingly.

    @tparam T Base hierarchy
  **/
  template<typename T> struct constant_ : constant_<typename T::parent>
  {
    using parent = constant_<typename T::parent>;
  };

  template<typename T>
  struct  constant_< unspecified_<T> > : hierarchy_of< typename T::value_type >
  {
    using parent = hierarchy_of_t< typename T::value_type, T >;
  };
} }

#endif

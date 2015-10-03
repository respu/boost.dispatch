//==================================================================================================
/*!
  @file

  Defines the hierarchy_of meta-function

  @copyright 2009 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_HIERARCHY_OF_HPP_INCLUDED
#define BOOST_DISPATCH_HIERARCHY_OF_HPP_INCLUDED

#include <boost/dispatch/detail/hierarchy_of.hpp>
#include <type_traits>

namespace boost { namespace dispatch
{
  /*!
    @ingroup group-meta
    @brief Retrieve the hierarchy of a Type

    For any type @c T, returns the hierarchy describing the properties of any given type.
    This Hierarchy can later be used to select functions implementation based on type properties.

    @tparam T     Type to categorize
    @tparam Origin

    @par Models:

    @metafunction

    @par Semantic:

  **/
  template<typename T, typename Origin = T>
  struct hierarchy_of : detail::hierarchy_of<T, typename std::remove_reference<Origin>::type>
  {};

  /// EAger short-cur for hierarchy_of
  template<typename T, typename Origin = T>
  using hierarchy_of_t = typename hierarchy_of<T, Origin>::type;
} }

#endif

//==================================================================================================
/*!
  @file

  Defines the meta::scalar_of meta-function

  @copyright 2009 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_META_INTROSPECTION_SCALAR_OF_HPP_INCLUDED
#define BOOST_DISPATCH_META_INTROSPECTION_SCALAR_OF_HPP_INCLUDED

#include <boost/dispatch/meta/introspection/detail/scalar_of.hpp>

namespace boost { namespace dispatch
{
  /*!
    @ingroup group-meta
    @brief Compute the basic value type of an arbitrary type

    Retrieves the most embedded fundamental type of any given type, carrying over
    cv-qualifiers.

    @tparam T Type to analyze
  **/
  template<typename T> struct scalar_of : ext::scalar_of<T> {};

  /// Eager shortcut for scalar_of
  template<typename T> using scalar_of_t = typename scalar_of<T>::type;
} }

#endif

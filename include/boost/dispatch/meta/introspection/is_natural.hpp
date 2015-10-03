//==================================================================================================
/*!
  @file

  Defines the is_natural meta-function

  @copyright 2009 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_META_INTROSPECTION_IS_NATURAL_HPP_INCLUDED
#define BOOST_DISPATCH_META_INTROSPECTION_IS_NATURAL_HPP_INCLUDED

#include <boost/dispatch/detail/brigand.hpp>
#include <type_traits>

namespace boost { namespace dispatch
{
  /*!
    @ingroup group-meta
    @brief Traits for detecting natural integral types

    Checks if a type @c T is a natural integral type, i.e an Integral type able to contain
    natural numbers. This includes all integral types except bool.

    @tparam T Type to check
  **/
  template<typename T>
  using is_natural = brigand::and_< std::is_integral<T>
                                  , brigand::not_<std::is_same<T,bool>>
                                  >;

  /// Eager short-cut for is_native
  template<typename T> using is_natural_t = typename is_natural<T>::type;
} }

#endif

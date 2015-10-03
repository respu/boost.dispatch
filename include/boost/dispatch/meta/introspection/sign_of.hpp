//==================================================================================================
/*!
  @file

  Defines the sign_of meta-function

  @copyright 2009 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_META_INTROSPECTION_SIGN_OF_HPP_INCLUDED
#define BOOST_DISPATCH_META_INTROSPECTION_SIGN_OF_HPP_INCLUDED

#include <boost/dispatch/meta/introspection/primitive_of.hpp>
#include <type_traits>

namespace boost { namespace dispatch
{
  namespace ext
  {
    template<typename T, typename Enable = void> struct  sign_of
    {
      using primitive = boost::dispatch::primitive_of_t<T>;
      using signed_t  = std::is_signed<primitive>;
      using float_t   = std::is_floating_point<primitive>;
      using type      = typename std::conditional < (signed_t::value || float_t::value)
                                                  , signed
                                                  , unsigned
                                                  >::type;
    };
  }

  /*!
    @ingroup group-meta
    @brief Return sign of a type

    If a type @c T can contains value with a sign (i.e signed integers and floating points-like
    types), sign_of<T> evaluates to @c signed. Otherwise, it evaluates @c unsigned.

    @tparam T Type to introspect.
  **/
  template<typename T>
  struct sign_of : ext::sign_of<typename std::decay<T>::type>
  {};

  /// Eager shortcut for sign_of
  template<typename T> using sign_of_t = typename sign_of<T>::type;
} }

#endif

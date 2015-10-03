//==================================================================================================
/*!
  @file

  Defines the apply_sign meta-function

  @copyright 2009 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_META_GENERATION_APPLY_SIGN_HPP_INCLUDED
#define BOOST_DISPATCH_META_GENERATION_APPLY_SIGN_HPP_INCLUDED

#include <boost/dispatch/meta/generation/as_unsigned.hpp>
#include <boost/dispatch/meta/generation/as_signed.hpp>

namespace boost { namespace dispatch
{
  namespace detail
  {
    template<typename T,typename Sign> struct apply_sign;
    template<typename T> struct apply_sign<T,signed> : boost::dispatch::as_signed<T>      {};
    template<typename T> struct apply_sign<T,unsigned> : boost::dispatch::as_unsigned<T>  {};
  }

  /*!
    @ingroup group-meta
    @brief Apply sign to given type

    Transforms any type @c T into a corresponding type with specified sign @c Sign.

    @tparam T     Type to modify
    @tparam Sign  Sign to apyl to @c T
  **/
  template<typename T,typename Sign> struct apply_sign : detail::apply_sign<T,Sign> {};

  template<typename T,typename Sign> using apply_sign_t = typename apply_sign<T,Sign>::type;
} }

#endif

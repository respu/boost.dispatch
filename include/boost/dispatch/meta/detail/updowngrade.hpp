//==================================================================================================
/*!
  @file

  Defines the downgrade meta-function

  @copyright 2009 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_META_DETAIL_UPDOWNGRADE_HPP_INCLUDED
#define BOOST_DISPATCH_META_DETAIL_UPDOWNGRADE_HPP_INCLUDED

#include <boost/dispatch/meta/introspection/primitive_of.hpp>
#include <boost/dispatch/meta/introspection/factory_of.hpp>
#include <boost/dispatch/meta/introspection/sign_of.hpp>
#include <boost/dispatch/meta/generation/make_integer.hpp>
#include <boost/dispatch/meta/generation/as_unsigned.hpp>
#include <boost/dispatch/meta/generation/apply_sign.hpp>
#include <boost/dispatch/detail/brigand/sequences/at.hpp>

namespace boost { namespace dispatch { namespace detail
{
  template<typename T,typename Sign,typename Map> struct updowngrade
  {
    // Decompose in factory/primitive
    using f_t = boost::dispatch::factory_of<T>;
    using p_t = boost::dispatch::primitive_of<T>;

    // Unsign the primitive to limit the map's size
    using b_t  = boost::dispatch::as_unsigned<p_t>;
    using db_t = brigand::at<Map,b_t>;

    // Reapply sign and reconstruct
    using d_t  = boost::dispatch::apply_sign<db_t,Sign>;
    using type = typename f_t::template apply<d_t>;
  };
} } }

#endif

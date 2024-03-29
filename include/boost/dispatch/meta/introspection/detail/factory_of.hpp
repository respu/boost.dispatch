//==================================================================================================
/*!
  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_META_INTROSPECTION_DETAIL_FACTORY_OF_HPP_INCLUDED
#define BOOST_DISPATCH_META_INTROSPECTION_DETAIL_FACTORY_OF_HPP_INCLUDED

#include <boost/dispatch/meta/introspection/model_of.hpp>
#include <boost/dispatch/meta/introspection/value_of.hpp>
#include <boost/dispatch/meta/introspection/primitive_of.hpp>

namespace boost { namespace dispatch { namespace detail
{
  template<typename T, typename U> struct factory_of
  {
    template<typename X> struct apply
    {
      using v_t   = boost::dispatch::value_of_t<T>;
      using f_t   = typename detail::factory_of<v_t,U>::template apply<X>::type;
      using type  = typename boost::dispatch::model_of<T>::template apply<f_t>::type;
    };
  };

  template<typename T> struct factory_of<T, T>
  {
    template<typename X> struct apply { using type = X; };
  };
} } }

#endif

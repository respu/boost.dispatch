//==================================================================================================
/*!
  @copyright 2009 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_META_INTROSPECTION_DETAIL_PRIMITIVE_OF_HPP_INCLUDED
#define BOOST_DISPATCH_META_INTROSPECTION_DETAIL_PRIMITIVE_OF_HPP_INCLUDED

#include <boost/dispatch/meta/introspection/value_of.hpp>

namespace boost { namespace dispatch { namespace detail
{
  template<class T, class Origin> struct primitive_of
  {
    using type = typename detail::primitive_of<boost::dispatch::value_of_t<T>, T>::type;
  };

  template<class T> struct primitive_of<T, T>
  {
    using type = T;
  };
} } }

#endif

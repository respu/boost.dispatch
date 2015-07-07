//==================================================================================================
/*!
  @file

  Defines the as_unsigned meta-function

  @copyright 2009 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_META_GENERATION_AS_UNSIGNED_HPP_INCLUDED
#define BOOST_DISPATCH_META_GENERATION_AS_UNSIGNED_HPP_INCLUDED

#include <boost/dispatch/meta/introspection/factory_of.hpp>
#include <boost/dispatch/meta/introspection/primitive_of.hpp>
#include <boost/dispatch/meta/introspection/is_natural.hpp>
#include <type_traits>

namespace boost { namespace dispatch
{
  namespace detail
  {
    template<typename T, typename Enable = void>
    struct as_unsigned
    {
      using f_t  = boost::dispatch::factory_of<T>;
      using p_t  = boost::dispatch::primitive_of<T>;
      using type = typename f_t::template apply<typename detail::as_unsigned<p_t>::type>;
    };

    template<typename T>
    struct as_unsigned<T, typename std::enable_if<std::is_fundamental<T>::value>::type>
    {
      template<typename U> struct id { using type = T;};
      using result  = std::conditional<is_natural<T>::value,std::make_unsigned<T>,id<T>>;
      using type    = typename result::type::type;
    };
  }

  /*!
    @ingroup group-meta
    @brief Turn a type into an equivalent unsigned type

    Converts any type which Primitive is Fundamental into a compatible unsigned type.

    @tparam T     Type to convert.
  **/
  template<typename T>
  using as_unsigned = typename detail::as_unsigned<typename std::decay<T>::type>::type;
} }

#endif

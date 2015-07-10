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
#ifndef BOOST_DISPATCH_META_INTROSPECTION_DETAIL_SCALAR__OF_HPP_INCLUDED
#define BOOST_DISPATCH_META_INTROSPECTION_DETAIL_SCALAR__OF_HPP_INCLUDED

#include <boost/dispatch/meta/introspection/value_of.hpp>
#include <type_traits>

namespace boost { namespace dispatch
{
  namespace detail
  {
    template<typename T, typename U = boost::dispatch::value_of<T>>
    struct scalar_of : boost::dispatch::detail::scalar_of<U>
    {};

    template<typename T> struct scalar_of<T, T>
    {
      using type = T;
    };
  }

  namespace ext
  {
    /*!
      @ingroup group-extension
      @brief Extension point for scalar_of

      This extension point allows customization of the scalar_of @metafunction
      by letting the user specify how the @metafunction should behave on a given type.

      @tparam T Type to analyze
    **/
    template<typename T>
    struct scalar_of : boost::dispatch::detail::scalar_of<T>
    {};

    template<typename T>
    struct scalar_of<T&&>
      : std::conditional< std::is_same< typename boost::dispatch::detail::scalar_of<T>::type
                                      , T
                                      >::value
                        , T&&
                        , typename boost::dispatch::detail::scalar_of<T&&>::type
                        >
    {};

    template<typename T>
    struct scalar_of<T&>
      : std::conditional< std::is_same< typename boost::dispatch::detail::scalar_of<T>::type
                                      , T
                                      >::value
                        , T&
                        , typename boost::dispatch::detail::scalar_of<T&>::type
                        >
    {};

    template<typename T>
    struct scalar_of<T const>
      : std::conditional< std::is_same< typename boost::dispatch::detail::scalar_of<T>::type
                                      , T
                                      >::value
                        , T const
                        , typename boost::dispatch::detail::scalar_of<T const>::type
                        >
    {};
  }
} }

#endif

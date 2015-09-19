//==================================================================================================
/*!
  @file

  Gateway header to hierarchy types

  @copyright 2009 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_AS_HPP_INCLUDED
#define BOOST_DISPATCH_AS_HPP_INCLUDED

#include <boost/dispatch/hierarchy/unspecified.hpp>
#include <boost/dispatch/meta/introspection/value_of.hpp>
#include <boost/dispatch/meta/introspection/model_of.hpp>
#include <boost/dispatch/hierarchy_of.hpp>
#include <boost/core/ignore_unused.hpp>

namespace boost { namespace dispatch
{
  /*!
    @ingroup group-api
    Provides a type wrapper allowing functions to receive type informations as an object.

    @tparam T Type to wrap
  **/
  template<typename T> struct as_
  {
    /// Encapsulated type
    using type = T;
  };

  /*!
    @ingroup group-api
    @brief Generates a type wrapper from an existing value

    @par Usage:

    @snippet api/as.cpp as

    @param  v Value from which type is wrapped from
    @return An instance of as_ instantiated with the type of @c v.
  **/
  template<typename T> as_<typename std::decay<T>::type> as(T&& v)
  {
    boost::ignore_unused(v);
    return {};
  };

  namespace detail
  {
    template<typename T> struct target_value            { using type = T; };
    template<typename T> struct target_value< as_<T> >  { using type = T; };
  }

  /*!
    @ingroup group-meta

    Retrieves the type wrapped by an instance of @c as_ .

    @par Usage:

    @snippet api/as.cpp target_value

    @tparam T Type to extract wrapped type from
  **/
  template<typename T> using target_value = typename detail::target_value<T>::type;

  /*!
    @ingroup group-hierarchy
    @brief Type wrapper hierarchy.

    @tparam T Wrapped type hierarchy
  **/
  template<typename T> struct target_ : target_< typename T::parent >
  {
    /// Parent hierarchy
    using parent = target_< typename T::parent >;
  };

#if !defined(DOXYGEN_ONLY)
  template<typename T> struct target_< unspecified_<T> > : unspecified_<T>
  {
    using parent = unspecified_<T>;
  };

  // Adapt to hierarchy system
  namespace ext
  {
    template<typename T> struct value_of<as_<T>> { using type = T; };
    template<typename T> struct model_of<as_<T>> { template<typename X> using apply = as_<X>; };

    template<typename T, typename Origin> struct hierarchy_of< as_<T>, Origin>
    {
      using type = target_<boost::dispatch::hierarchy_of<T,Origin>>;
    };
  }
#endif
} }

#endif

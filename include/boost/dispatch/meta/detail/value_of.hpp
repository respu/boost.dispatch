//==================================================================================================
/*!
  @file

  Defines the value_of meta-function

  @copyright 2009 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_META_DETAIL_VALUE_OF_HPP_INCLUDED
#define BOOST_DISPATCH_META_DETAIL_VALUE_OF_HPP_INCLUDED

#include <type_traits>

namespace boost { namespace dispatch
{
  // Forward declaration
  namespace meta { template<class T> struct value_of; }

  namespace ext
  {
    /*!
      @ingroup group-extension
      @brief SFINAE-enabled extension point for meta::value_of

      This extension point allows customization of the meta::value_of @metafunction
      by letting user defined SFINAE-enabled context in which they can specialize
      meta::value_of for family of types

      @par Usage:

      @tparam T       Type to build a Model @metafunction from
      @tparam Enable  SFINAE condition to be specified
    **/
    template<class T, class Enable = void>
    struct value_of
    {
      using type = T;
    };

    // Specialize for all Template<Type> like class
    template<template<class> class Template, typename Type>
    struct value_of<Template<Type>>
    {
      using type = Type;
    };

    /*!
      @ingroup group-extension
      @brief SFINAE-enabled extension point for meta::value_of with qualifiers

      This extension point allows customization of the meta::value_of @metafunction
      by letting user defined SFINAE-enabled context in which they can specialize
      meta::value_of for family of types with cv-qualifiers

      @par Usage:

      @tparam T       Type to build a Model @metafunction from
      @tparam Enable  SFINAE condition to be specified
    **/
    template<class T, class Enable = void>
    struct value_of_cv;

    template<class T, class Enable>
    struct value_of_cv<T const, Enable>
         : std::add_const<typename meta::value_of<T>::type>
    {};

    template<class T, class Enable>
    struct value_of_cv<T&, Enable>
         : std::add_lvalue_reference<typename meta::value_of<T>::type>
    {};

    template<class T, class Enable>
    struct value_of_cv<T&&, Enable>
         : std::add_rvalue_reference<typename meta::value_of<T>::type>
    {};
  }
} }

#endif

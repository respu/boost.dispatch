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
#ifndef BOOST_DISPATCH_META_VALUE_OF_HPP_INCLUDED
#define BOOST_DISPATCH_META_VALUE_OF_HPP_INCLUDED

#include <boost/dispatch/config.hpp>
#include <boost/dispatch/meta/detail/value_of.hpp>

namespace boost { namespace dispatch
{
  namespace meta
  {
    /*!
      @ingroup group-meta
      @brief Underlying type evaluation

      Evaluates, for any given type @c T, the underlying type of @c T.

      @par Models:

      @metafunction

      @par Semantic:

      For any type @c T,

      @code
      using U = meta::value_of<T>::type;
      @endcode

      is defined so that

      @code
      std::is_same<T, meta::model_of<T>::type<U>>::type
      @endcode

      evaluates to @true_ .

      @par Extension Point:

      meta::value_of can be specialized for user-defined types by either:

        - Directly overloading the meta::value_of class for a given type
        - Specialize (eventually through SFINAE) the ext::value_of and ext::value_of_cv classes

      Specialization for meta::value_of are provided for most of standard and
      Boost types. See the @ref group-adapted page.

      @tparam T Type to analyze
    **/
    template<typename T> struct  value_of          : ext::value_of<T>          {};
    template<typename T> struct  value_of<T&>      : ext::value_of_cv<T&>      {};
    template<typename T> struct  value_of<T&&>     : ext::value_of_cv<T&&>     {};
    template<typename T> struct  value_of<T const> : ext::value_of_cv<T const> {};

#ifndef BOOST_NO_RESTRICT_REFERENCES
    template<typename T> struct  value_of<T& BOOST_RESTRICT> : ext::value_of_cv<T&> {};
#endif
  }

  /*!
    @ingroup group-meta
    @brief C++14 style short-cut for meta::value_of
  **/
  template<typename T>
  using value_of_t = typename meta::value_of<T>::type;
} }

# endif

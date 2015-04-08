//==================================================================================================
/*!
  @file

  Defines the meta::transfer_qualifiers meta-function

  @copyright 2009 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_META_TRANSFER_QUALIFIERS_HPP_INCLUDED
#define BOOST_DISPATCH_META_TRANSFER_QUALIFIERS_HPP_INCLUDED

#include <boost/dispatch/details/type_traits.hpp>

namespace boost { namespace dispatch
{
  namespace meta
  {
    /*!
      @ingroup group-meta
      @brief Transfer qualifiers between types

      Modify a type so it bears the same cref-qualifier than another type while following the
      reference collapsing rules (<a href="http://isocpp.org/blog/2012/11/universal-references-in-c11-scott-meyers">
      as described in this article</a>) which state that:

      - An rvalue reference to an rvalue reference becomes (“collapses into”) an rvalue reference.
      - All other references to references (i.e., all combinations involving an lvalue reference)
        collapse into an lvalue reference.

      @par Model:

      @metafunction

      @tparam T Type to modify
      @tparam U Type which modifier needs to be transfered
    **/
    template<typename T, typename U>
    struct transfer_qualifiers
    {
      typedef T type;
    };

    template<typename T, typename U>
    struct transfer_qualifiers<T, U&&> : std::add_rvalue_reference<T> {};

    template<typename T, typename U>
    struct transfer_qualifiers<T, U&> : std::add_lvalue_reference<T> {};

    template<typename T, typename U>
    struct transfer_qualifiers<T, U const> : std::add_const<T> {};

    template<typename T, typename U>
    struct  transfer_qualifiers<T, U const&>
          : std::add_lvalue_reference<typename std::add_const<T>::type>
    {};
  }

  /*!
    @ingroup group-meta
    @brief C++14 style short-cut for meta::transfer_qualifiers
  **/
  template<typename T, typename U>
  using transfer_qualifiers_t = typename meta::transfer_qualifiers<T,U>::type;
} }

#endif

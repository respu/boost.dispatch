//==================================================================================================
/*!
  @file

  Defines the hierarchies associated to sized types

  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_HIERARCHY_SIZED_TYPE_HPP_INCLUDED
#define BOOST_DISPATCH_HIERARCHY_SIZED_TYPE_HPP_INCLUDED

#include <boost/dispatch/hierarchy/integer.hpp>
#include <boost/dispatch/hierarchy/floating.hpp>
#include <boost/dispatch/hierarchy/signed_types.hpp>
#include <boost/dispatch/meta/introspection/sign_of.hpp>
#include <boost/dispatch/meta/introspection/behave_as.hpp>
#include <type_traits>
#include <climits>
#include <cstddef>

namespace boost { namespace dispatch
{
  /*!
    @ingroup group-hierarchy
    @brief Sized type hierarchy tag

    Types classified as sized_type_ if their sizeof is exactly BitSize.

    @tparam T       Base hierarchy
    @tparam BitSize Type size in bits
  **/
  template<typename T, std::size_t BitSize>
  struct sized_type_ : std::conditional < behave_as<T, std::is_floating_point<brigand::_1>>::value
                                        , floating_<T>
                                        , signed_integral_<T,sign_of_t<T>>
                                        >::type
  {
    static const std::size_t bits = BitSize;
    static const std::size_t byte = bits/CHAR_BIT;

    using parent = typename std::conditional< behave_as<T, std::is_floating_point<brigand::_1>>::value
                                            , floating_<T>
                                            , signed_integral_<T,sign_of_t<T>>
                                            >::type;
  };

  /*!
    @ingroup group-hierarchy
    @brief 8 bits type hierarchy tag

    8 bits types are classified as type8_.

    @tparam T Base hierarchy
  **/
  template<typename T> using type8_ = sized_type_<T,8>;

  /*!
    @ingroup group-hierarchy
    @brief 16 bits type hierarchy tag

    16 bits types are classified as type16_.

    @tparam T Base hierarchy
  **/
  template<typename T> using type16_ = sized_type_<T,16>;

  /*!
    @ingroup group-hierarchy
    @brief 32 bits type hierarchy tag

    32 bits types are classified as type32_.

    @tparam T Base hierarchy
  **/
  template<typename T> using type32_ = sized_type_<T,32>;

  /*!
    @ingroup group-hierarchy
    @brief 64 bits type hierarchy tag

    64 bits types are classified as type64_.

    @tparam T Base hierarchy
  **/
  template<typename T> using type64_ = sized_type_<T,64>;
} }

#endif

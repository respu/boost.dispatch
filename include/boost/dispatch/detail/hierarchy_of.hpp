//==================================================================================================
/*!
  @file

  Defines the hierarchy_of meta-function extension point

  @copyright 2009 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_DETAIL_HIERARCHY_OF_HPP_INCLUDED
#define BOOST_DISPATCH_DETAIL_HIERARCHY_OF_HPP_INCLUDED

#include <boost/dispatch/meta/enable_if_type.hpp>
#include <boost/dispatch/hierarchy/scalar.hpp>
#include <boost/dispatch/property_of.hpp>
#include <type_traits>

namespace boost { namespace dispatch { namespace ext
{
  /*!
    @ingroup group-extension
    @brief SFINAE-enabled extension point for hierarchy_of

    This extension point allows customization of the hierarchy_of @metafunction
    by letting user defined SFINAE-enabled context in which they can specialize
    hierarchy_of for family of types

    @par Usage:

    @tparam T       Current reference type used for discrimination
    @tparam Origin  Type being categorized
    @tparam Enable  SFINAE condition to be specified
  **/
  template<typename T, typename Origin = T, typename Enable = void>
  struct  hierarchy_of
  {
    using type = scalar_<boost::dispatch::property_of_t<T,Origin>>;
  };

  // hierarchy_of on Hierarchy returns the Hierarchy
  template<typename T, typename Origin>
  struct  hierarchy_of<T, Origin, typename enable_if_type<typename T::hierarchy_tag>::type>
  {
    using type = T;
  };
}

namespace detail
{
  template<typename T, typename Origin> struct hierarchy_of : ext::hierarchy_of<T,Origin> {};

  template<typename T, typename Origin>
  struct hierarchy_of<T&,Origin> : detail::hierarchy_of<T,Origin> {};

  template<typename T, typename Origin>
  struct hierarchy_of<T&&,Origin> : detail::hierarchy_of<T,Origin> {};

  template<typename T, typename Origin>
  struct  hierarchy_of<T const,Origin>
        : detail::hierarchy_of<T,typename std::remove_const<Origin>::type>
  {};

#ifndef BOOST_NO_RESTRICT_REFERENCES
  template<typename T, typename Origin>
  struct hierarchy_of<T& BOOST_RESTRICT,Origin> : detail::hierarchy_of<T,Origin>
  {};
#endif
} } }

#endif

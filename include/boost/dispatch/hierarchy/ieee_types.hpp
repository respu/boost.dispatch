//==================================================================================================
/*!
  @file

  Defines the type hierarchies for IEEE-754 like types

  @copyright 2009 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_HIERARCHY_IEEE_TYPES_HPP_INCLUDED
#define BOOST_DISPATCH_HIERARCHY_IEEE_TYPES_HPP_INCLUDED

#include <boost/dispatch/hierarchy/fundamental.hpp>
#include <boost/dispatch/hierarchy/sized_types.hpp>

namespace boost { namespace dispatch
{
  /*!
    @ingroup group-hierarchy
    @brief IEEE-754 double type hierarchy tag

    Types are classified as double_ if they behaves as a double precision IEEE-754 type.

    @tparam T Base hierarchy
  **/
  template<typename T> struct double_ : type64_<T>
  {
    using parent = type64_<T>;
  };

  /*!
    @ingroup group-hierarchy
    @brief IEEE-754 single type hierarchy tag

    Types are classified as single_ if they behaves as a single precision IEEE-754 type.

    @tparam T Base hierarchy
  **/
  template<typename T> struct single_ : type32_<T>
  {
    using parent = type32_<T>;
  };

  /*!
    @ingroup group-hierarchy
    @brief Long double type hierarchy tag

    Types are classified as long_double_ if they behaves as a long double type.

    @tparam T Base hierarchy
  **/
  template<typename T> struct long_double_ : fundamental_<T>
  {
    using parent = fundamental_<T>;
  };
} }

#endif

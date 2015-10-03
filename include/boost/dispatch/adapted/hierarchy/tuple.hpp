//==================================================================================================
/*!
  @file

  Defines the tuple related hierarchies

  @copyright 2009 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_ADAPTED_HIERARCHY_TUPLE_HPP_INCLUDED
#define BOOST_DISPATCH_ADAPTED_HIERARCHY_TUPLE_HPP_INCLUDED

#include <boost/dispatch/hierarchy/unspecified.hpp>
#include <boost/fusion/include/as_vector.hpp>
#include <boost/dispatch/detail/brigand.hpp>
#include <type_traits>

namespace boost { namespace dispatch
{
  /*!
    @ingroup group-hierarchy
    @brief Tuple type hierarchy tag

    Types are classified as tuple_ if they represent a compound type models the FusionSequence
    concept.

    @tparam T Base type
    @tparam N Size of the classified tuple
  **/
  template<typename T, typename N> struct tuple_ : unspecified_<T>
  {
    /// tuple_ parent hierarchy type
    using parent = unspecified_<T>;
  };

  /*!
    @ingroup group-hierarchy
    @brief Homogeneous tuple type hierarchy tag

    Types are classified as bag_ if they represent a compound type that models the FusionSequence
    concept and which elements are all the same.

    By design, bag_ are also classifiable as tuple_.

    @tparam T Base hierarchy
    @tparam N Size of the classified bag
  **/
  template<typename T, typename N> struct bag_ : bag_<typename T::parent, N>
  {
    /// bag_ parent hierarchy type
    using parent = bag_<typename T::parent, N>;
  };

  template<typename T, typename N> struct bag_<unspecified_<T>,N> : tuple_<T,N>
  {
    using parent = tuple_<T,N>;
  };
} }

#endif

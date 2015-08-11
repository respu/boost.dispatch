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
#ifndef BOOST_DISPATCH_META_INTROSPECTION_IS_HOMOGENEOUS_HPP_INCLUDED
#define BOOST_DISPATCH_META_INTROSPECTION_IS_HOMOGENEOUS_HPP_INCLUDED

#include <boost/fusion/include/as_vector.hpp>
#include <boost/dispatch/detail/brigand.hpp>
#include <type_traits>

namespace boost { namespace dispatch
{
  namespace detail
  {
    template<typename Sequence> struct is_homogeneous_
    {
      // Turn the type into an actual Fusion Sequence
      using fixed = typename boost::fusion::result_of::as_vector<Sequence>::type;

      // Grab first element of the tuple
      using first = typename boost::fusion::result_of::value_at<fixed, brigand::int_<0>>::type;

      // Are all yes similar to first ?
      template<typename T> using same = typename std::is_same<T,first>::type;
      using type = brigand::all<brigand::as_list<fixed>,same>;
    };
  }

  /*!
    @ingroup group-meta
    @brief Detects homogeneous tuple

    For any given FusionSequence, checks if said sequence contains element of a single type.

    @tparam Sequence Type to check for homogeneity
  **/
  template<typename Sequence>
  using is_homogeneous = typename detail::is_homogeneous_<Sequence>::type;
} }

#endif

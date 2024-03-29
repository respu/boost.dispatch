//==================================================================================================
/*!
  @file

  Defines the tuple related hierarchies

  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_META_INTROSPECTION_IS_HOMOGENEOUS_HPP_INCLUDED
#define BOOST_DISPATCH_META_INTROSPECTION_IS_HOMOGENEOUS_HPP_INCLUDED

#include <boost/fusion/include/is_sequence.hpp>
#include <boost/fusion/include/as_vector.hpp>
#include <boost/fusion/include/size.hpp>
#include <boost/dispatch/detail/brigand.hpp>
#include <type_traits>
#include <tuple>

namespace boost { namespace dispatch
{
  namespace detail
  {
    template<typename Sequence> struct is_homogeneous_
    {
      static_assert ( boost::fusion::traits::is_sequence<Sequence>::value
                    , "Sequence does not model FusionSequence"
                    );

      // Zero sized sequence are not homogeneous
      using sz = boost::fusion::result_of::size<Sequence>;

      // Turn the type into an actual Fusion Sequence
      using fixed = typename boost::fusion::result_of::as_vector<Sequence>::type;

      template<typename T, bool Status> struct impl
      {
        // Empty sequence are not homogeneous
        using type = brigand::false_;
      };

      template<typename T>
      struct impl<T,true>
      {
        // Grab first element of the tuple
        using first = typename boost::fusion::result_of::value_at<fixed, boost::mpl::int_<0>>::type;

        // Are all types similar to first ?
        using same = std::is_same<brigand::_1,first>;
        using type = brigand::all<brigand::as_list<fixed>,same>;
      };

      using type = typename impl<fixed,sz::value != 0>::type;
    };

    // Special case for std::tuple<>
    template<> struct is_homogeneous_<std::tuple<>>
    {
      using type = brigand::false_;
    };

    // Special case for std::tuple<T>
    template<typename T> struct is_homogeneous_<std::tuple<T>>
    {
      using type = brigand::true_;
    };

    // Special case for std::tuple
    template<typename T, typename U, typename... Ts> struct is_homogeneous_<std::tuple<T,U,Ts...>>
    {
      // Are all yes similar to first ?
      using same = std::is_same<T,brigand::_1>;
      using type = brigand::all<std::tuple<U,Ts...>,same>;
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

//==================================================================================================
/*!
  @file

  Defines the upgrade meta-function

  @copyright 2009 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_META_GENERATION_UPGRADE_HPP_INCLUDED
#define BOOST_DISPATCH_META_GENERATION_UPGRADE_HPP_INCLUDED

#include <boost/dispatch/meta/introspection/primitive_of.hpp>
#include <boost/dispatch/meta/introspection/factory_of.hpp>
#include <boost/dispatch/meta/introspection/sign_of.hpp>
#include <boost/dispatch/meta/generation/make_integer.hpp>
#include <boost/dispatch/meta/generation/as_unsigned.hpp>
#include <boost/dispatch/meta/generation/apply_sign.hpp>
#include <boost/dispatch/meta/generation/as_signed.hpp>

#include <boost/dispatch/detail/brigand/sequences/pair.hpp>
#include <boost/dispatch/detail/brigand/sequences/map.hpp>
#include <boost/dispatch/detail/brigand/sequences/at.hpp>
#include <cstdint>

namespace boost { namespace dispatch
{
  namespace detail
  {
    template<typename T,typename Sign> struct upgrade;

    template<typename T,typename Sign>
    struct upgrade<T&,Sign> : boost::dispatch::detail::upgrade<T,Sign> {};

    template<typename T,typename Sign>
    struct upgrade<T&&,Sign> : boost::dispatch::detail::upgrade<T,Sign> {};

    template<typename T,typename Sign>
    struct upgrade<T const,Sign> : boost::dispatch::detail::upgrade<T,Sign> {};

    template<typename T,typename Sign> struct upgrade
    {
      // Decompose in factory/primitive
      using f_t = boost::dispatch::factory_of<T>;
      using p_t = boost::dispatch::primitive_of<T>;

      // Unsign the primitive to limit the map's size
      using b_t = boost::dispatch::as_unsigned<p_t>;

      // Use this map to transform to upgraded type
      using upgrade_map = brigand::map< brigand::pair<std::uint8_t  , std::uint16_t >
                                      , brigand::pair<std::uint16_t , std::uint32_t >
                                      , brigand::pair<std::uint32_t , std::uint64_t >
                                      , brigand::pair<std::uint64_t , std::uint64_t >
                                      , brigand::pair<unsigned long , std::uint64_t >
                                      , brigand::pair<float         , double        >
                                      , brigand::pair<double        , double        >
                                      >;

      using ub_t = brigand::at<upgrade_map,b_t>;

      // Reapply sign and reconstruct
      using u_t  = boost::dispatch::apply_sign<ub_t,Sign>;
      using type = typename f_t::template apply<u_t>;
    };

    // sizeof(bool) is non-standard, so we can't just map its upgrade to (un)signed short
    template<typename Sign>
    struct  upgrade<bool,Sign>
          : upgrade< boost::dispatch::make_integer<sizeof(bool)>,Sign>
    {};
  }

  template<typename T,typename Sign = sign_of<T>>
  using upgrade = typename detail::upgrade<T,Sign>::type;
} }

#endif

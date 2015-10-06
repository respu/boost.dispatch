//==================================================================================================
/*!
  @file

  Defines the upgrade meta-function

  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_META_GENERATION_UPGRADE_HPP_INCLUDED
#define BOOST_DISPATCH_META_GENERATION_UPGRADE_HPP_INCLUDED

#include <boost/dispatch/meta/detail/updowngrade.hpp>
#include <boost/dispatch/detail/brigand.hpp>
#include <cstdint>

namespace boost { namespace dispatch
{
  namespace detail
  {
    // Use this map to transform to upgraded type
    using upgrade_map = brigand::map< brigand::pair<std::uint8_t  , std::uint16_t >
                                    , brigand::pair<std::uint16_t , std::uint32_t >
                                    , brigand::pair<std::uint32_t , std::uint64_t >
                                    , brigand::pair<std::uint64_t , std::uint64_t >
                                    , brigand::pair<float         , double        >
                                    , brigand::pair<double        , double        >
                                    >;

    template<typename T,typename Sign>
    struct upgrade : boost::dispatch::detail::updowngrade<T,Sign,upgrade_map> {};

    template<typename T,typename Sign>
    struct upgrade<T&,Sign> : boost::dispatch::detail::upgrade<T,Sign> {};

    template<typename T,typename Sign>
    struct upgrade<T&&,Sign> : boost::dispatch::detail::upgrade<T,Sign> {};

    template<typename T,typename Sign>
    struct upgrade<T const,Sign> : boost::dispatch::detail::upgrade<T,Sign> {};

    // sizeof(bool) is non-standard, so we can't just map its upgrade to (un)signed short
    template<typename Sign>
    struct  upgrade<bool,Sign>
          : boost::dispatch::detail::upgrade<boost::dispatch::make_integer_t<sizeof(bool)>,Sign>
    {};
  }

  template<typename T,typename Sign = sign_of_t<T>>
  struct upgrade : detail::upgrade<T,Sign>
  {};

  template<typename T,typename Sign = sign_of_t<T>>
  using upgrade_t = typename upgrade<T,Sign>::type;
} }

#endif

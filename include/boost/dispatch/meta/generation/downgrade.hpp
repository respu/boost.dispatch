//==================================================================================================
/*!
  @file

  Defines the downgrade meta-function

  @copyright 2009 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
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
    // Use this map to transform to downgraded type
    using downgrade_map = brigand::map< brigand::pair<bool          , bool          >
                                      , brigand::pair<std::uint8_t  , std::uint8_t  >
                                      , brigand::pair<std::uint16_t , std::uint8_t  >
                                      , brigand::pair<std::uint32_t , std::uint16_t >
                                      , brigand::pair<std::uint64_t , std::uint32_t >
                                      , brigand::pair<float         , float         >
                                      , brigand::pair<double        , float         >
                                      >;

    template<typename T,typename Sign>
    struct downgrade : boost::dispatch::detail::updowngrade<T,Sign,downgrade_map> {};

    template<typename T,typename Sign>
    struct downgrade<T&,Sign> : boost::dispatch::detail::downgrade<T,Sign> {};

    template<typename T,typename Sign>
    struct downgrade<T&&,Sign> : boost::dispatch::detail::downgrade<T,Sign> {};

    template<typename T,typename Sign>
    struct downgrade<T const,Sign> : boost::dispatch::detail::downgrade<T,Sign> {};
  }

  template<typename T,typename Sign = sign_of<T>>
  using downgrade = typename detail::downgrade<T,Sign>::type;
} }

#endif

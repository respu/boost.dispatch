//==================================================================================================
/*!
  @file

  Defines the make_floating meta-function

  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_META_GENERATION_MAKE_FLOATING_HPP_INCLUDED
#define BOOST_DISPATCH_META_GENERATION_MAKE_FLOATING_HPP_INCLUDED

#include <boost/dispatch/detail/brigand.hpp>
#include <cstddef>

namespace boost { namespace dispatch
{
  namespace detail
  {
    template< std::size_t Size, typename Transform>
    struct  make_floating
    {
      static_assert ( Size == sizeof(float) || Size == sizeof(double)
                    , "boost::dispatch::make_floating: can't generate type of given Size"
                    );
      using type = brigand::no_such_type_;
    };

    template<typename Transform>
    struct make_floating<sizeof(double),Transform>
    {
      using type = brigand::apply<Transform,double>;
    };

    template<typename Transform>
    struct make_floating<sizeof(float),Transform>
    {
      using type = brigand::apply<Transform,float>;
    };
  }

  /*!
    @ingroup group-meta
    @brief Generate a floating point type of a given size

    For any given Size corresponding to a valid floating point type, return said type optionally
    transformed by an user-defined unary meta-function.

    @tparam Size      Size in bytes of the requested type
    @tparam Transform Optional unary meta-function to apply to the generated type
  **/
  template<std::size_t Size, typename Transform = brigand::identity<brigand::_1>>
  struct make_floating : detail::make_floating<Size,Transform>
  {};

  template<std::size_t Size, typename Transform = brigand::identity<brigand::_1>>
  using make_floating_t = typename make_floating<Size,Transform>::type;
} }

#endif

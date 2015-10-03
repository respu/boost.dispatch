//==================================================================================================
/*!
  @file
  @ingroup group-adapted

  Adapt std::integral_constant to be hierarchizable

  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_ADAPTED_STD_INTEGRAL_CONSTANT_HPP_INCLUDED
#define BOOST_DISPATCH_ADAPTED_STD_INTEGRAL_CONSTANT_HPP_INCLUDED

#include <boost/dispatch/meta/introspection/value_of.hpp>
#include <boost/dispatch/meta/introspection/model_of.hpp>
#include <boost/dispatch/adapted/hierarchy/integral_constant.hpp>
#include <type_traits>

namespace boost { namespace dispatch
{
  // model/value_of adaptation
  namespace ext
  {
    template<typename T, T N> struct model_of<std::integral_constant<T,N>>
    {
      template<typename X> struct apply { using type = std::integral_constant<X,X(N)>; };
    };

    template<typename T, T N> struct value_of<std::integral_constant<T,N>>
    {
      using type = T;
    };
  }

  namespace ext
  {
    // integral_constant<T,N> hierarchies as constant_< (u)int{8,16,32,64}<Origin> >
    template<typename T, T N, typename Origin>
    struct hierarchy_of<std::integral_constant<T,N>,Origin>
    {
      using type = constant_< boost::dispatch::property_of_t<T,Origin> >;
    };
  }

} }

#endif

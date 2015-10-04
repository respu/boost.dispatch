//==================================================================================================
/*!
  @file

  Provides the callable object registration macro

  @copyright 2009 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_FUNCTION_MAKE_CALLABLE_HPP_INCLUDED
#define BOOST_DISPATCH_FUNCTION_MAKE_CALLABLE_HPP_INCLUDED

#include <boost/dispatch/function/overload.hpp>
#include <boost/dispatch/function/functor.hpp>
#include <boost/dispatch/hierarchy/base.hpp>
#include <boost/dispatch/detail/auto_decltype.hpp>

/*!
  @ingroup group-api

  Generates the boilerplate code for adapting a @c TAG type as a Boost.Dispatch callable
  object

  @par Usage:

  @param TAG    Tag type to be implemented
  @param PARENT Tag's parent hierarchy
**/
#define BOOST_DISPATCH_MAKE_CALLABLE(TAG,PARENT)                                                    \
template<typename... Args>                                                                          \
static BOOST_FORCEINLINE BOOST_AUTO_DECLTYPE dispatch_to(Args&&... args)                            \
BOOST_AUTO_DECLTYPE_BODY( BOOST_DISPATCH_DISPATCHING_FUNCTION(TAG)                                  \
                          (ext::adl_helper(), std::forward<Args>(args)...)                          \
                        )                                                                           \
using parent = PARENT                                                                               \
/**/

/*!
  @ingroup group-api

  Generates the boilerplate code for generating a @c TAG type as
  a Boost.Dispatch callable object

  @par Usage:

  @param TAG    Tag type to be implemented
  @param PARENT Tag's parent hierarchy
**/
#define BOOST_DISPATCH_MAKE_TAG(TAG, PARENT)                                                        \
struct TAG : PARENT { BOOST_DISPATCH_MAKE_CALLABLE(TAG,PARENT); }                                   \
/**/

/*!
  @ingroup group-api

  Generates the boilerplate code for defining the dispatching function for a given @c TAG

  @par Usage:

  @param NAMESPACE  Namespace containing @c TAG
  @param TAG        Tag type identifier
**/
#define BOOST_DISPATCH_FUNCTION_DECLARATION(NAMESPACE,TAG)                                          \
template<typename Site>                                                                             \
inline generic_dispatcher<NAMESPACE::TAG>                                                           \
BOOST_DISPATCH_IMPLEMENTS(TAG, ::boost::dispatch::unspecified_<Site> const&, ... )                  \
{                                                                                                   \
  return {};                                                                                        \
}                                                                                                   \
/**/

/*!
  @ingroup group-api

  Generates a callable object from a @c TAG

  @par Usage:

  @param TAG  Fully qualified tag type to adapt
  @param NAME Callable object identifier
**/
#define BOOST_DISPATCH_FUNCTION_DEFINITION(TAG,NAME)                                                \
static const boost::dispatch::functor<TAG> NAME = {}                                                \
/**/

#endif

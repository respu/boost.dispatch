//==================================================================================================
/*!
  @file

  Helpers to define functions using the auto/decltype syntax

  @copyright 2009 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_DETAIL_AUTO_DECLTYPE_HPP_INCLUDED
#define BOOST_DISPATCH_DETAIL_AUTO_DECLTYPE_HPP_INCLUDED

#include <boost/config.hpp>

/*!

**/
#define BOOST_AUTO_DECLTYPE_BODY_SFINAE(body) -> decltype(body) { return body; }

#if defined(BOOST_NO_CXX14_RETURN_TYPE_DEDUCTION) || defined(BOOST_NO_CXX14_DECLTYPE_AUTO) || BOOST_VERSION < 105800
#define BOOST_AUTO_DECLTYPE               auto
#define BOOST_AUTO_DECLTYPE_HEADER(body)  -> decltype(body)
#define BOOST_AUTO_DECLTYPE_BODY(body)    BOOST_AUTO_DECLTYPE_BODY_SFINAE(body)
#else
/*!

**/
#define BOOST_AUTO_DECLTYPE               decltype(auto)

/*!

**/
#define BOOST_AUTO_DECLTYPE_HEADER(body)

/*!

**/
#define BOOST_AUTO_DECLTYPE_BODY(body)    { return body; }
#endif

#endif

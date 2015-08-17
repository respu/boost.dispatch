//==================================================================================================
/*!
  @file

  Defines functions properties hierarchies

  @copyright 2009 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_HIERARCHY_FUNCTIONS_HPP_INCLUDED
#define BOOST_DISPATCH_HIERARCHY_FUNCTIONS_HPP_INCLUDED

#include <boost/dispatch/hierarchy/fundamental.hpp>

namespace boost { namespace dispatch
{
  /*!
    @ingroup group-hierarchy
    @brief Elementwise function hierarchy tag

    Function object classified as elementwise_ if they can be used as argument to the map
    higher-order function.

    @tparam F Function object type
  **/
  template<typename F> struct elementwise_ : function_<F>
  {
    using parent = function_<F>;
  };

  /*!
    @ingroup group-hierarchy
    @brief Reductive function hierarchy tag

    Function object classified as reduction_ if they can be used as argument to the fold
    higher-order function.

    @tparam F Function object type
    @tparam BinOp Function object type for the underlying binary function used by fold
    @tparam NeutralElement Function object type returning the neutral element value of BinOp
  **/
  template<typename F, typename BinOp, typename NeutralElement>
  struct reduction_ : function_<F>
  {
    using parent = function_<F>;
  };

  /*!
    @ingroup group-hierarchy
    @brief Cumulative function hierarchy tag

    Function object classified as cumulative_ if they can be used as argument to the scan
    higher-order function.

    @tparam F Function object type
    @tparam BinOp Function object type for the underlying binary function used by scan
    @tparam NeutralElement Function object type returning the neutral element value of BinOp
  **/
  template<typename F, typename BinOp, typename NeutralElement>
  struct cumulative_ : function_<F>
  {
    using parent = function_<F>;
  };
} }

#endif

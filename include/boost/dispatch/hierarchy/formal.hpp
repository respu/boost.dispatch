//==================================================================================================
/*!
  @file

  Defines the formal_ hierarchy

  @copyright 2009 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_HIERARCHY_FORMAL_HPP_INCLUDED
#define BOOST_DISPATCH_HIERARCHY_FORMAL_HPP_INCLUDED

#include <boost/dispatch/hierarchy/unspecified.hpp>

namespace boost { namespace dispatch
{
  /*!
    @ingroup group-hierarchy
    @brief Formal architecture hierarchy tag

    The formal_ hierarchy represents a 'virtual' hardware in which code transformation but
    no execution can take place. Functions defined on formal_ hardware are usually trampoline
    function that rewrite or transform code path.
  **/
  struct formal_ : unspecified_<formal_>
  {
    using parent        =  unspecified_<formal_>;
  };
} }

#endif

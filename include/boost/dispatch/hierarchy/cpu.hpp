//==================================================================================================
/*!
  @file

  Defines the cpu_ hierarchy

  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_HIERARCHY_CPU_HPP_INCLUDED
#define BOOST_DISPATCH_HIERARCHY_CPU_HPP_INCLUDED

#include <boost/dispatch/hierarchy/formal.hpp>

namespace boost { namespace dispatch
{
  /*!
    @ingroup group-hierarchy
    @brief Basic architecture hierarchy tag

    The cpu_ hierarchy represents hardware with no specificities. Functions defined on cpu_
    hardware usually have common, hardware agnostic implementations.
  **/
  struct cpu_ : formal_
  {
    using parent = formal_;
  };
} }

#endif

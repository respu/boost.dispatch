//==================================================================================================
/*!
  @file

  Provides a kitchen sink include files for the Boost.Dispatch library

  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_HPP_INCLUDED
#define BOOST_DISPATCH_HPP_INCLUDED

#include <boost/dispatch/config.hpp>
#include <boost/dispatch/hierarchy.hpp>
#include <boost/dispatch/meta/introspection.hpp>
#include <boost/dispatch/meta/transfer_qualifiers.hpp>

namespace boost { namespace dispatch
{
  namespace concept
  {
    /*!
      @defgroup group-concept Concepts
      Concepts defined by the library
    **/
  }

  namespace detail
  {
    /*!
      @defgroup group-detail Implementation details
      Implementation details related components
    **/
  }

  namespace ext
  {
    /*!
      @defgroup group-extension Extension points
      Extension points for library components
    **/
  }

  /*!
    @defgroup group-api User API
    User level library components
  **/

  /*!
    @defgroup group-meta Meta-programming Utilities
    Meta-programming related components
  **/

  /*!
    @defgroup group-hierarchy Predefined Hierarchies
    Type hierarchies provided by the library
  **/

  /*!
    @defgroup group-adapted External adapters
    Adaptation header for external libraries
  **/
} }

#endif

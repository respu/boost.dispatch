//==================================================================================================
/*!
  @file

  Defines the scalar_ hierarchy

  @copyright 2009 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_META_HIERARCHY_SCALAR_HPP_INCLUDED
#define BOOST_DISPATCH_META_HIERARCHY_SCALAR_HPP_INCLUDED

//#include <boost/dispatch/hierarchy/unspecified.hpp>

namespace boost { namespace dispatch
{
  /*!
    @ingroup group-hierarchy
    @brief Scalar types hierarchy tag

    The scalar_ hierarchy represents types which values are stored in one or multiple general
    purpose registers.

    @tparam Hierarchy Type hierarchy
  **/
  template<typename Hierarchy>
  struct scalar_ : scalar_<typename Hierarchy::parent>
  {
    using parent = scalar_<typename Hierarchy::parent>;
  };

/*
  // When hitting unspecified_, we strip the scalar informations and use the basic property beneath
  template<typename Type>
  struct scalar_< unspecified_<Type> > : property_of<Type>
  {
    using parent = property_of<T>;
  };
*/
} }

#endif

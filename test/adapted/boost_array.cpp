//==================================================================================================
/*
  Copyright 2009 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
  Copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/adapted/boost/array.hpp>
#include <boost/dispatch/meta/introspection.hpp>
#include <boost/array.hpp>

#include <nstest/unit.hpp>
#include <nstest/unit/tests/types.hpp>

NSTEST_CASE( "factory_of over boost::array<T,N>")
{
  using base = boost::array<boost::array<boost::array<float,7>,5>,3>;

  NSTEST_TYPE_IS( (boost::dispatch::factory_of<base>::make<int*>)
                , (boost::array<boost::array<boost::array<int*,7>,5>,3>)
                );
}

NSTEST_CASE( "model_of of boost::array<T,N> is boost::array<_,N>")
{
  NSTEST_TYPE_IS( (boost::dispatch::model_of<boost::array<float,3>>::make<int>)
                , (boost::array<int,3>)
                );

  NSTEST_TYPE_IS( (boost::dispatch::model_of<boost::array<float,3>&>::make<int>)
                , (boost::array<int,3>)
                );

  NSTEST_TYPE_IS( (boost::dispatch::model_of<boost::array<float,3>&&>::make<int>)
                , (boost::array<int,3>)
                );

  NSTEST_TYPE_IS( (boost::dispatch::model_of<boost::array<float,3> const>::make<int>)
                , (boost::array<int,3>)
                );

  NSTEST_TYPE_IS( (boost::dispatch::model_of<boost::array<float,3> const&>::make<int>)
                , (boost::array<int,3>)
                );
}

NSTEST_CASE( "value_of of boost::array<T,N> is T")
{
  NSTEST_TYPE_IS( (boost::dispatch::value_of<boost::array<float,3>>)
                , float
                );

  NSTEST_TYPE_IS( (boost::dispatch::value_of<boost::array<float,3> const>)
                , float const
                );

  NSTEST_TYPE_IS( (boost::dispatch::value_of<boost::array<float,3>&>)
                , float&
                );

  NSTEST_TYPE_IS( (boost::dispatch::value_of<boost::array<float,3> const&>)
                , float const&
                );

  NSTEST_TYPE_IS( (boost::dispatch::value_of<boost::array<float,3>&&>)
                , float&&
                );

  NSTEST_TYPE_IS( (boost::dispatch::value_of<boost::array<boost::array<int,3>,5>>)
                , (boost::array<int,3>)
                );

  NSTEST_TYPE_IS( (boost::dispatch::value_of<boost::array<boost::array<int,3>,5>&>)
                , (boost::array<int,3>&)
                );

  NSTEST_TYPE_IS( (boost::dispatch::value_of<boost::array<boost::array<int,3>,5> const>)
                , (boost::array<int,3> const)
                );

  NSTEST_TYPE_IS( (boost::dispatch::value_of<boost::array<boost::array<int,3>,5> const&>)
                , (boost::array<int,3> const&)
                );

  NSTEST_TYPE_IS( (boost::dispatch::value_of<boost::array<boost::array<int,3>,5>&&>)
                , (boost::array<int,3>&&)
                );
}

NSTEST_CASE( "primitive_of of boost::array<T,N> is T")
{
  NSTEST_TYPE_IS( (boost::dispatch::primitive_of<boost::array<float,3>>)
                , float
                );

  NSTEST_TYPE_IS( (boost::dispatch::primitive_of<boost::array<float,3>&>)
                , float&
                );

  NSTEST_TYPE_IS( (boost::dispatch::primitive_of<boost::array<float,3>&&>)
                , float&&
                );

  NSTEST_TYPE_IS( (boost::dispatch::primitive_of<boost::array<float,3> const>)
                , float const
                );

  NSTEST_TYPE_IS( (boost::dispatch::primitive_of<boost::array<float,3> const&>)
                , float const&
                );

  NSTEST_TYPE_IS( (boost::dispatch::primitive_of<boost::array<boost::array<float,5>,3>>)
                , float
                );

  NSTEST_TYPE_IS( (boost::dispatch::primitive_of<boost::array<boost::array<float,5>,3>&>)
                , float&
                );

  NSTEST_TYPE_IS( (boost::dispatch::primitive_of<boost::array<boost::array<float,5>,3>&&>)
                , float&&
                );

  NSTEST_TYPE_IS( (boost::dispatch::primitive_of<boost::array<boost::array<float,5>,3> const>)
                , float const
                );

  NSTEST_TYPE_IS( (boost::dispatch::primitive_of<boost::array<boost::array<float,5>,3> const&>)
                , float const&
                );
}

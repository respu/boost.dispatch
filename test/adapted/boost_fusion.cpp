//==================================================================================================
/*
  Copyright 2009 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
  Copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/adapted/boost/fusion.hpp>
#include <boost/fusion/include/adapt_struct.hpp>
#include <boost/dispatch/hierarchy_of.hpp>
#include <boost/fusion/include/vector.hpp>

#include <nstest.hpp>

namespace bar
{
  struct foo
  {
    int i;
    double j;
    char k;
  };

  struct foo2
  {
    double i,j,k;
  };
}

BOOST_FUSION_ADAPT_STRUCT(bar::foo,i,j,k);
BOOST_FUSION_ADAPT_STRUCT(bar::foo2,i,j,k);

NSTEST_CASE( "hierarchy_of over boost::fusion::vector<T...>")
{
  using namespace boost::dispatch;

  NSTEST_TYPE_IS( hierarchy_of<boost::fusion::vector<>>
                , ( tuple_< boost::fusion::vector<>
                          , std::integral_constant<std::size_t,0u>
                          >
                  )
                );

  NSTEST_TYPE_IS( (hierarchy_of<boost::fusion::vector<int,void*,char,std::size_t*,float[4]>>)
                , ( tuple_< boost::fusion::vector<int,void*,char,std::size_t*,float[4]>
                          , std::integral_constant<std::size_t, 5u>
                          >
                  )
                );

  NSTEST_TYPE_IS( hierarchy_of<boost::fusion::vector<int>>
                , ( bag_< int32_<boost::fusion::vector<int>>
                        , std::integral_constant<std::size_t, 1u>
                        >
                  )
                );

  NSTEST_TYPE_IS( (hierarchy_of<boost::fusion::vector<int,int,int,int,int>>)
                , ( bag_< int32_<boost::fusion::vector<int,int,int,int,int>>
                        , std::integral_constant<std::size_t, 5u>
                        >
                  )
                );
}

NSTEST_CASE( "hierarchy_of over adapted sequences")
{
  using namespace boost::dispatch;

  NSTEST_TYPE_IS( hierarchy_of<bar::foo>
                , ( tuple_<bar::foo, std::integral_constant<std::size_t,3u>>)
                );

  NSTEST_TYPE_IS( hierarchy_of<bar::foo2>
                , ( bag_<double_<bar::foo2>, std::integral_constant<std::size_t,3u>>)
                );
}

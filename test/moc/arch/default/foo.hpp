//==================================================================================================
/*
  Copyright 2009 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
  Copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef ARCH_DEFAULT_FOO_INCLUDED
#define ARCH_DEFAULT_FOO_INCLUDED

#include <boost/dispatch/hierarchy/cpu.hpp>
#include <boost/dispatch/hierarchy/base.hpp>
#include <boost/dispatch/hierarchy/functions.hpp>

namespace boost { namespace dispatch { namespace meta
{
  struct dub
  {
    template<typename T> T operator()(T const& x) { return x/10; }
  };

  struct dub2
  {
    template<typename T> T operator()(T const& x) { return x*10; }
  };

  template<typename F, typename A, typename T>
  dub dispatching ( meta::adl_helper const& , function_<F> const&
                                            , unspecified_<A> const&
                                            , scalar_<unspecified_<T>> const&
                  )
  {
    return {};
  }
} } }

#endif

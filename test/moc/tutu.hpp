//==================================================================================================
/*
  Copyright 2009 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
  Copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef TUTU_INCLUDED
#define TUTU_INCLUDED

#include <boost/dispatch/function/register_namespace.hpp>

namespace tutu { namespace titi
{
  BOOST_DISPATCH_REGISTER_NAMESPACE(ext, (boost::dispatch::generic_dispatcher<Tag,Site>) );
} }

#endif
